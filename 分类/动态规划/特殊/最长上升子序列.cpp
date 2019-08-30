#include<iostream>
#include<vector>
using namespace std;

/**
 * leetcode: 300
 *  dp[i]表示最长上升子序列第i个数（应在遍历过程中始终维持最小）
 *  
 */

int binarySearch(vector<int>& nums, int target){
	int left=0;
	int right=nums.size()-1;
	while(left<=right){
		int mid=(left+right)/2;
		if(target==nums[mid])
			return mid;
		else if(target>nums[mid])
			left=mid+1;
		else
			right=mid-1;
	}
	return left;
}

int solution(vector<int>& nums){

	vector<int> dp;
	for(auto i:nums){
		if(dp.empty() || i>dp.back())
			dp.push_back(i);
		else{
			int idx=binarySearch(dp, i);
			dp[idx]=i;
		}
	}
	return dp.size();
}

int main(int argc, char const *argv[])
{
	vector<int> nums={10,9,2,5,3,7,101,18};
	cout<<solution(nums)<<endl;
	return 0;
}