#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/**
 * 剑指offer： 24
 * 三个指针
 */

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};


ListNode* ReverseList(ListNode* pHead) {
	if(!pHead || !pHead->next) return pHead; 
	ListNode* pre=nullptr;
	ListNode* cur=pHead;
	ListNode* next=pHead->next;
	while(cur){
		cur->next=pre;
		pre=cur;
		cur=next;
		if(next)
			next=next->next;
	}
	return pre;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}