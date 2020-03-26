#pragma once
#include<iostream>
using namespace std;

struct LinkNode
{
	int data;//数据域
	LinkNode* next;
	//LinkNode();
	//~LinkNode();
};

struct LinkList
{
	LinkNode* header;
	//LinkList();
	//~LinkList();

	LinkNode* Init();//初始化

	void check(LinkNode* header);//遍历

	void add(LinkNode* header);//插入

	void del(LinkNode* header);//删除
};
