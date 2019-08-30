#include<iostream>
#include<vector>
using namespace std;

/**
 * 剑指offer: 7
 * 
 */

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};


TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin){
	if(pre.empty())  return nullptr;
	TreeNode* root=new TreeNode(pre[0]);
	vector<int> leftPre, leftVin, rightPre, rightVin;
	int i=0;
	for(;vin[i]!=pre[0];i++){
		leftPre.push_back(pre[i+1]);
		leftVin.push_back(vin[i]);
	}
	i++;
	for(;i<vin.size();i++){
		rightPre.push_back(pre[i]);
		rightVin.push_back(vin[i]);
	}
	root->left=reConstructBinaryTree(leftPre, leftVin);
	root->right=reConstructBinaryTree(rightPre,rightVin);
	return root;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}