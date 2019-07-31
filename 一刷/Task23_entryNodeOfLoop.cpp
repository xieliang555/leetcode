#include<iostream>
using namespace std;

struct ListNode
{	
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
	
};

class Task23_entryNodeOfLoop
{
public:
	Task23_entryNodeOfLoop(){}
	~Task23_entryNodeOfLoop(){}

	ListNode* entryNodeOfLoop(ListNode* pHead){

		if(pHead==nullptr)
			return nullptr;

		ListNode* meetingNode=MeetingNode(pHead);
		if(meetingNode==nullptr)
			return nullptr;

		int loopSize=1;
		ListNode* pTemp=meetingNode;
		while(pTemp->next!=meetingNode){
			pTemp=pTemp->next;
			loopSize++;
		}

		ListNode* pFast=pHead;
		ListNode* pSlow=pHead;
		for(int i =0;i<loopSize;i++)
			pFast=pFast->next;
		while(pFast!=pSlow){
			pFast=pFast->next;
			pSlow=pSlow->next;
		}

		return pFast;

	}

	ListNode* MeetingNode(ListNode* pHead){

		ListNode* pSlow=pHead;
		ListNode* pFast;
		if(pSlow->next==nullptr)
			return nullptr;
		pFast=pSlow->next;

		while(pFast!=nullptr && pSlow!=nullptr){
			if(pFast==pSlow)
				return pFast;
			pFast=pFast->next;
			if(pFast!=nullptr)
				pFast=pFast->next;
			pSlow=pSlow->next;
		}
		return nullptr;
	}
	
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}