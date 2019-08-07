#include<iostream>
#include<vector>
#include<numeric>
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

vector<vector<int> > ret;
vector<int> path;

void recursionCore(TreeNode* root, int expectNumber){

	if(!root) return;
	path.push_back(root->val);
	recursionCore(root->left, expectNumber);
	recursionCore(root->right,expectNumber);
	if(root->left==nullptr && root->right==nullptr){
		if(accumulate(path.begin(), path.end(),0)==expectNumber)
			ret.push_back(path);
	}
	path.pop_back();
}

vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
	recursionCore(root, expectNumber);
	return ret;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}