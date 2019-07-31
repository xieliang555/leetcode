#include<iostream>
using namespace std;


/**
 * 给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
 */

class ListNode
{
public:
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){};
	
};

ListNode* hasLoop(ListNode*);

ListNode* EntryNodeOfLoop(ListNode* pHead){

	if(hasLoop(pHead)){
		ListNode* meetingNode=hasLoop(pHead);
		ListNode* slow=pHead;
		ListNode* fast=meetingNode;
		while(slow!=fast){
			slow=slow->next;
			fast=fast->next;
		}
		return fast;
	}

	return nullptr;

}

ListNode* hasLoop(ListNode* pHead){
	ListNode* fast=pHead;
	ListNode* slow=pHead;
	while(fast){
		slow=slow->next;
		fast=fast->next;
		if(fast)
			fast=fast->next;
		if(fast && (fast==slow))
			return fast;
	}
	return nullptr;
}


int main(int argc, char const *argv[])
{
	
	return 0;
}