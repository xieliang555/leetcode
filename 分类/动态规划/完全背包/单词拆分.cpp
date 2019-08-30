#include<iostream>
#include<vector>
#include<string>
using namespace std;

/**
 * leetcode: 139
 *
 * 动态规划： 完全背包问题
 * dp[i]表示前i个字符组成的字符串是否可以被背包中的单词拆分
 */

bool wordBreak(string s, vector<string>& wordDict){

	vector<int> dp(s.size()+1);
	dp[0]=1;
	for(int i=1;i<dp.size();i++){
		for(auto word:wordDict){
			if(i>=word.size() && s.substr(i-word.size(),word.size())==word){
				// 容易遗忘 || dp[i], 每一个符合要求的word都必须要尝试
				dp[i]=dp[i-word.size()] || dp[i];
			}
		}
	}
	return dp.back();
}

int main(int argc, char const *argv[])
{
	vector<string> wordDict={"apple", "pen"};
	string s="applepenapple";
	cout<<wordBreak(s,wordDict)<<endl;
	return 0;
}