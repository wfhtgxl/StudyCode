#include<iostream>
using namespace std;

class dongwu
{
public:
	void speak()
	{
		cout << "����˵��" << endl;
	}
};

class cat: public dongwu
{
public:
	void speak()
	{
		cout << "Сè˵��" << endl;
	}
};



int main() {
	cat c;
	dongwu d;
	c.speak();
	d.speak();
}