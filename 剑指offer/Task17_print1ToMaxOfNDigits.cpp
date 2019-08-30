#include<iostream>
#include<cstring>
using namespace std;


bool increment(char*);
void printNum(char*);


void print1ToMaxOfNDigits(int n){

	if(n<=0)
		return;

	char* number=new char[n+1];
	memset(number,'0',n);
	number[n]='\0';
	while(!increment(number))
		printNum(number);

	delete[] number;
}

bool increment(char* number){
	int length=strlen(number);
	int carry=0, sum=0;
	for(int i=length-1;i>=0;i--){
		sum=number[i]-'0'+carry;
		if(i==length-1){
			sum++;
		}
		if(sum>=10){
			if(i==0)
				return true;
			carry=1;
			sum-=10;
			number[i]=sum+'0';
		}
		else{
			number[i]=sum+'0';
			break;
		}
	}
	return false;
}

void printNum(char* number){
	while(*number=='0' && *number!='\0')
		number++;
	if(*number=='\0')
		return;
	else
		cout<<number<<' ';
}


int main(int argc, char const *argv[])
{
	print1ToMaxOfNDigits(2);
	return 0;
}
