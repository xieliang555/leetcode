#include<iostream>
#include<string>
using namespace std;

int firstNotRepeatingChar(string str){
	if(str.size()<=0) return -1;
	//一定要初始化为0，否则可能
	int hashTable[256]={0};
	int index=-1;
	for(int i=0;i<str.size();i++){
		hashTable[str[i]]++;
	}
	for(int i=0;i<str.size();i++){
		if(hashTable[str[i]]==1){
			index=i;
			break;
		}
	}
	return index;
}

int main(int argc, char const *argv[])
{
	cout<<firstNotRepeatingChar("googgle")<<endl;

	//为初始化的数组可能出现随机数
	int a[10];
	for(int i=0;i<10;i++)
		cout<<a[i]<<' ';
	cout<<endl;

	//字符型作为整型来用时（作为下标，或加减乘除,或赋值），取字符的ASCII
	char s='0';
	int arr[256];
	for(int i=0;i<256;i++)
		arr[i]=i;
	cout<<arr[s]<<endl;

	char x='0';
	char y='1';
	char sum=x+y;
	cout<<sum<<endl;

	// '0'的ASCII是48
	char z=48;
	cout<<z<<endl;

	return 0;
}