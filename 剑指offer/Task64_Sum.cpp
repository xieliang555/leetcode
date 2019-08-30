#include<iostream>
using namespace std;

//非递归思路
class Task64_Sum
{
public:
	Task64_Sum(){
		N++;
		Sum+=N;
	}
	~Task64_Sum(){}
	static int getSum(){ return Sum; }
	static void reset(){N=0;Sum=0;}
private:
	static int N;
	static int Sum;
	
};

//非const的static成员变量需要在类外初始化
int Task64_Sum::N=0;
int Task64_Sum::Sum=0;

int Sum_Solution(int n){
	//需要复位，oj上是多组测试
	Task64_Sum::reset();
	//注意对象数组的定义
	Task64_Sum* a=new Task64_Sum[n];
	delete[] a;
	a=nullptr;
	//注意静态函数的调用不是Task64_Sum.getSum()
	return Task64_Sum::getSum();
}

int main(int argc, char const *argv[])
{
	cout<<Sum_Solution(5)<<endl;
	return 0;
}