#include<iostream>
#include<deque>
#include<vector>
using namespace std;

/**
 * 剑指offer： 59_1
 *
 * 需注意：
 * 1）需要两端进出，故使用deque而不是queue
 * 2）需要检查队列首的元素是否过期，故队列存储的是元素的下标而不是该元素
 * 3）deque的操作在整个遍历过程是统一的，即每遍历一个数，考虑该数在队列的位置，然后检查队列首元素是否过期
 *   而vector的操作是在遍历到满足i>=size-1时才开始操作
 *
 */

vector<int> maxInWindows(const vector<int>& num, unsigned int size){

	vector<int> ret;
	deque<int> q;
	for(int i=0;i<num.size();i++){
		if(q.empty() || num[q.back()]>=num[i]){
			q.push_back(i);
		}
		else if(!q.empty() && num[q.back()]<num[i]){
			while(!q.empty() && num[q.back()]<num[i])
				q.pop_back();
			q.push_back(i);
		}
		if((i-q.front())>=size)
			q.pop_front();
		if(i>=(size-1)){
			ret.push_back(num[q.front()]);
		}
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	vector<int> num={2,3,4,2,6,2,5,1};
	vector<int> ret=maxInWindows(num,3);
	for(auto i:ret)
		cout<<i<<endl;
	return 0;
}