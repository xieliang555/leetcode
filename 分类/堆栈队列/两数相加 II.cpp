#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/**
 * leetcode: 445
 *
 * 由于不可以改变原来的链表，故使用栈来对链表进行反转
 */

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
	
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
	stack<ListNode*> s1;
	stack<ListNode*> s2;
	while(l1!=nullptr){
		s1.push(l1);
		l1=l1->next;
	}
	while(l2!=nullptr){
		s2.push(l2);
		l2=l2->next;
	}
	int carry=0;
	ListNode* nextNode=nullptr;
	ListNode* curNode=nullptr;
	// 注意： 不可以用!carry来判断空
	while(!s1.empty() || !s2.empty() || carry!=0){
		int Sum=0;
		if(!s1.empty()){
			Sum+=s1.top()->val;
			s1.pop();
		}
		if(!s2.empty()){
			Sum+=s2.top()->val;
			s2.pop();
		}
		Sum+=carry;
		carry=Sum/10;
		Sum=Sum%10;
		curNode=new ListNode(Sum);
		curNode->next=nextNode;
		nextNode=curNode;
	}
	return curNode;
}

int main(int argc, char const *argv[])
{
	ListNode* l1=new ListNode(1);
	ListNode* l2=new ListNode(2);
	ListNode* l3=addTwoNumbers(l1,l2);
	return 0;
}