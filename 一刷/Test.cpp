#include<iostream>
#include<cstring>
#include<string>
#include<stack>
#include<vector>
#include<typeinfo>
#include<cmath>
using namespace std;

class Test
{
public:
	Test(){}
	~Test(){}

};




int main(int argc, char const *argv[])
{
	int arr[2][3]={{1,2,3},{4,5,6}};
	int (*a)[3]=arr;
	cout<<**a<<endl;
	cout<<**(a+1)<<endl;
	cout<<*(*a+1)<<endl;
	cout<<*(a[0]+1)<<endl;
	cout<<*(a[1])<<endl;
	cout<<*a<<endl;
	cout<<"===================="<<endl;

	char str[]="hello";
	const char* str2="hello";
	cout<<typeid(str).name()<<endl;
	cout<<typeid(&str).name()<<endl;
	cout<<typeid(const char*).name()<<endl;
	cout<<typeid(char*).name()<<endl;
	cout<<"======================"<<endl;
	cout<<typeid(a).name()<<endl;
	// cout<<typeid(&a).name()<<endl;
	cout<<typeid(arr).name()<<endl;
	// cout<<typeid(&arr).name()<<endl;
	cout<<typeid(char(*)[6]).name()<<endl;
	cout<<typeid(char[2][3]).name()<<endl;
	cout<<typeid(&arr[0]).name()<<endl;
	cout<<typeid(char**).name()<<endl;
	cout<<"======================="<<endl;


	cout<<dec<<INT_MAX<<' '<<hex<<INT_MAX<<' '<<bitset<32>(INT_MAX)<<endl;
	cout<<dec<<INT_MIN<<' '<<hex<<INT_MIN<<' '<<bitset<32>(INT_MIN)<<endl;
	cout<<dec<<LONG_MAX<<' '<<hex<<LONG_MAX<<' '<<bitset<64>(LONG_MAX)<<endl;
	cout<<dec<<LONG_MIN<<' '<<hex<<LONG_MIN<<' '<<bitset<64>(LONG_MIN)<<endl;
	cout<<dec<<UINT_MAX<<' '<<hex<<UINT_MAX<<' '<<bitset<32>(UINT_MAX)<<endl;
	cout<<dec<<ULONG_MAX<<' '<<hex<<ULONG_MAX<<' '<<bitset<64>(ULONG_MAX)<<endl;
	cout<<"=================================================================="<<endl;





	return 0;
}