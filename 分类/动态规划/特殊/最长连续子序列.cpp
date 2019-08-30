#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/**
 * leetcode: 128
 * 动态规划：额外空间 map<int, int> 遍历每一个数字时，找到该数字所处的连续序列的两个端点下标，
 * 将该数字和两个端点的值更新为连续序列长度
 *
 * 本题易错：注意考虑存在重复数的特例
  */
 
int longestConsecutive(vector<int>& nums){

	unordered_map<int, int> um;
	int maxLen=0;
	for(auto i:nums){
		if(um[i]==0){
			int leftDis=um[i-1];
			int rightDis=um[i+1];
			int len=leftDis+1+rightDis;
			um[i]=len;
			um[i-leftDis]=len;
			um[i+rightDis]=len;
			maxLen=max(maxLen, len);
		}
	}
	return maxLen;
}

int main(int argc, char const *argv[])
{
	vector<int> nums={100, 4, 200, 1, 3, 4, 2};
	cout<<longestConsecutive(nums)<<endl;
	return 0;
}