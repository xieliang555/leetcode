#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int> >& matrix, int target) {
    if(matrix.empty()) return false;
    int column=matrix[0].size()-1;
    int row=0;
    bool found=false;
    while(row<matrix.size() && column>=0){
        if(matrix[row][column]==target){
            found=true;
            break;
        }
        while(row<matrix.size() && column>=0 && matrix[row][column]<target)
            row++;
        while(row<matrix.size() && column>=0 && matrix[row][column]>target)
            column--;
    }
    return found;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}