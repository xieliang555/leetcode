#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Task21_reorderArray
{
public:
	Task21_reorderArray(){}
	~Task21_reorderArray(){}

	//参考快速排序(不稳定)的思路,时间复杂度0(n)，但无法保证奇数与奇数，偶数与偶数之间的相对位置,不稳定
	void reOrderArray(vector<int> &array){
		int begin=0,end=array.size()-1;
		while(begin<end){
			while(begin<end && (array[begin] & 0x1)==1) begin++;
			while(begin<end && (array[end] & 0x1)!=1) end--;
			swap(array[begin],array[end]);
			begin++;
			end--;
		}
	}

	// 时间复杂度O(n^2),也可以考虑插入排序，遇到奇数往前移
	void reOrderArrayStable(vector<int> &array){
		vector<int>::iterator it=array.begin();
		for(int i=0;i<array.size();i++){
			if((*it & 0x1)!=1){
				int tmp=*it;
				array.erase(it);
				array.push_back(tmp);
			}
			else
				it++;
		}
	}
	
};

int main(int argc, char const *argv[])
{
	vector<int> v={1,1,1};
	Task21_reorderArray t;
	t.reOrderArray(v);
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<' ';
	return 0;
}