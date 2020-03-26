#include"Link.h"

LinkNode* LinkList::Init() {
	LinkNode* header = new LinkNode;
	header->data = NULL;
	header->next = nullptr;

	LinkNode* pCurrent = header;
	int temp;
	while (1) {
		if (pCurrent == nullptr) cout << "pCurrent is NULL";
		cin >> temp;
		if (temp == -1) break;
		/*LinkNode* newNode = new LinkNode;*/
		/*newNode->data = temp;*/
		pCurrent + temp;
		/*newNode->next = nullptr;*/

	/*	pCurrent->next = newNode;*/

		pCurrent = pCurrent->next;
	}
	return header;
}

void LinkList::check(LinkNode* header) {
	if (header == NULL) return;
	LinkNode* pCurrent = header->next;
	while (pCurrent) {
		cout << pCurrent << "  ";
		pCurrent = pCurrent->next;
	}
}

int main() {
	LinkList* list = new LinkList;//* &  ??                         LinkList list;        LinkList* node;              LinkList& node;					LinkList


	list->header = list->Init();
	list->check(list->header);
}