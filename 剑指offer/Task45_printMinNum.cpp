#include<vector>
#include<string>
#include<algorithm>
#include<iostream>

class Task45_printMinNum
{
public:
	Task45_printMinNum(){}
	~Task45_printMinNum(){}

	static bool cmp(int a, int b){
		std::string A;
		std::string B;
		A+=std::to_string(a);
		A+=std::to_string(b);
		B+=std::to_string(b);
		B+=std::to_string(a);
		return A<B;
	}

	std::string printMinNum(std::vector<int> numbers){
		if(numbers.empty()) return std::string();
		std::sort(numbers.begin(),numbers.end(),cmp);
		std::string ret;
		for(int i=0;i<numbers.size();i++){
			ret+=std::to_string(numbers[i]);
		}
		return ret;
	}
	
};

int main(int argc, char const *argv[])
{
	std::vector<int> v={3,32,321};
	Task45_printMinNum t;
	std::cout<<t.printMinNum(v)<<std::endl;
	return 0;
}