#include<iostream>
#include<vector>
using namespace std;

/**
 * 剑指offer: 49
 *
 * dp[i]表示第i个丑数
 * dp中的每一个数都要与2，3，5相乘
 */

int GetUglyNumber_Solution(int index){
	if(index==1) return 1;
	vector<int> dp(index+1);
	dp[1]=1;
	int idx2=1;
	int idx3=1;
	int idx5=1;
	int ret=0;
	for(int i=2;i<=index;i++){
		dp[i]=min(min(2*dp[idx2], 3*dp[idx3]),5*dp[idx5]);
		if(dp[i]==2*dp[idx2]) idx2++;
		if(dp[i]==3*dp[idx3]) idx3++;
		if(dp[i]==5*dp[idx5]) idx5++;
	}
	return dp.back();
}

int main(int argc, char const *argv[])
{
	cout<<GetUglyNumber_Solution(11)<<endl;
	return 0;
}