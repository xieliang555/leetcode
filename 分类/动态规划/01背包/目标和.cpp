#include<iostream>
#include<vector>
using namespace std;

/**
 * leetcode :494
 * 动态规划：0-1背包问题
 * 装满背包的方案数问题（子集和）
 * 此题需要转换一下问题：设所有正数的和为p，所有负数的和的绝对值为n，目标为target
 * 则p-n=target, p+n=sum; 解得p=(sum+target)/2， 即从背包中选出k个物品，使他们的和为p
 * dp[i][j]表示前i个数的和为j的方案数，使用一维滚动数组
 */

int findTargetSumWays(vector<int>& nums, int S){

	int Sum=0;
	for(auto i:nums)
		Sum+=i;
	int target=(Sum+S)/2;
	if(Sum<S || (Sum+S)%2==1) return 0;
	vector<int> dp_pre(target+1);
	vector<int> dp_cur(target+1);
	dp_pre[0]=1;
	for(int i=0;i<nums.size();i++){
		for(int j=0;j<dp_cur.size();j++){
			if(j>=nums[i]){
				dp_cur[j]=dp_pre[j]+dp_pre[j-nums[i]];
			}
			else
				dp_cur[j]=dp_pre[j];
		}
		dp_pre=dp_cur;

		for(auto i:dp_cur)
			cout<<i<<' ';
		cout<<endl;
	}
	return dp_cur.back();
}

int main(int argc, char const *argv[])
{
	vector<int> nums={1,1,1,1,1};
	cout<<findTargetSumWays(nums, 3)<<endl;
	return 0;
}

