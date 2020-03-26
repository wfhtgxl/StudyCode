#pragma once
#ifndef LinkStack_H
#define LinkStack_H

#define LinkStack_TURE 1 
#define LinkStack_FALSE 0
using namespace std;
#include <iostream>

//��ʽջ�Ľڵ�
typedef struct LinkNode {
	struct LinkNode* next;
};

//��ʽջ
typedef struct LinkStack {
	LinkNode header;//LinkNode* header;   header->next;
	int size;
}LinkStack;

//��ʼ��
LinkStack* Init_LinkStack() {
	//�����ṹ�� ���ṹ������ڴ�
	LinkStack* stack = new LinkStack;
	stack->header.next = NULL;
	stack->size = 0;
	return stack;
}

//��ջ
void Push_LinkStack(LinkStack* stack, LinkNode* data) {
		if (stack == NULL) return;
		if (data == NULL) return;
		//ͷ��
		data->next = stack->header.next;
		stack->header.next = data;
		stack->size++;
}

//����ջ��Ԫ��*    LinkNode*
void* Top_LinkStack(LinkStack* stack) {
	if (stack == NULL) return NULL;
	if (stack->size == 0) return NULL;
	return stack->header.next;//�����0 ��ʼ
}

//��ջ
void Pop_LinkStack(LinkStack* stack) {
	if (stack == NULL) return;
	if (stack->size == 0) return;
	//��һ����Ч�ڵ�
	LinkNode* pNext = stack->header.next;
	stack->header.next = pNext->next;
	stack->size--;
}

//�ж��Ƿ�Ϊ��
int IsEmpty(LinkStack* stack) {
	if (stack == NULL) return -1;
	if (stack->size == 0) return LinkStack_TURE;
	return LinkStack_FALSE;
}

//����ջ��Ԫ�صĸ���
int Size_LinkStack(LinkStack* stack) {
	if (stack == NULL) return -1;// ??
	return stack->size;
}

//����
void FreeSpace_LinkStack(LinkStack* stack) {
	if (stack == NULL) return;
	free(stack);
}

//���ջ
void Clear_LinkStack(LinkStack* stack) {
	if (stack == NULL) return;
	stack->header.next = NULL;
	stack->size = 0;
}

char* foo(const char* midExp)
{
	//��׺���ʽ
	char* afterExp = new char;
	int j = 0;//afterExp�±�
	int k = 0;//preExp�±�

	LinkStack* stack = Init_LinkStack();// + - * / ( ������ջ


	char numBuf[10] = { 0 };//���������ֲ��ܳ���10λ��Ҳ������׺���ʽ�����ֲ��ܳ���10λ
	char ch = 0;
	int numIndex = 0;//numBuf �±�
	while (midExp[k])
	{
		ch = midExp[k++];
		//������׺���ʽ�еĿո�
		if (ch == ' ')
		{
			continue;
		}
		//�س�������׺�������
		if ('\n' == ch)
		{
			break;
		}
		//1���������־����
		if (ch >= '0' && ch <= '9')
		{
			//����������������֣��������������� ѭ����� ���� 2��������
			while (((ch >= '0' && ch <= '9') || '.' == ch) && numIndex < 10)
			{
				numBuf[numIndex++] = ch;
				afterExp[j++] = ch;
				ch = midExp[k++];
			}
			numBuf[numIndex] = 0;
			afterExp[j++] = ' ';
		}
		//�س�������׺�������
		if ('\n' == ch)
		{
			break;
		}
		//������׺���ʽ�еĿո�
		else if (' ' == ch)
		{
			continue;
		}
		//2��������
		else if (ch < '0' || ch > '9')
		{
			numIndex = 0;//�������if ���ֿ϶��������ˣ��±�����Ϊ0
			//������һ����ջ
			if (')' == ch)
			{
				int flag = 1;//�ж���׺���ʽ�������Ƿ�ƥ��,����ɶԳ���
				while (!IsEmptyStack(&stack))
				{
					pop(&stack, &ch);
					if ('(' == ch)
					{
						flag = 0;//�ߵ�����˵����()���ųɶԳ���
						break;
					}
					afterExp[j++] = ch;
					afterExp[j++] = ' ';
				}
				if (flag)
				{
					printf("��׺���ʽ�������\n");
					exit(0);
				}

			}
			// + - ���������ȼ���͵ģ�һ���������ε�ջ��ѹջ��
			else if ('+' == ch || '-' == ch)
			{
				EleType top;
				GetTop(&stack, &top);
				//ջ�ջ���ջ��Ϊ������ ֱ��ѹջ
				if (IsEmptyStack(&stack) || '(' == top)
				{
					push(&stack, ch);
				}
				else
				{
					char cur = ch;
					while (!IsEmptyStack(&stack))
					{
						pop(&stack, &ch);
						if ('(' == ch)
						{
							//������Ϊ)�����Ŷ���ջ���൯��(������ѹ��ȥ
							push(&stack, ch);
							break;
						}
						afterExp[j++] = ch;
						afterExp[j++] = ' ';
					}

					push(&stack, cur);
				}
			}
			// * / �������ȼ�ֻ�� + -�ߣ�ջ�ջ�ջ��Ϊ(+-����ջ��ֱ��ѹջ��������������ε�ջ��ѹջ
			else if ('*' == ch || '/' == ch)
			{
				EleType top;
				GetTop(&stack, &top);
				//ջ�ջ���ջ��Ϊ������ͬ��ֱ��ѹջ
				if (IsEmptyStack(&stack) || '(' == top || '-' == top || '+' == top)
				{
					push(&stack, ch);
				}
				else if ('*' == top || '/' == top)
				{
					char cur = ch;
					while (!IsEmptyStack(&stack))
					{
						pop(&stack, &ch);
						if ('(' == ch || '-' == ch || '+' == ch)
						{
							//������Ϊ)�����Ŷ���ջ * / ���ȼ�����ջ�� + - �Ͳ���ջ�ˣ��൯��ѹ��ȥ
							push(&stack, ch);
							break;
						}
						afterExp[j++] = ch;
						afterExp[j++] = ' ';
					}
					push(&stack, cur);
				}
			}
			else if ('(' == ch)
			{
				push(&stack, ch);
			}
			else
			{
				printf("��׺���ʽ�������\n");
				exit(0);
			}
		}

	}
#endif