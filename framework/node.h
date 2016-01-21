#include <iostream>
#include <vector>
#include <llvm/IR/Value.h>

class CodeGenContext;
class NStatement;
class NExpression;
class NVariableDeclaration;

typedef std::vector<NStatement*> StatementList;
typedef std::vector<NExpression*> ExpressionList;
typedef std::vector<NVariableDeclaration*> VariableList;

class Node {
public:
	std::string node_name;
	int length;
	int width;
	int pos;
	Node* pfirstChild;
	Node* pnextSubling;
	Node (std::string n = " ", Node* pChild = NULL, Node* pSubling = NULL)
	{
		node_name = n;
		length = node_name.length();
		if (node_name == "ϵ") length = 1; 
		width = length;
		pfirstChild = pChild;
		pnextSubling = pSubling;
	}
	virtual ~Node() {}
	virtual llvm::Value* codeGen(CodeGenContext& context) { return NULL; }
};

class NExpression : public Node {
public:
	NExpression(std::string n = " ", Node* pChild = NULL, Node* pSubling = NULL): Node(n,pChild,pSubling) {}
};

class NStatement : public Node {
	public:
	NStatement(std::string n = " ", Node* pChild = NULL, Node* pSubling = NULL): Node(n,pChild,pSubling) {}
};

class NInteger : public NExpression {
public:
	long long value;
	NInteger( long long value, std::string n = " ", Node* pChild = NULL, Node* pSubling = NULL) : NExpression(n,pChild,pSubling),value(value) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NDouble : public NExpression {
public:
	double value;
	NDouble(double value, std::string n = " ", Node* pChild = NULL, Node* pSubling = NULL) : NExpression(n,pChild,pSubling),value(value) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NIdentifier : public NExpression {
public:
	std::string name;
	NIdentifier(const std::string& name, std::string n = " ", Node* pChild = NULL, Node* pSubling = NULL) : NExpression(n,pChild,pSubling),name(name) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NMethodCall : public NExpression {
public:
	const NIdentifier& id;
	ExpressionList arguments;
	NMethodCall(const NIdentifier& id, ExpressionList& arguments, std::string n = " ", Node* pChild = NULL, Node* pSubling = NULL) :
		NExpression(n,pChild,pSubling),id(id), arguments(arguments) { }
	NMethodCall(const NIdentifier& id, std::string n = " ", Node* pChild = NULL, Node* pSubling = NULL) : 
		NExpression(n,pChild,pSubling),id(id) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NBinaryOperator : public NExpression {
public:
	char* op;
	std::string op_str;
	NExpression& lhs;
	NExpression& rhs;
	NBinaryOperator(NExpression& lhs, char* op, NExpression& rhs, std::string n = " ", Node* pChild = NULL, Node* pSubling = NULL) :
		NExpression(n,pChild,pSubling),lhs(lhs), rhs(rhs), op(op) { op_str = op; }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NAssignment : public NExpression {
public:
	NIdentifier& lhs;
	NExpression& rhs;
	NAssignment(NIdentifier& lhs, NExpression& rhs, std::string n = " ", Node* pChild = NULL, Node* pSubling = NULL) : 
		NExpression(n,pChild,pSubling),lhs(lhs), rhs(rhs) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

///////////////////////////////////////////////////////////

class NBlock : public NExpression {
public:
	StatementList statements;
	NBlock() { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NExpressionStatement : public NStatement {
public:
	NExpression& expression;
	NExpressionStatement(NExpression& expression) : 
		expression(expression) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NReturnStatement : public NStatement {
public:
	NExpression& expression;
	NReturnStatement(NExpression& expression) : 
		expression(expression) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NVariableDeclaration : public NStatement {
public:
	const NIdentifier& type;
	NIdentifier& id;
	NExpression *assignmentExpr;
	NVariableDeclaration(const NIdentifier& type, NIdentifier& id) :
		type(type), id(id) { assignmentExpr = NULL; }
	NVariableDeclaration(const NIdentifier& type, NIdentifier& id, NExpression *assignmentExpr) :
		type(type), id(id), assignmentExpr(assignmentExpr) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NExternDeclaration : public NStatement {
public:
    const NIdentifier& type;
    const NIdentifier& id;
    VariableList arguments;
    NExternDeclaration(const NIdentifier& type, const NIdentifier& id,
            const VariableList& arguments) :
        type(type), id(id), arguments(arguments) {}
    virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NFunctionDeclaration : public NStatement {
public:
	const NIdentifier& type;
	const NIdentifier& id;
	VariableList arguments;
	NBlock& block;
	NFunctionDeclaration(const NIdentifier& type, const NIdentifier& id, 
			const VariableList& arguments, NBlock& block) :
		type(type), id(id), arguments(arguments), block(block) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};
