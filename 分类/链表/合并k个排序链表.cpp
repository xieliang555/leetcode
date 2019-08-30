#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/**
 * leetcode: 23
 *
 * 见leetcode 题解分析逐一两两合并时间复杂度是o(Nk)
 * 分治两两合并是o(Nlogk) N是总节点数，k是链表数
 * 注意逐一两两合并和分治两两合并都需要合并k-1次，
 * 计算时间复杂度时使用N/k作为链表平均长度计算
 *
 * 逐一两两合并时间复杂度：O(sum_{i=0}^{k-1}i*N/k)=O(kN)
 * 分治两两合并时间复杂度：O(Nlogk)
 */

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};


ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
    if(!pHead1) return pHead2;
    if(!pHead2) return pHead1;
    ListNode* dummyNode=new ListNode(0);
    ListNode* p=dummyNode;
    while(pHead1 && pHead2){
    	if(pHead1->val>pHead2->val){
    		p->next=pHead2;
    		pHead2=pHead2->next;
    		p=p->next;
    	}
    	else{
    		p->next=pHead1;
    		pHead1=pHead1->next;
    		p=p->next;
    	}
    }
    p->next=pHead1==nullptr?pHead2:pHead1;
    return dummyNode->next;
}


ListNode* recursionCore(vector<ListNode*>& lists, int left, int right){
	if(left==right) return lists[left];
	int mid=(left+right)/2;
	ListNode* l1=recursionCore(lists, left, mid);
	ListNode* l2=recursionCore(lists, mid+1, right);
	return Merge(l1,l2);
}

ListNode* mergeKLists(vector<ListNode*>& lists){
	if(lists.empty()) return nullptr;
	ListNode* ret=recursionCore(lists, 0, lists.size()-1);
	return ret;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}

