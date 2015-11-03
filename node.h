#include <iostream>
#include <string>
#include <queue>
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
	tokenNode(string n = " ", tokenNode* pChild = NULL, tokenNode* pSubling = NULL)
	{
		name = n;
		length = name.length();
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

	void fprint(FILE *fout)
	{
		getWidth();
		tokenNode *p;
		queue<tokenNode*> q;
		queue<tokenNode*> tempQueue;
		//queue<int> position;
		int currentPos = 0;
		if (root != NULL) q.push(root);
		while (!q.empty()){
			p = q.front();
			q.pop();
			while (true){
				//position.push(p->width/2);
				currentPos = p->pos;
				for (int i = 0; i < (p->width-p->length)/2; ++i)
				{
					fprintf(fout," ");
				}
				fprintf(fout,"%s ", p->name.c_str());
				for (int i = 0; i < (p->width-p->length)/2; ++i){
					fprintf(fout, " ");
				}

				if (p->pfirstChild != NULL) {
					p->pfirstChild->pos = currentPos;
					tempQueue.push(p->pfirstChild);
				}
				if (p->pnextSubling != NULL){
					currentPos += 2*p->width;
					//cout<<"current pos "<<currentPos<<endl;
					p = p->pnextSubling;
					p->pos = currentPos;
				}
				else{
					break;
				}
			}
			if (q.empty()){
				fprintf(fout,"\n");
				int tempSize = tempQueue.size();
				for (int i = 0; i < tempSize;++i ){
					q.push(tempQueue.front());
					tempQueue.pop();
				}
				if (!q.empty()){
					for (int i = 0; i < q.front()->pos; ++i){
						fprintf(fout, " ");
					}
				}
			}
		}		
	}

	void printWidth(FILE *fout)
	{
		getWidth();
		tokenNode *p;
		queue<tokenNode*> q;
		queue<tokenNode*> tempQueue;
		if (root != NULL) q.push(root);
		while (!q.empty()){
			p = q.front();
			q.pop();
			while (true){
				fprintf(fout,"%d ", p->width);
				if (p->pfirstChild != NULL) tempQueue.push(p->pfirstChild);
				if (p->pnextSubling != NULL){
					p = p->pnextSubling;
				}
				else{
					break;
				}
			}
			if (q.empty()){
				fprintf(fout,"\n");
				int tempSize = tempQueue.size();
				for (int i = 0; i < tempSize;++i ){
					q.push(tempQueue.front());
					tempQueue.pop();
				}
			}
		}		
	}


	void printpos(FILE *fout)
	{
		getWidth();
		tokenNode *p;
		queue<tokenNode*> q;
		queue<tokenNode*> tempQueue;
		if (root != NULL) q.push(root);
		while (!q.empty()){
			p = q.front();
			q.pop();
			while (true){
				fprintf(fout,"%d ", p->pos);
				if (p->pfirstChild != NULL) tempQueue.push(p->pfirstChild);
				if (p->pnextSubling != NULL){
					p = p->pnextSubling;
				}
				else{
					break;
				}
			}
			if (q.empty()){
				fprintf(fout,"\n");
				int tempSize = tempQueue.size();
				for (int i = 0; i < tempSize;++i ){
					q.push(tempQueue.front());
					tempQueue.pop();
				}
			}
		}		
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
			root->width = max(root->width,width);
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
		queue<int>verticalQueue; 
		if (root != NULL) q.push(root);
		while (!q.empty()){
			
			p = q.front();
			q.pop();
			

			while (true){
				for (int i = 0; i < (p->width-p->length)/2; ++i){
					printQueue.push(" ");
				}

				printQueue.push(p->name);
				verticalQueue.push(p->width/2);

				for (int i = 0; i < (p->width-p->length)/2; ++i){
					printQueue.push(" ");
				}
				if ((p->width-p->length)/2<=0) printQueue.push(" ");

				if (p->pfirstChild != NULL) tempQueue.push(p->pfirstChild);
				if (p->pnextSubling != NULL){
					p = p->pnextSubling;
				}
				else{
					break;
				}
			}

			if (q.empty()){
				printQueue.push("\n");
				while (!verticalQueue.empty()){
					int verticalPos = verticalQueue.front();
					verticalQueue.pop();
					for (int i = 0; i < verticalPos; ++i)
					{
						//printQueue.push(" ");
					}
					//printQueue.push("|");
					for (int i = 0; i < verticalPos; ++i)
					{
						//printQueue.push(" ");
					}					
				}
				//printQueue.push("\n");

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