#include<iostream>
#include<cstring>
using namespace std;

class Task12
{
public:
	Task12(){}
	~Task12(){}

	bool hasPath(char* matrix, int rows, int cols, char* str){

		if(matrix==nullptr||rows<1||cols<1||str==nullptr)
			return false;

		bool* visited=new bool[rows*cols];
		memset(visited,false,cols*rows);
		int pathLength=0;

		for(int col=0;col<cols;col++)
			for(int row=0;row<rows;row++)
				if(recusrion(matrix,rows,cols,str,col,row,pathLength,visited))
					return true;

		delete[] visited;
		return false;
    }

    bool recusrion(char* matrix, int rows, int cols, char* str, int col, int row,int pathLength, bool* visited){

    	if(str[pathLength]=='\0') 
    		return true;

    	bool hasPath=false;
    	if(col>=0 && col<cols && row>=0 && row<rows && matrix[row*cols+col]==str[pathLength] && !visited[row*cols+col]){

    		visited[row*cols+col]=true;
    		pathLength++;

    		hasPath=recusrion(matrix,rows,cols,str,col-1,row,pathLength,visited)||
    				recusrion(matrix,rows,cols,str,col+1,row,pathLength,visited)||
    				recusrion(matrix,rows,cols,str,col,row-1,pathLength,visited)||
    				recusrion(matrix,rows,cols,str,col,row+1,pathLength,visited);

    		if(!hasPath){
    			pathLength--;
    			visited[row*cols+col]=false;
    		}
    	}

    	return hasPath;
    }
	
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}