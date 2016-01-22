#ifndef SYNTAX_TREE_H
#define SYNTAX_TREE_H
#include "header.h"
#include "common.h"

#define CHECK_RTN(y) \
if (rtn!=0) { err(y) }

#define CHECK_RTN_EXIT(y) \
if(rtn!=0) { err(y) exit(-1);}

#define err(x) \
// cerr<<"error at line"<<lineCount<<"; content: "<<content<<" #"<<(x)<<endl;

struct IdInfo{
    int lineno;
    string type;
    string suffix;

    IdInfo():lineno(0),type(""),suffix(""){}
};

struct Cover{
    unordered_map<string,unordered_set<string>> dependency;
    unordered_set<string> affectedVar;
};

class TreeNode {
public:
    int rtn;
    static vector<string> args;
    static unordered_set<string> usedFunctionName;
    static unordered_set<string> usedStructType;
    static int genName;
    static int fornum,ifnum;
    static unordered_set<string> structTypes;
    static unordered_map<string,unordered_map<string,int>> structTable;
    static string structType;
    static vector<code> Codes;
    static vector<code> Defs;
	static bool EnableCodeGen;
    static vector<string> paras;
    static int insideStmtBlocks;
    static int insideFor;
    static stack<string> labelForContinue;
    static stack<string> labelForBreak;

    static bool insideFunction;
    static bool getPointer;

    static int arrsize;
    static int arrindex;
    static string arrid;

    static bool optimize;

    static void init();
private:
    static int registerNum;
    static int registerFingerPrint;
    static set<string> freeRegister;
public:

    string retType;
    static  string allocateRegister(const string prefix="r_");
    static void freReg(string id);

    string getToRoot(){
        if(parent==NULL){
            return "#"+content+"#";
        }
        return "#"+content+"# ->> "+parent->getToRoot();
    }

    void CodePrint();

    int lineCount;
    string content;
    string className;
    int childrenSize ;
    vector<TreeNode*> children;
    virtual ~TreeNode(){
        for(auto a:children){
            delete a;
        }
    }
    TreeNode * parent;
    TreeNode():parent(NULL),rtn(0),retType("i32"){};
    void clearWrapper(){
        structTable.clear();
        structTypes.clear();
        paras.clear();
        Codes.clear();
        Defs.clear();
        init();
        clear();
    }

    void getChildrenCover(){
        for(auto c:children){
            cover.affectedVar.insert(c->cover.affectedVar.begin(),c->cover.affectedVar.end());
        }
    }

    void clear(){
        symbolTable.clear();
        for(auto a:children){
            a->clear();
        }
    }

    virtual string Codegen(){
        for(auto a:children){
            a->Codegen();
        }
        return "NULL";
    }

    virtual bool isEmit(){
       return true;
    }


    virtual void CodeHelperGen(){
        return;
    }

    void show(){
        cerr<<"Content:"<<content<<endl;
        cerr<<"className:"<<className<<endl;
        cerr<<"children size:"<<children.size()<<endl;
    }


public:// symbolTable
    unordered_map<string, IdInfo> symbolTable;
    int GetIdPointer(const string & id, string & MemPtr) const;
    int SearchIdPointer(const string & id, string &MemPtr) const;

    int GetIdType(const string & id, string & type) const;
    int SearchIdType(const string & id, string &type) const;

    int saveIdtoTable( const string & id,  const string & type) ;
    int saveIdtoTable(const string  & id, const string & type ,string &MemPtr) ;
    int saveIdtoTable(const string  & id, const  string  & type, const string & suffix, string &MemPtr) ;

public:
    Cover cover;

};



void printTree(TreeNode * t, int level);

#endif
