#include<iostream>
#include<vector>
using namespace std;

/**
 * 剑指offer: 55_2
 *
 * 此题难点在于使用局部变量记录下一次递归的返回值
 * leftDepth记录着左子树的深度，rightDepth记录着右子树的深度，depth记录着当前节点的深度
 * 返回值表示当前子树是否是平衡二叉树
 *
 * 本题也可以使用返回值+全局变量实现，见解法2
 * 
 */

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};


bool recursionCore(TreeNode* pRoot, int& depth){
	if(!pRoot){
		depth=0;
		return true;
	}
	int leftDepth, rightDepth;
	bool left=recursionCore(pRoot->left, leftDepth);
	bool right=recursionCore(pRoot->right, rightDepth);
	if(abs(leftDepth-rightDepth)>1) return false;
	depth=leftDepth>rightDepth?leftDepth+1:rightDepth+1;
	return left && right;
}

bool IsBalanced_Solution(TreeNode* pRoot){

	int depth;
	return recursionCore(pRoot, depth);
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}