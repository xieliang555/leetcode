#include<iostream>
#include<vector>
using namespace std;

/**
 * 剑指offer: 51
 * 利用归并排序，注意逆序对在每一次归并是如何计算的
 * 牛客OJ超时？
 */


long long ret=0;

void merge(vector<int>& data, int left, int right){
	vector<int> tmp=data;
	int mid=(left+right)/2;
	int idx1=left;
	int idx2=mid+1;
	int idx3=left;
	while(idx1<=mid && idx2<=right){
		if(tmp[idx1]<=tmp[idx2])
			data[idx3++]=tmp[idx1++];
		else{
			data[idx3++]=tmp[idx2++];
			ret+=mid-idx1+1;
		}
	}
	while(idx1<=mid)
		data[idx3++]=tmp[idx1++];
	while(idx2<=right)
		data[idx3++]=tmp[idx2++];
}

void recursionCore(vector<int>& data, int left, int right){
	if(left>=right) return;
	int mid=(left+right)/2;
	recursionCore(data, left, mid);
	recursionCore(data, mid+1, right);
	merge(data, left, right);
}

int InversePairs(vector<int> data) {
    
	recursionCore(data, 0, data.size()-1);
	return ret%1000000007;
}

int main(int argc, char const *argv[])
{
	vector<int> data={8,4,5,7,1};
	cout<<InversePairs(data)<<endl;
	return 0;
}