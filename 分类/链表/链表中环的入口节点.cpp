#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/**
 * 剑指offer： 23
 */

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};


ListNode* findMeetingNode(ListNode* pHead){
	ListNode* fast=pHead;
	ListNode* slow=pHead;
	while(fast && slow){
		slow=slow->next;
		fast=fast->next;
		if(fast)
			fast=fast->next;
		if(fast==slow)
			return fast;
	}
	return nullptr;
}


ListNode* EntryNodeOfLoop(ListNode* pHead){
	ListNode* meetingNode=findMeetingNode(pHead);
	if(meetingNode){
		ListNode* fast=meetingNode;
		ListNode* slow=pHead;
		while(fast!=slow){
			fast=fast->next;
			slow=slow->next;
		}
		return fast;
	}
	return nullptr;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}