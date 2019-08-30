#include<stdio.h>
#include<climits>
#include<vector>
#include<iostream>
#include<list>
#include<map>
using namespace std;

void longestConsecutive(vector<int> &num) {
        // write your code here
        for(auto n:num)
            cout<<n<<endl;
}

vector<int> productExceptSelf(vector<int>& nums) {
    if(nums.size()<2) return vector<int>();
    int len=nums.size();
    vector<int> tmp1={1};
    vector<int> tmp2={1};
    vector<int> ret;
    for(int i=1;i<len;i++){
        tmp1.push_back(tmp1[i-1]*nums[i]);
        tmp2.push_back(tmp2[i-1]*nums[len-i]);
    }
    cout<<tmp1.size()<<' '<<tmp2.size()<<endl;
    for(int i=0;i<len;i++){
        ret.push_back(tmp1[i]*tmp2[len-i-1]);
    }
    return ret;

}

int main(int argc, char const *argv[])
{
	// printf("%d\n", INT_MAX);
	// list<int> a={1,2,3,4};
	// auto iter=a.begin();
	// cout<<(*iter);
	// iter++;
	// iter--;
	// cout<<(*iter);//

    // vector<int> a={1,2,3,4};
    // longestConsecutive(a);
    
    vector<int> a={1,2,3,4};
    vector<int> ret=productExceptSelf(a);
    return 0;
}
