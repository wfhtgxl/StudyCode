#include"header.h"
#include<iostream>
#include<vector>
using namespace std;

//            A
//         /      \
//        B        C
//       /\        /\
//      D  E     F  G

bool Compare(BiTree T1, BiTree T2)
{

	if (T1 && T2 && (T1->ch == T2->ch)) {
		if (Compare(T1->lchild, T2->lchild) && Compare(T1->rchild, T2->rchild)) //�����ڵ���ͬ���ݹ��жϽڵ�����������Ƿ���ͬ
			return true;
		else
			return false;
	}
	else if (T1 == NULL && T2 == NULL)  //������ǿ�����������ͬ
		return true;
	else
		return false;     //������������߲�ͬ
}


int main()
{
	BiTree root;
	BiTree root_compare;
	root = AddBiTree();
	root_compare = AddBiTree();
	//����������  
	cout << "Preorder traversal��\n";
	PreOrderTraverse(root);
	cout << "\nIn Order��\n";
	InOrderTraverse(root);
	cout << "\nPost Order��\n";
	PostOrderTraverse(root);
	cout << "\nLevel Order��\n";
	LevelOrderTraverse(root);
	cout << "\nLevel Order��\n";
	LevelOrderTraverse(root_compare);
	if (Compare(root, root_compare)) {
		cout << "similar!" << endl;
	}
	else {
		cout << "no similar!";
	}
	return 0;
}
//�������������ȫ������   
BiTree AddBiTree()
{
	vector<BiTree> trees;
	for (int i = 0; ; i++)
	{
		char c;
		cin >> c;
		if (c == '#')//c���ڻس�����forѭ��
		{
			break;
		}
		BiTree tree = new BiTNode();
		tree->ch = c;//ָ��Ϊ->������Ϊ.
		tree->lchild = NULL;
		tree->rchild = NULL;
		trees.push_back(tree);
	}
	for (int i = trees.size() - 1; i > 0; i--)//�������ϱ���
	{
		if (i % 2 != 0)//����
		{
			trees[(i - 1) / 2]->lchild = trees[i];
		}
		else//ż��
		{
			trees[(i - 1) / 2]->rchild = trees[i];
		}
	}
	return trees[0];//���ظ��ڵ�
}


//ǰ�����  
void PreOrderTraverse(BiTree T)
{
	if (T) {
		cout << T->ch << " ";
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

//�������  
void InOrderTraverse(BiTree T)
{
	if (T) {
		InOrderTraverse(T->lchild);
		cout << T->ch << " ";
		InOrderTraverse(T->rchild);
	}
}

//�������  
void PostOrderTraverse(BiTree T)
{
	if (T) {
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		cout << T->ch << " ";
	}
}
//��α��� 
void LevelOrderTraverse(BiTree T) {
	if (T)
	{
		vector<vector<BiTree>> vec;
		PreOrderTraverseWithLevel(T, 0, vec);
		for (int i = 0; i < vec.size(); i++)
		{
			for (int j = 0; j < vec[i].size(); j++)
			{
				cout << vec[i][j]->ch << " ";
			}
			cout << endl;
		}
	}

}


void PreOrderTraverseWithLevel(BiTree T, int level, vector<vector<BiTree>>& vec)
{
	if (T) {
		if (vec.size() < level + 1) {
			vector<BiTree> arr;
			vec.push_back(arr);
		}
		vec[level].push_back(T);
		PreOrderTraverseWithLevel(T->lchild, level + 1, vec);
		PreOrderTraverseWithLevel(T->rchild, level + 1, vec);
	}
}



