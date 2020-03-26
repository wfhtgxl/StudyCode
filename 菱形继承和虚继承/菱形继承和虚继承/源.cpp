#include<iostream>
using namespace std;

class BigBase 
{ 
	public:  
		BigBase() 
		{
	mParam = 0; 
		}  
	void func() 
	{
	cout << "BigBase::func" << endl; 
	} 
	public:  
		char a;
		double mParam; 
		
};

					  
class Base1 : virtual public BigBase {};

class Base2 : virtual public BigBase {};

class Base3 {};

class Derived : public Base1, public Base2 {};

						
int main() {
Derived derived;  
//1. 对“func”的访问不明确
derived.Base1:: func();
 cout << derived.mParam << endl;  
	cout << "derived.Base1::mParam:" << derived.Base1::mParam << endl;  
	cout << "derived.Base2::mParam:" << derived.Base2::mParam << endl; 
						  //2. 重复继承  
	cout << "Derived size:" << sizeof(Derived) << endl; //8  //12
	cout << "BigBase size:" << sizeof(BigBase) << endl; //4
	cout << "Base1 size:" << sizeof(Base1) << endl; //4
	cout << "Base3 size:" << sizeof(Base3) << endl; //1
 return EXIT_SUCCESS;
}