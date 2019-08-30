#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Task31_isPopOrder
{
public:
	Task31_isPopOrder(){}
	~Task31_isPopOrder(){}

	bool isPopOrder(vector<int> pushV,vector<int> popV){

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
	
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}