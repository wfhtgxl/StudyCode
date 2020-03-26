#ifndef SEQSTACK_H
#define SEQSTACK_H

#define MAX_SIZE 1024
#define SEQSTACK_TURE 1 
#define SEQSTACK_FALSE 0
using namespace std;
#include <iostream>

typedef struct SEQSTACK {
	void* data[MAX_SIZE];
	int size;
}SeqStack;

//初始化
SeqStack* Init_SeqStack() {
	//创建结构体 给结构体分配内存
	SeqStack* stack = new SeqStack;
	for (int i = 0; i < MAX_SIZE; i++) {
		stack->data[i] = NULL;
	}
	stack->size = 0;
	return stack;
}

//入栈
void Push_SeqStack(SeqStack* stack, void* data) {
		if (stack->size == MAX_SIZE) return;
		if (stack == NULL) return;
		if (data == NULL) return;
		stack->data[stack->size] = data;
		stack->size++;
}

//返回栈顶元素
void* Top_SeqStack(SeqStack* stack) {
	if (stack == NULL) return NULL;
	if (stack->size == 0) return NULL;
	return stack->data[stack->size - 1];//数组从0 开始
}

//出栈
void Pop_SeqStack(SeqStack* stack) {
	if (stack == NULL) return;
	if (stack->size == 0) return;
	stack->data[stack->size - 1] = NULL;
	stack->size--;
}

//判断是否为空
int IsEmpty(SeqStack* stack) {
	if (stack == NULL) return -1;
	if (stack->size == 0) return SEQSTACK_TURE;
	return SEQSTACK_FALSE;
}

//返回栈中元素的个数
int Size_SeqStack(SeqStack* stack) {
	return stack->size;
}

//销毁
void FreeSpace_SeqStack(SeqStack* stack) {
	if (stack != NULL) return;
	free(stack);
}

//清空栈
void Clear_SeqStack(SeqStack* stack) {
	if (stack == NULL) return;
	for (int i = 0; i < stack->size; i++) {
		stack->data[i] = NULL;
	}
	stack->size = 0;
}







#endif