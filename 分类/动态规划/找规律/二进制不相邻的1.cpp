#include<iostream>
#include<vector>
using namespace std;

/**
 * 程序员面试笔试宝典： 考虑n位二进制数，有多少位不存在两个相邻的1
 * n=1,满足条件的有0，1，a(1)=2
 * n=2,c满足条件的有00，01，10， a(2)=3
 * 考虑第n位，当第n位为1, 有a(n-2)个数满足条件，当第n位为0，有a(n-1)个数满足条件，故a(n)=a(n-1)+a(n-2)
 */

int solution(int n){

	if(n==1) return 2;
	if(n==2) return 3;
	vector<int> dp(n+1);
	dp[1]=2;
	dp[2]=3;
	for(int i=3;i<=n;i++)
		dp[i]=dp[i-1]+dp[i-2];
	return dp.back();
}

int main(int argc, char const *argv[])
{
	cout<<solution(7)<<endl;
	return 0;
}