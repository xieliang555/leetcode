#include<vector>
using namespace std;

vector<vector<int> > FindContinuousSequence(int sum){
	if(sum<3) return vector<vector<int> >();
	vector<vector<int> > ret;
	int left=1,right=2,curSum;
	while(left<right){
		vector<int> list;
		curSum=(left+right)*(right-left+1)/2;
		if(curSum==sum){
			for(int i=left;i<=right;i++)
				list.push_back(i);
			ret.push_back(list);
			right+=1;
		}
		else if (curSum<sum)
		{
			right+=1;
		}
		else
		{
			left+=1;
		}

	}
	return ret;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}