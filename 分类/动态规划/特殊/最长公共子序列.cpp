#include<iostream>
#include<string>
#include<vector>
using namespace std;

/**
 * OJ无此题
 * 程序员代码面试指南，左程云著
 *
 * dp[i][j]表示str1的前i个字符和str2的前j个字符的最长公共子序列
 *
 * 先利用dp计算最长公共子序列的长度，再利用dp数组得到最长公共子序列
 * 步骤：从dp数组右下角元素开始，如果dp[i][j]>max(dp[i][j-1],dp[i-1][j])，则该元素属于最长子序列，向左上角移动
 * 如果dp[i][j]==dp[i-1][j],向上移动
 * 如果dp[i][j]==dp[i][j-1],向左移动
 * 如果dp[i][j]==dp[i][j-1]==dp[i-1][j]，向上或向左移动
 *
 * 此题可拓展为求最长回文子序列
 */


void solution(string s1, string s2){

	//计算dp数组
	vector<vector<int> > dp(s1.size()+1);
	for(int i=0;i<s1.size()+1;i++)
		dp[i].resize(s2.size()+1);
	for(int i=1;i<=s1.size();i++){
		for(int j=1;j<=s2.size();j++){
			if(s1[i-1]==s2[j-1])
				dp[i][j]=1+dp[i-1][j-1];
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	int maxLen=dp.back().back();
	
	// 根据dp数组计算最长公共子序列
	char ret[20];
	int row=dp.size()-1;
	int col=dp[0].size()-1;
	while(row>=0 || col>=0){
		if(row>0 && dp[row][col]==dp[row-1][col])
			row--;
		else if(col>=0 && dp[row][col]==dp[row][col-1])
			col--;
		else{
			ret[--maxLen]=s1[row-1];
			row--;
			col--;
		}
	}
	cout<<ret<<endl;
}


int main(int argc, char const *argv[])
{
	string s1="abcda";
	string s2="adcba";
	solution(s1,s2);
	return 0;
}