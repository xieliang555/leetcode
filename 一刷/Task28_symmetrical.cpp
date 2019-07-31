#include<iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
	
};

class Task28_symmetrical
{
public:
	Task28_symmetrical(){}
	~Task28_symmetrical(){}

	bool isSymmetrical(TreeNode* pRoot){
		return recursionCore(pRoot,pRoot);
	}

	bool recursionCore(TreeNode* pRoot1,TreeNode* pRoot2){
		if(pRoot1==nullptr && pRoot2==nullptr) return true;
		if(pRoot1==nullptr || pRoot2==nullptr) return false;
		if(pRoot1->val!=pRoot2->val) return false;

		return recursionCore(pRoot1->left, pRoot2->right) &&
			   recursionCore(pRoot1->right, pRoot2->left);
	}
	
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}