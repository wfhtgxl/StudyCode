#include<iostream>
using namespace std;
class Base
{
public:  //网页头部  
	void publicarea()
	{
		cout << "公共" << endl;
	}
};

class News: public Base
{
public:  //网页头部  
	
	void news()
	{
		cout << "新闻" << endl;
	}
}; 

 
class Recreation
 { 
 public:  //网页头部  
	 void publicarea()
	 {
		 cout << "公共" << endl;
	 }
	 void recreation()
	 {
		 cout << "明星" << endl;
	 }
 }; 

class Aclass
{ 
	public: 
		int mA;  
		int mB; 
};

class Bclass : public Aclass 
{ 
	public:  
		int mC; 
}; 

class Cclass : public Bclass 
{ 
	public:  
		int mD; 
}; 

void test() 
{
	cout << "A size:" << sizeof(Aclass) << endl;
	cout << "B size:" << sizeof(Bclass) << endl;
	cout << "C size:" << sizeof(Cclass) << endl; 
}

class D 
{ 
	public:  
		D() { 
			cout << "D 类构造函数!" << endl; 
		}  
		~D() { 
			cout << "D 类析构函数!" << endl; 
		} 
};

class A
{
	public:  
		A() { 
			cout << "A 类构造函数!" << endl; 
		}  
		~A() { 
			cout << "A 类析构函数!" << endl;			
		}

};

class B : public A
{
public:
	B() {
		cout << "B 类构造函数!" << endl;
	}
	~B() {
		cout << "B 类析构函数!" << endl;
	}
};
 
class C : public B 
{
	public:  
		C() {
	cout << "C 类构造函数!" << endl; 
		}  
		~C() { 
	cout << "C 类析构函数!" << endl; 
		} 
	public:  D c; 
}; 

void test1() { 
	C c; 
}

 int main(){ 
	 News a;
	 a.news();
	 a.publicarea();
	 Recreation b;
	 b.publicarea();
	 b.recreation();
	 test(); 
	 test1();
	 return EXIT_SUCCESS;

}