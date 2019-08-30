#include<iostream>
#include<vector>
using namespace std;

/**
 * 剑指offer: 66
 */

vector<int> multiply(const vector<int>& A){
	if(A.empty()) return vector<int>();
	int len=A.size();
	vector<int> tmp1(len);
	vector<int> tmp2(len);
	tmp1[0]=1;
	tmp2[0]=1;
	for(int i=1;i<len;i++){
		tmp1[i]=tmp1[i-1]*A[i-1];
		tmp2[i]=tmp2[i-1]*A[len-i];
	}
	vector<int> ret(len);
	for(int i=0;i<tmp1.size();i++){
		ret[i]=tmp1[i]*tmp2[len-i-1];
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	vector<int> A={1,2,3,4};
	vector<int> ret=multiply(A);
	for(auto i:ret)
		cout<<i<<' ';
	return 0;
}