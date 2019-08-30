#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
	
};

class Task18_deleteListNode
{
public:
	Task18_deleteListNode(){}
	~Task18_deleteListNode(){}

	void deleteNode(ListNode** listHead, ListNode* toBeDeleteNode){

		//无效输入
		if(!(*listHead)||!toBeDeleteNode)
			return;

		//链表多个结点，删除除尾结点的其他结点
		if(toBeDeleteNode->next!=nullptr){
			ListNode* nextNode=toBeDeleteNode->next;
			toBeDeleteNode->val=nextNode->val;
			toBeDeleteNode->next=nextNode->next;
			delete nextNode;
			nextNode=nullptr;
		}

		//链表有多个结点，删除尾结点
		if(*listHead!=toBeDeleteNode && toBeDeleteNode->next==nullptr){
			ListNode* preNode=*listHead;
			while(preNode->next!=toBeDeleteNode)
				preNode=preNode->next;
			preNode->next=nullptr;
			delete toBeDeleteNode;
			toBeDeleteNode=nullptr;
		}

		//链表只有一个结点，删除尾结点
		else{
			delete toBeDeleteNode;
			toBeDeleteNode=nullptr;
			*listHead=nullptr;
		}

	}
	
};