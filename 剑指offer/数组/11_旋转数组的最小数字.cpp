#include<iostream>
#include<vector>
using namespace std;

int findMin(vector<int>& nums) {
    
    int left=0; 
    int right=nums.size()-1;
    while(left<=right){
    	int mid=(left+right)/2;
    	if(nums[left]<=nums[right])
    		return nums[left];
    	else{
    		if(nums[mid]>=nums[left])
    			left=mid+1;
    		else
    			right=mid;
    	}
    }

    return nums[left];
}

int main(int argc, char const *argv[])
{
	vector<int> nums={4,5,6,7,0,1,2,3};
	cout<<findMin(nums)<<endl;
	return 0;
}