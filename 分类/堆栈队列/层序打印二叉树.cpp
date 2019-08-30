#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

/**
 * 剑指offer: 32_1, 32_2
 * 牛客OJ: 
 * 1): 从上往下打印二叉树
 * 2): 把二叉树打印成多行
 */

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

// 不分行从上到下打印二叉树
// 使用队列
vector<int> PrintFromTopToBottom(TreeNode* root){
    if(!root) return vector<int>();
	queue<TreeNode*> q;
	vector<int> ret;
	q.push(root);
	while(!q.empty()){
		TreeNode* tmp=q.front();
		q.pop();
		if(tmp->left)
			q.push(tmp->left);
		if(tmp->right)
			q.push(tmp->right);
		ret.push_back(tmp->val);
	}
	return ret;
}

// 分行从上到下打印二叉树
// 使用队列
vector<vector<int> > Print(TreeNode* pRoot) {
	if(!pRoot) return vector<vector<int> >();
	vector<vector<int> > ret;
	queue<TreeNode*> q;
	q.push(pRoot);
	while(!q.empty()){
		vector<int> list;
		int size=q.size();
		for(int i=0;i<size;i++){
			TreeNode* tmp=q.front();
			q.pop();
			if(tmp->left)
				q.push(tmp->left);
			if(tmp->right)
				q.push(tmp->right);
			list.push_back(tmp->val);
		}
		ret.push_back(list);
	}
	return ret;
}


int main(int argc, char const *argv[])
{
	
	return 0;
}