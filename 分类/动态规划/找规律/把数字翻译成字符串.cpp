#include<iostream>
#include<vector>
#include<string>
using namespace std;

/**
 * 剑指offer: 46	(OJ无此题)
 * 动态规划： dp[i]表示前i个数字最多有多少种不同的翻译
 *
 * 两个注意的点：
 * 1）tmp>=10易遗忘
 * 2）从整数的高位开始遍历时，使用to_string将其转换为string类型
 */

int solution(int num){

	string s=to_string(num);

	if(s.size()==1) return 1;

	vector<int> dp(s.size()+1);
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<dp.size();i++){
		int tmp=(s[i-1]-'0')+(s[i-2]-'0')*10;
		if(tmp<=25 && tmp>=10){
			dp[i]=dp[i-1]+dp[i-2];
		}
		else{
			dp[i]=dp[i-1];
		}
	}

	return dp.back();

}


int main(int argc, char const *argv[])
{
	cout<<solution(100)<<endl;
	return 0;
}
