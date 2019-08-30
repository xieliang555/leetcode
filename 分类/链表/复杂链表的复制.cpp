#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/**
 * 剑指offer： 35
 */

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

void cloneNodes(RandomListNode* pHead){

	while(pHead){
		RandomListNode* nextNode=pHead->next;
		RandomListNode* newNode = new RandomListNode(pHead->label);
		pHead->next=newNode;
		newNode->next=nextNode;
		pHead=nextNode;
	}
}

void connectRandom(RandomListNode* pHead){

	while(pHead){
		// 易错，random可能为空
		if(pHead->random){
			RandomListNode* tmp=pHead->random;
			pHead->next->random=tmp->next;
		}
		pHead=pHead->next->next;
	}
}

RandomListNode* reconnect(RandomListNode* pHead){

	RandomListNode* ret=pHead->next;
	RandomListNode* p=ret;
	while(pHead){
		pHead->next=p->next;
		pHead=pHead->next;
		if(pHead){
			p->next=pHead->next;
			p=p->next;
		}
	}
	return ret;
}



RandomListNode* Clone(RandomListNode* pHead){
	if(!pHead) return pHead;
	cloneNodes(pHead);
	connectRandom(pHead);
	return reconnect(pHead);
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}

