#include<iostream>
#include<stack>
using namespace std;


struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

//方法1:递归
class Task54_KthNode
{
public:
	Task54_KthNode(){};
	~Task54_KthNode(){};

	int index=0;

	TreeNode* KthNode(TreeNode* pRoot, int k){
	
		if(k<=0 || pRoot==nullptr) return nullptr;
		int index=0;
		return recursionCore(pRoot,k);

	}

	TreeNode* recursionCore(TreeNode* pRoot, int k){
		if(pRoot!=nullptr){
			TreeNode* ret=recursionCore(pRoot->left,k);
			if(ret!=nullptr) 
				return ret;
			if((++index)==k)
				return pRoot;
			ret=recursionCore(pRoot->right,k);
			if(ret!=nullptr)
				return ret;

		}
		return nullptr;

	}
	
};


//方法2:辅助栈
TreeNode* KthNode(TreeNode* pRoot, int k){
	if(pRoot==nullptr || k<=0) return nullptr;
	stack<TreeNode*> s;
	int index=1;
	while(!s.empty() || pRoot!=nullptr){
		if(pRoot!=nullptr){
			s.push(pRoot);
			pRoot=pRoot->left;
		}
		else{
			pRoot=s.top();
			s.pop();
			if((index++)==k)
				return pRoot;
			pRoot=pRoot->right;
		}
	}
	return nullptr;
}



int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}