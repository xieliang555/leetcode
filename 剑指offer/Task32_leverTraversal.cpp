//考虑特殊输入和边界输入
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
	
};

class Task32_leverTraversal
{
public:
	Task32_leverTraversal(){}
	~Task32_leverTraversal(){}

	//输出一维vector，不区分层
	vector<int> traversal(TreeNode* root){
		queue<TreeNode*> q;
		vector<int> result;
		if(root==nullptr) return result;
		q.push(root);
		while(!q.empty()){
			TreeNode* node=q.front();
			result.push_back(node->val);
			q.pop();
			if(node->left!=nullptr)
				q.push(node->left);
			if(node->right!=nullptr)
				q.push(node->right);
		}

		return result;
	}

	//输出二维vector，区分不同的层
	vector<vector<int> > traversal_1(TreeNode* root){
		queue<TreeNode*> q;
		vector<vector<int> > result;
		if(root==nullptr) return result;
		q.push(root);
		while(!q.empty()){
			int size=q.size();
			vector<int> list;
			for(int i=0;i<size;i++){
				TreeNode* node=q.front();
				q.pop();
				list.push_back(node->val);
				if(node->left!=nullptr)
					q.push(node->left);
				if(node->right!=nullptr)
					q.push(node->right);
			}
			result.push_back(list);
		}

		return result;
	}

	//之字形打印二叉树
	vector<vector<int> > traversal_2(TreeNode* root){
		stack<TreeNode*> s1,s2;
		vector<vector<int> > result;
		if(root==nullptr) return result;
		s1.push(root);
		while(!s1.empty() || !s2.empty()){
			vector<int> list;
			if(!s1.empty()){
				int size=s1.size();
				for(int i=0;i<size;i++){
					TreeNode* node=s1.top();
					s1.pop();
					list.push_back(node->val);
					if(node->left)
						s2.push(node->left);
					if(node->right)
						s2.push(node->right);
				}
			}
			else{
				int size=s2.size();
				for(int i=0;i<size;i++){
					TreeNode* node=s2.top();
					s2.pop();
					list.push_back(node->val);
					if(node->right)
						s1.push(node->right);
					if(node->left)
						s1.push(node->left);
				}
			}
			result.push_back(list);
		}

		return result;
	}
	

	
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}