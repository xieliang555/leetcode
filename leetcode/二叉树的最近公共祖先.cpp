#include<iostream>
using namespace std;


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* ret=nullptr;

bool recursionCore(TreeNode* root, TreeNode* p, TreeNode* q){

	if(!root) return false;
	bool left=recursionCore(root->left,p,q);
	if(ret) return true;
	bool right=recursionCore(root->right,p,q);
	if(ret) return true;
	if((left && right) || (left && (root==p)) || (left && (root==q)) || (right && (root==p)) || (right && (root==q))){
		ret=root;
	}
	if(left || right || (root==p) || (root==q))
		return true;
	else 
		return false;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){

	bool tmp=recursionCore(root,p,q);
	return ret;

}

int main(int argc, char const *argv[])
{
	
	return 0;
}
