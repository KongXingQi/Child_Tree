#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

#define MAX_TREE_SIZE 13

typedef char CTElemType;



//��� �Լ����˵����  ������ӱ�ʾ�� ��һ��	˳��� + ����	�Ľṹ �о��е�д��� ������ ��ֹһ�㣡 �ر���	CTreeRightSibling	������� ����ˡ�����������
//

typedef struct CTNode //���ӽڵ�
{
	int child;			// ��ǰ�ڵ���±�
	struct CTNode* next;// �ýڵ�����ֵܣ���һ����
}ChildPtr;

typedef struct
{
	CTElemType data;		//����
	int parent;				//˫��
	ChildPtr* frist;		//����
}CTBox;

typedef struct
{
	CTBox nodes[MAX_TREE_SIZE];
	int root, n;// n ~ �ڵ����
}CTree;





//���Ľӿں���
//--------------------------------------------------------------------

// ��ʼ�������
void CTreeInit(CTree* CT);

// ����һ����
void CTreeCreate(CTree* CT);

//��ӡ�����
void CTreePrint(CTree* CT);

//������Ƿ�Ϊ��
bool CTreeEmpty(CTree* CT);

//���� e ��λ��
CTBox* CTreeFind(CTree* CT ,CTElemType e);

//�ҵ���ǰλ�õ�ֵ������
CTElemType CTreeFindVal(CTree* CT, CTBox* cur);

//����ǰ λ�� ��ֵ
void CTreeAssign(CTree* CT,CTBox* cur,CTElemType val);

//���ص�ǰ�ڵ��˫��
CTBox* CTreeParent(CTree* CT, CTBox* cur);

//���ص�ǰ�ڵ�ĳ���
CTBox* CTreeFristChild(CTree* CT,CTBox* cur);

//���ص�ǰ�ڵ�����ֵ�
CTBox* CTreeRightSibling(CTree* CT,CTBox* cur);

//�ڵ�ǰλ�õ� �� i ��λ�ò��� e
void CTreeInsert(CTree* CT,CTBox* cur,int i ,CTElemType e);

//ɾ����ǰλ�õĵ�	i	��������
void CTreeDelete(CTree* CT, CTBox* cur, int i);

//������
void CTreeDestroy(CTree* CT);



//--------------------------------------------------------------------
//β������
void LinkPushBack(ChildPtr** pphead, ChildPtr* newchild);
//��������
void LinkDestroy(ChildPtr** pphead);
