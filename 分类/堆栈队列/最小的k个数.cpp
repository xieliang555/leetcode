#include<iostream>
#include<queue>
#include<vector>
using namespace std;

/**
 * 剑指offer: 40
 *
 * 本题应注意stl中priority_queue的使用，模版初始化顺序依次为元素类型，容器类型，大堆(less<int>或小堆(greater<int>))
 * 求最小的k个数用大顶堆，求最大的k个数，用小顶堆
 */

vector<int> GetLeastNumbers_Solution(vector<int> input, int k){
	if(input.empty() || k>input.size() || k<=0) return vector<int>();
	priority_queue<int, vector<int>, less<int> > pq;
	for(auto i: input){
		if(pq.size()<k)
			pq.push(i);
		else{
			if(i<pq.top()){
				pq.pop();
				pq.push(i);
			}
		}
	}
	vector<int> ret(k);
	while(!pq.empty()){
		ret[--k]=pq.top();
		pq.pop();
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	vector<int> input={4,5,1,6,2,7,3,8};
	vector<int> ret=GetLeastNumbers_Solution(input,4);
	for(auto i:ret)
		cout<<i<<endl;
	return 0;
}