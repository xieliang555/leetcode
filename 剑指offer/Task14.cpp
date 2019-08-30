#include<iostream>
#include<cmath>
using namespace std;

class Task14
{
public:
	Task14(){}
	~Task14(){}

	int dp(int length){
		if(length<2)  return 0;
		if(length==2) return 1;
		if(length==3) return 2;

		int* product=new int[length+1];
		product[0]=0;
		product[1]=1;
		product[2]=2;
		product[3]=3;

		int max;

		for(int i=4;i<=length;i++){
			max=0;
			for(int j=1;j<=i/2;j++)
				if(product[j]*product[i-j]>max)
					max=product[j]*product[i-j];
			product[i]=max;
		}

		max=product[length];
		delete[] product;
		return max;
	}

	int greedy(int length){
		if(length<2)  return 0;
		if(length==2) return 1;
		if(length==3) return 2;

		int timeOf3=length/3;
		if(length-timeOf3*3 ==1){
			timeOf3-=1;
		}
		int timeOf2=(length-3*timeOf3)/2;
		return (int)(pow(3,timeOf3))*(int)(pow(2,timeOf2));
	}
	
};

int main(int argc, char const *argv[])
{
	Task14 t;
	return 0;
}