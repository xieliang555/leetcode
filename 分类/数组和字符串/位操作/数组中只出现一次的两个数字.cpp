#include<iostream>
#include<vector>
using namespace std;

/**
 * 剑指offer: 56_1
 *
 * 本题思路和难点在于如何将这两个数字分到两个不同的数组，然后分别在两个数组中找只出现一次的数字
 */

void FindNumsAppearOnce(vector<int> data, int* num1, int* num2){

	int result=0;
	for(auto i:data){
		result^=i;
	}
	int bit=1;
	while(!(bit & result)){
		bit<<=1;
	}
	*(num1)=0;
	*(num2)=0;
	for(auto i:data){
		if(i&bit)
			(*num1)^=i;
		else
			(*num2)^=i;
	}
}

int main(int argc, char const *argv[])
{
	vector<int> data={2,4,3,6,3,2,5,5};
	int a=0;
	int b=0;
	int* num1=&a;
	int* num2=&b;
	FindNumsAppearOnce(data, num1, num2);
	cout<<*num1<<' '<<*num2<<endl;
	return 0;
}

