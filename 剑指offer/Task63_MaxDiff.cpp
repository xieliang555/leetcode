#include<vector>
#include<iostream>
using namespace std;

int maxDiff(vector<int> nums){
	if(nums.empty()) return -1;

	int min=nums[0];
	int ret=0;
	for(int i=1;i<nums.size();i++){
		if(nums[i]<min)
			min=nums[i];
		int diff=(nums[i]-min);
		if(diff>ret)
			ret=diff;
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	vector<int> a={9,11,8,5,7,12,16,14};
	cout<<maxDiff(a)<<endl;
	return 0;
}