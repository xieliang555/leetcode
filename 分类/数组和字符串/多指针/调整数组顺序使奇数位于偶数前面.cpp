#include<iostream>
#include<vector>
using namespace std;

/**
 * 剑指offer： 21
 *
 * 前后双指针
 */


// 前后指针，时间复杂度O(n)，不稳定
void reOrderArray(vector<int> &array){

	int left=0; 
	int right=array.size()-1;
	while(left<right){
		while(left<right && array[left]&1)
			left++;
		while(left<right && !(array[right]&1))
			right--;
		swap(array[left],array[right]);
	}
}

// 插入排序，时间复杂度O(n^2)，稳定
void reOrderArray_1(vector<int> &array){

	for(int i=1;i<array.size();i++){
		for(int j=i;j>0 && array[j]&1 && !(array[j-1]&1);j--){
			swap(array[j],array[j-1]);
		}
	}
}

int main(int argc, char const *argv[])
{
	vector<int> array={1,2,3,4,5};
	reOrderArray_1(array);
	for(auto i:array)
		cout<<i<<endl;
	return 0;
}