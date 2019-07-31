#include<iostream>
using namespace std;

class ListNode
{
public:
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
	
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){

	ListNode* dummy=new ListNode(-1);
	ListNode* pMerge=dummy;
	ListNode* p1=l1;
	ListNode* p2=l2;
	while(p1 && p2){
		if(p1->val < p2->val){
			pMerge->next=p1;
			p1=p1->next;
			pMerge=pMerge->next;
		}
		else{
			pMerge->next=p2;
			p2=p2->next;
			pMerge=pMerge->next;
		}
	}
	pMerge->next=p1?p1:p2;
	return dummy->next;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}