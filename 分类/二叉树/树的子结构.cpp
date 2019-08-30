#include<iostream>
using namespace std;

/**
 * 剑指offer: 26
 *
 * 思路：遍历A树，对于A树的每一个节点，判断以该节点为根节点的子结构是否等于B树
 *
 * 剪枝：先完成完整遍历，再考虑剪枝
 */

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

bool doesTreeAhasTreeB(TreeNode* pRoot1, TreeNode* pRoot2){
	if(pRoot2==nullptr) return true;
	else if(pRoot1==nullptr) return false;
	if(pRoot1->val!=pRoot2->val) return false;
	bool left=doesTreeAhasTreeB(pRoot1->left, pRoot2->left);
	bool right=doesTreeAhasTreeB(pRoot1->right, pRoot2->right);
	return left && right;
}


bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){

	if (pRoot1==nullptr || pRoot2==nullptr) return false;
	bool cur=doesTreeAhasTreeB(pRoot1, pRoot2);
	if(cur) return true;
	bool left=HasSubtree(pRoot1->left, pRoot2);
	if(left) return true;
	bool right=HasSubtree(pRoot1->right, pRoot2);
	if(right) return true;
	return cur || left || right;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}