#include<iostream>
#include<vector>
using namespace std;


/**
 * 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 * 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，
 * 超过数组长度的一半，因此输出2。如果不存在则输出0。
 */


//此题除了快排外，还可以统计每一位数字出现的次数（辅助空间）将时间复杂度将为o(n)

int partition(vector<int>& , int, int);

int moreThanHalfNum(vector<int> nums){

	if(nums.empty()) return -1;
	int left=0; 
	int right=nums.size()-1;
	int mid=(left+right)/2;
	int idx=partition(nums, left, right);
	while(idx!=mid){
		if(idx>mid){
			right=idx-1;
			idx=partition(nums, left, right);
		}
		else{
			left=idx+1;
			idx=partition(nums, left, right);
		}
	}
	
	//检查位于中间的数是否超过一半
	int ret=nums[idx];
	int count=0;
	for(auto i: nums){
		if(i==ret)
			count++;
	}
	if(count>=(nums.size()+1)/2)
		return ret;
	else 
		return 0;
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
	vector<int> nums={1,2,3,2,5,4,2};
	cout<<moreThanHalfNum(nums)<<endl;

	return 0;
}