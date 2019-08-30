#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

/**
 * 剑指offer: 34
 * 
 */

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};


vector<vector<int> > ret;
vector<int> list;

void recursionCore(TreeNode* root, int expectNumber){
	if(!root) return;
	list.push_back(root->val);
	recursionCore(root->left,expectNumber);
	recursionCore(root->right,expectNumber);
	if(root->left==nullptr && root->right==nullptr){
		if(accumulate(list.begin(),list.end(),0)==expectNumber)
			ret.push_back(list);
	}
	list.pop_back();
}

vector<vector<int> > FindPath(TreeNode* root,int expectNumber){
	recursionCore(root,expectNumber);
	return ret;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}