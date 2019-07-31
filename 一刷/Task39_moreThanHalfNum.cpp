#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Task39_moreThanHalfNum
{
public:
	Task39_moreThanHalfNum(){}
	~Task39_moreThanHalfNum(){}

	//时间复杂度：o(n)
	int MoreThanHalfNum(vector<int> numbers){
		int val=numbers[0];
		int count=1;
		for(int i=1;i<numbers.size();i++){
			if(count==0){
				val=numbers[i];
				count=1;
			}
			else if(val!=numbers[i])
				count--;
			else
				count++;
		}

		// check if no number is more than half
		int countCheck=0;
		for(int i=0;i<numbers.size();i++){
			if(numbers[i]==val)
				countCheck++;
		}

		if(countCheck>(numbers.size()/2))
			return val;
		else
			return 0;
	}


	//快排思想，二分查找，由于二分后只需解决单子问题，故用循环，不用递归
	//平均时间复杂度：o(n)，缺点：会改变原数组顺序
	int MoreThanHalfNum_1(vector<int> numbers){
		int begin=0;
		int end=numbers.size()-1;
		int mid=numbers.size()/2;
		int index=partition(numbers, begin,end);
		while(index!=mid){
			if(index<mid){
				begin=index+1;
				index=partition(numbers,begin,end);
			}
			else
				end=index-1;
				index=partition(numbers,begin,end);
		}

		int result=numbers[index];
		// check if no number is more than half
		int countCheck=0;
		for(int i=0;i<numbers.size();i++){
			if(numbers[i]==result)
				countCheck++;
		}

		if(countCheck>(numbers.size()/2))
			return result;
		else
			return 0;
	}

	int partition(vector<int>& v, int begin, int end){
		//三数值取中
		int mid=(begin+end)/2;
		if(v[begin]>v[mid]) swap(v[begin],v[mid]);
		if(v[mid]>v[end]) swap(v[mid],v[end]);
		if(v[begin]>v[end]) swap(v[begin],v[end]);
		swap(v[begin],v[mid]);

		int tmp=v[begin];
		while(begin<end){
			// 注意（1）从右向左开始遍历，（2）双重循环注意越界处理
			// (3) 当需要访问vec[end]时，end取最后一位元素，而不是空
			// (4)必须取等号，否则2，3，3，5，3会死循环
			while(begin<end && v[end]>=tmp) end--;
			v[begin]=v[end];
			while(begin<end && v[begin]<=tmp) begin++;
			v[end]=v[begin];
		}
		v[begin]=tmp;
		return begin;
	}
	
};

int main(int argc, char const *argv[])
{
	Task39_moreThanHalfNum t;
	vector<int> v={1,2,3,2,5,4,2};
	cout<<t.MoreThanHalfNum(v)<<endl;
	cout<<t.MoreThanHalfNum_1(v)<<endl;
	return 0;
}