#include<iostream>
#include<cmath>
using namespace std;


int jumpFloorII(int number) {

	if(number<1) return 0;
	if(number==1) return 1;
	return pow(2,number-1);
}

int main(int argc, char const *argv[])
{
	int number=6;
	cout<<jumpFloorII(number);
	return 0;
}