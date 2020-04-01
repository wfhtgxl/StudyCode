#pragma once
#include<iostream>
#include<vector>
using namespace std;

typedef struct BiTNode {
	char ch;            //结点数据  
	struct BiTNode* lchild;        //左孩子  
	struct BiTNode* rchild;        //右孩子  
}BiTNode, * BiTree;


BiTree AddBiTree();// initialization tree 
void PreOrderTraverse(BiTNode*); //前序
void InOrderTraverse(BiTNode*);   //中序
void PostOrderTraverse(BiTNode*);  //后序
void LevelOrderTraverse(BiTNode*);//层次
void PreOrderTraverseWithLevel(BiTree T, int level, vector<vector<BiTree>>&);
