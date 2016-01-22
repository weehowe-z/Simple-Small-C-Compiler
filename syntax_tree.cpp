#include "syntax_tree.h"

unordered_set<string> TreeNode::usedFunctionName;
unordered_set<string> TreeNode::usedStructType;
vector<string> TreeNode::args;
int TreeNode::fornum;
int TreeNode::ifnum;
int TreeNode::genName;
vector<code> TreeNode::Codes;
vector<code> TreeNode::Defs;
bool TreeNode::EnableCodeGen;
vector<string> TreeNode::paras;
int TreeNode::insideStmtBlocks;
int TreeNode::insideFor;
stack<string> TreeNode::labelForContinue;
stack<string> TreeNode::labelForBreak;
bool TreeNode::insideFunction;
bool TreeNode::getPointer;
int TreeNode::arrsize;
string TreeNode::arrid;
int TreeNode::registerNum;
set<string> TreeNode::freeRegister;
int TreeNode::arrindex;
int TreeNode::registerFingerPrint;
bool TreeNode::optimize;
string TreeNode::structType;
unordered_set<string> TreeNode::structTypes;
unordered_map<string,unordered_map<string,int>> TreeNode::structTable;


void TreeNode::init() {
    fornum=0;
    ifnum=0;
    genName=0;
    insideStmtBlocks = 0;
    insideFor = 0;
    EnableCodeGen = true;
    getPointer = false;
    insideFunction = false;
    arrsize = 0;
    arrindex = 0;
    registerNum = 0;
    registerFingerPrint=0;
}

string TreeNode::allocateRegister(const string prefix) {
    string ret;
    if(prefix=="r_"){ //default
        if(freeRegister.size()>0){
            ret=*freeRegister.begin();
            freeRegister.erase(freeRegister.begin());
        }else{
            ret = "%" + prefix + to_string(registerNum++);
        }
    }else{
        ret = "%" + prefix +"oneshot";
    }
    ret=ret+".fp"+to_string(registerFingerPrint);
    registerFingerPrint++;
    return ret;
}

void TreeNode::freReg(string id) {
    if(id.size()>3 && id.substr(0,3)=="%r_") {
        size_t ed= id.find_last_of(".");
        freeRegister.insert(id.substr(0,ed));
    }
}

void TreeNode::CodePrint() {
    init();
    optimize=false;
    this->Codegen();

    for(int i=0; i<Defs.size();i++){
        Defs[i].print();
        Defs[i].printline();
    }

    for (int i = 0; i < Codes.size(); i++) {
        Codes[i].print();
        Codes[i].printline();
    }
}


int TreeNode::SearchIdType(const string &id, string &type) const {
    const TreeNode *treeNode = this;

    while (treeNode) {
        if (treeNode->className != "STMTBLOCK" && treeNode->className != "PROGRAM") {
            treeNode = treeNode->parent;
            continue;
        }
        if (treeNode->GetIdType(id, type) == 0) {
            return 0;
        } else {
            treeNode = treeNode->parent;
        }
    }
    return -1;
}

int TreeNode::GetIdType(const string &id, string &type) const {
    if (symbolTable.count(id) == 0) {
        return -1;
    }
    type = symbolTable.at(id).type;
    return 0;
}

int TreeNode::GetIdPointer(const string &id, string &MemPtr) const {

    if (symbolTable.count(id) == 0) {
        return -1;
    }
    MemPtr.clear();
    IdInfo tmp = symbolTable.at(id);

    if (className == "STMTBLOCK") {
        MemPtr.push_back('%');
    } else if (className == "PROGRAM") {
        MemPtr.push_back('@');
    }
    MemPtr.append("ptr_");
    MemPtr.append(id);
    MemPtr.append(".line" + to_string(tmp.lineno));
    MemPtr.append(tmp.suffix);
    return 0;
}

int TreeNode::SearchIdPointer(const string &id, string &MemPtr) const {
    const TreeNode *treeNode = this;

    while (treeNode) {
        if (treeNode->className != "STMTBLOCK" && treeNode->className != "PROGRAM") {
            treeNode = treeNode->parent;
            continue;
        }
        if (treeNode->GetIdPointer(id, MemPtr) == 0) {
            return 0;
        } else {
            treeNode = treeNode->parent;
        }
    }
    return -1;
}


int TreeNode::saveIdtoTable(const string & id,  const string & type, string & MemPtr) {
    string n;
    return saveIdtoTable(id, type, n, MemPtr);
}

int TreeNode::saveIdtoTable(const string & id, const string & type) {
    string tmp;
    string n;
    return saveIdtoTable(id, type, n, tmp);
}

int TreeNode::saveIdtoTable(const string & id, const string & type, const string & suffix, string &MemPtr) {
    TreeNode *treeNode = (TreeNode *) this;
    while (treeNode && treeNode->className != "STMTBLOCK" && treeNode->className != "PROGRAM") {
        treeNode = treeNode->parent;
    }

    if (treeNode->GetIdPointer(id, MemPtr) == 0) {
        err("find duplicate definition :" + id);
        return -1;
    }
    else {
        IdInfo tmp;
        tmp.lineno = lineCount;
        tmp.type = type;
        tmp.suffix = suffix;
        treeNode->symbolTable[id] = tmp;
        return treeNode->GetIdPointer(id, MemPtr);
    }
}

void printTree(TreeNode *t, int level) {
    int i = 0;
    if (level == 0) {
        printf("\n");
        printf("syntax tree:\n");
        printf("\n");
    }
    for (; i < level; i++) {
        printf("--");
    }
    printf("%s\n", t->content.c_str());
    for (i = 0; i < t->childrenSize; i++) {
        printTree(t->children[i], level + 1);
    }
}