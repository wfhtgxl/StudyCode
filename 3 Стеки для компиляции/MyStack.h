#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<string>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define STACK_SIZE 1024	 // ջ��ʼ����
#define STACK_INCREMENT 10   //ջ����ÿ�����������
#define EXPRESS_MAX 1024 //��׺���ʽ ���Ȳ��ܳ���1024
typedef int Status;
typedef char EleType;
using namespace std;

typedef struct SeqStack
{
	EleType* top;//ջ��ָ��
	EleType* base;//ջ��ָ��
	int stackSize;//ջ����
}SeqStack;

//��ʼ��ջ
void InitStack(SeqStack* stack)
{
	//���ٿռ�
	stack->base = stack->top = (EleType*)malloc(STACK_SIZE * sizeof(EleType));

	if (stack->base == NULL) return;
	stack->stackSize = STACK_SIZE;
}

//ѹջ
void push(SeqStack* stack, EleType e)
{
	if (stack == NULL)	return;
	*stack->top = e;
	stack->top++;
}

//ջ
Status pop(SeqStack* stack, EleType* e)
{
	if (stack == NULL || e == NULL)
	{
		return ERROR;
	}
	//��ջ
	if (stack->top == stack->base)
	{
		return ERROR;
	}
	*stack->top--;
	*e = *stack->top;//?
	return OK;
}

//��ȡջ��Ԫ��
Status GetTop(SeqStack* stack, EleType* e) {
	if (NULL == stack) {
		return ERROR;
	}
	*e = *(stack->top - 1);
	return OK;
}

//�ж�ջ�Ƿ�Ϊ��
int IsEmptyStack(SeqStack* stack) {
	if (NULL == stack) {
		return ERROR;
	}
	if (stack->top == stack->base) {
		return TRUE;
	}
	return FALSE;
}

//����
Status DestroyStack(SeqStack* stack)
{
	if (NULL == stack) {
		return ERROR;
	}
	//����ջ ���ͷ�ջ���ڴ���ռ�õĿռ���Դ
	if (!stack->base)
	{
		free(stack->base);
	}
	stack->top = stack->base = NULL;
	stack->stackSize = 0;
	return OK;
}

//����׺���ʽת�ɺ�׺���ʽ
char* foo(const char* midExp)
{
	//��׺���ʽ
	char* afterExp = (char*)malloc(sizeof(char) * EXPRESS_MAX);
	memset(afterExp, 0, EXPRESS_MAX);
	int j = 0;//afterExp�±�
	int k = 0;//preExp�±�

	SeqStack stack;// + - * / ( ������ջ
	InitStack(&stack);

	char numBuf[10];
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
		//if Enter, Finsh
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
					cout << "INPUT ERROR!\n";
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
				cout << "INPUT ERROR!\n";
				exit(0);
			}
		}

	}
	//����ջ���ݲ�Ϊ�� ���γ�ջ����ӡ
	while (!IsEmptyStack(&stack))
	{
		pop(&stack, &ch);
		afterExp[j++] = ch;
		afterExp[j++] = ' ';
	}
	return afterExp;
}
