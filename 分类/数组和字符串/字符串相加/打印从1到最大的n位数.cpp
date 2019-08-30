#include<iostream>
#include<vector>
#include<string>
using namespace std;

/**
 * 剑指offer: 17
 * OJ无此题
 *
 * string的长度为n可以提前确定，高位0不用输出
 */

string add(string& s){

	int carry=0;
	int a=1;
	for(int i=s.size()-1;i>=0;i--){
		int sum=s[i]-'0'+a+carry;
		a=0;
		if(sum<10){
			s[i]=sum+'0';
			carry=0;
		}
		else{
			s[i]=sum%10+'0';
			carry=sum/10;
		}
	}

	return s;
}

void print1ToMaxOfNDigits(int n){
	string s(n,'0');
	string endNum=string(n,'9');
	while(s!=endNum){
		string ret=add(s);
		for(auto i:ret)
			if(i!='0')
				cout<<i;
		cout<<' ';
	}

}

int main(int argc, char const *argv[])
{
	print1ToMaxOfNDigits(3);
	return 0;
}