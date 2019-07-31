#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/**
 * 要求时间复杂度是o(n)
 */

// 有序数组
int pairsOfSumK(vector<int> nums, int k){

	int left=0; 
	int right=nums.size()-1;
	int count=0;
	while(left<right){
		int sum=nums[left]+nums[right];
		if(sum==k){
			count++;
			left++;
		}
		else if(sum>k)
			right--;
		else
			left++;
	}
	return count;
}

//无序数组
int pairsOfSumK2(vector<int> nums, int k){

	unordered_map<int, int> um;
	for(auto i:nums)
		um[i]+=1;
	int count=0;
	for(auto i:nums){
		if(um[k-i])
			count++;
	}
	return count/2;
}

int main(int argc, char const *argv[])
{ 
	vector<int> nums={1,2,4,5,6};
	cout<<pairsOfSumK(nums,6)<<endl;
	vector<int> nums2={2,1,4,5,6};
	cout<<pairsOfSumK2(nums2,6)<<endl;

	return 0;
}