#include<iostream>
#include<vector>
using namespace std;


/**
 * （OJ无此题）
 * 经典的01背包问题 
 * dp[i][j]表示前i件物品总重量不超过j的最大价值，使用滚动的一维数组
 */

int knapsack(vector<int> weights, vector<int> values, int target){

	vector<int> dp_pre(target+1);
	vector<int> dp_cur(target+1);
	for(int i=0;i<weights.size();i++){
		for(int j=1;j<dp_cur.size();j++){
			if(j>=weights[i])
				dp_cur[j]=max(dp_pre[j], dp_pre[j-weights[i]]+values[i]);
			else
				dp_cur[j]=dp_pre[j];
		}
		dp_pre=dp_cur;
		for(auto i:dp_pre)
			cout<<i<<' ';
		cout<<endl;
	}

	return dp_cur.back();

}

int main(int argc, char const *argv[])
{
	vector<int> weights={2,2,1,3};
	vector<int> values={4,5,2,8};
	cout<<knapsack(weights,values,5)<<endl;
	return 0;
}