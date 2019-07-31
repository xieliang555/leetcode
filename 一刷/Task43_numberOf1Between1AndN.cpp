#include<iostream>

class Task43_numberOf1Between1AndN
{
public:
	Task43_numberOf1Between1AndN(){}
	~Task43_numberOf1Between1AndN(){}

	int NumberOf1Between1AndN(int n){

		int count=0;
		int i=1;
		while(n/i!=0){
			
			int lowBits=n%i;
			int highBits=n/(i*10);
			int currentBit=(n/i)%10;

			if(currentBit==0){
				count+=highBits*i;
			}
			else if(currentBit==1){
				count+=highBits*i+lowBits+1;
			}
			else
				count+=(highBits+1)*i;

			i*=10;

		}

		return count;
	}
	
};

int main(int argc, char const *argv[])
{
	Task43_numberOf1Between1AndN t;
	std::cout<<t.NumberOf1Between1AndN(12)<<std::endl;
	return 0;
}