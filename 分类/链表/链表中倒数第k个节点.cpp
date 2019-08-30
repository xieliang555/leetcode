#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/**
 * 剑指offer： 22
 */

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};


ListNode* FindKthToTail(ListNode* pListHead, unsigned int k){
	if(!pListHead) return nullptr;
	ListNode* p1=pListHead;
	ListNode* p2=pListHead;
	for(int i=0;i<k;i++){
		if(!p1) return nullptr;
		p1=p1->next;
	}
	while(p1){
		p1=p1->next;
		p2=p2->next;
	}
	return p2;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}