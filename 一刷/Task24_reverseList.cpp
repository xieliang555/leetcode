#include<iostream>
#include<limits>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
	
};

class Task24_reverseList
{
public:
	Task24_reverseList(){}
	~Task24_reverseList(){}

	ListNode* reverseList(ListNode* pHead){

		ListNode* pPre=nullptr;
		ListNode* pCur=pHead;
		ListNode* pNext=nullptr;
		while(pCur!=nullptr){
			pNext=pCur->next;
			pCur->next=pPre;
			pPre=pCur;
			pCur=pNext;
		}

		return pPre;
	}

	//recursion solution
	ListNode* reverseList1(ListNode* pHead){

		if(pHead==nullptr || pHead->next==nullptr)
			return pHead;

		ListNode* pNode=reverseList1(pHead->next);
		pHead->next->next=pHead;
		pHead->next=nullptr;

		return pNode;
	}

	
};

int main(int argc, char const *argv[])
{
	ListNode* l1=new ListNode(8);
	ListNode* l2=new ListNode(9);
	l1->next=l2;
	ListNode* tmp=l1;
	Task24_reverseList t;
	tmp=t.reverseList1(l1);
	while(tmp!=nullptr){
		cout<<tmp->val<<' ';
		tmp=tmp->next;
	}

	delete l1;
	delete l2;
	return 0;
}