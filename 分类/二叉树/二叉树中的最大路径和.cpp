#include<iostream>
#include<vector>
#include<climits>
using namespace std;

/**
 * leetcode: 124
 *
 * 返回值表示的意义是以当前节点为路径末尾端点的最长路径
 * 
 */

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

int maxLen=INT_MIN;

int recursionCore(TreeNode* root){
	if(!root) return 0;
	int left=recursionCore(root->left);
	int right=recursionCore(root->right);
	int Max=max(max(left+root->val, right+root->val),root->val);
	maxLen=max(max(maxLen,Max),root->val+left+right);
	return Max;
}

int maxPathSum(TreeNode* root) {
    
    int tmp=recursionCore(root);
    return maxLen;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}