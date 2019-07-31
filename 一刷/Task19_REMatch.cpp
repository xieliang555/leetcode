#include<iostream>
#include<cstring>
using namespace std;

/**
 * pattern 是'.*'时，str可以是任意长度的任意字符，如"ab"和".*"匹配
 * str中不包括'.','*'字符
 */

class Task19_REMatch
{
public:
	Task19_REMatch(){}
	~Task19_REMatch(){}

	bool match(char* str, char* pattern){

		//空字符串不代表空指针
		if(str==nullptr || pattern==nullptr)
			return false;

		return matchCore(str,pattern);

	}

	bool matchCore(char* str, char* pattern){

		if(*str=='\0' && *pattern=='\0')
			return true;
		if(*str!='\0' && *pattern=='\0')
			return false;

		//模式第二个是‘*’
		if(*(pattern+1)=='*'){
			if(*pattern==*str || ((*pattern=='.') && *str!='\0')){
				return matchCore(str,pattern+2) ||
					   matchCore(str+1,pattern+2) ||
					   matchCore(str+1,pattern);
			}
			else
				return matchCore(str,pattern+2);
		}

		//第二个模式不是‘*’
		if((*pattern=='.' && *str!='\0') || *pattern==*str)
			return matchCore(str+1,pattern+1);

		return false;
	}
	
};

int main(int argc, char const *argv[])
{
	char str[4]="aa";
	char pattern[8]=".*";
	Task19_REMatch t;
	cout<<boolalpha<<t.match(str,pattern)<<endl;
	return 0;
}