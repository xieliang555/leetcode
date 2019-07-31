#include<iostream>
#include<vector>
using namespace std;

/**
 * 把数组所有0移到最后，其余相对顺序不变时间o(n)，空间o(1)
 */

void moveZeroes(vector<int>& nums){

	int newIdx=0;
	int oldIdx=0;
	while(oldIdx<nums.size()){
		if(nums[oldIdx])
			nums[newIdx++]=nums[oldIdx];
		oldIdx++;
	}
	while(newIdx<nums.size()){
		nums[newIdx++]=0;
	}
}

int main(int argc, char const *argv[])
{
	vector<int> nums={1,0,0,2,3,0,4};
	moveZeroes(nums);
	for(auto i:nums)
		cout<<i<<' ';
	return 0;
}