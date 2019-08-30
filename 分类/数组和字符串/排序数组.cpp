#include<iostream>
#include<vector>
using namespace std;

/**
 * 给定一个整数数组 nums，将该数组升序排列。
 */

void recursionCore(vector<int>&, int, int);
int partition(vector<int>&, int, int);

vector<int> sortArray(vector<int>& nums){

	recursionCore(nums, 0, nums.size()-1);
	vector<int> ret=nums;
	return ret;
}

void recursionCore(vector<int>& nums, int left, int right){

	if(left>=right) return;
	int mid=partition(nums, left, right);
	recursionCore(nums, left, mid-1);
	recursionCore(nums,mid+1,right);

}

// 先利用三位取中，找到待排的数字放到数组第一位，
// 然后找到第一位应在的下标，并返回下标
int partition(vector<int>& nums, int left, int right){
	//三位取中
	int mid=(left+right)/2;
	if(nums[left]>nums[mid]) swap(nums[left],nums[mid]);
	if(nums[mid]>nums[right]) swap(nums[mid],nums[right]);
	if(nums[left]<nums[mid]) swap(nums[left],nums[mid]);

	int tmp=nums[left];
	while(left<right){
		while(left<right && nums[right]>=tmp) right--;
		nums[left]=nums[right];
		while(left<right && nums[left]<=tmp) left++;
		nums[right]=nums[left];
	}
	nums[left]=tmp;
	return left;
}


int main(int argc, char const *argv[])
{
	vector<int> nums={5,1,1,2,0,0};
	vector<int> ret=sortArray(nums);
	for(auto i:ret)
		cout<<i<<' ';
	return 0;
}