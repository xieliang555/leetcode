#include<iostream>
using namespace std;

/**
 * 剑指offer: 28
 *
 * 思路： 两棵树使用不同的遍历顺序，结果相同则互为镜像
 */

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

bool recursionCore(TreeNode* pRoot1, TreeNode* pRoot2){
	if(pRoot1==nullptr && pRoot2==nullptr) return true;
	else if(pRoot1==nullptr || pRoot2==nullptr) return false;
	if(pRoot1->val!=pRoot2->val) return false;
	bool left=recursionCore(pRoot1->left, pRoot2->right);
	bool right=recursionCore(pRoot1->right, pRoot2->left);
	return left && right;
}

bool isSymmetrical(TreeNode* pRoot){
	return recursionCore(pRoot, pRoot);
}

int main(int argc, char const *argv[])
{
	
	return 0;
}

