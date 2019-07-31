#include<iostream>
using namespace std;


int Min(int num1, int num2, int num3){
	int min=(num1<num2)?num1:num2;
	min=(min<num3)?min:num3;
	return min;
}

int uglyNum(int index){

	if(index<=0) return 0;

	// 直接通过简单例子确认要创建多大的数组
	int* pUglyNum=new int[index];
	pUglyNum[0]=1;

	 // 确定初始值后，往后每次+1，不需要通过繁琐的下标计算来确认
	 int* pMultiply2=pUglyNum;
	 int* pMultiply3=pUglyNum;
	 int* pMultiply5=pUglyNum;

	 // while需要繁琐的下标计算，用for直接统计循环次数
	 for(int i=1;i<index;i++){
	 	int min=Min((*pMultiply2)*2, (*pMultiply3)*3, (*pMultiply5)*5);
	 	pUglyNum[i]=min;

	 	if(min==(*pMultiply2)*2)
	 		pMultiply2++;
	 	if(min==(*pMultiply3)*3)
	 		pMultiply3++;
	 	if(min==(*pMultiply5)*5)
	 		pMultiply5++;
	 }

	 // 数组最后一个元素index-1而不是index
	 int uglyNum=pUglyNum[index-1];
	 delete[] pUglyNum;
	 return uglyNum;
}

int main(int argc, char const *argv[])
{
	cout<<uglyNum(1)<<endl;
	return 0;
}
