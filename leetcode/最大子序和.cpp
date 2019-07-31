#include<iostream>
#include<vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    if(nums.empty()) return -1;
    if(nums.size()==1) return nums[0];
    int pre=nums[0];
    int cur;
    int ret=pre;
    for(int i=1;i<nums.size();i++){
    	cur=max(nums[i],nums[i]+pre);
    	ret=max(ret, cur);
    	pre=cur;
    }
    return ret;
}

int main(int argc, char const *argv[])
{
	vector<int> v={-2,1,-3,4,-1,2,1,-5,4};
	cout<<maxSubArray(v);
	return 0;
}

