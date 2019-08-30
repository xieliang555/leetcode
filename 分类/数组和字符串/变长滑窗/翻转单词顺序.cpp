#include<iostream>
#include<vector>
#include<string>
using namespace std;

/**
 * 剑指offer: 58
 * 此题难点在于灵活使用循环：for+while
 */

void Reverse(string& s, int left, int right){
	while(left<right){
		swap(s[left],s[right]);
		left++;
		right--;
	}
}

string ReverseSentence(string str){

	int left=0;
	Reverse(str, 0, str.size()-1);
	for(int i=0;i<str.size();){
		// i<str.size()易漏
		while(str[i]!=' ' && i<str.size())
			i++;
		Reverse(str, left, i-1);
		i++;
		left=i;
	}
	return str;
}

int main(int argc, char const *argv[])
{
	string s="abc d";
	cout<<ReverseSentence(s)<<endl;
	return 0;
}