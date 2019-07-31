#include<iostream>
#include<cstring>
using namespace std;

/**
 * 1
 */

class AssignOperator
{
public:
	//含有默认参数的构造函数可以不需要额外再定义不含参数的构造函数
	AssignOperator(const char* pData=nullptr);
	// AssignOperator(const AssignOperator&);
	~AssignOperator(void);

	AssignOperator& operator=(const AssignOperator&);

	void get();

private:
	//对象外访问私有成员需要通过公有函数
	char* m_pData;
};

AssignOperator:: AssignOperator(const char* pData){
	//strlen不支持传入nullptr
	if(pData==nullptr){
		m_pData=new char[1];
		m_pData[0]='\0';
	}
	else{
		m_pData=new char[strlen(pData)+1];
		strcpy(m_pData,pData);
	}
}

AssignOperator:: ~AssignOperator(){
	delete[] m_pData;
	cout<<"sucess"<<endl;
}


//传入常引用，避免调用拷贝构造函数；返回引用，可以连续赋值（object1=object2 等价于 object1.operator=(object2),返回 &object1）
AssignOperator& AssignOperator:: operator=(const AssignOperator& opt){
	//判断传入的参数是否是同一个实例，避免释放自身的内存
	//注意将对象赋给指针时需要加引用
	if(this!=&opt){
		//删除原来指向的内存避免内存泄漏
		delete []m_pData;
		m_pData=nullptr;
		m_pData=new char[strlen(opt.m_pData)+1];
		strcpy(m_pData,opt.m_pData);
	}
	return *this;
}

void AssignOperator:: get(){
	cout<<m_pData<<endl;
}

//将test函数写在main之外的好处是可以看到析构函数是否被调用
void test1(){
	cout<<"test1 begin:"<<endl;
	const char* str="hello world";
	AssignOperator ass1(str);
	AssignOperator ass2;
	ass2=ass1;
	cout<<"the expected result is: "<<endl;
	ass1.get();
	cout<<"the actual result is: "<<endl;
	ass2.get();
}


void test2(){
	cout<<"test2 begin:"<<endl;
	const char* str="hello world";
	AssignOperator ass1(str);
	ass1=ass1;
	cout<<"the expected result is: "<<endl;
	ass1.get();
	cout<<"the actual result is: "<<endl;
	ass1.get();
}

void test3(){
	cout<<"test3 begin: "<<endl;
	const char* str="hello world";
	AssignOperator ass1(str);
	AssignOperator ass2,ass3;
	ass2=ass3=ass1;
	cout<<"the expected result is: "<<endl;
	ass1.get();
	cout<<"the actual result is: "<<endl;
	ass2.get();
	ass3.get();
}


int main(int argc, char const *argv[])
{
	test1();
	cout<<"=============================="<<endl;
	test2();
	cout<<"=============================="<<endl;
	test3();

	return 0;
}

//如果在new出字符串数组时堆中的内存不足，会出现什么情况？如何解决？需要用到拷贝构造函数