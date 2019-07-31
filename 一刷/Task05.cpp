#include<iostream>
using namespace std;

/**
 * 5
 * length是字符串数组总容量
 */

class ReplaceBlank
{
public:
	ReplaceBlank(){};
	~ReplaceBlank(){};

	void replace(char* str, int length){

		if(str==nullptr||length<=0) return;

		int blankCount=0;
		int realSize=0;
		for(int i=0;str[i]!='\0';i++){
			realSize++;
			if(str[i]==' '){
				blankCount++;
			}
		}

		//从'\0'开始，而不是从最后一个字符开始
		int newIndex=realSize+2*blankCount;
		int originIndex=realSize;

		if(newIndex>length) return;

		while(originIndex>=0 && newIndex>originIndex){
			if(str[originIndex]==' '){
				str[newIndex--]='0';
				str[newIndex--]='2';
				str[newIndex--]='%';
			}
			else{
				str[newIndex--]=str[originIndex];
			}
			originIndex--;
		}
	}	
};

int main(int argc, char const *argv[])
{
	char s[]=" helloworld";
	cout<<s<<endl;
	ReplaceBlank r;
	r.replace(s,20);
	cout<<s<<endl;
	return 0;
}