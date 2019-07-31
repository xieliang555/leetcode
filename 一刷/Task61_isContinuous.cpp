#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

bool IsContinuous(vector<int> numbers){
	if(numbers.empty()) return false;
	sort(numbers.begin(),numbers.end());
	int countZero=0;
	int countGap=0;
	for(int i=0;i<numbers.size()-1;i++){
		if(numbers[i]==0)
			countZero++;
		//提前访问后一位注意循环次数，容易越界
		else if(numbers[i+1]==numbers[i])
			return false;
		else
			//一次循环中需要考虑数组前后关系时，考虑[i+1]和[i]而不是[i]和[i-1]
			countGap+=numbers[i+1]-numbers[i]-1;
	}
	if(countGap>countZero)
		return false;
	return true;
}

int main(int argc, char const *argv[])
{
	vector<int> a={1,3,2,4,6};
	cout<<boolalpha<<IsContinuous(a);
	return 0;
}