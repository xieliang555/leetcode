#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/**
 * leetcode: 329
 *  额外的二维数组保存按升序排序后的矩阵二维数组的每一个list是[num, row, col]。按照二维数组的第一维升序的顺序更新矩阵的每一个元素。
 *  dp[i][j]表示以坐标为（i，j）的元素为路径末尾值的路径长度
 */

int longestIncreasingPath(vector<vector<int>>& matrix){

	vector<vector<int> > tmp;
	for(int i=0;i<matrix.size();i++){
		for(int j=0;j<matrix[0].size();j++){
			vector<int> list={matrix[i][j],i,j};
			tmp.push_back(list);
		}
	}
	sort(tmp.begin(),tmp.end());

	vector<vector<int> > dp=matrix;
	for(int i=0;i<dp.size();i++)
		for(int j=0;j<dp[0].size();j++)
			dp[i][j]=1;


	int ret=0;
	for(auto list:tmp){
		int Max=0;
		if(list[1]>0 && list[0]>matrix[list[1]-1][list[2]])
			Max=max(dp[list[1]-1][list[2]],Max);
		if(list[1]<dp.size()-1 && list[0]>matrix[list[1]+1][list[2]])
			Max=max(dp[list[1]+1][list[2]],Max);
		if(list[2]>0 && list[0]>matrix[list[1]][list[2]-1])
			Max=max(dp[list[1]][list[2]-1],Max);
		if(list[2]<dp[0].size()-1 && list[0]>matrix[list[1]][list[2]+1])
			Max=max(dp[list[1]][list[2]+1],Max);
		dp[list[1]][list[2]]+=Max;
		ret=max(ret, dp[list[1]][list[2]]);
	}

	return ret;
}

int main(int argc, char const *argv[])
{
	vector<vector<int> > matrix={{9,9,4},{6,6,8},{2,1,1}};
	cout<<longestIncreasingPath(matrix)<<endl;
	return 0;
}