#pragma once
#include<iostream>
using namespace std;

typedef struct DynamicArray {
	int* pAddr;		//������ݵĵ�ַ
	int size;		//��ǰԪ�ظ���		
	int capacity;			//�����������ɵ��������

}Dynamic_Array;

//��ʼ��
Dynamic_Array* Init_Array();
//����
void PushBack_Array(Dynamic_Array* arr, int val);
//ɾ��������λ�ã�
void RemoveByPos_Array(Dynamic_Array* arr, int pos);
//ɾ��������ֵ��
void RemoveByvVal_Array(Dynamic_Array* arr, int pos);