#include <iostream>
#include <string>
using namespace std;

void func(int* num)
{
	cout << "this is the ptr function..." << endl;
}

void func(int num)
{
	cout << "this is the normal function..." << endl;
}

void main(int argc, char** argv)
{
	func(NULL);
	func(nullptr);
}