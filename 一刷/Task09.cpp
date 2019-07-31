#include<iostream>
#include<stack>

//一个栈是入口，一个栈是出口

class Task9
{
public:
	Task9(){}
	~Task9(){}

	void push(int node){
		stack1.push(node);
	}

	int pop(){
		int tmp;
		if(stack2.empty()){
			while(!stack1.empty()){
				tmp=stack1.top();
				stack2.push(tmp);
				stack1.pop();
			}
		}
		tmp=stack2.top();
		stack2.pop();
		return tmp;
	}
	
private:
	stack<int> stack1;
	stack<int> stack2;

};