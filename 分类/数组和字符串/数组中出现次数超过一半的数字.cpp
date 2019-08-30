#include<iostream>
#include<vector>
using namespace std;

/**
 * 剑指offer: 39
 *
 * 累加
 */

int MoreThanHalfNum_Solution(vector<int> numbers){

	int count=0;
	int pre;
	for(int i=0;i<numbers.size();i++){
		if(count==0){
			pre=numbers[i];
			count=1;
		}
		else if(numbers[i]==pre){
			count++;
		}
		else
			count--;
	}

	// 检查该数是否超过一半
	count=0;
	for(auto i:numbers){
		if(i==pre)
			count++;
	}

	return count>numbers.size()/2?pre:0;
}

int main(int argc, char const *argv[])
{
	vector<int> numbers={1,2,3,2,2,2,5,4};
	cout<<MoreThanHalfNum_Solution(numbers)<<endl;
	return 0;
}