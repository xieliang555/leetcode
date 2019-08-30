#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Task34_findPath
{
public:
	Task34_findPath(){}
	~Task34_findPath(){}

	vector<vector<int> > findPath(TreeNode* root, int expectNumber){

		vector<vector<int> > result;
		vector<int> path;

		if(root==nullptr) return result;
		recursionCore(root,expectNumber,result,path);

		return result;

	}

	void recursionCore(TreeNode* root, int expectNumber, vector<vector<int> >& result, vector<int>& path){

		path.push_back(root->val);

		//这种方式相比于终止条件为if(root!=nullptr)，不会遍历到空结点
		if(root->left!=nullptr)
			recursionCore(root->left,expectNumber,result,path);
		if(root->right!=nullptr)
			recursionCore(root->right,expectNumber,result,path);

		if(root->left==nullptr && root->right==nullptr){
			if(accumulate(path.begin(),path.end(),0)==expectNumber)
				result.push_back(path);
		}
			
		path.pop_back();
	}
	
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}