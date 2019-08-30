#include<iostream>
#include<vector>
using namespace std;

/**
 * 剑指offer: 57_1
 * 前后双指针
 */

vector<int> FindNumbersWithSum(vector<int> array,int sum){

	vector<int> ret;
	int left=0;
	int right=array.size()-1;
	while(left<right){
		int Sum=array[left]+array[right];
		if(Sum==sum){
			ret.push_back(array[left]);
			ret.push_back(array[right]);
			return ret;
		}
		else if(Sum>sum){
			right--;
		}
		else
			left++;
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	vector<int> array={1,2,4,7,11,15};

	return 0;
}