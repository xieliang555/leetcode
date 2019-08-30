#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

/**
 * leetcode: 347
 * map默认按照key排序，如果要按照value排序，自定义仿函数报错？
 * 
 * 此题采用unordered_map统计频率, 然后使用priority_queue对value排序
 *
 * 自定义仿函数：
 * 仿函数即行为像函数的类或结构体
 * 重载括号运算符operator() 
 * 左边大于右边为true则为降序，左边小于右边为true则为升序
 *
 * 注意priority_queue的仿函数与map,sort等其他的相反
 */

struct cmp{
	bool operator()(const pair<int, int>& left, const pair<int, int>& right){
		return left.second>right.second;
	}
};

vector<int> topKFrequent(vector<int>& nums, int k){

	unordered_map<int,int> um;
	for(auto i:nums){
		um[i]++;
	}
	vector<int> ret(k);
	priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
	for(auto i:um){
		if(pq.size()<k)
			pq.push(i);
		else if(i.second>pq.top().second){
			pq.pop();
			pq.push(i);
		}
	}
	while(!pq.empty()){
		ret[--k]=pq.top().first;
		pq.pop();
	}

	return ret;
}

int main(int argc, char const *argv[])
{
	vector<int> nums={1,1,1,2,2,3};
	vector<int> ret=topKFrequent(nums, 2);
	for(auto i:ret){
		cout<<i<<endl;
	}
	return 0;
}