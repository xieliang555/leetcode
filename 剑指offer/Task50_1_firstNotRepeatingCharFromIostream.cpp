#include<iostream>
using namespace std;

class Task50_1_firstNotRepeatingCharFromIostream
{
public:
	Task50_1_firstNotRepeatingCharFromIostream():index(0){
		for(int i=0;i<256;i++){
			hashTable[i]=-1;
		}
	}
	~Task50_1_firstNotRepeatingCharFromIostream(){}


	//由于是数据流故无法将字符串保存，需要通过index来记录各个字符的位置
	//以找到第一次出现且index最小的字符
	void Insert(char ch){
		if(hashTable[ch]==-1)
			hashTable[ch]=index;
		else
			hashTable[ch]=-2;
		index++;
	}

	char FirstAppearingOnce(){
		int minimun_indx=INT_MAX;
		char ch='#';
		for(int i=0;i<256;i++){
			if(hashTable[i]>=0 && hashTable[i]<minimun_indx){
				minimun_indx=hashTable[i];
				ch=i;
			}
		}

		return ch;
	}

private:
	int index;
	int hashTable[256];
	
};

int main(int argc, char const *argv[])
{
	char i=4;
	cout<<i<<endl;
	return 0;
}