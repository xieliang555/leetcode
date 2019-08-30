#include<iostream>
#include<vector>
using namespace std;

/**
 * vector版,看第2版
 */

class TwoDArrayFind2
{
public:
	TwoDArrayFind2(){};
	~TwoDArrayFind2(){};
	
	bool find(int target,vector<vector<int> > array){
		int c=array[0].size()-1;
		int r=0;
		bool flag=false;
		while(c>=0 && r<array.size()){

			if(array[r][c]<target){
				r++;
			}	
			else if(array[r][c]>target){
				c--;
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
	int matrix[]={1,2,3,2,4,9,4,7,10};
	vector<vector<int> > arr(3);
	int count=0;
	for(int i=0;i<3;i++)
		arr[i].resize(3);
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			arr[i][j]=matrix[count++];
	int n=4;
	TwoDArrayFind2 t;
	cout<<"test1 begin:"<<endl;
	cout<<"the expected result is:  true"<<endl;
	cout<<"the actual result is: "<<boolalpha<<t.find(n,arr)<<endl;
	cout<<"=========================="<<endl;
}

void test2(){
	int matrix[]={1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
	vector<vector<int> > arr(4);
	int count=0;
	for(int i=0;i<4;i++)
		arr[i].resize(4);
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			arr[i][j]=matrix[count++];
	int n=11;
	TwoDArrayFind2 t;
	cout<<"test2 begin:"<<endl;
	cout<<"the expected result is:  true"<<endl;
	cout<<"the actual result is: "<<boolalpha<<t.find(n,arr)<<endl;
	cout<<"=========================="<<endl;
}


int main(int argc, char const *argv[])
{
	test1();
	test2();
	return 0;
}