#include"head.h"

LinkNode* LinkList::Init()//初始化
{
	int tmp = 1;
	//头节点
	LinkNode* header = new LinkNode;
	header->next = NULL;
	header->data = NULL;


	//辅助指针
	LinkNode* AuxiliaryCurrent = header;//与后方节点连接

	while (1)
	{
		LinkNode* newNode = new LinkNode;
		cin >> tmp;
		if (tmp == 0) {
			break;
		}
		newNode->data = tmp;
		AuxiliaryCurrent->next = newNode;
		AuxiliaryCurrent = AuxiliaryCurrent->next;
	}
	AuxiliaryCurrent->next = NULL;


	return header;
}

void LinkList::check(LinkNode* header)	/*遍历*/
{
	if (header == NULL)
	{
		cout << "header是空" << endl;
		return;
	}

	LinkNode* temporaryAuxiliaryCurrent = header->next;

	while (temporaryAuxiliaryCurrent != NULL)
	{
		cout << temporaryAuxiliaryCurrent << "  ";

		temporaryAuxiliaryCurrent = temporaryAuxiliaryCurrent->next;
	}
	cout << endl;
}
//插入
void LinkList::add(LinkNode* header)
{
	if (header == NULL)
	{
		cout << "header是空" << endl;
		return;
	}

	int tmp = 1;
	LinkNode* newNode = new LinkNode;
	cout << "Please input Inserted element : " << endl;
	cin >> tmp;
	newNode->data = tmp;
	cout << "Please input address :";
	cin >> tmp;

	LinkNode* AuxiliaryCurrent = header->next;
	LinkNode* temporaryAuxiliaryCurrent;
	while (1)
	{
		if (AuxiliaryCurrent->data == tmp)
		{
			temporaryAuxiliaryCurrent = AuxiliaryCurrent->next;
			AuxiliaryCurrent->next = newNode;
			newNode->next = temporaryAuxiliaryCurrent;
			break;
		}
		AuxiliaryCurrent = AuxiliaryCurrent->next;
	}

}
//删除元素 **
//void LinkList::del(LinkNode* header)
//{
//	if (header == NULL)
//	{
//		cout << "header是空" << endl;
//		return;
//	}
//	int tmp;
//	cout << "Please input delete data: ";
//	cin >> tmp;
//	LinkNode* AuxiliaryCurrent = header->next;
//	while (true)
//	{
//		if (AuxiliaryCurrent->data == tmp)
//		{
//
//
//		}
//
//	}
//
//
//}


void LinkList:: Sort(LinkNode* header)//链表排序 (冒泡？？）
{
	LinkNode* FrontCurrent = nullptr;
	LinkNode* BackCurrent;
	int temp;
	for (FrontCurrent = header->next; FrontCurrent != NULL; FrontCurrent = FrontCurrent->next)
	{
		for (BackCurrent = FrontCurrent->next; BackCurrent != NULL; BackCurrent = BackCurrent->next)
		{
			if (FrontCurrent->data > BackCurrent->data)
			{
				temp = FrontCurrent->data;
				FrontCurrent->data = BackCurrent->data;
				BackCurrent->data = temp;
			}
		}
	}
}

//删除重复的元素
void LinkList::Remove(LinkNode* header)
{
	LinkNode* CurrentCurrent = header->next;
	LinkNode* PreviousCurrent = header;
	while (CurrentCurrent)
	{

		if (CurrentCurrent->data == PreviousCurrent->data)
		{
			LinkNode* temp = CurrentCurrent;
			PreviousCurrent->next = CurrentCurrent->next;
			CurrentCurrent = CurrentCurrent->next;
			delete temp;
		}
		else {
			PreviousCurrent = CurrentCurrent;
			CurrentCurrent = CurrentCurrent->next;
		}

	}
}

//重载<<
ostream& operator<<(ostream& cout, LinkNode* pCurrent)
{
	cout << pCurrent->data;
	return cout; 
}

//合并
LinkNode* LinkList::MergeList(LinkNode* header1, LinkNode* header2)
{
	if (header1 == NULL)
	{
		return header2;
	}
	else if (header2 == NULL)
	{
		return header1;
	}
	LinkNode* Mergeheader = NULL;
	if (header1->data < header2->data)
	{
		Mergeheader = header1;
		Mergeheader->next = MergeList(header1->next, header2);
	}
	else
	{
		Mergeheader = header2;
		Mergeheader->next = MergeList(header1, header2->next);
	}
	return Mergeheader;
}

//int achieve()
//{
//	LinkNode* pHead1 = new LinkNode(1);
//	LinkNode* pCur = pHead1;
//	for (int i = 3; i < 10; i += 2)
//	{
//		LinkNode* tmpNode = new LinkNode(i);
//		pCur->next = tmpNode;
//		pCur = tmpNode;
//	}
//
//	LinkNode* pHead2 = new LinkNode(2);
//	pCur = pHead2;
//	for (int j = 4; j < 10; j += 2)
//	{
//		LinkNode* tmpNode = new LinkNode(j);
//		pCur->next = tmpNode;
//		pCur = tmpNode;
//	}
//
//	LinkNode* head = MergeList(pHead1, pHead2);
//	while (head)
//	{
//		cout << head->data << " ";
//		head = head->next;
//	}
//
//
//
//}

int main() {
	//初始化LIST1
	cout << "List1:" <<endl;
	LinkList* List1 = new LinkList;
	List1->header = List1->Init();
	List1->check(List1->header);
	cout << endl;
	//初始化LIST2
	cout << "List2:" << endl;
	LinkList* List2 = new LinkList;
	List2->header = List2->Init();
	List2->check(List2->header);
	cout << endl;
	//合并LIST
	cout << "MergeList:" << endl;
	LinkList* MergeList = new LinkList;
	MergeList->header = MergeList->MergeList(List1->header,List2->header);
	MergeList->Remove(MergeList->header);
	MergeList->check(MergeList->header);
	LinkList* List3 = new LinkList;
	List3=*(List1) & *(List2);
	List3->check(List3->header);
	getchar();
	return 0;
}