//特殊输入和边界检测
#include<iostream>
#include<stack>
using namespace std;

class Task30_stackWithMin
{
public:
	Task30_stackWithMin(){}
	~Task30_stackWithMin(){}

	stack<int> s1;
	stack<int> s2;

	void push(int value){
		s1.push(value);
		if(s2.empty()||value<s2.top())
			s2.push(value);
		else
			s2.push(s2.top());
	}

	void pop(){
		s1.pop();
		s2.pop();
	}

	int top(){
		return s1.top();
	}

	int min(){
		return s2.top();
	}
	
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}