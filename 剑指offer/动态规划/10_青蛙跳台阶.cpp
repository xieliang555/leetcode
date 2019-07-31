#include<iostream>
using namespace std;


int jumpFloor(int number){
	if(number<1) return 0;
	if(number==1) return 1;
	if(number==2) return 2;
	int prepre=1;
	int pre=2;
	int cur;
	for(int i=3;i<=number;i++){
		cur=prepre+pre;
		prepre=pre;
		pre=cur;
	}
	return cur;
}

int main(int argc, char const *argv[])
{
	int number=5;
	cout<<jumpFloor(number)<<endl;
	return 0;
}