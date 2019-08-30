#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<cmath>
using namespace std;

class Test2
{
public:

	bool func(char* str){

		if(*str=='\0')
			return true;

		if(*str=='0'){
			return func(str+1);
		}

		return false;
	}
	
};

void IntAsChar(){
	int a=0;
	int* p=&a;
	cout<<&a<<endl;
	cout<<p<<endl;
	cout<<&p<<endl;
	Test2 t;
	cout<<&t<<endl;
}


void ThreeNumberGetMiddle(vector<int>& vec, int begin, int end){
	//三数值取中
	int mid=(begin+end)/2;
	if(vec[begin]>vec[mid])
		swap(vec[begin],vec[mid]);
	if(vec[mid]>vec[end])
		swap(vec[mid],vec[end]);
	if(vec[begin]>vec[end])
		swap(vec[begin],vec[end]);
	swap(vec[begin],vec[mid]);
}

int partition(vector<int>& vec, int begin, int end){
	ThreeNumberGetMiddle(vec,begin,end);
	int tmp=vec[begin];
	while(begin<end){
		// 注意（1）从右向左开始遍历，（2）注意越界处理
		// (3) 当需要访问vec[end]时，end取最后一位元素，而不是空
		// (4)必须取等号，否则2，3，3，5，3会死循环
		while(vec[end]>=tmp && begin<end) end--;
		vec[begin]=vec[end];
		while(vec[begin]<=tmp && begin<end) begin++;
		vec[end]=vec[begin];
	}
	vec[begin]=tmp;
	return begin;
}

void QuickSort(vector<int>& vec, int begin, int end){
	if(begin<end){
		int mid=partition(vec,begin,end);
		QuickSort(vec,begin,mid-1);
		QuickSort(vec,mid+1,end);
	}
}

void heap_test(){
	vector<int> v={10,20,30,5,15};
	make_heap(v.begin(),v.end());
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<' ';
	cout<<endl;
	pop_heap(v.begin(),v.end());
	v.pop_back();
	push_heap(v.begin(),v.end());
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<' ';
}

void set_tese(){
	multiset<int> m={10,20,30,20,20};
	set<int> m_1={5,2,1,2,3};
	cout<<m.size()<<endl;
	vector<int> v(m_1.begin(),m_1.end());
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<' ';
}

void testStatic(){
	static int j=0;
	++j;
	printf("%d\n",j);
}


int main(int argc, char const *argv[])
{
	// Test2 t;
	// char str[5]="0000";
	// char str1[5]="0010";
	// cout<<boolalpha<<t.func(str)<<endl;
	// cout<<t.func(str1)<<endl;
	// IntAsChar();

	// vector<int> vec={2,3,3,5,3};
	// QuickSort(vec,0,vec.size()-1);
	// for(int i=0;i<vec.size();i++)
	// 	cout<<vec[i]<<' ';
	
	// heap_test();
	// set_tese();
	// 
	// for (int i=1;i<=5;i++)
	// 	testStatic();
	cout<<sqrt(5)<<endl;
	if(sqrt(5)*sqrt(5)==4){
		cout<<boolalpha<<true<<endl;
	}	
	
	return 0;
}