#include<iostream>
using namespace std;

/**
 * 3.2解2,时间复杂度O(nlogn),空间复杂度O(1)
 */

class Duplication3
{
public:
	Duplication3(){};
	~Duplication3(){};
	
	int getDuplicate(const int* arr, int length){
		if(arr==nullptr) return -1;
		int begin=0,end=length;
		int count=0;
		while(begin<end-1){
			count =0;
			int mid=(begin+end)/2;
			for(int i=0;i<length;i++){
				if(arr[i]>=begin && arr[i]<mid)
					count++;
			}
			if(count>(mid-begin))
				end=mid;
			else{
				begin=mid;
			}
		}

		count=0;
		for(int i=0;i<length;i++){
			if(arr[i]==begin)
				count++;
		}

		if(count>1)
			return begin;
		else
			return -1;
	}
};

void test1(){
	int arr[]={0,1,2,3,4,5};
	Duplication3 d;
	cout<<"test1 begin:"<<endl;
	cout<<"the expected result is: "<<-1<<endl;
	cout<<"the actual result is:"<<d.getDuplicate(arr,6)<<endl;
	cout<<"=========================="<<endl;
}

void test2(){
	int arr[]={0,1,2,2,4,5,5};
	Duplication3 d;
	cout<<"test2 begin:"<<endl;
	cout<<"the expected result is: "<<"2 or 5"<<endl;
	cout<<"the actual result is:"<<d.getDuplicate(arr,7)<<endl;
	cout<<"=========================="<<endl;
}

void test3(){
	int* arr=nullptr;
	Duplication3 d;
	cout<<"test3 begin:"<<endl;
	cout<<"the expected result is: -1"<<endl;
	cout<<"the actual result is: "<<d.getDuplicate(arr,0)<<endl;
	cout<<"=========================="<<endl;
}


int main(int argc, char const *argv[])
{
	test1();
	test2();
	test3();
	return 0;
}