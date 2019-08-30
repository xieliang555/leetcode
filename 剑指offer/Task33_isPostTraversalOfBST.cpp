#include<vector>
#include<iostream>
using namespace std;



class Task_33_isPostTraversalOfBST
{
public:
	Task_33_isPostTraversalOfBST(){}
	~Task_33_isPostTraversalOfBST(){}


	bool traversal(vector<int> sequence){
		if(sequence.size()<=0) 
			return false;
		else
			return traversalCore(sequence,0,sequence.size()-1);
	}

	//vector用下标访问比指针(迭代器)更方便，链表用指针
	bool traversalCore(vector<int> sequence, int begin, int end){

		if(begin>=end) return true;

		int demarc=begin;
		while(sequence[demarc]<sequence[end])
			demarc++;
		for(int i=demarc;i<end;i++)
			if(sequence[i]<=sequence[end])
				return false;

		return traversalCore(sequence,begin,demarc-1) && 
			   traversalCore(sequence,demarc,end-1);
	}
	
};

int main(int argc, char const *argv[])
{
	vector<int> arr={7,4,6,5};
	Task_33_isPostTraversalOfBST t;
	cout<<boolalpha<<t.traversal(arr);
	return 0;
}