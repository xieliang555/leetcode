#include<iostream>
#include<vector>
using namespace std;

class Task11
{
public:
	Task11(){}
	~Task11(){}

	int func(vector<int> rotateArray){

		int left=0,right=rotateArray.size()-1;
		int mid;

		if(rotateArray[left]<rotateArray[right])
			return rotateArray[left];

		while(left<right-1){
			mid=(left+right)/2;

			if(rotateArray[mid]==rotateArray[left]
				&& rotateArray[mid]<=rotateArray[right]){
				for(int i=left+1;i<right;i++)
					if(rotateArray[i]<rotateArray[left])
						return rotateArray[i];
			}

			if(rotateArray[mid]>=rotateArray[left])
				left=mid;
			else if(rotateArray[mid]<=rotateArray[right])
				right=mid;

		}
		return rotateArray[right];
	}
	
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}