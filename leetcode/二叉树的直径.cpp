#include<iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

int maxDiameter=0;

int recursionCore(TreeNode* root){

	if(!root) return 0;

	int leftLen=recursionCore(root->left);
	int rightLen=recursionCore(root->right);
	maxDiameter=max(maxDiameter,leftLen+rightLen+1);
	return max(leftLen+1,rightLen+1);
}

int diameterOfBinaryTree(TreeNode* root) {
    
    if(!root) return 0;
    recursionCore(root);
    return maxDiameter-1;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}