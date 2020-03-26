#pragma once
#include<iostream>
using namespace std;

typedef struct DynamicArray {
	int* pAddr;		//存放数据的地址
	int size;		//当前元素个数		
	int capacity;			//容器所能容纳的最大数量

}Dynamic_Array;

//初始化
Dynamic_Array* Init_Array();
//插入
void PushBack_Array(Dynamic_Array* arr, int val);
//删除（根据位置）
void RemoveByPos_Array(Dynamic_Array* arr, int pos);
//删除（根据值）
void RemoveByvVal_Array(Dynamic_Array* arr, int pos);