#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/**
 * 牛客
 * 可将问题转化为求字符串和反转字符串的最长公共子序列长度
 * dp[i][j]表示s1的前i个字符和s2的前j个字符的最长公共子序列长度（记）
 */


void solution(string s){

	string s_r=s;
	reverse(s_r.begin(),s_r.end());
	vector<vector<int> > dp(s.size()+1);
	for(int i=0;i<=s.size();i++)
		dp[i].resize(s.size()+1);
	for(int i=1;i<=s.size();i++){
		for(int j=1;j<=s.size();j++){
			if(s[i-1]==s_r[j-1])
				dp[i][j]=1+dp[i-1][j-1];
			else
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}
	}
	cout<<s.size()-dp.back().back()<<endl;
}

int main(int argc, char const *argv[])
{
	string s;
	while(cin>>s)
		solution(s);
	return 0;
}