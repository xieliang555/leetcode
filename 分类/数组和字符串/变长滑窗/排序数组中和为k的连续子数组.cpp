#include<iostream>
#include<vector>
using namespace std;

/**
 * OJ无此题
 * 求无序数组和为k的连续子数组个数
 * 此题难点在于灵活使用循环: for+while
 */

int subarraySum(vector<int>& nums, int k){

	int slow=0;
	int Sum=0;
	int count=0;
	for(int i=0;i<nums.size();){
		Sum+=nums[i];
		if(Sum==k){
			count++;
			// 最好提前减掉简化后面的步骤
			Sum-=nums[slow];
			slow++;
			i++;
		}
		else if(Sum>k){
			while(Sum>k && slow<=i){
				Sum-=nums[slow];
				slow++;
			}
			if(Sum==k)
				count++;
			i++;
		}
		else
			i++;
	}

	return count;
}

int main(int argc, char const *argv[])
{
	vector<int> nums={1,2,3,4,5,6};
	cout<<subarraySum(nums,6)<<endl;
	return 0;
}