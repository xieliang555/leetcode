#include<vector>
#include<iostream>

class Task41_maximumSubArray
{
public:
	Task41_maximumSubArray(){}
	~Task41_maximumSubArray(){}

	int maximumSubArray(std::vector<int> array){
		if(array.empty())
			return 0;

		int accuSum=array[0];
		int maxSum=array[0];
		for(int i=1;i<array.size();i++){
			accuSum+=array[i];
			if(accuSum<=array[i]){
				accuSum=array[i];
			}
			if(accuSum>maxSum)
				maxSum=accuSum;
		}

		return maxSum;
	}
	
};

int main(int argc, char const *argv[])
{
	
	Task41_maximumSubArray t;
	std::vector<int> v={-2,-8,-1,-5,-9};
	std::cout<<t.maximumSubArray(v)<<std::endl;
	return 0;
}

