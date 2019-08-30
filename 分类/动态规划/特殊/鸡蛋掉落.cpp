#include<iostream>
#include<vector>
using namespace std;

/**
 * leetcode: 887
 * 动态规划：将问题转换为i个鸡蛋走j步最高能确定多少层楼，（i和楼层已知，求j）
 * 1）dp[i][j]表示i个蛋走j步最高能确定的楼层
 * 2）记： 第一个鸡蛋从哪一层试起如何确定：
 * 假设第一个鸡蛋选择在x层掉落，如果碎了，则dp[i-1][j-1]必须能确定x层楼以下的楼高（根据这个原则确定x），
 * 如果没碎，则还可以确定x楼以上dp[i][j-1]层楼高，因此一共可以确定dp[i-1][j-1]+1+dp[i][j-1]
 * 3）计算出了dp表后易知可以使用一维滚动数组
 *
 * 
 * 易错：dp[1][2]=2, 故最后应该返回N
 */

int superEggDrop(int K,int N){

	vector<int> dp_pre(K,1);
	vector<int> dp_cur(K);
	for(int i=2;i<=N;i++){
		dp_cur[0]=i;
		for(int j=1;j<dp_pre.size();j++){
			dp_cur[j]=dp_pre[j]+1+dp_pre[j-1];
			if(dp_cur[j]>=N)
				return i;
		}
		dp_pre=dp_cur;
	}
	return N;
}

int main(int argc, char const *argv[])
{
	cout<<superEggDrop(1,2)<<endl;
	return 0;
}