#pragma once
#include<iostream>
using namespace std;

struct LinkNode
{
	int data;//������
	LinkNode* next;
	//LinkNode();
	//~LinkNode();
};

struct LinkList
{
	LinkNode* header;
	//LinkList();
	//~LinkList();

	LinkNode* Init();//��ʼ��

	void check(LinkNode* header);//����

	void add(LinkNode* header);//����

	void del(LinkNode* header);//ɾ��
};
