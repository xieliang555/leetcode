#include<iostream>
#include<queue>
#include<vector>
using namespace std;

/**
 * 剑指offer: 41
 *
 * 本题易错：p1.size()返回的是unsigned long long类型，如果p1.size()<p2.size()，
 * 相减仍是unsigned long long类型，不会得到负数，会溢出，尽量避免size()相减
 *
 * 本题思路：
 * 初始状态先插入小顶堆（小顶堆存储大较大的数，大顶堆存储着较小的数）
 * 后面的数与小顶堆堆顶比较，如果比堆顶小，插入大顶堆，如果比小顶堆大，插入小顶堆
 * 每一次插入数据，维持小顶堆size>=大顶堆size
 */

priority_queue<int, vector<int>, greater<int> > p1;
priority_queue<int, vector<int>, less<int> > p2;

void Insert(int num){
    
    if(p1.empty() || num>p1.top())
    	p1.push(num);
    else
    	p2.push(num);
    // 调整
    if(p1.size()==p2.size()+2){
    	p2.push(p1.top());
    	p1.pop();
    }
    // 调整
    if(p2.size()>p1.size()){
    	p1.push(p2.top());
    	p2.pop();
    }
}


double GetMedian(){ 
	return p1.size()>p2.size()?p1.top():(p1.top()+p2.top())/2.0;
}

int main(int argc, char const *argv[])
{
	Insert(5);
	Insert(2);
	Insert(3);
	cout<<GetMedian()<<endl;
	return 0;
}