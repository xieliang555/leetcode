#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
	
};

class Task22_findKthToTail
{
public:
	Task22_findKthToTail(){}
	~Task22_findKthToTail(){}

	ListNode* findKthToTail(ListNode* pListHead, unsigned int k){

		if(pListHead==nullptr || k==0)
			return nullptr;

		ListNode* pAhead=pListHead;
		ListNode* pBehind=pListHead;

		for(int count=0; count<k; count++){
			if(pAhead==nullptr)
				return nullptr;
			pAhead=pAhead->next;
		}

		while(pAhead!=nullptr){
			pAhead=pAhead->next;
			pBehind=pBehind->next;
		}

		return pBehind;
	}
	
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}