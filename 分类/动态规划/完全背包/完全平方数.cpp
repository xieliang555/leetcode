#include<iostream>
#include<vector>
#include<climits>
using namespace std;

/**
 * leetcode : 279
 * 完全背包问题：每个物品可以无限使用
 * 完全背包+贪心，第二重循环只需要考虑完全平方数（背包里的物品），而不是所有数
 * dp[i]表示target为i时最小的完全平方数个数
 */

int numSquares(int n){

	vector<int> dp(n+1, INT_MAX);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j*j<=i;j++){
			if(j*j==i)
				dp[i]=1;
			else
				dp[i]=min(dp[i],dp[j*j]+dp[i-j*j]);
		}
	}

	return dp.back();
}

int main(int argc, char const *argv[])
{
	cout<<numSquares(13)<<endl;
	return 0;
}

