#include<iostream>
#include<stack>
using namespace std;

/**
 * 剑指offer： 30
 *
 * 双栈，辅助栈的栈顶始终记录着当前最小值
 */

stack<int> s1, s2;

void push(int value) {
    s1.push(value);
    if(s2.empty() || value<=s2.top())
    	s2.push(value);
    else
    	s2.push(s2.top());
}

void pop() {
    s1.pop();
    s2.pop();
}

int top() {
    return s1.top();
}

int min() {
   return s2.top(); 
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}