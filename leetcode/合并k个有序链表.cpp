#include<iostream>
#include<vector>
using namespace std;

class ListNode
{
public:
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
	
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){

	ListNode* dummy=new ListNode(-1);
	ListNode* pMerge=dummy;
	ListNode* p1=l1;
	ListNode* p2=l2;
	while(p1 && p2){
		if(p1->val < p2->val){
			pMerge->next=p1;
			p1=p1->next;
			pMerge=pMerge->next;
		}
		else{
			pMerge->next=p2;
			p2=p2->next;
			pMerge=pMerge->next;
		}
	}
	pMerge->next=p1?p1:p2;
	return dummy->next;
}

ListNode* merge(vector<ListNode*> lists, int left, int right){

	if(left>=right) return lists[right];

	int mid=(left+right)/2;
	ListNode* l1=merge(lists, left, mid);
	ListNode* l2=merge(lists, mid+1, right);
	return mergeTwoLists(l1, l2);
}

//见leetcode 题解分析逐一两两合并时间复杂度是o(Nk)
//分治两两合并是o(Nlogk) N是总节点数，k是链表数
//注意逐一两两合并和分治两两合并都需要合并k-1次，
//计算时间复杂度时使用N/k作为链表平均长度计算
ListNode* mergeKLists(vector<ListNode*>& lists) {
	if(lists.empty()) return nullptr;
	return merge(lists, 0, lists.size()-1);
}


int main(int argc, char const *argv[])
{
	
	return 0;
}