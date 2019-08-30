#include<iostream>
using namespace std;

int Add(int num1, int num2){
	if(num1==0) return num2;
	if(num2==0) return num1;

	int sum, carry;
	while(num2){
		sum=num1^num2;
		carry=(num1 & num2)<<1;
		num2=carry;
		num1=sum;
	}
	return num1;
}

int main(int argc, char const *argv[])
{
	cout<<Add(1,2)<<endl;
	return 0;
}