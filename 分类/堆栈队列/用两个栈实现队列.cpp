#include<iostream>
#include<stack>
using namespace std;

/**
 * 剑指offer： 9
 *
 * 双栈实现，一个栈进，一个栈出
 */

stack<int> stack1, stack2;

void push(int node) {
    stack1.push(node);
}

int pop() {
    if(stack2.empty()){
    	while(!stack1.empty()){
    		stack2.push(stack1.top());
    		stack1.pop();
    	}
    }
    int ret=stack2.top();
    stack2.pop();
    return ret;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}

