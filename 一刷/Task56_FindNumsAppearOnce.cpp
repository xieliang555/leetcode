#include<vector>
using namespace std;

//重要知识点： 位运算
//1）判断最低位是不是1（是不是奇数）
//2）二进制右移>>
//3) 异或运算

int findFirstBit1(int);
bool indexBitIs1(int, int);

void FindNumsAppearOnce(vector<int> data, int* num1, int* num2){
	if(data.size()<2) return;

	int resultExclusiveOR=0;
	for(int i=0;i<data.size();i++){
		resultExclusiveOR^=data[i];
	}

	int indexBit=findFirstBit1(resultExclusiveOR);

	*num1=0;
	*num2=0;
	for(int i=0;i<data.size();i++){
		if(indexBitIs1(data[i],indexBit))
			*num1^=data[i];
		else
			*num2^=data[i];
	}
}

int findFirstBit1(int num){
	int index=0;
	while((num & 1)==0){
		index++;
		num=num>>1;
	}
	return index;
}

bool indexBitIs1(int num,int indexBit){
	num=num>>indexBit;
	return (num & 1);
}

int main(int argc, char const *argv[])
{
	vector<int> a={1,2,2,4,5};
	return 0;
}