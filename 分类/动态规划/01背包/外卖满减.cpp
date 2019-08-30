#include<iostream>
#include<vector>
using namespace std;

/**
 * 牛客
 * 动态规划：0-1背包问题
 * 装满背包的方案总数数问题的变种（子集和），不需要考虑价值
 * dp[i][j]表示前i个菜不低于j元的最低价格，使用一维的滚动数组
 */

int solution(vector<int> prices, int target){

	vector<int> dp_pre(target+1, 10000);
	vector<int> dp_cur(target+1);
	for(auto price: prices){
		for(int i=1;i<=target;i++){
			if(price>=i)
				dp_cur[i]=min(dp_pre[i], price);
			else
				dp_cur[i]=min(dp_pre[i], price+dp_pre[i-price]);
		}
		dp_pre=dp_cur;
	}
	return dp_cur.back();
}

int main(int argc, char const *argv[])
{
	vector<int> prices={18,19,17,6,7};
	cout<<solution(prices,20)<<endl;
	return 0;
}