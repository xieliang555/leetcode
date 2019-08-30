#include<iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
	
};

int depthTree(TreeNode* pRoot){

	if(pRoot!=nullptr){
		int left=depthTree(pRoot->left);
		int right=depthTree(pRoot->right);
		return left>right?(left+1):(right+1);
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}