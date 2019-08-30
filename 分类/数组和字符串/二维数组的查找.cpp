#include<iostream>
#include<vector>
using namespace std;

/**
 * 剑指offer: 4
 */

bool Find(int target, vector<vector<int> > matrix){

	int row=0;
	int col=matrix[0].size()-1;
	while(row<matrix.size() && col>=0){
		if(matrix[row][col]==target)
			return true;
		while(col>=0 && matrix[row][col]>target)
			col--;
		while(row<matrix.size() && matrix[row][col]<target)
			row++;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}