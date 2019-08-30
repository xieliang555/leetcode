#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/**
 * 剑指offer： 25
 */

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};


ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
    if(!pHead1) return pHead2;
    if(!pHead2) return pHead1;
    ListNode* dummyNode=new ListNode(0);
    ListNode* p=dummyNode;
    while(pHead1 && pHead2){
    	if(pHead1->val>pHead2->val){
    		p->next=pHead2;
    		pHead2=pHead2->next;
    		p=p->next;
    	}
    	else{
    		p->next=pHead1;
    		pHead1=pHead1->next;
    		p=p->next;
    	}
    }
    p->next=pHead1==nullptr?pHead2:pHead1;
    return dummyNode->next;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}