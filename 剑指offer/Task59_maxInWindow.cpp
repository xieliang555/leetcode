#include<vector>
#include<deque>
using namespace std;

//记结论及注意迁移(可以用来实现优先队列)

/**
结论：
每从num中读取一个值：
1.当队列不为空时，新增加的值从队尾开始比较，把所有比他小的值弹出
2.判断队首是否过期，过期需要弹出
3.将当前值push到队列尾
*/

/*
迁移：
迁移至queue+deque实现priority_queue（和30题stack+stack实现max stack类似）
本质上维护了一个从大到小排列的deque（30题维护了一个从大到小排列的stack），该deque：
1）队首是最大值且不过期
2）先加入的值小于队尾，直接push进队尾，否则一直pop队尾
*/

//注意看 59_2如何迁移

vector<int> maxInWindows(const vector<int>& num, unsigned int size){
	if(num.empty() || size>num.size() ||size<1)
		return vector<int>();
	vector<int> ret;
	deque<int> index;
	for(int i=0;i<num.size();i++){
		//从后面依次弹出队列中比当前num值小的元素，同时保证队列首元素为当前窗口最大值下标
		while(index.size() && num[index.back()]<=num[i])
			index.pop_back();
		//过期需要弹出
		//举简单例子避免复杂下标计算
		if(index.size() && i-index.front()>=size)
			index.pop_front();
		index.push_back(i);
		//当滑动窗口首地址i大于等于size时才开始写入窗口最大值
		//举简单例子避免复杂的下标计算
		if((i+1)>=size)
			ret.push_back(num[index.front()]);
	}
	return ret;
}


//方法2: priority_queue?（直接调用stl库）

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}