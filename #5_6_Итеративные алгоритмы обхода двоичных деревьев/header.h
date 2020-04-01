#pragma once
#include<iostream>
#include<vector>
using namespace std;

typedef struct BiTNode {
	char ch;            //�������  
	struct BiTNode* lchild;        //����  
	struct BiTNode* rchild;        //�Һ���  
}BiTNode, * BiTree;


BiTree AddBiTree();// initialization tree 
void PreOrderTraverse(BiTNode*); //ǰ��
void InOrderTraverse(BiTNode*);   //����
void PostOrderTraverse(BiTNode*);  //����
void LevelOrderTraverse(BiTNode*);//���
void PreOrderTraverseWithLevel(BiTree T, int level, vector<vector<BiTree>>&);
