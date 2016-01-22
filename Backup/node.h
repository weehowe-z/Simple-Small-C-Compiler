#include <iostream>
#include <string>
#include <queue>
#include <math.h>
#include "llvm/IR/Value.h"


class CodeGenContext;

using namespace std;

class tokenNode
{
public:
	string name;
	int length;
	int width;
	int pos;
	tokenNode* pfirstChild;
	tokenNode* pnextSubling;

	llvm::Value* codeGen(CodeGenContext& context) { return NULL; }

	tokenNode(string n = " ", tokenNode* pChild = NULL, tokenNode* pSubling = NULL)
	{
		name = n;
		length = name.length();
		if (name == "ϵ") length = 1; 
		width = length;
		pfirstChild = pChild;
		pnextSubling = pSubling;
	}
	tokenNode(int n = 0, tokenNode* pChild = NULL, tokenNode* pSubling = NULL)
	{
		char *intStr;
		sprintf(intStr, "%d", n);
		name = string(intStr);
		length = name.length();
		if (name == "ϵ") length = 1;
		width = length;
		pos = 0;
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


	int getWidthHelp(tokenNode* root)
	{
		if (root->pfirstChild == NULL){
			root->width = root->length;
			return root->width;
		}
		else{
			int width = 0;
			int count = 0;
			for (tokenNode* p = root->pfirstChild; p != NULL; p = p->pnextSubling){
				width += getWidthHelp(p)+1;
				count++;
			}
			width--;
			root->width = max(root->length,width);
			return root->width;
		}
	}

	void getWidth()
	{
		if (root == NULL) return;
		else {
			getWidthHelp(root);
		}
	}

	void printQueue(FILE *fout)
	{
		queue<string> q =getPrintString();
		while (!q.empty()){
			string str = q.front();
			q.pop();
			fprintf(fout,"%s", str.c_str());
		}
	}
	
	queue<string> getPrintString()
	{
		getWidth();
		tokenNode *p;
		queue<tokenNode*> q;
		queue<tokenNode*> tempQueue;
		queue<string> printQueue;

		queue<int>remainQueue;
		queue<int>verticalLowPosQueue;
		queue<int>verticalUpPosQueue;
		queue<int>underlineSingleQueue;
		queue< queue<int> > underlineQueue;
		queue<string>printDataQueue;//save tokens and lower vertical sign
		queue<string>printSignQueue;//save upper vertical sign

		if (root != NULL) {
			q.push(root);
			remainQueue.push(0);
		}

		int currentPos = 0;
		
		while (!q.empty()){
			
			p = q.front();
			q.pop();

			int remain = remainQueue.front();
			remainQueue.pop();
			if (currentPos<remain){
				for (int i = 0; i < remain-currentPos; ++i)
				{
					printDataQueue.push(" ");
				}
				currentPos = remain;
			}

			while (true){
				int currentPosTemp = 0;
				for (int i = 0; i < ((p->width-p->length)/2.0); ++i){
					printDataQueue.push(" ");
					currentPosTemp++;
				}
				printDataQueue.push(p->name);

				currentPosTemp += p->length;
				for (int i = 0; i < (p->width-p->length)/2.0; ++i){
					printDataQueue.push(" ");
					currentPosTemp++;
				}
				if ((p->width-p->length)/2==0) {
					printDataQueue.push(" ");
					currentPosTemp++;
				}
				if (p != root) {
					verticalUpPosQueue.push(currentPos + p->width/2);
					underlineSingleQueue.push(currentPos + p->width/2);
				}
				if (p->pfirstChild != NULL) {
					tempQueue.push(p->pfirstChild);
					if (p->pfirstChild->pnextSubling!=NULL){
						remainQueue.push(currentPos);
					}
					else if (p->width%2!=0&&p->pfirstChild->width%2==0){
						remainQueue.push(currentPos+ceil((p->width-p->pfirstChild->width)/2.0)-1);
					}
					else {
						remainQueue.push(currentPos+ceil((p->width-p->pfirstChild->width)/2.0));
					}
					verticalLowPosQueue.push(currentPos + p->width/2);
				}

				currentPos += currentPosTemp;
				
				if (p->pnextSubling != NULL){
					p = p->pnextSubling;
				}
				else{
					if (p!=root){
						underlineQueue.push(underlineSingleQueue);
						while (!underlineSingleQueue.empty()){
							underlineSingleQueue.pop();
						}
					}
					break;
				}
			}

			if (q.empty()){
				currentPos = 0;
				printDataQueue.push("\n");
				//print lower vertical
				
				int previousPos = 0;

				while (!verticalLowPosQueue.empty()){
					int verticalPos = verticalLowPosQueue.front();
					verticalLowPosQueue.pop();
					for (int i = previousPos; i < verticalPos; ++i){
							printDataQueue.push(" ");
					}
					previousPos = verticalPos + 1;
					printDataQueue.push("|");
				}
				printDataQueue.push("\n");
				
				//print Upper vertiacl
				previousPos = 0;

				int underlineFrontPos = 0;
				int underlineBackPos = 0;
				if (!underlineQueue.empty()){
					underlineFrontPos = underlineQueue.front().front();
					underlineBackPos = underlineQueue.front().back();
					underlineQueue.pop();
				}

				while (!verticalUpPosQueue.empty()){
					int verticalPos = verticalUpPosQueue.front();
					verticalUpPosQueue.pop();
					for (int i = previousPos; i < verticalPos; ++i){
						if (i > underlineBackPos && !underlineQueue.empty()){
							underlineFrontPos = underlineQueue.front().front();
							underlineBackPos = underlineQueue.front().back();
							underlineQueue.pop();
						}
						if (i > underlineFrontPos && i < underlineBackPos) printSignQueue.push("-");
						else printSignQueue.push(" ");
					}
					previousPos = verticalPos + 1;
					printSignQueue.push("|");
				}
				printSignQueue.push("\n");

				//push back to printQueue
				while (!printSignQueue.empty()){
					printQueue.push(printSignQueue.front());
					printSignQueue.pop();
				}
				while (!printDataQueue.empty()){
					printQueue.push(printDataQueue.front());
					printDataQueue.pop();
				}


				int tempSize = tempQueue.size();
				for (int i = 0; i < tempSize;++i ){
					q.push(tempQueue.front());
					tempQueue.pop();
				}
			}
		}
		return printQueue;	
	}
};