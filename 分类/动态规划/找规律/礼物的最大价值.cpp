#include<iostream>
#include<vector>
using namespace std;

/**
 * 剑指offer： 47（OJ无此题）
 * dp[i][j]表示从（0，0）走到(i,j)的最大价值
 */

int solution(vector<vector<int> > v){

	vector<vector<int> > dp=v;
	for(int i=1;i<dp[0].size();i++){
		dp[0][i]+=dp[0][i-1];
	}
	for(int i=1;i<dp.size();i++){
		dp[i][0]+=dp[i-1][0];
	}
	for(int i=1;i<dp.size();i++){
		for(int j=1;j<dp[0].size();j++){
			dp[i][j]+=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp.back().back();
}

int main(int argc, char const *argv[])
{
	vector<vector<int> > v={{1,10,3,8},{12,2,9,6},{5,7,4,11},{3,7,16,5}};
	cout<<solution(v)<<endl;
	return 0;
}