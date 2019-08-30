#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/**
 * leetcode: 148
 *
 * 使用快排实现链表的排序
 * 快慢指针，快指针为当前指针，
 * 如果当前指针指向大于target,快指针直接向后移一个
 * 否则慢指针向后移一个，交换快慢指针值，快指针向后移一个
 * 
 */

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};


ListNode* quickSort(ListNode* head, ListNode* end){
	if(!head || !head->next) return head;
	ListNode* fast=head->next;
	ListNode* slow=head;
	int value=slow->val;
	// 易错 容易写成fast!=nullptr
	while(fast!=end){
		if(fast->val<value){
			slow=slow->next;
			swap(slow->val,fast->val);
		}
		fast=fast->next;
	}
	// 易错，不可以swap(head, slow)
	swap(head->val, slow->val);
	return slow;
}


void recursionCore(ListNode* head, ListNode* end){
	// 易错 容易写成head->next!=end
	if(head==end) return;
	ListNode* mid=quickSort(head, end);
	recursionCore(head, mid);
	// 易错 容易写成mid
	recursionCore(mid->next, end);
}


ListNode* sortList(ListNode* head){
	if(!head) return head;
	recursionCore(head, nullptr);
	return head;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}