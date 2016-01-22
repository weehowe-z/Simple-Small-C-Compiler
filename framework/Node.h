#ifndef TreeNode_H
#define TreeNode_H
#include "syntax_tree.h"
#define GenNode(x) \
class x##TreeNode: public TreeNode{ \
public:\
virtual string Codegen() override; \
}; \

#define SwitchClass(x) \
if(#x == classname) return new x##TreeNode();

#define smartEmit \
if(optimize && !isEmit()){ return "NULL";} \


#define addDep(x,y) \
if(y.size()>0 && y.at(0)!='-' && isdigit(y.at(0)) ){\
cover.dependency[x].insert(y); \
cover.affectedVar.insert(x); \
}


GenNode(PROGRAM);
GenNode(EXTDEFS);
class EXTDEFTreeNode: public TreeNode{
public:
virtual string Codegen() override;
virtual bool isEmit() override ;
};
GenNode(SEXTVARS);
GenNode(EXTVARS);
GenNode(STSPEC);
GenNode(FUNC);
GenNode(PARAS);
GenNode(STMTBLOCK);
GenNode(STMTS);
GenNode(STMT);
GenNode(DEFS);
GenNode(SDEFS);
GenNode(SDECS);
GenNode(DECS);
GenNode(VAR);
GenNode(INIT);
GenNode(EXP);
GenNode(EXPS);
GenNode(ARRS);
GenNode(INT);


class ARGSTreeNode: public TreeNode{
public:
    virtual void CodeHelperGen() override;

    virtual string Codegen() override;
};
GenNode(UNARYOP);

class ConstValue{
public:
    static TreeNode * get(const string classname){
        SwitchClass(PROGRAM);
        SwitchClass(EXTDEFS);
        SwitchClass(EXTDEF);
        SwitchClass(SEXTVARS);
        SwitchClass(EXTVARS);
        SwitchClass(STSPEC);
        SwitchClass(FUNC);
        SwitchClass(PARAS);
        SwitchClass(STMTBLOCK);
        SwitchClass(STMTS);
        SwitchClass(STMT);
        SwitchClass(DEFS);
        SwitchClass(SDEFS);
        SwitchClass(SDECS);
        SwitchClass(DECS);
        SwitchClass(VAR);
        SwitchClass(INIT);
        SwitchClass(EXP);
        SwitchClass(EXPS);
        SwitchClass(ARRS);
        SwitchClass(ARGS);
        SwitchClass(UNARYOP);
        SwitchClass(INT);
        return new TreeNode();
    };
};

TreeNode* createNodeIns(int line,string type, string content, int childrenSize, ...);

#endif

