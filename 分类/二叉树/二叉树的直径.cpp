#include<iostream>
#include<vector>
using namespace std;

/**
 * leetcode: 543
 *
 * 返回值的含义表示以该节点为路径末尾的最长长度
 * 
 */

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

int maxDia=0;

int recursionCore(TreeNode* root){
	if(!root) return 0;
	int left=recursionCore(root->left);
	int right=recursionCore(root->right);
	maxDia=max(maxDia, left+right+1);
	return left>right?left+1:right+1;
}

int diameterOfBinaryTree(TreeNode* root){
	if(!root) return 0;
	int tmp=recursionCore(root);
	return maxDia-1;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}