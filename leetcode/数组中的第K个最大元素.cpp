#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int findKthLargest(vector<int>& nums, int k){

	if(nums.empty()) return -1;

	priority_queue<int, vector<int>, greater<int> > pq;
	for(auto i:nums){
		if(pq.size()<k){
			pq.push(i);
		}
		else{
			if(i>pq.top()){
				pq.pop();
				pq.push(i);
			}
		}
	}
	return pq.top();
}

int main(int argc, char const *argv[])
{
	vector<int> nums={3,6,3,4,7,8,5};
	cout<<findKthLargest(nums,4)<<endl;
	return 0;
}