#include<iostream>
using namespace std;

struct RandomListNode
{
	int label;
	RandomListNode* next;
	RandomListNode* random;
	RandomListNode(int x):label(x),next(nullptr),random(nullptr){}
};

class Task35_cloneComplexList
{
public:
	Task35_cloneComplexList(){}
	~Task35_cloneComplexList(){}

	RandomListNode* cloneComplexList(RandomListNode* pHead){

		if(pHead==nullptr) return pHead;
		cloneNodes(pHead);
		connectRandomNode(pHead);
		return ReconnectNodes(pHead);

	}

	void cloneNodes(RandomListNode* pHead){
		RandomListNode* pTmp;
		while(pHead!=nullptr){
			pTmp=pHead->next;
			RandomListNode* pNew=new RandomListNode(pHead->label);
			pHead->next=pNew;
			pNew->next=pTmp;
			pHead=pTmp;
		}
	}

	//指针访问前注意判断是否为空
	void connectRandomNode(RandomListNode* pHead){
		while(pHead!=nullptr){
			if(pHead->random!=nullptr)
				pHead->next->random=pHead->random->next;
			pHead=pHead->next->next;
		}
	}

	RandomListNode* ReconnectNodes(RandomListNode* pHead){
		RandomListNode* pCloneHead=pHead->next;
		RandomListNode* pNode1=pHead;
		RandomListNode* pNode2=pCloneHead;
		while(pNode1!=nullptr){
			pNode1->next=pNode2->next;
			if(pNode2->next!=nullptr)
				pNode2->next=pNode2->next->next;
			pNode1=pNode1->next;
			pNode2=pNode2->next;
		}

		return pCloneHead;
	}
	
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}