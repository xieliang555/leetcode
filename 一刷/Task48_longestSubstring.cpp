#include<string>
#include<iostream>
using namespace std;


//时间复杂度o(n)，需要额外的空间
int longestSubstring(string s){
	int arr[26];
	for(int i=0;i<26;i++)
		arr[i]=-1;

	int maxLength=0;
	int curLength=0;
	for(int i=0;i<s.length();i++){
		int index=s[i]-'a';
		if(arr[index]<0 || (i-arr[index])>curLength){
			curLength++;
			arr[index]=i;
		}
		else{
			curLength=i-arr[index];
			arr[index]=i;
		}

		if(maxLength<curLength)
			maxLength=curLength;

	}

	return maxLength;
}


//时间复杂度o(n^2), 不需要额外空间
int longestSubstring1(string s){
	if(s.size()<=0) return 0;
	int maxLength=1;
	int curLength=1;
	int startIndx=0;
	for(int i=1;i<s.size();i++){
		for(int j=startIndx;j<i;j++){
			if(s[i]==s[j])
				startIndx=j+1;
		}
		curLength=i-startIndx+1;
		if(curLength>maxLength)
			maxLength=curLength;
	}
	return maxLength;
}




int main(int argc, char const *argv[])
{
	cout<<"method 1"<<endl;
	cout<<longestSubstring("arabcacfr")<<endl;
	cout<<longestSubstring("acfrarabc")<<endl;
	cout<<longestSubstring("arabcacfr")<<endl;
	cout<<longestSubstring("aaaa")<<endl;
	cout<<longestSubstring("abcdefg")<<endl;
	cout<<longestSubstring("aaabbbccc")<<endl;
	cout<<longestSubstring("abcdcba")<<endl;
	cout<<longestSubstring("abcdaef")<<endl;
	cout<<longestSubstring("a")<<endl;
	cout<<longestSubstring("")<<endl;

	cout<<"method 2"<<endl;
	cout<<longestSubstring1("arabcacfr")<<endl;
	cout<<longestSubstring1("acfrarabc")<<endl;
	cout<<longestSubstring1("arabcacfr")<<endl;
	cout<<longestSubstring1("aaaa")<<endl;
	cout<<longestSubstring1("abcdefg")<<endl;
	cout<<longestSubstring1("aaabbbccc")<<endl;
	cout<<longestSubstring1("abcdcba")<<endl;
	cout<<longestSubstring1("abcdaef")<<endl;
	cout<<longestSubstring1("a")<<endl;
	cout<<longestSubstring1("")<<endl;
	return 0;
}