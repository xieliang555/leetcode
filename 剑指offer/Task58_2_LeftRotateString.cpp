#include<string>
#include<iostream>
using namespace std;

string LeftRotateString(string str, int n){
	if(n<0) return str; 
	if(n==0) return str;
	string strTmp=str.substr(0,n);
	str.erase(0,n);
	str+=strTmp;
	return str;
}


int main(int argc, char const *argv[])
{
	string a="abcdefg";
	cout<<LeftRotateString(a,8);
	return 0;
}