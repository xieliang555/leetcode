#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Task38_permutation
{
public:
	Task38_permutation(){}
	~Task38_permutation(){}

	vector<string> Permutation(string str){

		vector<string> result;
		if(str.empty()) return result;
		permutation(str, 0, result);
		sort(result.begin(),result.end());
		return result;
	}

	void permutation(string str, int begin, vector<string>& result){
		if(begin==str.size()-1){
			//避免“aa”出现两次
			if(find(result.begin(),result.end(),str)==result.end())
				result.push_back(str);
		}
		else{
			for(int i=begin;i<str.size();i++){
				swap(str[begin],str[i]);
				permutation(str, begin+1,result);
				swap(str[begin],str[i]);
			}
		}
	}
	
};

int main(int argc, char const *argv[])
{
	Task38_permutation t;
	string str="aa";
	vector<string> ret=t.Permutation(str);
	for(int i=0;i<ret.size();i++)
		cout<<ret[i]<<endl;
	return 0;
}