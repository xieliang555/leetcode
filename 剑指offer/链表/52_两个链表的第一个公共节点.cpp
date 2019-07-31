#include<iostream>
using namespace std;

/**
 * 输入两个链表，找出它们的第一个公共结点。
 */

class ListNode
{
public:
	int val;
	ListNode* next;
	ListNode(int x): val(x),next(nullptr){};	
};

ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2){

	if(pHead1==nullptr || pHead2==nullptr) return nullptr;

	ListNode* p1=pHead1;
	ListNode* p2=pHead2;
	while(p1!=p2){
		p1=p1==nullptr?pHead2:p1->next;
		p2=p2==nullptr?pHead1:p2->next;
	}

	return p1;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}