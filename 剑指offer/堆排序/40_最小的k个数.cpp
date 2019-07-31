#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k){

	if(input.empty() || k>input.size() || k<=0) return vector<int>();

	priority_queue<int> pq;
	for(auto i:input){
		if(pq.size()<k){
			pq.push(i);
		}
		else if(i<pq.top()){
			pq.pop();
			pq.push(i);
		}
	}

	vector<int> ret;
	while(!pq.empty()){
		ret.push_back(pq.top());
		pq.pop();
	}

	sort(ret.begin(), ret.end());

	return ret;
}

int main(int argc, char const *argv[])
{
	vector<int> input={1,2,3,5,3,6};
	vector<int> ret=GetLeastNumbers_Solution(input, 4);
	for(auto i: ret)
		cout<<i<<' ';
	return 0;
}