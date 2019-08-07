#include<iostream>
#include<string>
#include<vector>
using namespace std;


bool wordBreak(string s, vector<string>& wordDict){

	vector<int> dp(s.size()+1);
	dp[0]=1;
	for(int i=1;i<dp.size();i++){
		for(auto word: wordDict){
			if(i>=word.size() && (s.substr(i-word.size(), word.size())==word)){
				dp[i]=dp[i-word.size()] || dp[i];
			}
		}
	}

	return dp.back();
}


// 以下代码有逻辑错误，较难debug
// bool wordBreak(string s, vector<string>& wordDict){

// 	vector<int> dp(s.size()+1);
// 	dp[0]=1;
// 	for(int i=1;i<dp.size();i++){
// 		for(auto word: wordDict){
// 			if(i>=word.size() && (s.substr(i-word.size(), word.size())==word)){
// 				dp[i]=dp[i-word.size()];
// 				break;
// 			}
// 		}
// 	}

// 	return dp.back();
// }

int main(int argc, char const *argv[])
{
	string s="applepenapple";
	vector<string> wordDict={"apple","pen","app"};
	bool ret=wordBreak(s, wordDict);
	cout<<boolalpha<<ret<<endl;
	return 0;
}