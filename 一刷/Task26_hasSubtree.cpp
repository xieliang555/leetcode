#include<iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Task26_hasSubtree
{
public:
	Task26_hasSubtree(){}
	~Task26_hasSubtree(){}

	bool hasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
		bool result=false;
		if(pRoot1!=nullptr && pRoot2!=nullptr){
			if(pRoot1->val==pRoot2->val){
				result=doseTree1HaveTree2(pRoot1,pRoot2);
			}
			if(!result)
				result=hasSubtree(pRoot1->left,pRoot2);
			if(!result)
				result=hasSubtree(pRoot1->right,pRoot2);
		}

		return result;
	}

	bool doseTree1HaveTree2(TreeNode* pRoot1, TreeNode* pRoot2){

		if(pRoot2==nullptr) return true;
		if(pRoot1==nullptr) return false;

		if(pRoot1->val!=pRoot2->val) return false;
		return doseTree1HaveTree2(pRoot1->left,pRoot2->left) &&
			   doseTree1HaveTree2(pRoot1->right,pRoot2->right);
	}
	
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}