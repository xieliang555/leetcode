#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/**
 * 剑指offer: 45
 *
 * 重新定义比较运算符
 */


static bool cmp(string s1, string s2){
	string a=s1+s2;
	string b=s2+s1;
	return a<b;
}

string PrintMinNumber(vector<int> numbers){

	vector<string> s;
	for(auto i:numbers){
		s.push_back(to_string(i));
	}
	sort(s.begin(), s.end(), cmp);
	string ret;
	for(auto i:s)
		ret+=i;
	return ret;
}

int main(int argc, char const *argv[])
{
	vector<int> numbers={3,32,321};
	cout<<PrintMinNumber(numbers)<<endl;
	return 0;
}