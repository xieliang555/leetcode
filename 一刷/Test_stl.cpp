#include<queue>
#include<functional>
#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
#include<cmath>
#include<string>
#include<cstdlib>
#include<map>
using namespace std;

void priority_queue_test(){

	int v[]={1,2,5,6,3};
	std::priority_queue<int, std::vector<int>, std::less<int> > max(v,v+5);
	while(!max.empty()){
		std::cout<<max.top()<<' ';
		max.pop();
	}
	std::cout<<std::endl;
	std::priority_queue<int, std::vector<int>, std::greater<int> > q;
	q.push(1);
	std::cout<<q.top()<<std::endl;
	q.push(2);
	std::cout<<q.top()<<std::endl;
	q.push(5);
	std::cout<<q.top()<<std::endl;
	q.push(6);
	std::cout<<q.top()<<std::endl;
	q.push(3);
	std::cout<<q.top()<<std::endl;

}

void make_heap_test(){
	std::vector<int> v={1,2,3,4,5};
	std::make_heap(v.begin(),v.end(),std::less<int>());
	for(int i=0;i<v.size();i++)
		std::cout<<v[i]<<' ';
}

void multiset_test(){
	std:: multiset<int,std::greater<int> > m={1,2,3,4,3};
	std::vector<int> v(m.begin(),m.end());
	for(int i=0;i<v.size();i++)
		std::cout<<v[i]<<' ';
}

void map_test(){
	map<char,int> m;
	m['a']=1;
	m['b']=2;
	m['c']=3;
	for(auto i:m){
		cout<<i.first<<' ';
	}
}


int main(int argc, char const *argv[])
{
	// priority_queue_test();
	// make_heap_test();
	// multiset_test();
	map_test();
	
	return 0;
}