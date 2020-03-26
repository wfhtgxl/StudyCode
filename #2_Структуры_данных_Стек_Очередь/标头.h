#pragma once
#include <memory>
#include <iostream>
using namespace std;
class IntStack
{
	unique_ptr<int[]>stackArray;
	int capacity;//最大容量
	int top;
public:
	// 初始化
	IntStack(int capacity);
	// 添加元素
	void push(int value);
	//删除元素
	void pop(int& value);
	//判断是否为空
	bool isEmpty() const;
	// Stack Exceptions 栈异常
	class Overflow {};
	class Underflow {};
};