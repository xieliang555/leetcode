#include<iostream>
#include<list>
using namespace std;

//版本2 leetcode 236二叉树的最近公共祖先

//此题改为二叉树，其他不变（不会普通树的遍历）
//注意最低公共祖先，自己不可以是自己的祖先，所以d和f的最低公共祖先是b而不是d;
	
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

bool GetNodePath(TreeNode*, TreeNode*, list<TreeNode*>&);
TreeNode* GetLastCommonParent(list<TreeNode*>&, list<TreeNode*>&);

TreeNode* GetLastCommonParentCore(TreeNode* pRoot, TreeNode* pNode1, TreeNode* pNode2){
	if(pRoot==nullptr)
		return nullptr;
	list<TreeNode*> leftPath;
	list<TreeNode*> rightPath;
	bool foundLeft=GetNodePath(pRoot,pNode1,leftPath);
	bool foundRight=GetNodePath(pRoot,pNode2,rightPath);
	if(!foundLeft) leftPath.clear();
	if(!foundRight) rightPath.clear();
	TreeNode* ret=GetLastCommonParent(leftPath,rightPath);
	return ret;

}

//先序+后序+剪枝
bool GetNodePath(TreeNode* pRoot, TreeNode* pNode, list<TreeNode*>& path ){

	if(pRoot!=nullptr){	
		path.push_back(pRoot);
		bool foundLeft=GetNodePath(pRoot->left,pNode,path);
		if(foundLeft==true)
			return foundLeft;
		bool foundRight=GetNodePath(pRoot->right,pNode,path);
		if(foundRight==true)
			return foundRight;
		bool foundCurrent=(pRoot==pNode)?true:false;
		//
		path.pop_back();
		return foundLeft || foundRight || foundCurrent;
	}
	return false;
}

TreeNode* GetLastCommonParent(list<TreeNode*>& path1, list<TreeNode*>& path2){
	// //test
	// auto iter=path1.rbegin();
	// while(iter!=path1.rend()){
	// 	cout<<(*iter)->val<<' ';
	// 	iter++;
	// }
	// //test
	
	// 技巧：填充。当找两个数组如：[1,2,6,7],[1,2,5]最后一个相同的元素2，
	// 将短的数组填充成和长的一样，然后从后向前遍历。
	// 以下写法注意当长度相同时long和short相同
	
	// list<TreeNode*> longList=path1.size()>path2.size()?path1:path2;
	// list<TreeNode*> shortList=path2.size()>path1.size()?path1:path2;
	list<TreeNode*> longList=path1.size()>path2.size()?path1:path2;
	list<TreeNode*> shortList=path1.size()>path2.size()?path2:path1;
	TreeNode* tmp=shortList.back();
	//
	for(int i=shortList.size();i<longList.size();i++){
		shortList.push_back(tmp);
	}

	TreeNode* ret=nullptr;
	auto iter1=longList.rbegin();
	auto iter2=shortList.rbegin();
	//iterator 不是指针，不可以赋值为nullptr
	while(iter1!=longList.rend() && iter2!=shortList.rend()){
		if(*iter1==*iter2){
			ret=*iter1;
			break;
		}
		// //test
		// cout<<(*iter1)->val<<' '<<(*iter2)->val<<endl;
		// //test
		iter1++;
		iter2++;
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	TreeNode d(4);
	TreeNode e(5);
	TreeNode f(6);
	TreeNode g(7);
	TreeNode h(8);
	TreeNode i(9);
	TreeNode test(10);
	a.left=&b;
	a.right=&c;
	b.left=&d;
	b.right=&e;
	d.left=&f;
	d.right=&g;
	e.left=&h;
	e.right=&i;

	// list<TreeNode*> l;
	// cout<<boolalpha<<GetNodePath(&a,&i,l);
	// while(!l.empty()){
	// 	cout<<(l.front()->val)<<' ';
	// 	l.pop_front();
	// }
	
	//
	TreeNode* t=GetLastCommonParentCore(&a,&d,&f);
	if(t!=nullptr)
		cout<<(t->val)<<endl;
	return 0;
}