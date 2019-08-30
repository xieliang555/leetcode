#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

/**
 * 剑指offer: 10_2
 *
 * 动态规划：通过计算前几个简单例子找规律
 */


// 一次只可以跳1个台阶或2个台阶
int solution(int n){
	if(n==1 || n==2) return 1;
	vector<int> dp(n+1);
	dp[1]=1;
	dp[2]=1;
	for(int i=3;i<=n;i++)
		dp[i]=dp[i-1]+dp[i-2];
	return dp.back();

}

//一次可以跳n个台阶
int solution_2(int n){
	return pow(2,n-1);
}

int main(int argc, char const *argv[])
{
	cout<<solution_2(6)<<endl;
	return 0;
}