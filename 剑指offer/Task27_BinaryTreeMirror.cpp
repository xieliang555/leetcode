#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
	
};

class Task27_BinaryTreeMirror
{
public:
	Task27_BinaryTreeMirror(){}
	~Task27_BinaryTreeMirror(){}


	//recursion
	void mirror(TreeNode* pRoot){

		if(pRoot!=nullptr){
			TreeNode* tmp=pRoot->left;
			pRoot->left=pRoot->right;
			pRoot->right=tmp;

			mirror(pRoot->left);
			mirror(pRoot->right);
		}
	}
	
	//iteration
	void mirror_2(TreeNode* pRoot){
		stack<TreeNode*> s;
		if(pRoot==nullptr) return;
		s.push(pRoot);
		while(!s.empty()){
			TreeNode* node=s.top();
			s.pop();
			swap(node->left,node->right);
			if(node->right!=nullptr)
				s.push(node->right);
			if(node->left!=nullptr)
				s.push(node->left);
		}
	}
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}