#pragma once
#include<iostream>
using namespace std;

struct LinkNode
{
	friend ostream& operator<<(ostream& cout, LinkNode* pCurrent);
	int data;//������
	LinkNode* next;
	//LinkNode();
	//~LinkNode();
};

class LinkList
{
	friend ostream& operator<<(ostream& cout, LinkNode * pCurrent);

	//void operator+=(const int& data) {
	//	if (header == nullptr) {
	//		header = new LinkNode(data);
	//		return;
	//	}
	//	LinkNode* trav = header;
	//	while (trav) {
	//		if (trav->data == data) {
	//			return;
	//		}
	//		else if (trav->data > data) {
	//			LinkNode* tmp = new LinkNode(data);
	//			tmp->next = trav;
	//			if (trav->prev_) {
	//				tmp->prev_ = trav->prev_;
	//				trav->prev_->next_ = tmp;
	//			}
	//			else {
	//				head = tmp;
	//			}
	//			trav->prev = tmp;
	//			return;
	//		}
	//		trav = trav->next_;
	//	}

	//123	234      2 3
	friend LinkList* operator&(LinkList& list1, LinkList& list2);
	//123	234		1 4
	friend LinkList operator|(LinkList& list1, LinkList& list2);

public:
	LinkNode* header;
	//LinkList();
	//~LinkList();

	LinkNode* Init();//��ʼ��

	void check(LinkNode* header);//����

	void add(LinkNode* header);//����

	void del(LinkNode* header);//ɾ��

	void Sort(LinkNode* header);//����

	void Remove(LinkNode* header);//�Ƴ��ظ�

	LinkNode* MergeList(LinkNode* header1, LinkNode* header2);//�ϲ�

	

	//friend LinkList operator|(LinkList& list1, LinkList& list2) {
	//	LinkList list;
	//	LinkNode* pCurrent = list.header;
	//	LinkNode* pCurrent1 = list1.header->next;
	//	LinkNode* pCurrent1 = list2.header->next;
	//	int i = 0;
	//	int tmp;
	//	while (pCurrent1 && pCurrent2) {
	//		//���data��ͬ�Ͱ�data����list��������pCurrentͬʱ����
	//		if (pCurrent1->data == pCurrent2->data) {
	//			LinkNode* newNode = new LinkNode;
	//			newNode->data = pCurrent1->data;
	//			pCurrent->next = newNode;
	//			pCurrent1 = pCurrent1->next;
	//			pCurrent2 = pCurrent2->next;
	//		}
	//		else if (pCurrent1->data > pCurrent2->data) {
	//			LinkNode* newNode = new LinkNode;
	//			newNode->data = pCurrent1->data;
	//			pCurrent->next = newNode;
	//			tmp = pCurrent2->data;
	//			while (pCurrent1) {
	//				if (pCurrent2->data == pCurrent1->data) {
	//					i++;
	//					//break;//break��Χ��
	//				}
	//				pCurrent1 = pCurrent1->next;
	//			}
	//			
	//			if (i == 0) {
	//				LinkNode* newNode = new LinkNode;
	//				newNode->data = tmp;
	//				pCurrent->next = newNode;
	//			}
	//			pCurrent1 = pCurrent1->next;
	//			pCurrent2 = pCurrent2->next;
	//		}
	//		else if (pCurrent1->data < pCurrent2->data) {
	//			LinkNode* newNode = new LinkNode;
	//			newNode->data = pCurrent2->data;
	//			pCurrent->next = newNode;
	//			tmp = pCurrent1->data;
	//			while (pCurrent2) {
	//				if (pCurrent2->data == pCurrent1->data) {
	//					i++;
	//					//break;//break��Χ��
	//				}
	//				pCurrent2 = pCurrent2->next;
	//			}

	//			if (i == 0) {
	//				LinkNode* newNode = new LinkNode;
	//				newNode->data = tmp;
	//				pCurrent->next = newNode;
	//			}
	//			pCurrent1 = pCurrent1->next;
	//			pCurrent2 = pCurrent2->next;
	//		}
	//	}
	//	pCurrent->next = nullptr��
	//		return list;
	//}
};
 LinkList* operator&(LinkList& list1, LinkList& list2) {
	LinkList* list = new LinkList;
	LinkNode* pCurrent = list->header;
	LinkNode* pCurrent1 = list1.header->next;
	LinkNode* pCurrent2 = list2.header->next;

	while (pCurrent1 && pCurrent2) {
		//���data��ͬ�Ͱ�data����list��������pCurrentͬʱ����
`		if (pCurrent1->data == pCurrent2->data) {
			LinkNode* newNode = new LinkNode;
			newNode->data = pCurrent1->data;
			pCurrent->next = newNode;
			pCurrent1 = pCurrent1->next;
			pCurrent2 = pCurrent2->next;
		}
		//���������򽫴��Ԫ�ص�list��pCurrent���䣬������С��Ԫ�ص�list��������ͬ�͵���list������pCurrent����
		else if (pCurrent1->data > pCurrent2->data) {
			while (pCurrent2) {
				if (pCurrent2->data == pCurrent1->data) {
					LinkNode* newNode = new LinkNode;
					newNode->data = pCurrent2->data;
					pCurrent->next = newNode;
				}
				pCurrent2 = pCurrent2->next;
			}
			pCurrent1 = pCurrent1->next;
			pCurrent2 = pCurrent2->next;
		}

		else if (pCurrent1->data < pCurrent2->data) {
			while (pCurrent1) {
				if (pCurrent2->data == pCurrent1->data) {
					LinkNode* newNode = new LinkNode;
					newNode->data = pCurrent1->data;
					pCurrent->next = newNode;
				}
				pCurrent1 = pCurrent1->next;
			}
			pCurrent1 = pCurrent1->next;
			pCurrent2 = pCurrent2->next;
		}
	}
	pCurrent->next = nullptr;
	return list;
}
#pragma once
