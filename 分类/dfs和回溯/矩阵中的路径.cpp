#include<iostream>
#include<vector>
#include<string>
using namespace std;

/**
 * 剑指offer: 12
 *
 * 回溯是一种带剪枝的dfs，利用额外的临时变量（本题是visited数组）来剪枝。
 *
 * 回溯应注意：
 * 1）对于二维矩阵可以以任何一个点作为起始点。
 * 2）visited数组的更新。
 */

vector<vector<int> > visited;

bool backtrack(vector<vector<char> > chs, int row, int col, string s, int begin){
	if(begin>=s.size()) return true;
	bool ret=false;
	visited[row][col]=1;
	if(s[begin]==chs[row][col] && row>=1 && !visited[row-1][col]){
		ret|=backtrack(chs, row-1, col, s, begin+1);
		if(ret) return ret;
	}
	if(s[begin]==chs[row][col] && row<chs.size()-1 && !visited[row+1][col]){
		ret|=backtrack(chs, row+1, col, s, begin+1);
		if(ret) return ret;
	}
	if(s[begin]==chs[row][col] && col>=1 && !visited[row][col-1]){
		ret|=backtrack(chs, row, col-1, s, begin+1);
		if(ret) return ret; 
	}
	if(s[begin]==chs[row][col] && col<chs[0].size()-1 && !visited[row][col+1]){
		ret|=backtrack(chs, row, col+1, s, begin+1);
		if(ret) return ret;
	}
	if(!ret)
		visited[row][col]=0;
	return ret;
}


bool hasPath(vector<vector<char> > chs, string s){

	for(int i=0;i<chs.size();i++)
		visited.push_back(vector<int>(chs[0].size(),0));

	for(int i=0;i<chs.size();i++){
		for(int j=0;j<chs[0].size();j++){
			if(backtrack(chs, i, j, s, 0))
				return true;
		}
	}

	return false;
}

int main(int argc, char const *argv[])
{

	vector<vector<char> > chs={{'a', 'b', 't', 'g'},{'c', 'f', 'c', 's'}, {'j', 'd', 'e', 'h'}};
	string s="abtg";
	cout<<hasPath(chs, s)<<endl;
	return 0;
}