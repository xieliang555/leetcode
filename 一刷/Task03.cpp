#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 3.1
 */

class Duplication
{
public:
	Duplication(){};
	~Duplication(){};

	bool duplicate(int num[],int length,int* duplicate){

		//数组作为函数参数退化为指针
		if(num==nullptr || length<=0) return false;

		for(int i=0;i<length;i++){
			while(num[i]!=i){
				if(num[i]==num[num[i]]){
					*duplicate=num[i];
					return true;
				}
				swap(num[i],num[num[i]]);
			}
		}
		return false;
	}
	
};

int main(int argc, char const *argv[])
{
	int arr[]={2,3,1,0,2,5,3};
	int a;
	int* dup=&a;
	Duplication d;
	bool b=d.duplicate(arr,7,dup);
	cout<<boolalpha<<b<<' '<<*dup<<endl;
	return 0;
}