#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums, int target) {
    
    int left=0;
    int right=nums.size()-1;
    while(left<=right){
    	int mid=(left+right)/2;
    	if(target==nums[mid]) 
    		return mid;
    	else if(nums[left]<=nums[mid]){
    		if(target<nums[mid] && target>=nums[left])
    			right=mid-1;
    		else
    			left=mid+1;
    	}
    	else{
    		if(target>nums[mid] && target<=nums[right])
    			left=mid+1;
    		else
    			right=mid-1;
    	}
    }
    return -1;
}

int main(int argc, char const *argv[])
{
	vector<int> nums={4,5,6,7,0,1,2,3};
	cout<<search(nums, 9)<<endl;
	return 0;
}