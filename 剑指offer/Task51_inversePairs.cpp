#include<vector>
#include<iostream>
using namespace std;

long long recursionCore(vector<int>&, vector<int>&, int,int);
long long countInversePairs(vector<int>&, vector<int>&, int, int);


int InversePairs(vector<int> data){

	if(data.empty()) return 0;
	vector<int> tmp=data;
	long long count=recursionCore(data,tmp,0,data.size()-1);
	return count%1000000007;

}

long long recursionCore(vector<int>& data, vector<int>& tmp, int first, int last){

	if(first==last) return 0;

	int mid=(first+last)/2;
	long long left=recursionCore(data,tmp,first,mid);
	long long right=recursionCore(data,tmp,mid+1,last);
	return left+right+countInversePairs(data,tmp,first,last);
}

long long countInversePairs(vector<int>& data, vector<int>& tmp, int first, int last){
	for(int i=first;i<=last;i++)
		tmp[i]=data[i];
	int mid=(first+last)/2;
	long long count=0;
	int i=first,j=mid+1,k=first;
	while(i<=mid && j<=last){
		if(tmp[j]<tmp[i]){
			count+=mid-i+1;
			data[k++]=tmp[j++];
		}
		else
			data[k++]=tmp[i++];
	}
	while(i<=mid)
		data[k++]=tmp[i++];
	while(j<=last)
		data[k++]=tmp[j++];
	return count;
}

int main(int argc, char const *argv[])
{
	vector<int> a={8,4,5,7,1};
	cout<<InversePairs(a)<<endl;
	return 0;
}