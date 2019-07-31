#include<iostream>
#include<climits>
using namespace std;

struct ListNode
{	
	int val;
	ListNode* next;
	ListNode(int x): val(x),next(nullptr){}
};

class Task18_1_deleteDuplication
{
public:
	Task18_1_deleteDuplication(){}
	~Task18_1_deleteDuplication(){}


	ListNode* deleteDuploication(ListNode* pHead){

		if(pHead==nullptr||pHead->next==nullptr)
			return pHead;

		ListNode dummy(INT_MIN);
		ListNode* pPreNode=&dummy;
		pPreNode->next=pHead;
		ListNode* pCurNode=pHead;
		while(pCurNode!=nullptr){
			int value=pCurNode->val;
			if(pCurNode->next!=nullptr && value==pCurNode->next->val){
				while(pCurNode!=nullptr && pCurNode->val==value){
					ListNode* tmp=pCurNode->next;
					delete pCurNode;
					pCurNode=tmp;
				}
				pPreNode->next=pCurNode;
			}

			else{	
				pPreNode=pCurNode;
				pCurNode=pCurNode->next;
			}
		}
		return dummy.next;
	}
	
};


int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}