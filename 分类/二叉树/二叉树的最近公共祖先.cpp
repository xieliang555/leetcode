#include<iostream>
#include<vector>
using namespace std;

/**
 * leetcode: 236
 * 
 */

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

TreeNode* ret=nullptr;

bool recursionCore(TreeNode* root, TreeNode* p, TreeNode* q){
	if(!root) return false;
	bool left=recursionCore(root->left, p, q);
	if(ret) return true;
	bool right=recursionCore(root->right, p, q);
	if(ret) return true;
	if(left && right || left && (root==p) || left && (root==q) || right && (root==p) || right && (root==q)){
		ret=root;
	}
	return left || right || root==p || root==q;
}


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){

	bool tmp=recursionCore(root, p,q);
	return ret;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}