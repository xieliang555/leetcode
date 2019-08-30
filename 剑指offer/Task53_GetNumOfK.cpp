#include<vector>
#include<iostream>
using namespace std;

int getIndex(vector<int>& ,double);

int GetNumOfK(vector<int> data, int k){

	if(data.empty()) return 0;
	return getIndex(data,k+0.5)-getIndex(data,k-0.5);
}

int getIndex(vector<int>& data, double k){
	int begin=0, end=data.size()-1;
	while(begin<=end){
		int mid=(begin+end)/2;
		if(data[mid]<k)
			begin=mid+1;
		if(data[mid]>k)
			end=mid-1;
	}
	return begin;
}


int main(int argc, char const *argv[])
{
	vector<int> a1={3,3,3,4,5};
	vector<int> a2={1,2,4,4,4};
	vector<int> a3={1,2,3,4,5};
	vector<int> a4={3,3,3,3,3};
	vector<int> a5;
	cout<<GetNumOfK(a1,3)<<endl;
	cout<<GetNumOfK(a2,4)<<endl;
	cout<<GetNumOfK(a3,6)<<endl;
	cout<<GetNumOfK(a4,3)<<endl;
	cout<<GetNumOfK(a5,4)<<endl;

	return 0;
}