#include<iostream>
#include<string>
using namespace std;

/*
请实现一个函数，将一个字符串中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
 */

void replaceSpace(string& s){


	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]==' '){
			s+="  ";
		}
	}

	int left=len-1;
	int right=s.size()-1;
	while(left>=0 && right>=0){
		if(s[left]==' '){
			s[right--]='0';
			s[right--]='2';
			s[right--]='%';
			left--;
		}
		s[right--]=s[left--];
	}

}

int main(int argc, char const *argv[])
{

	string s=" hello world";
	replaceSpace(s);
	cout<<s<<endl;
	return 0;
}