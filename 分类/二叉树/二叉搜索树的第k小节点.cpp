#include<iostream>
#include<stack>
using namespace std;

/**
 * 剑指offer: 54
 *
 * 递归解法：返回值无法实现，通过引入额外变量保存返回节点
 *
 * 此题用栈实现中序遍历比用递归实现简单
 * 栈实现中序遍历的要点(记)：
 * 有一个当前节点，根据当前节点的状态分两步：
 * 1）如果当前节点不为空，当前节点入栈，当前节点指向其左子节点
 * 2）如果当前节点为空，栈顶出栈，当前节点指向栈顶节点的右子节点
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};


//使用递归+剪枝
TreeNode* ret=nullptr;
void recursionCore(TreeNode* pRoot, int& k){
	if(!pRoot) return;
	recursionCore(pRoot->left, k);
	if(ret) return;
	k--;
	if(k==0){
		ret=pRoot;
	}
	recursionCore(pRoot->right,k);
	if(ret) return;
}

TreeNode* KthNode(TreeNode* pRoot, int k){

	recursionCore(pRoot,k);
	return ret;
}


// 使用栈
TreeNode* KthNode_2(TreeNode* pRoot, int k){
	if(!pRoot) return nullptr;
	stack<TreeNode*> s;
	TreeNode* curNode=pRoot;
	TreeNode* ret=nullptr;
	while(!s.empty() || curNode){
		if(curNode){
			s.push(curNode);
			curNode=curNode->left;
		}
		else{
			TreeNode* tmp=s.top();
			s.pop();
			k--;
			if(k==0){
				ret=tmp;
				break;
			}
			curNode=tmp->right;
		}
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}
