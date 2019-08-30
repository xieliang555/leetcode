#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

/**
 * 剑指offer: 32_3
 */

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};


// 之字形打印二叉树
// 使用双栈交替使用
vector<vector<int> > Print_2(TreeNode* pRoot) {
    if(!pRoot) return vector<vector<int> >();
	stack<TreeNode*> s1;
	stack<TreeNode*> s2;
	vector<vector<int> > ret;
	s1.push(pRoot);
	while(!s1.empty() || !s2.empty()){
		vector<int> list;
		if(!s1.empty()){
			while(!s1.empty()){
				TreeNode* tmp=s1.top();
				s1.pop();
				if(tmp->left)
					s2.push(tmp->left);
				if(tmp->right)
					s2.push(tmp->right);
				list.push_back(tmp->val);
			}
		}
		else{
			while(!s2.empty()){
				TreeNode* tmp=s2.top();
				s2.pop();
				if(tmp->right)
					s1.push(tmp->right);
				if(tmp->left)
					s1.push(tmp->left);
				list.push_back(tmp->val);
			}
		}
		ret.push_back(list);
	}
	return ret;
}


int main(int argc, char const *argv[])
{
	
	return 0;
}