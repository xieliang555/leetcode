#include<iostream>
#include<vector>
using namespace std;

class Task29_printMatrix
{
public:
	Task29_printMatrix(){}
	~Task29_printMatrix(){}

	vector<int> printMatrix(vector<vector<int> > matrix){

		//圈数控制循环次数
		int columns=matrix[0].size();
		int rows=matrix.size();
		int numCircles=columns>rows?(rows+1)/2:(columns+1)/2;
		int start=0;
		vector<int> result;
		for(int i=0;i<numCircles;i++){
			printCircle(matrix, result,columns,rows,start);
			start++;
			columns-=2;
			rows-=2;
		}

		return result;
	}

	void printCircle(vector<vector<int> > &matrix,vector<int> &result, int columns, int rows, int start){

		//4个循环的起始条件和终止条件只需要三个变量即可控制,start, endX, endY
		int endX=start+rows-1;
		int endY=start+columns-1;

		//从左到右遍历一行
		for(int i=start;i<=endY;i++)
			result.push_back(matrix[start][i]);

		//从上到下遍历一列，至少两行
		if(start<endX){
			for(int i=start+1;i<=endX;i++)
				result.push_back(matrix[i][endY]);
		}

		//从右到左遍历一行，至少两行两列
		if(start<endX && start<endY){
			for(int i=endY-1;i>=start;i--)
				result.push_back(matrix[endX][i]);
		}

		//从下到上遍历一列，至少三行两列
		if(start<endX-1 && start<endY){
			for(int i=endX-1;i>start;i--)
				result.push_back(matrix[i][start]);
		}
	}
	
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}