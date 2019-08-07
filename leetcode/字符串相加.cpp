#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string addStrings(string num1, string num2) {
    
    string s;
    int idx1=num1.size()-1;
    int idx2=num2.size()-1;
    // 要注意初始化，否则为随机数
    int curBit=0;
    while(idx1>=0 || idx2>=0 || curBit!=0){
    	if(idx1>=0)
    		curBit+=num1[idx1--]-'0';
    	if(idx2>=0)
    		curBit+=num2[idx2--]-'0';
    	s+=to_string(curBit%10);
    	curBit/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}

int main(int argc, char const *argv[])
{
	
	string s1="123";
	string s2="11111";
	cout<<addStrings(s1,s2)<<endl;
	return 0;
}