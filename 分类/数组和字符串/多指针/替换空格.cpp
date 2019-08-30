#include<iostream>
#include<string>
using namespace std;

/**
 * 剑指offer: 5
 */

string replaceSpace(string s){

	int len=s.size();
	for(auto i:s){
		if(i==' ')
			len+=2;
	}

	string ret(len,' ');
	int idx0=s.size()-1;
	int idx1=ret.size()-1;
	while(idx0>=0){
		if(s[idx0]!=' ')
			ret[idx1--]=s[idx0--];
		else{
			idx0--;
			ret[idx1--]='0';
			ret[idx1--]='2';
			ret[idx1--]='%';
		}
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	string s="we are happy";
	cout<<replaceSpace(s)<<endl;
	return 0;
}