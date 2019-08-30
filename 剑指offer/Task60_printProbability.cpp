#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

//参考： https://blog.csdn.net/k346k346/article/details/50988681 

vector<int> printProbability(int num){
	if(num<1) return vector<int>();
	vector<int> s(6*num);
	for(int i=0;i<6;i++)
		s[i]=1;
	if(num==1)
		return s;
	//循环条件只考虑循环次数，否则易出错
	for(int i=2;i<=num;i++){
		//涉及数组更新时，数组后面的要用到数组前面的元素，应从后向前更新
		for(int j=(i*6-i);j>=0;j--){
			int tmp1=j>=0?s[j]:0;
			int tmp2=j-1>=0?s[j-1]:0;
			int tmp3=j-2>=0?s[j-2]:0;
			int tmp4=j-3>=0?s[j-3]:0;
			int tmp5=j-4>=0?s[j-4]:0;
			int tmp6=j-5>=0?s[j-5]:0;
			s[j]=tmp1+tmp2+tmp3+tmp4+tmp5+tmp6;
		}
	}
	return s;
}

int main(int argc, char const *argv[])
{
	int num=11;
	vector<int> a=printProbability(num);
	vector<double> prob(6*num);
	//循环条件只考虑循环次数
	for(int i=0;i<(num*6-num+1);i++){
		prob[i]=a[i]/pow(6.0,num);
		cout<<prob[i]<<endl;
	}
	return 0;
}