#include<iostream>
#include<vector>
using namespace std;

/**
 * leetcode: 69
 *
 * 标准的二分查找
 */

int mySqrt(int x){

	int left=0;
	int right=x;
	while(left<=right){
		int mid=(left+right)/2;
		if(mid*mid==x)
			return mid;
		else if(mid*mid>x)
			right=mid-1;
		else
			left=mid+1;
	}
	return right;
}

int main(int argc, char const *argv[])
{
	cout<<mySqrt(8)<<endl;
	return 0;
}