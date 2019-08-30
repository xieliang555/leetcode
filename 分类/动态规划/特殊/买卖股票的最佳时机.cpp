#include<iostream>
#include<vector>
#include<climits>
using namespace std;

/**
 * leetcode: 121, 122, 123, 188
 * 
 */

// 只能买卖一次
// 贪心算法：不断更新maxProfit和minPrice
int maxProfit(vector<int>& prices){
	if(prices.empty()) return 0;
	int maxProfit=0;
	int minPrice=prices[0];
	for(int i=1;i<prices.size();i++){
		maxProfit=max(maxProfit, prices[i]-minPrice);
		minPrice=min(minPrice, prices[i]);
	}
	return maxProfit;
}

// 可以买卖无限次
// 贪心算法: 今天比昨天高，就“买”昨天的，卖今天的（虽然不符合逻辑，但可以这样考虑问题）
int maxProfit_2(vector<int>& prices){
	if(prices.size()<2) return 0;
	int maxProfit=0;
	for(int i=1;i<prices.size();i++){
		if(prices[i]>prices[i-1])
			maxProfit+=prices[i]-prices[i-1];
	}
	return maxProfit;
}


// 可以买卖k次
// 动态规划： dp[i][0]表示第i次交易买入时的最大收益，dp[i][1]表示第i次交易卖出时的最大收益
// 困难： 记住dp表示的意义，记住如何计算dp表（此题状态方程不易显示的表示）
// 见leetcode 188评论最高赞解
int maxProfit(int k, vector<int>& prices){

	vector<vector<int> > dp(k);
	for(auto i:dp)
		i.resize(2);

	for(int i=0;i<dp.size();i++)
		dp[i][0]=INT_MIN;

	for(auto price:prices){

	}
	return 0;
}


int main(int argc, char const *argv[])
{
	vector<int> prices={1,2,3,4,5};
	cout<<maxProfit_2(prices)<<endl;
	return 0;
}