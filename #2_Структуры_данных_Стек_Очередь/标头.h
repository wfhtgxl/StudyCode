#pragma once
#include <memory>
#include <iostream>
using namespace std;
class IntStack
{
	unique_ptr<int[]>stackArray;
	int capacity;//�������
	int top;
public:
	// ��ʼ��
	IntStack(int capacity);
	// ���Ԫ��
	void push(int value);
	//ɾ��Ԫ��
	void pop(int& value);
	//�ж��Ƿ�Ϊ��
	bool isEmpty() const;
	// Stack Exceptions ջ�쳣
	class Overflow {};
	class Underflow {};
};