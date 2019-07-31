#include<iostream>

int LastRemaining_Solution(int n, int m){

	if(n<1 || m<1)
		return -1;
	if(n==0)
		return 0;
	int ret=0;
	for(int i=2;i<n;i++){
		//易写成%n
		ret=(ret+m)%i;
	}
	return ret;
}

int main(int argc, char const *argv[])
{

	return 0;
}