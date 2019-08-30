#include<iostream>
#include<vector>
using namespace std;

/**
 * leetcode 33
 *
 * 可以假设不存在重复数字
 *
 * 二分查找
 *
 * 步骤
 * 1）先确定中间数在左半部分还是右半部分
 * 2）在1）的基础上缩小范围
 */

int search(vector<int>& nums, int target) {
    
    int left=0;
    int right=nums.size()-1;
    while(left<=right){
    	int mid=(left+right)/2;
    	if(nums[mid]==target)
    		return mid;
    	else if(nums[mid]<=nums[right]){
    		if(target>nums[mid] && target<=nums[right])
    			left=mid+1;
    		else
    			right=mid-1;
    	}
    	else{
    		if(target<nums[mid] && target>=nums[left])
    			right=mid-1;
    		else
    			left=mid+1;
    	}
    }
    return -1;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}