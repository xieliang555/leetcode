#include<iostream>
#include<cstring>
using namespace std;

void print1ToMaxOfNDigits(char*,int);
void printNum(char*);

void solution(int n){

	if(n<=0) return;

	char* number=new char[n+1];
	memset(number,'0',n);
	number[n]='\0';

	for(int i=0;i<=9;i++){
		number[0]=i+'0';
		print1ToMaxOfNDigits(number,0);
	}

	delete[] number;
}

void print1ToMaxOfNDigits(char* number, int index){
	if(index==strlen(number)-1){
		printNum(number);
		return;
	}
	for(int i=0;i<=9;i++){
		number[index+1]=i+'0'; 
		print1ToMaxOfNDigits(number,index+1);
	}
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
	solution(3);
	return 0;
}