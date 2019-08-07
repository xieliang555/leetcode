#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    
    int count=0;
    int accum=0;
    unordered_map<int, int> um;
    um[0]=1;
    for(auto i:nums){
    	accum+=i;
    	if(um[accum-k])
    		count+=um[accum-k];
    	um[accum]++;

    }
    return count;
}

int main(int argc, char const *argv[])
{
	vector<int> nums={1,1,1};
	cout<<subarraySum(nums,0)<<endl;
	return 0;
}