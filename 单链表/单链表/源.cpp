#include"head.h"

LinkNode* LinkList::Init()//��ʼ��
{
	int tmp = 1;

	//ͷ�ڵ�
	LinkNode* header = new LinkNode;
	header->next = NULL;
	header->data = NULL;


	 //����ָ��
	LinkNode* AuxiliaryCurrent = header;//��󷽽ڵ�����

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

void LinkList::check(LinkNode* header)	/*����*/
{
	if (header == NULL)
	{
		cout << "header�ǿ�" << endl;
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
		cout << "header�ǿ�" << endl;
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
		cout << "header�ǿ�" << endl;
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