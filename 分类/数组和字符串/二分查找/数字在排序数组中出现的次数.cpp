#include<iostream>
#include<vector>
using namespace std;

/**
 * 剑指offer: 53_1
 * 二分查找
 *
 * 注意target需要定义为double而不是int
 */

int binarySearch(vector<int> data, double target){
	int left=0; 
	int right=data.size()-1;
	while(left<=right){
		int mid=(left+right)/2;
		if(data[mid]==target)
			return mid;
		else if(target>data[mid])
			left=mid+1;
		else
			right=mid-1;
	}
	return left;
}

int GetNumberOfK(vector<int> data, int k){

	return binarySearch(data, k+0.5)-binarySearch(data, k-0.5);
}

int main(int argc, char const *argv[])
{
	vector<int> data={1,2,3,3,3,3,4,5};
	cout<<GetNumberOfK(data, 3)<<endl;
	return 0;
}