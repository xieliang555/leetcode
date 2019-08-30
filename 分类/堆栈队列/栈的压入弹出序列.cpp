#include<iostream>
#include<stack>
#include<vector>
using namespace std;

/**
 * 剑指offer： 31
 *
 * 辅助栈模拟入栈出栈
 * 本题难点在于循环的起始和终止条件，可以选择试凑法
 * 对于vector1使用for循环，对于vector2使用for循环，对于s.empty()使用while循环，主要尝试这三种选择
 */


bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    if(pushV.size()==0) return false;

	stack<int> s;
	for(int i=0,j=0;i<pushV.size();i++){
		s.push(pushV[i]);
		while(j<popV.size() && s.top()==popV[j]){
			s.pop();
			j++;
		}
	}

	return s.empty();
}


int main(int argc, char const *argv[])
{
	vector<int> pushV={1,2,3,4,5};
	vector<int> popV={4,5,3,2,1};
	cout<<IsPopOrder(pushV,popV)<<endl;
	return 0;
}

