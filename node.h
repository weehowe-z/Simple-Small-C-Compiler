#include <iostream>
#include <string>
#include <queue>
using namespace std;

class tokenNode
{
public:
	string name;
	int length;
	tokenNode* pfirstChild;
	tokenNode* pnextSubling;
	tokenNode(string n = " ", tokenNode* pChild = NULL, tokenNode* pSubling = NULL)
	{
		name = n;
		length = name.length();
		pfirstChild = pChild;
		pnextSubling = pSubling;
	}
	~tokenNode(){}
	void printName()
	{
		cout<<name<<endl;
	}
	
};

class parseTree
{
public:
	tokenNode* root;
	parseTree(tokenNode* rt = NULL)
	{
		root = rt;
	}
	~parseTree()
	{
		tokenNode *p,*temp;
		queue<tokenNode*> q;
		if (root != NULL){
			q.push(root);
		}
		else return;
		while (!q.empty()){		
			p = q.front();
			q.pop();
			while (true){
				temp = p;
				if (p->pfirstChild != NULL) q.push(p->pfirstChild);
				if (p->pnextSubling != NULL){
					p = p->pnextSubling;
				}
				else{
					delete temp;
					break;
				}
				delete temp;
			}
		}
	}
	void changeRoot(tokenNode* rt = NULL)
	{
		root = rt;
	}
	void print()
	{
		tokenNode *p;
		queue<tokenNode*> q;
		queue<tokenNode*> tempQueue;
		if (root != NULL) q.push(root);
		while (!q.empty()){
			p = q.front();
			q.pop();
			while (true){
				cout<<p->name<<" ";
				if (p->pfirstChild != NULL) tempQueue.push(p->pfirstChild);
				if (p->pnextSubling != NULL){
					p = p->pnextSubling;
				}
				else{
					break;
				}
			}
			if (q.empty()){
				cout<<endl;
				int tempSize = tempQueue.size();
				for (int i = 0; i < tempSize;++i ){
					q.push(tempQueue.front());
					tempQueue.pop();
				}
			}
		}		
	}
};