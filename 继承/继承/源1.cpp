#include<iostream>
using namespace std;
class Base
{
public:  //��ҳͷ��  
	void publicarea()
	{
		cout << "����" << endl;
	}
};

class News: public Base
{
public:  //��ҳͷ��  
	
	void news()
	{
		cout << "����" << endl;
	}
}; 

 
class Recreation
 { 
 public:  //��ҳͷ��  
	 void publicarea()
	 {
		 cout << "����" << endl;
	 }
	 void recreation()
	 {
		 cout << "����" << endl;
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
			cout << "D �๹�캯��!" << endl; 
		}  
		~D() { 
			cout << "D ����������!" << endl; 
		} 
};

class A
{
	public:  
		A() { 
			cout << "A �๹�캯��!" << endl; 
		}  
		~A() { 
			cout << "A ����������!" << endl;			
		}

};

class B : public A
{
public:
	B() {
		cout << "B �๹�캯��!" << endl;
	}
	~B() {
		cout << "B ����������!" << endl;
	}
};
 
class C : public B 
{
	public:  
		C() {
	cout << "C �๹�캯��!" << endl; 
		}  
		~C() { 
	cout << "C ����������!" << endl; 
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