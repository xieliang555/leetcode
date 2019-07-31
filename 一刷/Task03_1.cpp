#include<iostream>
using namespace std;

/**
 * 3.2解1,时间复杂度O(n),空间复杂的O(n)
 */

class Duplication2
{
public:
	Duplication2(){};
	~Duplication2(){};

	int getDuplicate1(const int* num, const int length, int tmp[]){
		if(num==nullptr) 
			return -1;
	
		for(int i=0;i<length;i++){
			tmp[num[i]]++;
			if(tmp[num[i]]>1)
				return tmp[num[i]];
		}
		return -1;
	}
	
};

void test1(){
	int arr[]={1,3,2,3,2,4};
	int tmp[6]={0};
	Duplication2 d;
	cout<<d.getDuplicate1(arr,6,tmp)<<endl;
}

void test2(){
	int* arr=nullptr;
	int tmp[1]={0};
	Duplication2 d;
	cout<<d.getDuplicate1(arr,0,tmp)<<endl;
}

void test3(){
	int arr[]={0,1,2,3,4,5};
	int tmp[6]={0};
	Duplication2 d;
	cout<<d.getDuplicate1(arr,6,tmp)<<endl;
}

int main(int argc, char const *argv[])
{
	cout<<"method 1:"<<endl;
	cout<<"test1 begin"<<endl;
	cout<<"the expected result is: "<<endl;
	cout<<"2 or 3"<<endl;
	cout<<"the actual result is: "<<endl;
	test1();
	cout<<"========================"<<endl;
	cout<<"test2 begin"<<endl;
	cout<<"the expected result is: "<<endl;
	cout<<"-1"<<endl;
	cout<<"the actual result is: "<<endl;
	test2();
	cout<<"========================"<<endl;
	cout<<"test3 begin"<<endl;
	cout<<"the expected result is: "<<endl;
	cout<<"-1"<<endl;
	cout<<"the actual result is: "<<endl;
	test3();
	cout<<"========================"<<endl;
	return 0;
}