#include<vector>
using namespace std;


vector<int> FindNumbersWithSum(vector<int> array, int sum){

	if(array.size()<2) return vector<int>();
	vector<int> result;
	int left=0,right=array.size()-1;
	while(left<right){
		int curSum=array[left]+array[right];
		if(curSum>sum)
			right--;
		if(curSum<sum)
			left++;
		if(curSum==sum){
			result.push_back(array[left]);
			result.push_back(array[right]);
			break;
		}
	}
	return result;
}

int main(int argc, char const *argv[])
{
	vector<int> a;
	FindNumbersWithSum(a,10);
	return 0;
}