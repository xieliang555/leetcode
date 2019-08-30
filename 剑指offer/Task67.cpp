#include<string>
#include<climits>
#include<iostream>
using namespace std;

//注意考虑三种输出情况
//（1）：正常输入功能测试
//（2）：边界输入
//（3）：特殊输入
bool IsValidInput=true;

int StrToInt(string str){
	bool minus=false;
	auto pStr=str.begin();
	//不可以判断str==nullptr 或 pStr==nullptr
	//它们都不是指针类型
	if(str.empty()){
		IsValidInput=false;
		return 0;
	}
	else if((*pStr)=='+')
		pStr++;
	else if((*pStr)=='-'){
		minus=true;
		pStr++;
	}
	long long num=0;
	while((*pStr)!='\0'){
		if(num>INT_MAX){
			num=0;
			IsValidInput=false;
			break;
		}
		else if(minus && num<INT_MIN){
			num=0;
			IsValidInput=false;
			break;
		}
		else if((*pStr)>'9' || (*pStr)<'0'){
			num=0;
			IsValidInput=false;
			break;
		}
		num=num*10+(*pStr)-'0';
		pStr++;
	}

	if(minus)
		num=0-num;
	return num;

}

int main(int argc, char const *argv[])
{
	string s="123";
	cout<<StrToInt(s)<<endl;
	return 0;
}