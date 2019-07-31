#include<vector>
#include<iostream>
using namespace std;

/**
 * 7
 */

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class ReconstructBinaryTree
{
public:
	ReconstructBinaryTree(){}
	~ReconstructBinaryTree(){}

	TreeNode* reconstruct(vector<int> pre, vector<int> vin){
		
		if(pre.size()==0) return nullptr;

		TreeNode* root=new TreeNode(pre[0]);
		vector<int> preLeft,vinLeft,preRight,vinRight;
		int i=0;
		for(;i<pre.size() && vin[i]!=pre[0];i++);
		for(int j=0;j<pre.size();j++){
			if(j<i){
				preLeft.push_back(pre[j+1]);
				vinLeft.push_back(vin[j]);
			}
			else if(j>i){
				preRight.push_back(pre[j]);
				vinRight.push_back(vin[j]);
			}
		}

		root->left=reconstruct(preLeft,vinLeft);
		root->right=reconstruct(preRight,vinRight);
		return root;
	}
	
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}