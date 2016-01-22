#include "Node.h"

TreeNode *createNodeIns(int line, string type, string content, int childrenSize, ...) {
    TreeNode *p = ConstValue::get(type);
    p->className = type;
    p->lineCount = line;
    p->content = content;
    p->childrenSize = childrenSize;
    p->children.resize(childrenSize);
    if(p->className=="INT"){
        p->content=p->Codegen();
    }
    va_list childrenList;
    va_start(childrenList, childrenSize);
    int i;
    for (i = 0; i < childrenSize; i++) {
        p->children[i] = va_arg(childrenList, TreeNode*);
        p->children[i]->parent = p;
    }
    va_end(childrenList);
    return p;
}


string PROGRAMTreeNode::Codegen() {
    addCode("@.str = private unnamed_addr constant [3 x i8] c\"%d\\00\", align 1\n");
    addCode("@.str1 = private unnamed_addr constant [4 x i8] c\"%d\\0A\\00\", align 1\n");
    for (auto c:children) {
        c->Codegen();
    }
    addCode("\ndeclare i32 @__isoc99_scanf(i8*, ...) #1\n");
    addCode("declare i32 @printf(i8*, ...) #1\n");

    addCode("attributes #0 = { nounwind uwtable \"less-precise-fpmad\"=\"false\"\"no-frame-pointer-elim\"=\"true\" \"no-frame-pointer-elim-non-leaf\" \"no-infs-fp-math\"=\"false\" \"no-nans-fp-math\"=\"false\" \"stack-protector-buffer-size\"=\"8\" \"unsafe-fp-math\"=\"false\" \"use-soft-float\"=\"false\" }")
    addCode("attributes #1 = { \"less-precise-fpmad\"=\"false\" \"no-frame-pointer-elim\"=\"true\" \"no-frame-pointer-elim-non-leaf\" \"no-infs-fp-math\"=\"false\" \"no-nans-fp-math\"=\"false\" \"stack-protector-buffer-size\"=\"8\" \"unsafe-fp-math\"=\"false\" \"use-soft-float\"=\"false\" }");

    return "NULL";
}

string EXTDEFSTreeNode::Codegen() {
    return TreeNode::Codegen();
}

string EXTDEFTreeNode::Codegen() {
    smartEmit
    if (content == "EXTDEF: TYPE FUNC STMTBLOCK") {
        insideFunction = true;
        string ret = TreeNode::Codegen();
        insideFunction = false;
        return ret;
    } else if(content=="EXTDEF: STSPEC SEXTVARS ;"){
        string tmp=TreeNode::Codegen();
        structType.clear();
        return tmp;
    }
    return TreeNode::Codegen();
}

string EXTVARSTreeNode::Codegen() {
    if (children.size() <= 2) { //var//var,extvars
        TreeNode *t = children[0];
        if (t->content == "VAR: ID") {
            addCode("%s  = common global i32 0, align 4\n");
            string memPtr;
            rtn = saveIdtoTable(t->children.at(0)->content, "i32", memPtr);
            CHECK_RTN("error in saving to table");
            addReg(memPtr);
        } else if (t->content == "VAR: ID [ INT ]") {
            addCode("%s  = common global [ " + t->children.at(1)->content + " x i32] zeroinitializer, align 4\n");
            string memPtr;
            rtn = saveIdtoTable(t->children.at(0)->content, "[ " + t->children.at(1)->content + " x i32]", memPtr);
            CHECK_RTN("error in saving to table");
            addReg(memPtr);
        } else {
            err("Content not valid");
        }
        for (int i = 1; i < children.size(); i++) {
            children[i]->Codegen();
        }
    }
    else if (children.size() <= 4) { //var = init
        const TreeNode *t = children.at(0);
        const TreeNode *r = children.at(2);
        if (t->content == "VAR: ID" && r->content == "INIT: EXPS") {
            //EXPS must be INT
            if (!isdigit(r->children.at(0)->content.back())) {
                err("not digit in initialize");
                exit(-1);
            }
            addCode("%s  = common global i32 " + r->children.at(0)->content + ", align 4\n");
            string memPtr;
            rtn = saveIdtoTable(t->children.at(0)->content, "i32", memPtr);
            CHECK_RTN("error in saving to table");
            addReg(memPtr);

        } else if (t->content == "VAR: ID [ INT ]" && r->content == "INIT: { ARGS }") {
            EnableCodeGen = false;
            string list = r->children.at(0)->Codegen();
            EnableCodeGen = true;

            addCode("%s  = common global [ " + t->children.at(1)->content + " x i32] [ " + list + " ], align 4\n");
            string memPtr;
            // cerr<<"117 @"<<content<<endl;
            string saveType="[ " + t->children.at(1)->content + " x i32]";

            rtn = saveIdtoTable(t->children.at(0)->content, saveType, memPtr);
            CHECK_RTN("error in saving to table");
            addReg(memPtr);
            // cerr<<"ending @"<<content<<endl;
        } else {
            err("Content not valid #"+t->content+"#"+r->content+"#");
        }


        for (int i = 3; i < children.size(); i++) {
            children[i]->Codegen();
        }
    }
    return "NULL";
}

string DEFSTreeNode::Codegen() {
    if (content == "DEFS: TYPE DECS ; DEFS") {
        children.at(1)->Codegen();
        children.at(2)->Codegen();
        return "NULL";
    } else if (content == "DEFS: STSPEC SDECS ; DEFS") {
        err("not implemented");
        exit(-1);
    }
    return TreeNode::Codegen();
}


string DECSTreeNode::Codegen() {
    if (children.size() <= 2) { //var//var,extvars
        TreeNode *t = children[0];
        if (t->content == "VAR: ID") {
            addCode("%s  = alloca i32 , align 4\n");
            string memPtr;
            rtn = saveIdtoTable(t->children.at(0)->content, "i32", memPtr);
            CHECK_RTN("error in saving to table");
            addReg(memPtr);
        } else if (t->content == "VAR: ID [ INT ]") {
            addCode("%s  = alloca [ " + t->children.at(1)->content + " x i32] , align 4\n");
            string memPtr;
            rtn = saveIdtoTable(t->children.at(0)->content, "[ " + t->children.at(1)->content + " x i32]", memPtr);
            CHECK_RTN("error in saving to table");
            addReg(memPtr);
        } else {
            err("Content not valid");
        }
        for (int i = 1; i < children.size(); i++) {
            children[i]->Codegen();
        }
    }
    else if (children.size() <= 4) { //var = init
        TreeNode *t = children.at(0);
        TreeNode *r = children.at(2);
        if (t->content == "VAR: ID" && r->content == "INIT: EXPS") {//a=1
            //EXPS must be INT

            string memPtr;
            rtn = saveIdtoTable(t->children.at(0)->content, "i32", memPtr);
            CHECK_RTN("error in saving to table");
            addCode("%s  = alloca i32 , align 4\n");
            addReg(memPtr);

            getPointer=false;
            string tmp=r->children.at(0)->Codegen();

            addCode(" store i32 %s , i32* %s, align 4")
            addReg(tmp)
            addReg(memPtr)

            freReg(tmp);


        } else if (t->content == "VAR: ID [ INT ]" && r->content == "INIT: { ARGS }") {//a={0,1}


            addCode("%s  = alloca [ " + t->children.at(1)->content + " x i32] , align 4\n");
            string memPtr;
            rtn = saveIdtoTable(t->children.at(0)->content, "[ " + t->children.at(1)->content + " x i32]", memPtr);
            CHECK_RTN("error in saving to table");
            arrsize = atoi(t->children.at(1)->content.c_str());
            arrid = memPtr;
            addReg(memPtr);
            arrindex=0;
            r->children.at(0)->CodeHelperGen();

        } else {
            err("Content not valid left:" + t->content+ "right"+ r->content);
        }


        for (int i = 3; i < children.size(); i++) {
            children[i]->Codegen();
        }
    }

    return "NULL";
}

string INITTreeNode::Codegen() {
    return TreeNode::Codegen();
}

string ARGSTreeNode::Codegen() {
    string ret;
    getPointer = false;
    string val = children.at(0)->Codegen();
    if(val=="NULL"){
        return "";
    }
    args.push_back(val);
    //cerr<<"getting "<<val<<children.at(0)->content<<endl;
    if (isdigit(val.at(0)) || val.at(0) == '-') { // const
        ret = " i32 " + val + " ";
    } else {
        // cerr << " register must be i32, not checking."<<val<< endl;
        ret = " i32 " + val + " ";
    }

    for (uint i = 1; i < (int) children.size(); i++) {
        ret.append(",");
        ret.append(children.at(i)->Codegen());
    }
    return ret;
}


string FUNCTreeNode::Codegen() {
    EnableCodeGen = false;
    string list = children.at(1)->Codegen();
    EnableCodeGen = true;

    addCode("define i32 @%s(" + list + ") #0")
    addReg(children.at(0)->content)
    return "NULL";
}

string ARRSTreeNode::Codegen() {
    err("should not be called")
    return TreeNode::Codegen();
}


string UNARYOPTreeNode::Codegen() {
    err("should not be called")
    return TreeNode::Codegen();
}


string VARTreeNode::Codegen() {
    err("should not be called")
    return TreeNode::Codegen();
}

string PARASTreeNode::Codegen() {
    string ret;
    if (children.size() >= 2) { // int id
        string id = children.at(1)->content;
        ret = " i32 %%" + id + " ";
        paras.push_back(id);
        for (uint i = 2; i < children.size(); i++) {
            ret.append(",");
            ret.append(children.at(i)->Codegen());
        }
    }
    return ret;
}

string STMTBLOCKTreeNode::Codegen() {
    if (insideStmtBlocks == 0) {
        addCode("{\n")
    }
    if (paras.size() > 0) {
        for (int i = 0; i < paras.size(); i++) {
            string reg;
            rtn = saveIdtoTable(paras[i], "i32", "para", reg);
            CHECK_RTN("error in saving id when paras size>0");
            addCode("    %s = alloca i32, align 4\n")
            addReg(reg);
            addCode("    store i32 %%%s, i32* %s, align 4\n");
            addReg(paras[i])
            addReg(reg);
        }
        paras.clear();
    };
    TreeNode::Codegen();
    if (insideStmtBlocks == 0) {
        addCode("}\n")
    };
    return "NULL";
}

//done
string STMTSTreeNode::Codegen() {
    return TreeNode::Codegen();
}

string STMTTreeNode::Codegen() {
    if (content == "STMT: read ( EXPS )") {
        getPointer = true;
        string tmp = children.at(0)->Codegen();

        addCode(" %s = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* %s)")
        addReg(allocateRegister("tmp_"))
        addReg(tmp);
        freReg(tmp);

    } else if (content == "STMT: write ( EXPS )") {
        getPointer = false;
        string tmp = children.at(0)->Codegen();
        addCode("%s = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 %s)")
        addReg(allocateRegister("tmp_"))
        addReg(tmp);

        freReg(tmp);
    } else if (content == "STMT: STMTBLOCK") {
        insideStmtBlocks++;
        string ret = TreeNode::Codegen();
        insideStmtBlocks--;
        return ret;
    } else if (content == "STMT: EXP ;") {
        string ret= TreeNode::Codegen();
        freReg(ret);
    } else if (content == "STMT: RETURN EXPS ;") {
        //0: return
        //1: exps
        //string reg=allocateRegister();
        if (!insideFunction) {
            err("return must call inside function!");
            exit(-1);
        }
        string reg = children[1]->Codegen();
        addCode("ret i32 %s");
        addReg(reg);
        freReg(reg);
    } else if (content == "STMT: if ( EXPS ) STMT" || content == "STMT: if ( EXPS ) STMT else STMT") {
        //unimplemented
        ifnum++;
        getPointer = false;
        string reg = children.at(0)->Codegen();
        string tmp = allocateRegister("tmp_");
        if(children.at(0)->retType=="i1") {
            addCode(" %s = icmp ne i1 %s, 0\n")
        }else{
            addCode(" %s = icmp ne i32 %s, 0\n")
        }
        addReg(tmp)
        addReg(reg)
        freReg(reg);
        string labelstart = "label.if.ix" + to_string(ifnum) + ".then";
        string labelelse= "label.if.ix"+to_string(ifnum)+".else";
        string labelend = "label.if.ix" + to_string(ifnum) + ".end";

        addCode("  br i1 %s, label %%%s, label %%%s\n ")
        addReg(tmp);
        addReg(labelstart)
        freReg(tmp);
        if(children.size()>2) {
            addReg(labelelse)
        }else{
            addReg(labelend)
        }

        addCode("%s:")
        addReg(labelstart)
        children.at(1)->Codegen();
        addCode("br label %%%s")
        addReg(labelend)

        if (children.size() > 2) {//else has somethingchildren.at(2
            addCode("%s:")
            addReg(labelelse)
            // cerr<<"Children size:"<<children.size()<<endl;
            children.at(2)->Codegen();
            addLabel(labelend);
        }else{
            addCode("%s:")
            addReg(labelend)
        }
    } else if (content == "STMT: for ( EXP ; EXP ; EXP ) STMT") {
        insideFor++;
        fornum++;
        //getPointer=false;
        children.at(0)->Codegen();

        string forcheck ="label.for.ix"+to_string(fornum)+".check";
        string forcond = "label.for.ix" + to_string(fornum) + ".cond";
        string forbody = "label.for.ix" + to_string(fornum) + ".body";
        string forend = "label.for.ix" + to_string(fornum) + ".end";
        labelForBreak.push(forend);
        labelForContinue.push(forcond);
        //addLabel(forcond)
        addLabel(forcheck)
        getPointer = false;
        string tmp = children.at(1)->Codegen();
        string j;
        if(children.at(1)->retType=="i32"){//i32
            j=allocateRegister("tmp_");
            addCode(" %s = icmp ne i32 %s, 0 \n; for conversion")
            addReg(j)
            addReg(tmp)
            freReg(tmp);
        }else{
            j=tmp;
        }

        addCode("  br i1 %s, label %%%s, label %%%s\n")
        addReg(j);
        freReg(j);
        addReg(forbody)
        addReg(forend)

        addCode("%s:")
        addReg(forbody)

        children.at(3)->Codegen(); //stmt
        addLabel(forcond)
        children.at(2)->Codegen(); // inc

        addCode("  br label %%%s\n")
        addReg(forcheck);

        addCode("%s:")
        addReg(forend)

        insideFor--;
        labelForContinue.pop();
        labelForBreak.pop();
    } else if (content == "STMT: CONT ;") {
        if (insideFor == 0) {
            err("continue must be in for statement");
            exit(-1);
        }
        addCode("br label %%%s")
        addReg(labelForContinue.top());
    } else if (content == "STMT: BREAK ;") {
        if (insideFor == 0) {
            err("break must be in for statement");
            exit(-1);
        }
        addCode("br label %%%s")
        addReg(labelForBreak.top());
    } else {
        err("not valid syntax");
        exit(-1);
    }
    return "NULL";
}

string EXPTreeNode::Codegen() {
    if(children.size()==0){
        return "NULL";
    }else{
        cover=children.at(0)->cover;
        string tmp= children.at(0)->Codegen();
        retType=children.at(0)->retType;
        return tmp;
    }
}


bool EXTDEFTreeNode::isEmit() {
    if(content=="EXTDEF: TYPE FUNC STMTBLOCK"){
        string functionName=children.at(1)->children.at(0)->content;
        if(usedFunctionName.count(functionName)==0 && functionName!="main"){
            err("not emiting funciton")
            return false;
        }
    }else if(content=="EXTDEF: STSPEC SEXTVARS ;"){
        if(children.at(0)->content=="STSPEC: STRUCT { SDEFS }"){
            err("not emiting")
            if(children.at(1)->children.size()==0){
                return false;
            }
        }else{
            string typeName="%"+children.at(0)->children.at(1)->content;
            if(usedStructType.count(typeName)==0){
                err("not emiting: "+typeName )
                return false;
            }
        }
    }
    return true;
}

string EXPSTreeNode::Codegen() {
    const bool thisNodeGetPointer = getPointer;
    if (isdigit(content.back())) {
        //int
        return content;
    } else if (content == "EXPS: ID ARRS") {
        if (children.at(1)->content == "ARRS: null") {
            //id case
            string memPtr;
            rtn = SearchIdPointer(children.at(0)->content, memPtr);
            CHECK_RTN_EXIT("not found symbol:" + children.at(0)->content);
            if (thisNodeGetPointer) {
                return memPtr;
            } else {
                string reg = allocateRegister();
                addCode("  %s = load i32* %s, align 4\n")
                addReg(reg);
                addReg(memPtr);
                addDep(reg,memPtr);
                return reg;
            }
        } else if (children.at(1)->content == "ARRS: [ EXPS ]") {
            getPointer = false;
            string reg = children.at(1)->children.at(0)->Codegen();
            string type;
            rtn = SearchIdType(children.at(0)->content, type);
            string memPtr;
            rtn = SearchIdPointer(children.at(0)->content, memPtr);
            CHECK_RTN_EXIT("not found symbol:" + children.at(0)->content);
            addCode("  %s = getelementptr inbounds " + type + "* %s, i32 0, i32 %s\n");
            string ret = allocateRegister();
            addReg(ret);
            addReg(memPtr);
            addReg(reg);
            addDep(ret,memPtr)
            addDep(ret,reg)
            freReg(reg);

            if (thisNodeGetPointer) {
                return ret;
            } else {
                string de = allocateRegister();
                addCode("  %s = load i32* %s, align 4\n");
                addReg(de);
                addReg(ret);
                addDep(de,ret);
                freReg(ret);
                return de;
            }
        }
    } else if (content == "EXPS: ( EXPS )") {
        cover=children.at(0)->cover;
        retType=children.at(0)->retType;
        return children.at(0)->Codegen();
    } else if (content == "EXPS: UNARYOP EXPS") {
        string &c = children.at(0)->content;
        if (c == "++" || c == "--") {
            getPointer = true;
            string tmp = children.at(1)->Codegen();
            string op = allocateRegister();
            string res = allocateRegister();
            addCode(" %s = load i32* %s, align 4\n")
            addReg(op);
            addReg(tmp);
            addDep(op,tmp);

            if (children.at(0)->content == "++") {
                addCode("   %s = add nsw i32 %s, 1\n")
            } else if (children.at(0)->content == "--") {
                addCode("   %s = sub nsw i32 %s, 1\n")
            }
            addReg(res)
            addReg(op)
            addDep(res,op)
            freReg(op);

            addCode("   store i32 %s, i32* %s, align 4\n")
            addReg(res);
            addReg(tmp);
            addDep(tmp,res)

            if (thisNodeGetPointer) {
                freReg(res);
                return tmp;
            } else {
                freReg(tmp);
                return res;
            }
        } else {
            getPointer = false;
            string tmp = children.at(1)->Codegen();
            string res = allocateRegister();

            if (children.at(0)->content == "-") {
                addCode("   %s= sub nsw i32 0, %s\n");
            } else if (children.at(0)->content == "!" || children.at(0)->content == "~") {
                retType="i1";
                addCode("   %s = icmp eq i32 %s, 0\n")
            } else if (children.at(0)->content == "+") {
                addCode("   %s = add nsw i32 %s, 0\n")
            }
            addReg(res)
            addReg(tmp)
            addDep(res,tmp)
            freReg(tmp);
            return res;
        }

    } else if (content == "EXPS: ID ( ARGS )") {
        args.clear();
        string list = children.at(1)->Codegen();
        string funcitonName=children.at(0)->content;
        usedFunctionName.insert(funcitonName);
        string ret = allocateRegister();
        addCode("%s = call i32 @%s(" + list + ")")
        addReg(ret);
        addReg(funcitonName);

        for(int i=0;i<args.size();i++){
            addDep(ret,args[i]);
        }
        args.clear();

        return ret;
    } else if (content == "EXPS: ID DOT ID") {

        string st=children.at(0)->content;
        string type;
        rtn=SearchIdType(st,type);
        CHECK_RTN("not found symbol:"+st);
        string ptr;
        rtn=SearchIdPointer(st,ptr);
        CHECK_RTN("not found symbol:"+st)


        if(type=="i32" || type=="i1" || type=="i32*" || type[0] =='[') {
            err("only struct can  be used as first parameter of Dot ,get type:" + type)
            exit(-1);
        }
        string at=children.at(2)->content;
        if(structTypes.count(type)==0){
            err("symbol not found: " +type)
            for(auto a:structTypes){
                // cerr<<a<<endl;
            }
            exit(-1);
        }

        if(structTable[type].count(at)==0){
            err("symbol in struct type:"+type+" does not has:" +at)
            for(auto a:structTable[type]){
                // cerr<<a.first<<endl;
            }
            exit(-1);
        }
        int ix= structTable[type][at];
        string reg=allocateRegister();
        addCode("%s = getelementptr inbounds %s* %s, i32 0, i32 "+to_string(ix))
        addReg(reg);
        addReg(type);
        addReg(ptr);
        addDep(reg,ptr);
        if(thisNodeGetPointer){
            return reg;
        }else{
            string de = allocateRegister();
            addCode("  %s = load i32* %s, align 4\n");
            addReg(de);
            addReg(reg);
            addDep(de,reg);
            freReg(reg);
            return de;
        }
    } else if (children.size() == 2) { //binary case
        string op1, op2, res;
        if (content == "=" || content == "+=" || content == "-=" || content == "/=" || content == "*=" ||
            content == "|=" || content == "&=" || content==">>=" || content =="<<=" || content== "^=") {
            res=allocateRegister();
            getPointer = true;
            string ptr1;
            ptr1 = children[0]->Codegen();
            getPointer = false;
            op1 = children[0]->Codegen();
            getPointer = false;
            op2 = children[1]->Codegen();
            if (content[0] == '+') {
                addCode("%s= add nsw i32 %s, %s\n")
            } else if (content[0] == '-') {
                addCode("%s= sub nsw i32 %s, %s\n")
            } else if (content[0] == '*') {
                addCode("%s= mul nsw i32 %s, %s\n")
            } else if (content[0] == '|') {
                addCode("%s= or i32 %s, %s\n")
            } else if (content[0] == '&') {
                addCode("%s= and i32 %s, %s\n")
            } else if (content[0] == '/') {
                addCode("%s= sdiv i32 %s, %s\n")
            } else if (content[0]=='>'){ //>>=
                addCode("%s= ashr i32 %s, %s\n")
            } else if(content[0]=='<'){  //<<=
                addCode("%s= lshr i32 %s, %s\n")
            }else if(content[0]=='^'){   //^=
                addCode("%s= xor i32 %s, %s\n")
            }
            if (content[0] == '=') {
                freReg(res);
                res = op2;
            } else {
                addReg(res)
                freReg(op1);
                addReg(op1)
                freReg(op2);
                addReg(op2)
                addDep(res,op1);
                addDep(res,op2);
            }
            addCode("    store i32 %s, i32* %s, align 4\n");
            addReg(res)
            addReg(ptr1)
            addDep(ptr1,res)
            if (thisNodeGetPointer) {
                freReg(res);
                return ptr1;
            } else {
                return res;
            }
        } else {
            getPointer = false;
            op1 = children[0]->Codegen();
            string op1Type=children.at(0)->retType;
            getPointer = false;
            op2 = children[1]->Codegen();
            res = allocateRegister();
            string op2Type=children.at(1)->retType;

            if (content == "&&") {
                string tmp1 = allocateRegister();
                string tmp2 = allocateRegister();
                retType="i1";
                addCode("  %s = icmp ne "+op1Type+" %s, 0\n")
                addReg(tmp1)
                addReg(op1)
                addDep(tmp1,op1)
                freReg(op1);

                addCode("  %s = icmp ne " +op2Type+" %s, 0\n")
                addReg(tmp2)
                addReg(op2)
                addDep(tmp2,op2)
                freReg(op2);

                addCode(" %s = and i1 %s, %s\n")
                addReg(res)
                addReg(tmp1)
                addReg(tmp2)
                addDep(res,tmp1)
                addDep(res,tmp2)
                freReg(tmp1);
                freReg(tmp2);
                return res;
            } else if (content == "||") {
                retType="i1";
                string tmp1 = allocateRegister();
                string tmp2 = allocateRegister();
                addCode("  %s = icmp ne "+op1Type+" %s, 0\n")
                addReg(tmp1)
                addReg(op1)
                addDep(tmp1,op1)
                freReg(op1);
                addCode("  %s = icmp ne " +op2Type+" %s, 0\n")
                addReg(tmp2)
                addReg(op2)
                addDep(tmp2,op2)
                freReg(op2);
                addCode(" %s = or i1 %s, %s\n")
                addReg(res)
                addReg(tmp1)
                addReg(tmp2)
                addDep(res,tmp1)
                addDep(res,tmp2)
                freReg(tmp1);
                freReg(tmp2);
                return res;
            }

            if (content == "+") {
                addCode("%s= add nsw i32 %s, %s\n")
            } else if (content == "-") {
                addCode("%s= sub nsw i32 %s, %s\n")
            } else if (content == "*") {
                addCode("%s= mul nsw i32 %s, %s\n")
            } else if (content == "/") {
                addCode("%s= sdiv i32 %s, %s\n")
            } else if (content == "%") {
                addCode("%s= srem i32 %s, %s\n")
            } else if (content == ">") {
                retType="i1";
                addCode("%s= icmp sgt i32 %s, %s\n")
            } else if (content == "<") {
                retType="i1";
                addCode("%s= icmp slt i32 %s, %s\n ; set retType to i1")
            } else if (content == "^") {
                addCode("%s= xor i32 %s, %s\n")
            } else if (content == "|") {
                addCode("%s= or nsw i32 %s, %s\n")
            } else if (content == "&") {
                addCode("%s= and i32 %s, %s\n")
            } else if (content == "<=") {
                retType="i1";
                addCode("%s= icmp sle i32 %s, %s\n")
            } else if (content == ">=") {
                retType="i1";
                addCode("%s= icmp sge i32 %s, %s\n")
            } else if (content == "==") {
                retType="i1";
                addCode("%s= icmp eq i32 %s, %s\n")
            } else if (content == "!=") {
                retType="i1";
                addCode("%s= icmp ne i32 %s, %s\n")
            } else if (content == "<<") {
                addCode("%s= lshr i32 %s, %s\n")
            } else if (content == ">>") {
                addCode("%s= ashr i32 %s, %s\n")
            } else {
                err("not implemented:" + content);
                exit(-1);
            }
            addReg(res)
            freReg(op1);
            freReg(op2);
            addReg(op1)
            addReg(op2)
            addDep(res,op1)
            addDep(res,op2)
            return res;
        }

    }
    // cerr<<"should not be here："<<content<<endl;
    getPointer = thisNodeGetPointer;
    return "NULL";
}

void ARGSTreeNode::CodeHelperGen() {

    getPointer = false;
    string val = children.at(0)->Codegen();
    if (isdigit(val.at(0)) || val.at(0) == '-') { // const
        string ptr = allocateRegister("tmp_");
        addCode("%s =  getelementptr inbounds [" + to_string(arrsize) + " x i32]* %s, i32 0, i32 " + to_string(arrindex) +
                "\n")
        addReg(ptr)
        addReg(arrid)
        addCode("  store i32 %s, i32* %s, align 4\n")
        addReg(val)
        addReg(ptr)
    } else {
        err(" register must be i32, not checking.");
        exit(-1);
    }
    arrindex++;

    for (uint i = 1; i < children.size(); i++) {
        children.at(i)->CodeHelperGen();
    }
    return;
}

string SDECSTreeNode::Codegen() {
    string ret;
    if(structType.empty()){
        err(" not inside a struct");
        exit(-1);
    }
    ret = "i32 ";
    string id = children.at(0)->content;
    int ix= structTable[structType].size();
    structTable[structType][id]=ix;
    for(int i=1;i<children.size();i++){
        ret= ret+","+children.at(1)->Codegen();
    }
    return ret;
}

string SDEFSTreeNode::Codegen() {
    string ret;
    if(children.size()>0){
        ret=children.at(1)->Codegen();
        string y=children.at(2)->Codegen();
        if(y!="NULL" && y.size()>0){
            ret=ret+"," +y;
        }
    }
    return ret;
};

string STSPECTreeNode::Codegen() {
    show();
    if(content=="STSPEC: STRUCT ID"){
        string id=children.at(1)->content;
        structType ="%"+id;
        if(structTypes.count(structType)==0){
            err("no such symbol struct :"+id)
            for(auto a:structTypes){
                    // cerr<<a<<endl;
            }
            exit(-1);
        }
    }else if(content=="STSPEC: STRUCT ID { SDEFS }"){
        string id = children.at(1)->content;
        structType="%"+id;
        structTypes.insert(structType);
        string list = children.at(2)->Codegen();
        addDefs(" %s = type {"+list+"}");
        addDefReg(structType);
    }else if(content=="STSPEC: STRUCT { SDEFS }"){
        string id=to_string(genName)+".gen";genName++;
        structType="%"+id;
        structTypes.insert(structType);
        string list= children.at(1)->Codegen();
        addDefs(" %s = type {"+list+"}");
        addDefReg(structType);
    }
    return "NULL";
}

string SEXTVARSTreeNode::Codegen() {
    if(children.size()>0){
        string id =children.at(0)->content;
        string MemPtr;
        rtn = saveIdtoTable(id,structType,".struct",MemPtr);
        CHECK_RTN("error saving to symbol table, may be duplicate: "+ id);
        usedStructType.insert(structType);
        if(!insideFunction) {
            addCode("%s = common global %s zeroinitializer, align 4\n")
            addReg(MemPtr)
            addReg(structType)
        }else{
            addCode("%s = alloca %s, align 4\n")
            addReg(MemPtr)
            addReg(structType)
        }
        for (uint i=1;i<children.size();i++){
            children.at(i)->Codegen();
        }
    }
    return "NULL";
}

string INTTreeNode::Codegen() {
    string ret,v;
    bool positive=(content.at(0)!='-');
    if(!positive){
        v=content.substr(1);
    }else{
        v=content;
    }
    if(v.size()>2 && v.at(1)=='x' ){
        //16 base
        int tmp=0;
        int add=0;
        for(uint i=2;i<v.size();i++){
            tmp*=16;
            char p= v.at(i);
            if(p>='0' && p<='9'){
                add=p-'0';
            }else if(p>='A' && p<='F'){
                add=10+p-'A';
            }else if(p>='a' && p< 'f'){
                add=10+p-'a';
            }
            tmp+=add;
        }
        ret=to_string(tmp);
        if(!positive){
            ret.insert(ret.begin(),'-');
        }
    }else if(v.size()>1 && v.at(0)=='0'){
        //8 base
        int tmp=0;
        for(uint i=1;i<v.size();i++){
            tmp*=8;
            tmp+=v.at(i)-'0';
        }
        ret=to_string(tmp);
        if(!positive){
            ret.insert(ret.begin(),'-');
        }
    }else{
        ret=content;
    }
    return ret;
}

