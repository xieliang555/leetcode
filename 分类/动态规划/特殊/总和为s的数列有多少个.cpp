#include<iostream>
#include<vector>
using namespace std;

/**
 *
 * OJ无此题
 * 
 * 给定两个正整数N和S,你需要找出所有的长度为N的正整数数列中，满足单调递增以及总和为S的数列有多少个
 * 共一行，两个整数N和S. (1<N, s < 10000)
 *
 * 利用动态规划： dp[i][j]表示长度为i和为j的序列个数
 */


void solution(int n, int s){

	vector<vector<int> > dp(n+1);
	for(int i=0;i<=n;i++)
		dp[i].resize(s+1);
	for(int i=0;i<=n;i++)
		dp[i][0]=1;
	dp[1][1]=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=s;j++){
			if(j>=i)
				dp[i][j]=dp[i-1][j]+dp[i-1][j-i];
			else
				dp[i][j]=dp[i-1][j];
		}
	}

	cout<<dp.back().back()<<endl;

}

int main(int argc, char const *argv[])
{
	solution(4,4);
	return 0;
}

