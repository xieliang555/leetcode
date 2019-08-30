#include<iostream>
#include<vector>
#include<string>
using namespace std;

/**
 * 剑指offer: 48	
 * 牛客OJ不含此题
 *
 * 本题难点：在常规的dp数组基础上上，还需要额外的空间记录当前字符最近出现的下标
 * dp[i]表示以第i个字符结尾的最长不含重复字符的子串长度
 */



int longestSubstring(string s){
	if(s.empty()) return 0;
	vector<int> dp(s.size());
	dp[0]=1;
	vector<int> tmp(26,-1);
	tmp[s[0]-'a']=0;
	int maxLen=1;
	for(int i=1;i<dp.size();i++){
		if(tmp[s[i]-'a']==-1)
			dp[i]=1+dp[i-1];
		else if(i-tmp[s[i]-'a']<=dp[i-1])
			dp[i]=i-tmp[s[i]-'a'];
		else
			dp[i]=1+dp[i-1];
		tmp[s[i]-'a']=i;
		maxLen=max(maxLen, dp[i]);
	}
	return maxLen;
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
	return 0;
}