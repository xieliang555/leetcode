#include<vector>
#include<iostream>
#include<climits>
using namespace std;

/** 
 * leetcode: 322
 * 动态规划，完全背包问题，每个物品可以无限使用 完全背包问题的dp数组的形式不确定，需根据实际情况确定
 * 完全背包+贪心，第二重循环只需要考虑可兑换的零钱（背包里的物品），而不是所有数
 * dp[i]表示amount为i时最少需要硬币个数
 */

int coinChange(vector<int>& coins, int amount){

	vector<int> dp(amount+1,INT_MAX);
	dp[0]=0;
	for(int i=1;i<=amount;i++){
		for(auto coin:coins){
			if(i>=coin && dp[i-coin]!=INT_MAX){
				dp[i]=min(dp[i],1+dp[i-coin]);
			}
		}
	}

	if(dp.back()!=INT_MAX) 
		return dp.back();
	else 
		return -1;
}

int main(int argc, char const *argv[])
{
	vector<int> nums={2,3,5};
	cout<<coinChange(nums, 11)<<endl;
	return 0;
}