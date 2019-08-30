#include<vector>
#include<iostream>
#include<cmath>
using namespace std;

/**
 * 剑指offer； 60
 *
 * 动态规划：0-1背包问题
 * 求装满背包的方案总数(子集和), 不需要考虑价值
 * dp[i][j]表示前i个骰子和为j的方案总数，使用一维滚动数组
 *
 * 通过计算dp数组好规律，找到状态转移方程
 */


int solution(int n, int target){

	vector<int> dp_cur(6*n+1);
	vector<int> dp_pre(6*n+1);
	for(int i=1;i<=6;i++)
		dp_pre[i]=1;
	for(int i=2;i<=n;i++){
		for(int i=1;i<dp_cur.size();i++){
			int tmp1=(i-6)>=1?dp_pre[i-6]:0;
			int tmp2=(i-5)>=1?dp_pre[i-5]:0;
			int tmp3=(i-4)>=1?dp_pre[i-4]:0;
			int tmp4=(i-3)>=1?dp_pre[i-3]:0;
			int tmp5=(i-2)>=1?dp_pre[i-2]:0;
			int tmp6=(i-1)>=1?dp_pre[i-1]:0;
			dp_cur[i]=tmp1+tmp2+tmp3+tmp4+tmp5+tmp6;
		}
		dp_pre=dp_cur;
	}
	return dp_cur[target];
}

int main(int argc, char const *argv[])
{

	cout<<solution(3,8)<<endl;
	return 0;
}