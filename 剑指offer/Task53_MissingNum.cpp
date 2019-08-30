#include<vector>
#include<iostream>
using namespace std;

int missingNum(vector<int> nums){


	if(nums.empty()) return 0;
	//当待查找的是0时会越界，故另外考虑
	if(nums[0]!=0) return 0;

	int left=0, right=nums.size()-1;
	while(left<=right){
		int mid=(left+right)/2;
		if(nums[mid]==mid)
			left=mid+1;
		else if(nums[mid-1]==mid)
			right=mid-1;
		else
			return mid;

	}
	return -1;
}

int main(int argc, char const *argv[])
{
	vector<int> a={0,1,3,4};
	cout<<missingNum(a)<<endl;
	return 0;
}