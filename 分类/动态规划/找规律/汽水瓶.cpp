#include<iostream>
#include<vector>
using namespace std;

/** 
 * 牛客
 * dp[i]表示i个空瓶最多可换的瓶数
 */

vector<int> solution(){

	vector<int> dp(101);
	dp[0]=0;
	dp[1]=0;
	dp[2]=1;
	for(int i=3;i<=100;i++){
		dp[i]+=dp[i-2]+1;
	}
	return dp;
}

int main(int argc, char const *argv[])
{
	
	vector<int> dp=solution();
	int n;
	while(cin>>n){
		if(n!=0)
			cout<<dp[n]<<endl;
	}
	return 0;
}