#include<iostream>
#include<string>
#include<vector>
using namespace std;

/**
 * OJ无此题
 * 程序员代码面试指南，左程云著
 *
 * dp[i][j]表示以str1的第i个字符和str2的第j个字符结尾的最长公共子串长度，如果str[i]!=str[j]，则dp[i][j]=0
 *
 * 先利用dp计算最长公共子串的长度，再利用dp数组得到最长公共子串
 * 步骤：
 * 遍历dp数组，找到最大的数字即最长子串的长度，该数字对应的字符即为最长子串末尾的字符
 *
 * 此题可拓展为求最长回文子串
 */

void solution(string s1, string s2){

	// 计算dp数组
	vector<vector<int> > dp(s1.size()+1);
	for(int i=0;i<dp.size();i++)
		dp[i].resize(s2.size()+1);
	for(int i=1;i<dp.size();i++){
		for(int j=1;j<dp[0].size();j++){
			if(s1[i-1]==s2[j-1])
				dp[i][j]=1+dp[i-1][j-1];
		}
	}

	int maxLen=0;
	int endIdx;
	// 根据dp数组计算最长公共子串
	for(int i=1;i<dp.size();i++){
		for(int j=1;j<dp[0].size();j++){
			if(dp[i][j]>maxLen){
				maxLen=dp[i][j];
				endIdx=i;
			}
		}
	}
	cout<<s1.substr(endIdx-maxLen, maxLen)<<endl;
}

int main(int argc, char const *argv[])
{
	string s1="abcde";
	string s2="bebcd";
	solution(s1,s2);
	return 0;
}