#include"LinkList.hpp"
#include<iostream>

using namespace std;

int main()
{
    LinkList a;
    LinkList b;
    a += 2;
	a += 4;
    a += 6;
    a += 8;
	a += 5;
    b += 1;
    b += 3;
    b += 5;
    b += 7;
    b += 8;
    LinkList c = a & b;
    LinkList d(a | b);
    cout << "a ---" << a;
    cout << "b---" << b;
    cout << "a & b---" << c;
    cout <<    "a | b---" << d;
    a.merge(b);
    cout << "MergeList---" << a;
}