#include<iostream>
#include<vector>
using namespace std;

/**
 * 剑指offer： 13
 *
 * visited数组的作用主要是矩阵上下左右走可能会有重复，利用visited数组记录路径可以避免重复计算
 */

vector<vector<int> > visited;
int ret=0;

bool check(int threshold, int row, int col){
	int Sum=0;
	while(row){
		Sum+=row%10;
		row/=10;
	}
	while(col){
		Sum+=col%10;
		col/=10;
	}
	if(Sum<=threshold)
		return true;
	else
		return false;
}

void backtrack(int threshold, int rows, int cols, int row, int col){

	visited[row][col]=1;
	if(row>=1 && !visited[row-1][col] && check(threshold, row-1, col)){
		ret++;
		backtrack(threshold, rows, cols, row-1, col);
	}
	if(row<rows-1 && !visited[row+1][col] && check(threshold, row+1, col)){
		ret++;
		backtrack(threshold, rows, cols, row+1, col);
	}
	if(col>=1 && !visited[row][col-1] && check(threshold, row, col-1)){
		ret++;
		backtrack(threshold, rows, cols, row, col-1);
	}
	if(col<cols-1 && !visited[row][col+1] && check(threshold, row, col+1)){
		ret++;
		backtrack(threshold, rows, cols, row, col+1);
	}
}

int movingCount(int threshold, int rows, int cols){
    if(threshold<0) return 0;
	for(int i=0;i<rows;i++)
		visited.push_back(vector<int>(cols,0));
	// 坐标（0，0）
	ret++;
	backtrack(threshold, rows, cols, 0, 0);
	return ret;
}


int main(int argc, char const *argv[])
{
	cout<<movingCount(15,20,20)<<endl;
	return 0;
}