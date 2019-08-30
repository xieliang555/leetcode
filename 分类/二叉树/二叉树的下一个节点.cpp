#include<iostream>
using namespace std;

/**
 * 剑指offer: 8
 *
 * 思路： 将所有节点分为3类：（记）
 * 1）该节点存在右子树，则中序遍历中该节点的下一节点是该节点右子树的最左节点
 * 2）该节点不存在右子树，且该节点属于父节点的右子节点，则中序遍历中下一节点为：一直沿着父节点的路径向上，
 * 找到找到某一节点，该节点属于其父节点的左子节点，则该节点的父节点即为目标节点。
 * 3）该节点不存在右子树，且该节点属于父节点的左子节点，则中序遍历中下一节点是父节点.
 */

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};


// 不需要知道树的根节点
TreeLinkNode* GetNext(TreeLinkNode* pNode){

	if(!pNode) return nullptr;

	TreeLinkNode* ret=nullptr;
	if(pNode->right){
		pNode=pNode->right;
		while(pNode->left){
			pNode=pNode->left;
		}
		ret=pNode;
	}
	else if(pNode->next && pNode==pNode->next->right){
		while(pNode->next && pNode==pNode->next->right)
			pNode=pNode->next;
		if(pNode->next)
			ret=pNode->next;
	}
	else {
		ret=pNode->next;
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}