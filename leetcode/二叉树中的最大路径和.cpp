#include<iostream>
using namespace std;


class TreeNode
{
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x),left(nullptr),right(nullptr){}
	
};

//后序遍历
// maxSum保存遍历每一个节点的全局最优（4种情况）
// recursionCore返回以当前节点为路径末尾的最大路径和

int maxSum=INT_MIN;

int recursionCore(TreeNode* root){
	if(!root) return 0;
	int left=recursionCore(root->left);
	int right=recursionCore(root->right);
	int ret=max(root->val, left+root->val);
	ret=max(ret, right+root->val);
	maxSum=max(maxSum, right+left+root->val);
	maxSum=max(maxSum,ret);
	return ret;
}

int maxPathSum(TreeNode* root){
	int ret= recursionCore(root);
	return maxSum;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}