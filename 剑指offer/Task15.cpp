#include<iostream>
using namespace std;

class Task15
{
public:
	Task15(){}
	~Task15(){}

	int numberOf1(int n){
		int count=0;
		while(n){
			count++;
			n=(n-1)&n;
			cout<<n<<' ';
		}
		return count;
	}
	
};

int main(int argc, char const *argv[])
{
	Task15 t;
	t.numberOf1(9);
	cout<<abs(INT_MIN)<<' '<<INT_MIN<<endl;
	cout<<INT_MAX<<endl;
	cout<<INT_MAX+1<<endl;
	return 0;
}