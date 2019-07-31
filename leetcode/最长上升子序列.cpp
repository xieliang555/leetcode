#include<iostream>
#include<vector>
using namespace std;

int getIdx(vector<int> dp, int num){
	int left=0;
	int right=dp.size()-1;
	while(left<=right){
		int mid=(left+right)/2;
		if(num==dp[mid])
			return mid;
		else if(num>dp[mid])
			left=mid+1;
		else
			right=mid-1;
	}
	return left;
}

int lengthOfLIS(vector<int>& nums){
	if(nums.empty()) return 0;
	vector<int> dp;
	dp.push_back(nums[0]);
	for(int i=1;i<nums.size();i++){
		if(nums[i]>dp.back())
			dp.push_back(nums[i]);
		else if(nums[i]<dp.back()){
			int idx=getIdx(dp, nums[i]);
			dp[idx]=nums[i];
		}
	}
	return dp.size();
}

int main(int argc, char const *argv[])
{
	vector<int>  nums={10,9,2,5,3,7,101,6};
	cout<<lengthOfLIS(nums)<<endl;
	return 0;
}