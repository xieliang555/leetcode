#include<iostream>
#include<vector>
using namespace std;

int getNumSameAsIndex(vector<int> nums){

	if(nums.empty()) return 0;
	int left=0,right=nums.size()-1;
	while(left<=right){
		int mid=(left+right)/2;
		if(nums[mid]<mid)
			left=mid+1;
		if(nums[mid]>mid)
			right=mid-1;
		if(nums[mid]==mid)
			return mid;
	}
	return -1;

}

int main(int argc, char const *argv[])
{
	vector<int> a={0,2,3,4};
	vector<int> a1={1,2,3};
	vector<int> a2={-1,0,2};
	cout<<getNumSameAsIndex(a2)<<endl;
	return 0;
}