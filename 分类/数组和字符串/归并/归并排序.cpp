#include<iostream>
#include<vector>
using namespace std;

/**
 * leetcode: 215, 数组中的第K个最大元素, 利用归并法求
 */


void merge(vector<int>& nums, int left, int right){

	int mid=(left+right)/2;
	vector<int> tmp=nums;
	int idx1=left;
	int idx2=mid+1;
	int idx3=left;
	while(idx1<=mid && idx2<=right){
		if(tmp[idx1]<=tmp[idx2])
			nums[idx3++]=tmp[idx1++];
		else
			nums[idx3++]=tmp[idx2++];
	}
	while(idx1<=mid)
		nums[idx3++]=tmp[idx1++];
	while(idx2<=right)
		nums[idx3++]=tmp[idx2++];
}

void recursionCore(vector<int>& nums, int left, int right){
	if(left>=right) return;
	int mid=(left+right)/2;
	recursionCore(nums, left, mid);
	recursionCore(nums, mid+1, right);
	merge(nums, left, right);

}

int findKthLargest(vector<int>& nums, int k){

	recursionCore(nums, 0, nums.size()-1);
	return nums[nums.size()-k];
}

int main(int argc, char const *argv[])
{
	vector<int> nums={2,4,1,5,3};
	cout<<findKthLargest(nums,5)<<endl;
	return 0;
}