#include<iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Task36_convert
{
public:
	Task36_convert(){}
	~Task36_convert(){}

	TreeNode* convert(TreeNode* pRootOfTree){

		if(pRootOfTree==nullptr) return pRootOfTree;

		TreeNode* pLastNode=nullptr;
		recursionCore(pRootOfTree,&pLastNode);

		TreeNode* pHead=nullptr;
		while(pLastNode!=nullptr){
			pHead=pLastNode;
			pLastNode=pLastNode->left;
		}

		return pHead;
	}

	void recursionCore(TreeNode* pRootOfTree, TreeNode** pLastNode){

		//本题考查中序遍历的控制遍历结点的版本
		if(pRootOfTree->left!=nullptr)
			recursionCore(pRootOfTree->left,pLastNode);

		pRootOfTree->left=*pLastNode;
		//先考虑最通用的解如结点6，然后再考虑特殊解如结点4
		if((*pLastNode)!=nullptr)
			(*pLastNode)->right=pRootOfTree;
		*pLastNode=pRootOfTree;
	
		if(pRootOfTree->right!=nullptr)
			recursionCore(pRootOfTree->right,pLastNode);

	}
	
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}