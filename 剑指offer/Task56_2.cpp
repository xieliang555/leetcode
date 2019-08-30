#include<vector>
#include<iostream>
using namespace std;

//知识点：位运算，每一位相加

int findNumAppearOnce(vector<int> data){

	if(data.size()<=0) return -1;

	int bitsSum[32]={0};
	for(int i=0;i<data.size();i++){
		int bitMask=1;
		//注意，数组的高位代表数的低位，易出错
		//第二个循环长度是固定的32，与n无关，故总的时间复杂的是o(n)
		for(int j=31;j>=0;j--){
			int bit=data[i] & bitMask;
			if(bit!=0)
				bitsSum[j]+=1;
			bitMask=bitMask<<1;
		}
	}


	int ret=0;
	//数组的低位代表数的高位
	for(int i=0;i<32;i++){
		ret=ret<<1;
		ret+=bitsSum[i]%3;
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	vector<int> a={1,2,2,2,3,3,3};
	cout<<findNumAppearOnce(a);
	return 0;
}