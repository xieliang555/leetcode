#include<iostream>
#include<string>
#include<cctype>
#include<vector>
#include<iomanip>
#include<cctype>
#include<cmath>
#include<unordered_map>
using namespace std;


// 保留两位小数 
// 	double a=1.347555;
//	cout<<fixed<<setprecision(2)<<a<<endl;
//	1.35
//	

int solution(vector<int> nums1, vector<int> nums2){

	vector<int> dp_cur(nums1.size()+1);
	vector<int> dp_pre(nums1.size()+1);
	for(int i=1;i<dp_cur.size();i++){
		for(int j=1;j<dp_cur.size();j++){
			if(nums2[i-1]==nums1[j-1])
				dp_cur[j]=1+dp_pre[j-1];
			else
				dp_cur[j]=max(dp_cur[j-1],dp_pre[j]);
		}
		dp_pre=dp_cur;
	}
	return nums1.size()-dp_cur.back();
}

int solution_2(vector<int> nums1, vector<int> nums2){

	vector<int> dp;
	unordered_map<int, int> um;
	for(int i=0;i<nums1.szie();i++){
		um[nums1[i]]=i;
	}
	int len=1;
	dp.push_back(nums2[0]);
	for(int i=1;i<nums2.size();i++){
		if(um[nums2[i]]>um[dp.back()]){
			len++;
			dp.push_back(nums2[i]);
		}
		else{
			
		}
	}
}

int main(int argc, char const *argv[]){

	int n=120;
	int ret=0;
	for(int i=n/3;i<n/2;i++){
		for(int j=1;j<(n-i)/2;j++){
			if(pow(j,2)+pow(n-i-j,2)==pow(i,2))
				ret++;
		}
	}
	cout<<ret<<endl;
	return 0;
}