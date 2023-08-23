#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

#define MAX_TREE_SIZE 13

typedef char CTElemType;



//这个 自己个人的理解  这个孩子表示法 是一个	顺序表 + 链表	的结构 感觉有点写的锉 哈哈哈 不止一点！ 特别是	CTreeRightSibling	这个函数 老锉了。。。。。。
//

typedef struct CTNode //孩子节点
{
	int child;			// 当前节点的下标
	struct CTNode* next;// 该节点的右兄弟（下一个）
}ChildPtr;

typedef struct
{
	CTElemType data;		//数据
	int parent;				//双亲
	ChildPtr* frist;		//长子
}CTBox;

typedef struct
{
	CTBox nodes[MAX_TREE_SIZE];
	int root, n;// n ~ 节点个数
}CTree;





//树的接口函数
//--------------------------------------------------------------------

// 初始化这个树
void CTreeInit(CTree* CT);

// 构造一个树
void CTreeCreate(CTree* CT);

//打印这个树
void CTreePrint(CTree* CT);

//检测树是否为空
bool CTreeEmpty(CTree* CT);

//返回 e 的位置
CTBox* CTreeFind(CTree* CT ,CTElemType e);

//找到当前位置的值并返回
CTElemType CTreeFindVal(CTree* CT, CTBox* cur);

//给当前 位置 赋值
void CTreeAssign(CTree* CT,CTBox* cur,CTElemType val);

//返回当前节点的双亲
CTBox* CTreeParent(CTree* CT, CTBox* cur);

//返回当前节点的长子
CTBox* CTreeFristChild(CTree* CT,CTBox* cur);

//返回当前节点的右兄弟
CTBox* CTreeRightSibling(CTree* CT,CTBox* cur);

//在当前位置的 第 i 棵位置插入 e
void CTreeInsert(CTree* CT,CTBox* cur,int i ,CTElemType e);

//删除当前位置的第	i	棵子树的
void CTreeDelete(CTree* CT, CTBox* cur, int i);

//销毁树
void CTreeDestroy(CTree* CT);



//--------------------------------------------------------------------
//尾插链表
void LinkPushBack(ChildPtr** pphead, ChildPtr* newchild);
//销毁链表
void LinkDestroy(ChildPtr** pphead);
