#include<iostream>
using namespace std;

/**
 * 4 指针版
 */

class TwoDArrayFind
{
public:
	TwoDArrayFind(){};
	~TwoDArrayFind(){};

	bool find(int* matrix, int columns, int rows,int number){
		const int c=columns;
		int* corner=matrix+columns-1;
		bool flag=false;
		while(matrix!=nullptr && columns>0 && rows>0){

			if(*corner<number){
				rows--;
				corner+=c;
			}
			else if(*corner>number){
				columns--;
				corner-=1;
			}
			else{
				flag=true;
				break;
			}
		}
		return flag;
	}
	
};


void test1(){
	int matrix[]={1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
	int n=11;
	TwoDArrayFind t;
	cout<<"test1 begin:"<<endl;
	cout<<"the expected result is:  true"<<endl;
	cout<<"the actual result is: "<<boolalpha<<t.find(matrix,4,4,n)<<endl;
	cout<<"=========================="<<endl;
}

void test2(){
	int matrix[]={1,2,3,2,4,9,4,7,10};
	int n=11;
	TwoDArrayFind t;
	cout<<"test2 begin:"<<endl;
	cout<<"the expected result is:  false"<<endl;
	cout<<"the actual result is: "<<boolalpha<<t.find(matrix,3,3,n)<<endl;
	cout<<"=========================="<<endl;
}

void test3(){
	int* matrix=nullptr;
	int n=4;
	TwoDArrayFind t;
	cout<<"test3 begin:"<<endl;
	cout<<"the expected result is:  false"<<endl;
	cout<<"the actual result is: "<<boolalpha<<t.find(matrix,3,3,n)<<endl;
	cout<<"=========================="<<endl;
}


int main(int argc, char const *argv[])
{
	test1();
	test2();
	test3();
	return 0;
}