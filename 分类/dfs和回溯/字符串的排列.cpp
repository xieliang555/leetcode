#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/**
 * 剑指offer: 38
 * 依次交换第一位和剩余位，得到第一位的所有可能
 * 然后再利用dfs，对于其余位重复上述步骤
 *
 * 本题易错：
 * 1)字符串可能出现重复的字符如：“aab”
 * 2)遗漏swap
 */

vector<string> result;

void recursionCore(string str, int begin){
	if(begin==str.size()-1){
		for(auto i:result){
			// 避免"aa"出现两次
			if(i==str)
				return;
		}
		result.push_back(str);
		return;
	}
	for(int i=begin; i<str.size();i++){
		swap(str[begin],str[i]);
		recursionCore(str, begin+1);
		// 容易漏
		swap(str[begin],str[i]);
	}
}

vector<string> Permutation(string str) {
    if(str.empty()) return vector<string>();
    recursionCore(str,0);
    sort(result.begin(), result.end());
    return result;
}

int main(int argc, char const *argv[])
{
	string s="aab";
	vector<string> ret=Permutation(s);
	for(auto i:ret)
		cout<<i<<' '<<endl;
	return 0;
}