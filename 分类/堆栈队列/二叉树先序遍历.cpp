#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

/**
 * leetcode: 144
 */

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};


vector<int> preorderTraversal(TreeNode* root) {
    if(!root) return vector<int>();
    stack<TreeNode*> s;
    vector<int> ret;
    s.push(root);
    while(!s.empty()){
    	TreeNode* tmp=s.top();
    	s.pop();
    	ret.push_back(tmp->val);
    	if(tmp->right)
    		s.push(tmp->right);
    	if(tmp->left)
    		s.push(tmp->left);
    }
    return ret;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}