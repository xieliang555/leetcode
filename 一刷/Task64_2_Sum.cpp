#include<iostream>
using namespace std;

class A;
A* Array[2];

//递归思路，虚函数
class A{
public:
	virtual int sum(int n){
		return 0;
	}
};

class B : public A{
public:
	virtual int sum(int n){
		//关键
		return n+Array[!!n]->sum(n-1);
	}
};

int Sum_Solution(int n){
	A a;
	B b;
	Array[0]=&a;
	Array[1]=&b;
	int val=Array[1]->sum(n);
	return val;

}

int main(int argc, char const *argv[])
{
	
	return 0;
}