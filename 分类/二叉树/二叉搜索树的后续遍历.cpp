#include<iostream>
#include<vector>
using namespace std;

/**
 * 剑指offer: 33
 * 
 */


bool recursionCore(vector<int> sequence){
	if(sequence.empty()) return true;
	vector<int> left, right;
	int curNode=sequence.back();
	int i=0;
	for(;sequence[i]<curNode;i++)
		left.push_back(sequence[i]);
	for(;i<sequence.size()-1;i++){
		if(sequence[i]>curNode)
			right.push_back(sequence[i]);
		else
			return false;
	}
	bool leftRet=recursionCore(left);
	bool rightRet=recursionCore(right);
	return leftRet && rightRet;
}

bool VerifySquenceOfBST(vector<int> sequence){
	if(sequence.empty()) return false;
	return recursionCore(sequence);
}

int main(int argc, char const *argv[])
{
	
	return 0;
}