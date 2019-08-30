#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/**
 * 剑指offer： 18_2
 *
 * 本题的思路在于找到最后一个重复节点，同时删除所有的相同节点，而不是一个一个的删除
 */

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};

ListNode* deleteDuplication(ListNode* pHead){
	if(!pHead || !(pHead->next)) return pHead;
	ListNode* dummy=new ListNode(0);
	dummy->next=pHead;
	ListNode* preNode=dummy;
	ListNode* curNode=pHead;
	while(curNode){
		if(curNode->next && (curNode->val==curNode->next->val)){
			while(curNode->next && (curNode->val==curNode->next->val)){
				curNode=curNode->next;
			}
			preNode->next=curNode->next;
			curNode=curNode->next;
		}
		else{
			preNode=curNode;
			curNode=curNode->next;
		}
	}
	return dummy->next;
}

int main(int argc, char const *argv[])
{

	return 0;
}