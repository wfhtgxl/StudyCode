#include<iostream>
using namespace std;

class dongwu
{
public:
	void speak()
	{
		cout << "动物说话" << endl;
	}
};

class cat: public dongwu
{
public:
	void speak()
	{
		cout << "小猫说话" << endl;
	}
};



int main() {
	cat c;
	dongwu d;
	c.speak();
	d.speak();
}