#include<iostream>
using namespace std;

//递归思想，位运算控制递归
int Sum_Solution(int n){
	int ret=n;
	n && (ret+=Sum_Solution(n-1));

	return ret;
}


//递归思想，函数模版？
template<int m> inline int SumTo(){ 
	return m + SumTo<m-1>(); 
}  

template<> inline int SumTo<1>(){
	return 1;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}