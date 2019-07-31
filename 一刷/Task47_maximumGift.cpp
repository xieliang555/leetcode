#include<iostream>
#include<vector>
using namespace std;

class Task47_maximumGift
{
public:
	Task47_maximumGift(){}
	~Task47_maximumGift(){}


	int maximumGift(vector<vector<int> > v){
		if(v.empty()) return 0;
		vector<vector<int> > tmp(v.begin(),v.end());
		int row=v.size();
		int colm=v[0].size();
		for(int i=row-1;i>=0;i--)
			for(int j=colm-1;j>=0;j--){
				int downNum=0,rightNum=0;
				if(i<(row-1))
					downNum=tmp[i+1][j];
				if(j<(colm-1))
					rightNum=tmp[i][j+1];
				tmp[i][j]=rightNum>downNum?(v[i][j]+rightNum):(v[i][j]+downNum);
			}
		return tmp[0][0];
	}

	//优化为一维数组
	int maximumGift2(vector<vector<int> > v){
		if(v.empty()) return 0;
		vector<int> tmp(v[0].begin(),v[0].end());
		int row=v.size();
		int colm=v[0].size();
		for(int i=row-1;i>=0;i--)
			for(int j=colm-1,downNum=0,rightNum=0;j>=0;j--){
				if(i<(row-1))
					downNum=tmp[j];
				tmp[j]=rightNum>downNum?(v[i][j]+rightNum):(v[i][j]+downNum);
				rightNum=tmp[j];
			}
		return tmp[0];
	}
	
};

int main(int argc, char const *argv[])
{
	vector<vector<int> > v={{1,10,3,8},{12,2,9,6},{5,7,4,11},{3,7,16,5}};
	Task47_maximumGift t;
	cout<<t.maximumGift(v)<<endl;
	cout<<t.maximumGift2(v)<<endl;
	return 0;
}