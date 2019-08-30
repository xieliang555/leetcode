#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

/**
 * leetcode: 94
 * 有一个当前节点，根据当前节点的状态分两步：
 * 1）如果当前节点不为空，当前节点入栈，当前节点指向其左子节点
 * 2）如果当前节点为空，栈顶出栈，当前节点指向栈顶节点的右子节点
 */

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};


vector<int> inorderTraversal(TreeNode* root) {
    
    vector<int> ret;
    TreeNode* curNode=root;
    stack<TreeNode*> s;
    while(!s.empty() || curNode!=nullptr){
    	if(curNode){
    		s.push(curNode);
    		curNode=curNode->left;
    	}
    	else{
    		TreeNode* tmp=s.top();
    		s.pop();
    		ret.push_back(tmp->val);
    		curNode=tmp->right;
    	}
    }
    return ret;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}