#include<iostream>
#include<vector>
using namespace std;


/**
 * 剑指offer: 11
 *
 * 二分查找
 *
 * 此题难点在于可能存在重复数，如1 0，1，1，1
 *
 * 思路：每一次循环中间数和右端比较：
 * 当中间数大于右端，此时可以确定中间数在左半部分，则left=mid+1;
 * 当中间数等于右端，此时无法判断中间数在左半部分还是右半部分，只能确定右端>=最小值，故right--
 * 当中间数小于右端，此时可以确定中间数一定在有半部分，故right=mid
 *
 */

int minNumberInRotateArray(vector<int> rotateArray){
	if(rotateArray.empty()) return 0;
	int left=0;
	int right=rotateArray.size()-1;
	while(left<right){
		int mid=(left+right)/2;
		if(rotateArray[mid]>rotateArray[right])
			left=mid+1;
		else if(rotateArray[mid]==rotateArray[right])
			right--;
		else
			right=mid;
	}
	return rotateArray[left];
}

int main(int argc, char const *argv[])
{
	vector<int> v={1,0,1,1,1};
	cout<<minNumberInRotateArray(v)<<endl;
	return 0;
}