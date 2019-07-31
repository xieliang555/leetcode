#include<iostream>
#include<stack>
using namespace std;

class TreeNode
{
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
	
};

//递归实现
void Mirror(TreeNode *pRoot) {

	if(!pRoot) return;

	swap(pRoot->left, pRoot->right);
	Mirror(pRoot->left);
	Mirror(pRoot->right);
}

//栈实现
void Mirror2(TreeNode* pRoot){
	if(!pRoot) return;
	stack<TreeNode*> s;
	s.push(pRoot);
	while(!s.empty()){
		TreeNode* p=s.top();
		s.pop();
		swap(p->left, p->right);
		if(p->right)
			s.push(p->right);
		if(p->left)
			s.push(p->left);
	}
}

int main(int argc, char const *argv[])
{
	
	return 0;
}