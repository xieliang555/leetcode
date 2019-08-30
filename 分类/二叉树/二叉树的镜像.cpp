#include<iostream>
using namespace std;

/**
 * 剑指offer: 27
 * 
 */

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};


void Mirror(TreeNode* pRoot){
	if(!pRoot) return;
	swap(pRoot->left, pRoot->right);
	Mirror(pRoot->left);
	Mirror(pRoot->right);
}

int main(int argc, char const *argv[])
{
	
	return 0;
}