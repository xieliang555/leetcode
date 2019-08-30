#include<iostream>
#include<cstring>
using namespace std;

class Task20_isNumeric
{
public:
	Task20_isNumeric(){}
	~Task20_isNumeric(){}

	bool isNumeric(char* string){
		if(string==nullptr)
			return false;

		bool numeric=scanInteger(&string);

		if(*string=='.'){
			string++;
			numeric=scanUnsignedInteger(&string) || numeric;
		}

		if(*string=='E'||*string=='e'){
			string++;
			numeric=scanInteger(&string) && numeric;
		}

		return numeric && (*string=='\0');


	}

	bool scanInteger(char** str){
		if(**str=='+'|| **str=='-')
			(*str)++;
		return scanUnsignedInteger(str);
	}

	bool scanUnsignedInteger(char** str){
		char* before=*str;
		while(**str>='0' && **str<='9')
			(*str)++;
		return *str>before;
	}
	
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}