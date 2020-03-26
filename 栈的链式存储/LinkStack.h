#pragma once
#ifndef LinkStack_H
#define LinkStack_H

#define LinkStack_TURE 1 
#define LinkStack_FALSE 0
using namespace std;
#include <iostream>

//链式栈的节点
typedef struct LinkNode {
	struct LinkNode* next;
};

//链式栈
typedef struct LinkStack {
	LinkNode header;//LinkNode* header;   header->next;
	int size;
}LinkStack;

//初始化
LinkStack* Init_LinkStack() {
	//创建结构体 给结构体分配内存
	LinkStack* stack = new LinkStack;
	stack->header.next = NULL;
	stack->size = 0;
	return stack;
}

//入栈
void Push_LinkStack(LinkStack* stack, LinkNode* data) {
		if (stack == NULL) return;
		if (data == NULL) return;
		//头插
		data->next = stack->header.next;
		stack->header.next = data;
		stack->size++;
}

//返回栈顶元素*    LinkNode*
void* Top_LinkStack(LinkStack* stack) {
	if (stack == NULL) return NULL;
	if (stack->size == 0) return NULL;
	return stack->header.next;//数组从0 开始
}

//出栈
void Pop_LinkStack(LinkStack* stack) {
	if (stack == NULL) return;
	if (stack->size == 0) return;
	//第一个有效节点
	LinkNode* pNext = stack->header.next;
	stack->header.next = pNext->next;
	stack->size--;
}

//判断是否为空
int IsEmpty(LinkStack* stack) {
	if (stack == NULL) return -1;
	if (stack->size == 0) return LinkStack_TURE;
	return LinkStack_FALSE;
}

//返回栈中元素的个数
int Size_LinkStack(LinkStack* stack) {
	if (stack == NULL) return -1;// ??
	return stack->size;
}

//销毁
void FreeSpace_LinkStack(LinkStack* stack) {
	if (stack == NULL) return;
	free(stack);
}

//清空栈
void Clear_LinkStack(LinkStack* stack) {
	if (stack == NULL) return;
	stack->header.next = NULL;
	stack->size = 0;
}

char* foo(const char* midExp)
{
	//后缀表达式
	char* afterExp = new char;
	int j = 0;//afterExp下标
	int k = 0;//preExp下标

	LinkStack* stack = Init_LinkStack();// + - * / ( ）符号栈


	char numBuf[10] = { 0 };//连续的数字不能超过10位，也就是中缀表达式中数字不能超过10位
	char ch = 0;
	int numIndex = 0;//numBuf 下标
	while (midExp[k])
	{
		ch = midExp[k++];
		//忽略中缀表达式中的空格
		if (ch == ' ')
		{
			continue;
		}
		//回车代表中缀输入完毕
		if ('\n' == ch)
		{
			break;
		}
		//1、若是数字就输出
		if (ch >= '0' && ch <= '9')
		{
			//如果输入连续的数字，不是连续的数字 循环完毕 会走 2、非数字
			while (((ch >= '0' && ch <= '9') || '.' == ch) && numIndex < 10)
			{
				numBuf[numIndex++] = ch;
				afterExp[j++] = ch;
				ch = midExp[k++];
			}
			numBuf[numIndex] = 0;
			afterExp[j++] = ' ';
		}
		//回车代表中缀输入完毕
		if ('\n' == ch)
		{
			break;
		}
		//忽略中缀表达式中的空格
		else if (' ' == ch)
		{
			continue;
		}
		//2、非数字
		else if (ch < '0' || ch > '9')
		{
			numIndex = 0;//进入这个if 数字肯定不连续了，下标重置为0
			//右括号一定弹栈
			if (')' == ch)
			{
				int flag = 1;//判断中缀表达式中括号是否匹配,如果成对出现
				while (!IsEmptyStack(&stack))
				{
					pop(&stack, &ch);
					if ('(' == ch)
					{
						flag = 0;//走到这里说明是()括号成对出现
						break;
					}
					afterExp[j++] = ch;
					afterExp[j++] = ' ';
				}
				if (flag)
				{
					printf("中缀表达式输入错误\n");
					exit(0);
				}

			}
			// + - 符号是优先级最低的，一定是先依次弹栈再压栈。
			else if ('+' == ch || '-' == ch)
			{
				EleType top;
				GetTop(&stack, &top);
				//栈空或者栈顶为左括号 直接压栈
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
							//不是因为)右括号而弹栈，多弹的(左括号压回去
							push(&stack, ch);
							break;
						}
						afterExp[j++] = ch;
						afterExp[j++] = ' ';
					}

					push(&stack, cur);
				}
			}
			// * / 符号优先级只比 + -高，栈空或栈顶为(+-符号栈才直接压栈，其他情况先依次弹栈再压栈
			else if ('*' == ch || '/' == ch)
			{
				EleType top;
				GetTop(&stack, &top);
				//栈空或者栈顶为左括号同样直接压栈
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
							//不是因为)右括号而弹栈 * / 优先级高于栈顶 + - 就不弹栈了，多弹的压回去
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
				printf("中缀表达式输入错误\n");
				exit(0);
			}
		}

	}
#endif