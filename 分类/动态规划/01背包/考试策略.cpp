#include<iostream>
#include<vector>
using namespace std;

/**
 *
 * 牛客
 * 动态规划：0-1背包问题
 * 多重0-1背包问题，dp[i][j]表示前i道题时间不超过j最高的得分，使用一维滚动数组
 * 
 * 注意多重背包易遗忘的项
 */

int solution(vector<vector<int> > v){

	vector<int> dp_pre(121);
	vector<int> dp_cur(121);
	for(int i=0;i<v.size();i++){
		for(int j=1;j<=120;j++){
			if(j<v[i][0])
				dp_cur[j]=dp_pre[j];
			else if(j<v[i][2])
				dp_cur[j]=max(dp_pre[j], v[i][1]+dp_pre[j-v[i][0]]);
			else{
				dp_cur[j]=max(dp_pre[j], v[i][3]+dp_pre[j-v[i][2]]);
				// 该项容易遗忘
				dp_cur[j]=max(dp_cur[j], v[i][1]+dp_pre[j-v[i][0]]);
			}
		}
		dp_pre=dp_cur;
	}
	return dp_cur.back();
}

int main(int argc, char const *argv[])
{
	vector<vector<int> > v={{20,20,100,60},{50,30,80,55},{100,60,110,88},{5,3,10,6}};
	cout<<solution(v)<<endl;
	return 0;
}