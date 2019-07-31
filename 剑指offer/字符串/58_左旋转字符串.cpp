#include<iostream>
#include<vector>
#include<string>
using namespace std;

void rotate(string& s, int left, int right){

	while(left<right){
		swap(s[left],s[right]);
		left++;
		right--;
	}
}

string LeftRotateString(string str, int n){

	rotate(str, 0, str.size()-1);
	rotate(str, 0,str.size()-1-n);
	rotate(str, str.size()-n, str.size()-1);
	return str;

}

int main(int argc, char const *argv[])
{
	string s="abcdefgh";
	cout<<LeftRotateString(s, 2);
	return 0;
}