#include<iostream>
#include<vector>
using namespace std;

/**
 * 剑指offer: 55_2
 *
 * 
 */

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

bool ret=true;

int recursionCore(TreeNode* pRoot){
	if(!pRoot) return 0;
	int leftLen=recursionCore(pRoot->left);
	int rightLen=recursionCore(pRoot->right);
	if(abs(leftLen-rightLen)>1) ret=false;
	return leftLen>rightLen?leftLen+1:rightLen+1;
}

bool IsBalanced_Solution(TreeNode* pRoot){

	int tmp=recursionCore(pRoot);
	return ret;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}