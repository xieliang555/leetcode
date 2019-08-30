#include<iostream>
#include<vector>
using namespace std;

/**
 * 剑指offer: 62
 *
 * f(n,m)表示n个数每次删除第m个数（从1开始）最后剩下的数字
 * 注意分析如何得到状态转移函数，如找到f(5,2)和f(4,2)的关系，然后利用动态规划迭代
 * f(5,2)是指序列(0，1，2，3，4) 删除第2个数后的序列为(2,3,4,0), f(4,2)是指序列0，1，2，3 
 * f(4,2)第一个删除的数是1，向右移两格是3，恰好是(2,3,4,0)要删除的数，另外由于f(5,2)最后结果不能超过5
 * 故f(5,2)=(f(4,2)+2)%5
 */
	
int LastRemaining_Solution(int n, int m){
	if(n<1 || m<1) return -1;
	int dp=0;
	for(int i=2;i<=n;i++){
		dp=(dp+m)%i;
	}
	return dp;
}

int main(int argc, char const *argv[])
{
	cout<<LastRemaining_Solution(8,3)<<endl;
	return 0;
}