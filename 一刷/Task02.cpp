#include<iostream>
using namespace std;

/**
 * 2
 */

class Singleton
{
private:
	Singleton(){};
	~Singleton(){};
	static Singleton* instance;

public:
	static Singleton* getInstance();
	static void deleteInstance();
};


//指针初始化后才可以访问
Singleton* Singleton:: instance=nullptr;

Singleton* Singleton:: getInstance(){
	if(instance==nullptr){
		instance=new Singleton;
		cout<<"instance created"<<endl;
	}
	else
		cout<<"instance already exits"<<endl;
	return instance;
}

void Singleton:: deleteInstance(){
	delete instance;
	instance=nullptr;
	cout<<"success"<<endl;
}

void test(){
	Singleton::getInstance();
	Singleton::getInstance();
	Singleton::deleteInstance();
}


int main(int argc, char const *argv[])
{
	test();
	return 0;
}



//本例在单线程环境下可行，在多线程环境下无法实现功能（饿汉实现）