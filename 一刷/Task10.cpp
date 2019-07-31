/**
 * 10
 */

#include<iostream>
using namespace std;


class Fibonacci
{
public:
	Fibonacci(){}
	~Fibonacci(){}

	int Fibonacci1(int n){
		if(n<=0) return 0;
		if(n==1) return 1;

		return Fibonacci1(n-1)+Fibonacci1(n-2);
	}

	int Fibonacci2(int n){
		if(n<=0) return 0;
		if(n==1) return 1;

		else{
			int tmp0=0;
			int tmp1=1;
			int tmp2;
			for(int i=2;i<=n;i++){
				tmp2=tmp0+tmp1;
				tmp0=tmp1;
				tmp1=tmp2;
			}
			return tmp2;
		}
	}
	
};

int main(int argc, char const *argv[])
{
	Fibonacci f1;
	cout<<f1.Fibonacci1(3)<<endl;
	cout<<f1.Fibonacci2(3)<<endl;
	return 0;
}