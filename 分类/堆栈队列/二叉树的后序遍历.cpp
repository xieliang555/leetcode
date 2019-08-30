#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

/**
 * leetcode: 145
 *
 * 后序遍历可以通过先序遍历得到，与先序遍历存在两点不同
 * 1）左子节点先入栈，右子节点后入栈
 * 2）最后输出的数组需要反转
 */

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};


vector<int> postorderTraversal(TreeNode* root){
	if(!root) return vector<int>();
    stack<TreeNode*> s;
    vector<int> ret;
    s.push(root);
    while(!s.empty()){
    	TreeNode* tmp=s.top();
    	s.pop();
    	ret.push_back(tmp->val);
    	if(tmp->left)
    		s.push(tmp->left);
    	if(tmp->right)
    		s.push(tmp->right);
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}