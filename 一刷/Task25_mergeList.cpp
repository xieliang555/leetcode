#include<iostream>
#include<limits>
using namespace std;

struct ListNode
{
	int val;
	ListNode* pNext;
	ListNode(int x): val(x),pNext(nullptr){}
};

class Task25_mergeList
{
public:
	Task25_mergeList(){}
	~Task25_mergeList(){}

	ListNode* Merge(ListNode* pHead1, ListNode* pHead2){


		ListNode dummy(INT_MIN);
		dummy.pNext=nullptr;
		ListNode* pCur=&dummy;
		while(pHead1!=nullptr && pHead2!=nullptr){
			if(pHead1->val<pHead2->val){
				pCur->pNext=pHead1;
				pCur=pCur->pNext;
				pHead1=pHead1->pNext;
			}
			else{
				pCur->pNext=pHead2;
				pCur=pCur->pNext;
				pHead2=pHead2->pNext;
			}

		}
		pCur->pNext=pHead2==nullptr?pHead1:pHead2;
		return dummy.pNext;
	}



	//recursion solution
	ListNode* Merge1(ListNode* pHead1,ListNode* pHead2){
		if(pHead1==nullptr) return pHead2;
		if(pHead2==nullptr) return pHead1;

		if(pHead1->val<pHead2->val){
			pHead1->pNext=Merge1(pHead1->pNext,pHead2);
			return pHead1;
		}
		else{
			pHead2->pNext=Merge1(pHead1,pHead2->pNext);
			return pHead2;
		}
	}
	
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}