#include"CTree.h"


// 初始化这个树
void CTreeInit(CTree* CT)
{
	assert(CT);
	//节点数为 0 根 就是第一个
	CT->n = 0;
	CT->root = 0;
	//规定 无数据时 data = -1 无双亲 = -1 指针全为空
	int i = 0;
	for (i = 0; i < MAX_TREE_SIZE; i++)
	{
		CT->nodes[i].data = -1;
		CT->nodes[i].frist = NULL;
		CT->nodes[i].parent = -1;
	}

}

ChildPtr* ChilePtrCreate(int cur)
{
	ChildPtr* newchild = (ChildPtr*)malloc(sizeof(ChildPtr));
	newchild->child = cur;
	newchild->next = NULL;

	return newchild;
}

void LinkPushBack(ChildPtr** pphead, ChildPtr* newchild)
{
	//尾插链表 ！！！


	//传过来的是长子
	// 如果传过来的长子是空的	说明里面没有长子
	if (*pphead == NULL)
	{
		*pphead = newchild;
	}
	else						 //里面有长子
	{
		ChildPtr* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newchild;
	}
	

}

void LinkDestroy(ChildPtr** pphead)
{

	ChildPtr* cur = *pphead;
	while (*pphead != NULL)
	{
		*pphead = (*pphead)->next;
		free(cur);
		cur = *pphead;	
	}


}



// 构造一个树
void CTreeCreate(CTree* CT)
{
	assert(CT);
	int i = 0;
	printf("请输入总共的节点数:>");
	scanf("%d",&CT->n);

	for (i = 0; i < CT->n; i++)
	{
		fflush(stdin);
		printf("请输入第 %d 个节点:>",i+1);
		scanf("%c",&CT->nodes[i].data);
		printf("第 %d 个节点的双亲的下标是:>",i+1);
		scanf("%d",&CT->nodes[i].parent);
		printf("\n");
	}
	
	//
	int cur;
	ChildPtr* newchild = NULL;
	//从1 开始 因为第一个节点本来就没有双亲
	for (cur = 1; cur < CT->n; cur++)
	{
		newchild = ChilePtrCreate(cur);
		LinkPushBack(&(CT->nodes[CT->nodes[cur].parent].frist), newchild);
	}


}

//打印这个树
void CTreePrint(CTree* CT)
{
	assert(CT);
	if (CT->n == 0)
	{
		printf("此树为空\n");
		return;
	}

	int i = 0;
	for (i = 0; i < CT->n; i++)
	{
		printf("%c",CT->nodes[i].data);
	}
	printf("\n");
}



//检测树是否为空
bool CTreeEmpty(CTree* CT)
{
	assert(CT);
	return CT->n == 0;
}

//返回 e 的位置
CTBox* CTreeFind(CTree* CT, CTElemType e)
{
	assert(CT);
	int i = 0;
	for (i = 0; i < CT->n; i++)
	{
		if (CT->nodes[i].data == e)
		{
			return &(CT->nodes[i]);
		}
	}

	return NULL;
}

//找到当前位置的值并返回
CTElemType CTreeFindVal(CTree* CT, CTBox* cur)
{
	assert(CT && cur);
	return cur->data;
}

//给当前 位置 赋值
void CTreeAssign(CTree* CT, CTBox* cur, CTElemType val)
{
	assert(CT && cur);
	cur->data = val;
}



//返回当前节点的双亲
CTBox* CTreeParent(CTree* CT, CTBox* cur)
{
	if (cur->parent == -1)
	{
		return NULL;
	}
	return &(CT->nodes[cur->parent]);
}

//返回当前节点的长子
CTBox* CTreeFristChild(CTree* CT, CTBox* cur)
{
	if (cur->frist == NULL)
	{
		return NULL;
	}
	return &(CT->nodes[cur->frist->child]);

}

//返回当前节点的右兄弟
CTBox* CTreeRightSibling(CTree* CT, CTBox* cur)
{
	int i = 0;
	for (i = 0; i < CT->n; i++)
	{
		if (CT->nodes[i].data == cur->data)
		{
			break;
		}
	}
	// 找到了当前节点的下标
	
	if (CT->nodes[CT->nodes[i].parent].frist->child == i)
	{
		return &(CT->nodes[CT->nodes[CT->nodes[i].parent].frist->next->child]);
	}
	else
	{
		ChildPtr* tmp = CT->nodes[CT->nodes[i].parent].frist;
		while (tmp->child != i)
		{
			tmp = tmp->next;
			if (tmp->next == NULL)
			{
				printf("无右边兄弟\n");
				return NULL;
			}
		}
		tmp = tmp->next;
		return &(CT->nodes[tmp->child]);
	}
}

//在当前位置的 第 i 棵位置插入 e
void CTreeInsert(CTree* CT, CTBox* cur, int i, CTElemType e)
{
	assert(CT && cur);
	assert(CT->n < MAX_TREE_SIZE);

	CT->nodes[CT->n].data = e;
	CT->nodes[CT->n].frist = NULL;
	int k = 0;
	for (k = 0; k < CT->n; k++)
	{
		if (CT->nodes[k].data == cur->data)
		{
			break; 
		}
	}
	CT->nodes[CT->n].parent = k;



	ChildPtr* newchild = ChilePtrCreate(CT->n);

	//判断是否是叶子 即是否在长子域插
	if (cur->frist == NULL)
	{
		LinkPushBack(&(cur->frist), newchild);
	}
	else
	{
		int k = 1;
		//链表的前一个后一个
		ChildPtr* Lprev = cur->frist;
		ChildPtr* Lcur = cur->frist;
		while (k != i)
		{
			Lcur = Lcur->next;
			k++;
			if (k == i)
			{
				break;
			}
			else
			{
				Lprev++;
			}
		}

		Lprev->next = newchild;
		newchild->next = Lcur;

	}
	CT->n++;
}

//删除当前位置的第	i	棵子树的
void CTreeDelete(CTree* CT, CTBox* cur, int i)
{
	


}


//销毁树
void CTreeDestroy(CTree* CT)
{


	int i = 0;
	for (i = 0; i < CT->n; i++)
	{
		CT->nodes[i].data = -1;
		LinkDestroy(&(CT->nodes[i].frist));
		CT->nodes[i].parent = -1;
	}
	CT->n = 0;
	CT->root = 0;

}