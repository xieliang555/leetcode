#include<iostream>
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

int TreeDepth(TreeNode* pRoot){
	if(!pRoot) return 0;
	int left=TreeDepth(pRoot->left);
	int right=TreeDepth(pRoot->right);
	return max(left,right)+1;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}