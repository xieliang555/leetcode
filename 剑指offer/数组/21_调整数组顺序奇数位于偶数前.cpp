#include<iostream>
#include <vector>
using namespace std;

/**
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
 * 使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
 * 并保证奇数和奇数，偶数和偶数之间的相对位置不变。
 */


// 双指针两头遍历，时间复杂度o(n),空间复杂度o(n)
void reOrderArray(vector<int>& array){

	vector<int> temp(array.begin(),array.end());
	int left=0; 
	int right=array.size()-1;
	int l=0;
	int r=array.size()-1;
	for(int i=0;i<array.size();i++){
		if(temp[l] & 1){
			array[left++]=temp[l++];
		}
		else
			l++;
		if((temp[r] & 1)==0){
			array[right--]=temp[r--];
		}
		else
			r--;
	}
}


// 插入排序，时间复杂度o(n^2),无额外辅助空间
void reOrderArray1(vector<int> &array) {
    
    if(array.empty()) return;
    for(int i=1;i<array.size();i++){
    	for(int j=i; j>=1 && (array[j]&1) && !(array[j-1]&1);j--)
    		swap(array[j],array[j-1]);
    }
}


int main(int argc, char const *argv[])
{
	vector<int> a={1,2,3,4,5,6,7};
	reOrderArray1(a);
	for(auto i:a)
		cout<<i<<' ';
	return 0;
}
