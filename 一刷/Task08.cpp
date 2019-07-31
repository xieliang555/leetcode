#include<iostream>
#include<vector>

/**
 * 8
 */

struct  TreeLinkNode
{
	int val;
	TreeLinkNode* left;
	TreeLinkNode* right;
	TreeLinkNode* next;
	TreeLinkNode(int x):val(x),left(nullptr),right(nullptr),next(nullptr){}
};

class GetNextTreeNode
{
public:
	GetNextTreeNode(){}
	~GetNextTreeNode(){}
	
	TreeLinkNode* getNext(TreeLinkNode* pNode){

		if(pNode==nullptr) return nullptr;

		TreeLinkNode* pNext=nullptr;
		//结点有右子树
		if(pNode->right!=nullptr){
			pNode=pNode->right;
			while(pNode->left!=nullptr)
				pNode=pNode->left;
			pNext=pNode;
		}
		//结点没有右子树
		else if(pNode->next!=nullptr){
			while(pNode->next!=nullptr && pNode!=pNode->next->left)
				pNode=pNode->next;
			pNext=pNode->next;
		}
		//根节点没有右子树
		else
			pNext=nullptr;
		return pNext;
	}
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}