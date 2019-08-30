#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/**
 * 剑指offer: 61
 *
 * 先排序，注意可能有重复数（重复的0或重复的其他数）
 * 本题的考点在于全面考虑多种情况，以及if else 的组织
 */

bool IsContinuous( vector<int> numbers ){
	if(numbers.empty()) return false;
	int countZero=0;
	int countGap=0;
	sort(numbers.begin(),numbers.end());
	for(int i=0;i<numbers.size()-1;i++){
		if(numbers[i]==0) countZero++;
		else if(numbers[i]==numbers[i+1])
			return false;
		else 
			countGap+=numbers[i+1]-numbers[i]-1;
	}
	if(countZero>=countGap)
		return true;
	else
		return false;

}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}