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

	while (tmp != 0)
	{
		LinkNode* newNode = new LinkNode;
		cin >> tmp;
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
			cout << temporaryAuxiliaryCurrent->data<< endl;

		temporaryAuxiliaryCurrent = temporaryAuxiliaryCurrent->next;
	}

}

void LinkList::add(LinkNode* header)
{
	if (header == NULL)
	{
		cout << "header是空" << endl;
		return;
	}
	
	int tmp = 1;
	LinkNode* newNode = new LinkNode;
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

void LinkList::del(LinkNode* header)
{
	if (header == NULL)
	{
		cout << "header是空" << endl;
		return;
	}
	int tmp;
	cout << "Please input delete data: ";
	cin >> tmp;
	LinkNode* AuxiliaryCurrent = header->next;
	while (true)
	{
		if (AuxiliaryCurrent->data == tmp) 
		{


		}

	}


}

int main() {
	LinkList* List = new LinkList;
	List->header = List->Init();
	List->check(List->header);
	List->add(List->header);
	List->check(List->header);
}