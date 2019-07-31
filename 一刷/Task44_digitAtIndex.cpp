#include<iostream>
#include<cmath>
#include<string>

class Task44_digitAtIndex
{
public:
	Task44_digitAtIndex(){}
	~Task44_digitAtIndex(){}

	int DigitAtIndex(int index){
		if(index<0) return -1;

		else if(index<10) return index;

		else{
			int count=2;
			int number=index-9;
			while(true){
				int indexFromRight=9*pow(10,count-1)*count;
				if(number<=indexFromRight)
					break;
				else{
					number-=indexFromRight;
					count++;
				}
			}

			int ret, numberAtIndex;
			if(number%count==0){
				numberAtIndex=std::pow(10,count-1)+number/count-1;
				ret=numberAtIndex%10;
			}
			else{
				numberAtIndex=std::pow(10,count-1)+number/count;
				ret=numberAtIndex/std::pow(10,count-number%count);
			}
			return ret%10;
		}

	}
	
};

int main(int argc, char const *argv[])
{
	Task44_digitAtIndex t;
	int a[]={0,1,9,10,189,190,1000,1001,1002};
	for(int i=0;i<9;i++)
		std::cout<<t.DigitAtIndex(a[i])<<' ';
	return 0;
}