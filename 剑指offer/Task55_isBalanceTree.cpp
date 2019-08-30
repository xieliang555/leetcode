#include<iostream>
#include<cmath>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

int getDepth(TreeNode*);

bool IsBalanced_Solution(TreeNode* pRoot){
	return getDepth(pRoot)!=-1;

}

int getDepth(TreeNode* pRoot){
	//子树是平衡树，返回树深度，否则返回-1；
	if(pRoot){
		int left=getDepth(pRoot->left);
		if(left==-1)
			return -1;
		int right=getDepth(pRoot->right);
		if(right==-1)
			return -1;
		return abs(left-right)>1?-1:(fmax(left,right)+1);
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}