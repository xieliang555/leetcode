#include<queue>
#include<vector>
#include<functional>

class Task41_medianOfDataStream
{
public:
	Task41_medianOfDataStream(){}
	~Task41_medianOfDataStream(){}

	std::priority_queue<int,std::vector<int>, std::less<int> > max_heap;
	std::priority_queue<int, std::vector<int>, std::greater<int> > min_heap;

	void Insert(int num){
		if(min_heap.empty() || num>min_heap.top())
			min_heap.push(num);
		else
			max_heap.push(num);
		//调整
		if(min_heap.size()==max_heap.size()+2){
			max_heap.push(min_heap.top());
			min_heap.pop();
		}
		//保持最小堆size>=最大堆size
		if(min_heap.size()+1==max_heap.size()){
			min_heap.push(max_heap.top());
			max_heap.pop();
		}

	}

	double GetMedian(){
		//必须处以2.0而不是2（因为int/int最后结果是int类型，然后再转换为double类型）
		return max_heap.size()==min_heap.size()?(max_heap.top()+min_heap.top())/2.0:min_heap.top();

	}
	
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}