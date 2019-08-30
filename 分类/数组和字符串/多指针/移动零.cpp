#include<iostream>
#include<vector>
using namespace std;

/**
 * leetcode: 283
 */

void moveZeroes(vector<int>& nums){

	int fast=0;
	int slow=0;
	while(fast<nums.size()){
		if(nums[fast]!=0){
			nums[slow++]=nums[fast];
		}
		fast++;
	}
	while(slow<nums.size())
		nums[slow++]=0;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}