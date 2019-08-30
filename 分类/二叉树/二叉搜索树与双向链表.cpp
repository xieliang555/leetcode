#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

/**
 * 剑指offer: 36
 *
 * 难点：需要一个额外的节点保存中序遍历中的上一个节点（且必须为中序操作，不可以为后续操作，
 * 因为后续操作返回的不是中序遍历的上一节点），而不是通过返回值来得到上一个节点
 * 返回表头（二叉树最左边的节点作为表头）
 */

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};


TreeNode* lastNode=nullptr;

void recursionCore(TreeNode* pRootOfTree){
	if(!pRootOfTree) return ;
	recursionCore(pRootOfTree->left);
	if(lastNode) lastNode->right=pRootOfTree;
	pRootOfTree->left=lastNode;
	lastNode=pRootOfTree;
	recursionCore(pRootOfTree->right);
}


TreeNode* Convert(TreeNode* pRootOfTree){
	if(!pRootOfTree) return nullptr;
	recursionCore(pRootOfTree);
	while(pRootOfTree->left){
		pRootOfTree=pRootOfTree->left;
	}
	return pRootOfTree;  
}

int main(int argc, char const *argv[])
{
	
	return 0;
}