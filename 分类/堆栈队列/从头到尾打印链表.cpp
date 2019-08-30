#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/**
 * 剑指offer： 6
 */

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};


vector<int> printListFromTailToHead(ListNode* head) {
    stack<ListNode*> s;
    vector<int> ret;
    while(head){
    	s.push(head);
    	head=head->next;
    }
    while(!s.empty()){
    	ret.push_back(s.top()->val);
    	s.pop();
    }
    return ret;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}