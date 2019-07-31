#include<iostream>
using namespace std;


//递归思想，函数指针
typedef int (*pFun)(int);

int Sum_Termination(int n){
	return 0;
}

int Sum_Solution(int n){
	//静态成员只初始化一次
	static pFun f[2]={Sum_Termination,Sum_Solution};
	return f[!!n](n-1)+n;
}

int main(int argc, char const *argv[])
{
	cout<<Sum_Solution(5)<<endl;

	return 0;
}