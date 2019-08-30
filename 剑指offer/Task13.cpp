#include<iostream>
using namespace std;

class Task13
{
public:
	Task13(){}
	~Task13(){}

	int movingCount(int threshold, int rows, int cols){

		bool* visited=new bool[rows*cols];
		memset(visited,false,rows*cols);

		int count=backTracking(threshold,rows,cols,0,0,visited);

		delete[] visited;
		return count;
	}

	int backTracking(int threshold, int rows, int cols, int row, int col, bool* visited){

		int count=0;
		if(col>=0 && col<cols && row>=0 && row<rows && getDigitSum(row)+getDigitSum(col)<=threshold && !visited[row*cols+col]){
			visited[row*cols+col]=true;
			count=1+backTracking(threshold,rows,cols,row+1,col,visited)+
					backTracking(threshold,rows,cols,row-1,col,visited)+
					backTracking(threshold,rows,cols,row,col+1,visited)+
					backTracking(threshold,rows,cols,row,col-1,visited);
		}

		return count;
	}

	int getDigitSum(int index){
		int sum=0;
		while(index>0){
			sum+=index%10;
			index/=10;
		}
		return sum;
	}
	
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}