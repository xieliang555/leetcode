#include<iostream>
#include<vector>
using namespace std;


/**
 * leetcode: 162
 *
 * 二分查找
 *
 * 注意本题两端均为-∞
 */

int findPeakElement(vector<int>& nums){

	int left=0;
	int right=nums.size()-1;
	while(left<right){
		int mid=(left+right)/2;
		if(nums[mid+1]>=nums[mid])
			left=mid+1;
		else
			right=mid;
	}
	return left;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}