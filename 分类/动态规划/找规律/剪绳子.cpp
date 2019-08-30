#include<iostream>
#include<vector>
using namespace std;

/**
 * 剑指offer： 14
 * 动态规划：通过计算前几个元素找规律，找到dp数组表示的含义
 * 也可以根据dp数组找到规律，使用贪心算法进行优化
 */

// dp solution
int solution(int length){

	if(length==2) return 1;
	if(length==3) return 2;
	vector<int> dp(length+1);
	dp[0]=0;
	dp[1]=1;
	dp[2]=2;
	dp[3]=3;
	for(int i=4;i<=length;i++){
		for(int j=1;j<=i/2;j++){
			dp[i]=max(dp[i],dp[j]*dp[i-j]);
		}
	}
	return dp.back();
}


// greedy solution
// 通过dp数组，发现尽可能的剪出3，可以得到最大的长度
int solution_2(int length){

	if(length==2) return 1;
	if(length==3) return 2;
	if(length==4) return 4;
	if(length==5) return 6;
	int ret=1;
	while(length>5){
		length-=3;
		ret*=3;
	}
	if(length==5) return ret*6;
	if(length==4) return ret*4;
	else return ret*3;
}

int main(int argc, char const *argv[])
{
	cout<<solution_2(8)<<endl;
	return 0;
}