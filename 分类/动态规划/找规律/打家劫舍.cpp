#include<iostream>
#include<vector>
using namespace std;

/**
 * leetcode：198
 * 动态规划： 计算前几个数找状态转移方程
 * dp[i]表示前i家最多能抢到多少钱
 */

int rob(vector<int>& nums) {

	if(nums.empty()) return 0;
	if(nums.size()==1) return nums[0];
    
    vector<int> dp(nums.size());
    dp[0]=nums[0];
    dp[1]=max(dp[0],nums[1]);
    for(int i=2;i<nums.size();i++){
    	dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
    }
    return dp.back();
}

int main(int argc, char const *argv[])
{
	vector<int> nums={2,7,9,3,1};
	cout<<rob(nums)<<endl;
	return 0;
}

