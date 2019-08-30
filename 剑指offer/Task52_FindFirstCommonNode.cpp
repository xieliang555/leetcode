#include<stack>
#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};

//方法1: 
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2){

	if(pHead1==nullptr || pHead2==nullptr) return nullptr;

	int len1=0, len2=0;
	ListNode* p1=pHead1;
	ListNode* p2=pHead2;
	while(p1!=nullptr){
		len1++;
		p1=p1->next;
	}
	while(p2!=nullptr){
		len2++;
		p2=p2->next;
	}
	int LenthDif=(len1<len2)?(len2-len1):(len1-len2);
	ListNode* pLong=(len1<len2)?pHead2:pHead1;
	ListNode* pShort=(len1<len2)?pHead1:pHead2;
	for(int i=0;i<LenthDif;i++)
		pLong=pLong->next;
	while(pLong!=nullptr && pShort!=nullptr){
		if(pLong==pShort)
			return pLong;
		pLong=pLong->next;
		pShort=pShort->next;
	}
	return nullptr;

}


//方法2:使用辅助栈,注意考虑多种边界情况
ListNode* FindFirstCommonNode2(ListNode* pHead1, ListNode* pHead2){

	if(pHead1==nullptr || pHead2==nullptr) return nullptr;

	stack<ListNode*> s1;
	stack<ListNode*> s2;
	while(pHead1!=nullptr){
		s1.push(pHead1);
		pHead1=pHead1->next;
	}
	while(pHead2!=nullptr){
		s2.push(pHead2);
		pHead2=pHead2->next;
	}

	if(s1.top()!=s2.top()) return nullptr;
	ListNode* ret=nullptr;
	while(!s1.empty() && !s2.empty()){
		if(s1.top()!=s2.top())
			return s1.top()->next;
		else{
			ret=s1.top();
			s1.pop();
			s2.pop();
		}
	}
	
	return ret;
}





int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}