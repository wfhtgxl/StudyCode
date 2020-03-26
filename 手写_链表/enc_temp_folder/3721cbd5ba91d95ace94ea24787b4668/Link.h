#pragma once
#include<iostream>
using namespace std;

struct LinkNode
{
	friend inline ostream& operator<<(ostream& os, LinkNode* node);
	friend void operator+(LinkNode* node_new, LinkNode& node_old);
	int data;
	LinkNode* next;
};

class LinkList {
public:
	LinkNode* header;
	
	LinkNode* Init();//*
	void check(LinkNode* header);
};

inline ostream& operator<<(ostream& os, LinkNode* node) {//&--.    *-- ->  º‰Ω”∑√Œ              2.  LinkNode& node     node.data         cout << *pCurrent;
	os << node->data;
	return os;
}

void operator+(LinkNode& node_old, int temp) {
	LinkNode* newNode = new LinkNode;
	newNode->next = nullptr;
	newNode->data = temp;
	node_old.next =  newNode;
	
}