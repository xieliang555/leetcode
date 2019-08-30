#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/**
 * 6 
 */

class ListNode{
public:
	int val;
	ListNode* next;
	ListNode(){};
	ListNode(int x):val(x),next(nullptr){}
};

class ReversePrintList
{
public:
	ReversePrintList(){};
	~ReversePrintList(){};

	// recursion solution
	vector<int>& recursion(ListNode* head,vector<int>& numbers){
		if(head->next!=nullptr){
			recursion(head->next,numbers);
		}
		numbers.push_back(head->val);
		return numbers;
	}

	// stack solution
	vector<int> stack(ListNode* head){
		vector<int> v;
		//当类型与函数名相同需要加上std::表示所属
		std::stack<int> s;
		while(head!=nullptr){
			s.push(head->val);
			head=head->next;
		}
		while(!s.empty()){
			v.push_back(s.top());
			s.pop();
		}
		return v;
	}
};

void recursionTest(){
	cout<<"recursion test:"<<endl;
	vector<int> m;
	ListNode l1(1);
	ListNode l2(2);
	ListNode l3(3);
	l1.next=&l2;
	l2.next=&l3;
	ReversePrintList r;
	r.recursion(&l1,m);
	for(int i=0;i<m.size();i++)
		cout<<m[i]<<' ';
	cout<<endl;
}

void stackTest(){
	cout<<"stack test:"<<endl;
	vector<int> m;
	ListNode l1(1);
	ListNode l2(2);
	ListNode l3(3);
	l1.next=&l2;
	l2.next=&l3;
	ReversePrintList r;
	vector<int> n=r.stack(&l1);
	for(int i=0;i<n.size();i++)
		cout<<n[i]<<' ';
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	recursionTest();
	stackTest();
	return 0;
}