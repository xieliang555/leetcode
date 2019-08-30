#include<iostream>
#include<vector>
using namespace std;

/**
 * leetcode: 200
 *
 * 回溯法：本题直接在原矩阵上改，不需要visited数组来标记
 * 每次找到了一个岛屿后，就要把该岛屿的所有"1"都变成'0"
 */


void backtrack(vector<vector<char> >& grid, int row, int col){
	grid[row][col]='0';
	if(row>0 && grid[row-1][col]=='1'){
		backtrack(grid, row-1, col);
	}
	if(row<grid.size()-1 && grid[row+1][col]=='1'){
		backtrack(grid, row+1, col);
	}
	if(col>0 && grid[row][col-1]=='1'){
		backtrack(grid, row, col-1);
	}
	if(col<grid[0].size()-1 && grid[row][col+1]=='1'){
		backtrack(grid, row, col+1);
	}
}

int numIslands(vector<vector<char>>& grid) {
    
	int ret=0;
	for(int row=0;row<grid.size();row++){
		for(int col=0;col<grid[0].size();col++){
			if(grid[row][col]=='1'){
				ret++;
				backtrack(grid, row, col);
			}
		}
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}