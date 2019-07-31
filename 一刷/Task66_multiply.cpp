#include<vector>
#include<iostream>
using namespace std;

vector<int> multiply(const vector<int>& A){
	if(A.empty()) return vector<int>();

	vector<int> B(A.size());
	vector<int> C(A.size(),1);
	vector<int> D(A.size(),1);
	for(int i=1;i<A.size();i++){
		C[i]=A[i-1]*C[i-1];
	}
	for(int i=A.size()-2;i>=0;i--){
		D[i]=A[i+1]*D[i+1];
	}
	for(int i=0;i<A.size();i++){
		B[i]=C[i]*D[i];
	}
	return B;
}

int main(int argc, char const *argv[])
{
	vector<int> A={1,2,3,4};
	vector<int> B=multiply(A);
	for(int i=0;i<B.size();i++)
		cout<<B[i]<<' ';
	return 0;
}