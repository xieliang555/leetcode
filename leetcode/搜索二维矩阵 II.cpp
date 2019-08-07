#include<iostream>
#include<vector>
using namespace std;

 bool searchMatrix(vector<vector<int> >& matrix, int target){
 	if(matrix.empty()) return false;
 	int col=matrix[0].size()-1;
 	int row=0;
 	while(row<matrix.size() && col>=0){
 		if(target==matrix[row][col]) return true;
 		while(row<matrix.size() && col>=0 && target<matrix[row][col])
 			col--;
 		while(row<matrix.size() && col>=0 && target>matrix[row][col])
 			row++;
 	}

 	return false;

 }

 int main(int argc, char const *argv[])
 {
 	
 	return 0;
 }