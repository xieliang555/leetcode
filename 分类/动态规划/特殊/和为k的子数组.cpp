#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/**
 * leetcode: 560
 *
 * unordered_map<int, int> dp, 其中dp[i]表示累计和为i的个数
 */

int subarraySum(vector<int>& nums, int k) {
    
	unordered_map<int, int> dp;
	int accum=0;
	int ret=0;
	dp[0]=1;
	for(auto i: nums){
		accum+=i;
		if(dp[accum-k])
			ret+=dp[accum-k];
		dp[accum]++;
	}
	return ret;

}

int main(int argc, char const *argv[])
{
	vector<int> nums={1,1,1};
	cout<<subarraySum(nums, 2)<<endl;
	return 0;
}

