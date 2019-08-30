#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

/**
 * OJ无此题
 */

void solution(string s1, string s2){

	if(s1.size()<s2.size()){
		swap(s1,s2);
	}
	else if(s1.size()==s2.size() && s1<s2)
		swap(s1,s2);
	int idx1=s1.size()-1;
	int idx2=s2.size()-1;
	int carry=0;
	string ret;
	int result;
	while(idx2>=0){
		if((s1[idx1]-s2[idx2])>=carry){
			result=s1[idx1--]-s2[idx2--]-carry;
			carry=0;
		}
		else{
			result=s1[idx1--]-s2[idx2--]-carry+10;
			carry=1;
		}
		ret+=to_string(result);
	}
	while(idx1>=0){
		result=s1[idx1--]-'0'-carry;
		ret+=(to_string(result));
	}
	while(ret.back()=='0')
		ret.pop_back();
	reverse(ret.begin(),ret.end());
	if(ret.empty()) ret="0";
	cout<<ret<<endl;
}

int main(int argc, char const *argv[])
{
	string s1="1884";
	string s2="1885";
	solution(s1,s2);
	return 0;
}