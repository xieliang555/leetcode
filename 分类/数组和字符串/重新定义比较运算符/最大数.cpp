#include<vector>
#include <iostream>
using namespace std;

/**
 * 给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
 * 输入: [3,30,34,5,9]
 * 输出: 9534330
 */

struct cmp
{
	bool operator()(string s1, string s2){
		string a=s1+s2;
		string b=s2+s1;
		return a>b;
	}
};

string largestNumber(vector<int>& nums){

	vector<string> tmp;
	for(auto i:nums)
		tmp.push_back(to_string(i));
	sort(tmp.begin(),tmp.end(),cmp());
	string ret;
	for(auto i:tmp)
		ret+=i;

	if(tmp[0]=="0") return tmp[0];

	return ret;
}

int main(int argc, char const *argv[])
{
	vector<int> v={0,0};
	cout<<largestNumber(v)<<endl;
	return 0;
}