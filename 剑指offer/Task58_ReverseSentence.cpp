#include<string>
using namespace std;

void ReverseWord(string& ,int, int);

//sentence规范，即word之间只有一个空格
string ReverseSentence(string str){
	if(str.size()<=0) return str;
	ReverseWord(str,0,str.size()-1);
	int left=0;
	for(int i=0;i<str.size()+1;i++){
		if(str[i]==' ' || str[i]=='\0'){
			ReverseWord(str,left,i-1);
			left=i+1;
		}

	}
	return str;
}

void ReverseWord(string& str, int left, int right){
	while(left<right){
		swap(str[left],str[right]);
		left++;
		right--;
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
