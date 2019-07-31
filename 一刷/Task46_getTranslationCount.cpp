#include<iostream>
using namespace std;

class Task46_getTranslationCount
{
public:
	Task46_getTranslationCount(){}
	~Task46_getTranslationCount(){}

	int getTranslationCount(int number){
	
		if(number<0) return 0;

		if(number<10 || (number>25 && number<100)) return 1;

		if(number>=10 && number<=25) return 2;

		int count2=1,count1;
		if(number%100 <=25 && number%100>=10)
			count1=2;
		else
			count1=1;

		int bit2=number/10%10,bit1;
		number/=100;
		while(number!=0){
			bit1=number%10;
			int combinedBits=bit1*10+bit2;
			int g=0;
			if(combinedBits<=25&& combinedBits>=10)  g=1;
			int ret=count1+g*count2;

			count2=count1;
			count1=ret;
			bit2=bit1;
			number/=10;
		}

		return count1;
	}
	
};



//剑指offer提供代码
int GetTranslationCount(const string& number);

int GetTranslationCount(int number)
{
    if(number < 0)
        return 0;

    string numberInString = to_string(number);
    return GetTranslationCount(numberInString);
}

int GetTranslationCount(const string& number)
{
    int length = number.length();
    int* counts = new int[length];
    int count = 0;

    for(int i = length - 1; i >= 0; --i)
    {
        count = 0;
         if(i < length - 1)
               count = counts[i + 1];
         else
               count = 1;

        if(i < length - 1)
        {
            int digit1 = number[i] - '0';
            int digit2 = number[i + 1] - '0';
            int converted = digit1 * 10 + digit2;
            if(converted >= 10 && converted <= 25)
            {
                if(i < length - 2)
                    count += counts[i + 2];
                else
                    count += 1;
            }
        }

        counts[i] = count;
    }

    count = counts[0];
    delete[] counts;

    return count;
}


int main(int argc, char const *argv[])
{
	Task46_getTranslationCount t;
	for(int i=0;i<12258;i++){
		if(t.getTranslationCount(i)!=GetTranslationCount(i)){
			cout<<i<<' '<<t.getTranslationCount(i)<<' '<<GetTranslationCount(i)<<endl;
			break;
		}
	}
	return 0;
}