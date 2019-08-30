#include<iostream>
#include<cmath>
using namespace std;

//区分输出的0是正常输出还是无效输出
bool g_InvalidInput=false;
double powerWithUnsignedExponent(double base, int exponent);


double Power(double base, int exponent){

	g_InvalidInput=false;

	// 此处不考虑大数问题故可以用==判断double
	if(base==0.0 && exponent<=0){
		g_InvalidInput=true;
		return 0;
	}

	double result=1;
	for(int i=1;i<=abs(exponent);i++)
		result*=base;

	if(exponent<0)
		result=1.0/result;

	return result;
}

double Power2(double base, int exponent){

	g_InvalidInput=false;

	if(base==0.0 && exponent<=0){
		g_InvalidInput=true;
		return 0;
	}

	double result=1;
	result=powerWithUnsignedExponent(base,abs(exponent));

	if(exponent<0)
		result=1.0/result;

	return result;

}

//使用递归解
double powerWithUnsignedExponent(double base, int exponent){
	if(exponent==0) return 1;
	if(exponent==1) return base;

	double result=powerWithUnsignedExponent(base,exponent>>1);
	result*=result;
	if((exponent & 0x1) ==1)
		result*=base;

	return result;
}


int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}