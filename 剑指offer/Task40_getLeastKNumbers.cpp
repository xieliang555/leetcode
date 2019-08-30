#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<functional>
using namespace std;

class Task40_getLeastKNumbers
{
public:
	Task40_getLeastKNumbers(){}
	~Task40_getLeastKNumbers(){}

	//快排思想，平均时间复杂度o(n)，缺点：会改变原数组顺序
	vector<int> getLeastKNumbers(vector<int> input, int k){

		//不考虑k牛客网会超时
		vector<int> ret;
		if(k<=0 || k>input.size()) return ret;

		int begin=0;
		int end=input.size()-1;
		int index=partition(input,begin,end);
		while(index!=k-1){
			if(index<k-1){
				begin=index+1;
				index=partition(input,begin,end);
			}
			else{
				end=index-1;
				index=partition(input,begin,end);
			}
		}

		if(input.empty()) return ret;
		for(int i=0;i<k;i++)
			ret.push_back(input[i]);
		return ret;
	}

	int partition(vector<int>& v, int begin,int end){
		//三数值取中
		int mid=(begin+end)/2;
		if(v[begin]>v[mid]) swap(v[begin],v[mid]);
		if(v[mid]>v[end]) swap(v[mid],v[end]);
		if(v[begin]>v[end]) swap(v[begin],v[end]);
		swap(v[begin],v[mid]);

		int tmp=v[begin];
		while(begin<end){
			while(begin<end && v[end]>=tmp) end--;
			v[begin]=v[end];
			while(begin<end && v[begin]<=tmp) begin++;
			v[end]=v[begin];
		}
		v[begin]=tmp;
		return begin;
	}


	//最大堆思想,时间复杂度o(nlogk),不改变原数组，且适合海量数据
	vector<int> getLeastKNumbers_1(vector<int> input, int k){

		if(k<=0 || k>input.size())
			return vector<int>();

		vector<int> ret(input.begin(),input.begin()+k);
		make_heap(ret.begin(),ret.end());

		for(int i=k;i<input.size();i++){
			if(input[i]<ret.front()){
				pop_heap(ret.begin(),ret.end());
				ret.pop_back();

				ret.push_back(input[i]);
				push_heap(ret.begin(),ret.end());
			}
		}
		sort_heap(ret.begin(),ret.end());
		return ret;
	}

	//红黑树思想，时间复杂度o(nlogk)，不改变原数组，且适合海量数据
	vector<int> getLeastKNumbers_2(vector<int> input, int k){

		if(k<=0||k>input.size())
			return vector<int>();

		//大的放前面
		multiset<int, greater<int> > s; 
		for(int i=0;i<input.size();i++){
			if(s.size()<k){
				s.insert(input[i]);
			}
			else{
				if(input[i]<*(s.begin())){
					s.erase(s.begin());
					s.insert(input[i]);
				}
			}
		}

		vector<int> ret(s.begin(),s.end());
		return ret;
	}
	
};

int main(int argc, char const *argv[])
{
	vector<int> v={3,2,5,4,1};
	Task40_getLeastKNumbers t;
	vector<int> ret=t.getLeastKNumbers_2(v,3);
	for(int i=0;i<ret.size();i++)
		cout<<ret[i]<<' ';
	return 0;
}