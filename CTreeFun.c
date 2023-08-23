#include"CTree.h"


// ��ʼ�������
void CTreeInit(CTree* CT)
{
	assert(CT);
	//�ڵ���Ϊ 0 �� ���ǵ�һ��
	CT->n = 0;
	CT->root = 0;
	//�涨 ������ʱ data = -1 ��˫�� = -1 ָ��ȫΪ��
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
	//β������ ������


	//���������ǳ���
	// ����������ĳ����ǿյ�	˵������û�г���
	if (*pphead == NULL)
	{
		*pphead = newchild;
	}
	else						 //�����г���
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



// ����һ����
void CTreeCreate(CTree* CT)
{
	assert(CT);
	int i = 0;
	printf("�������ܹ��Ľڵ���:>");
	scanf("%d",&CT->n);

	for (i = 0; i < CT->n; i++)
	{
		fflush(stdin);
		printf("������� %d ���ڵ�:>",i+1);
		scanf("%c",&CT->nodes[i].data);
		printf("�� %d ���ڵ��˫�׵��±���:>",i+1);
		scanf("%d",&CT->nodes[i].parent);
		printf("\n");
	}
	
	//
	int cur;
	ChildPtr* newchild = NULL;
	//��1 ��ʼ ��Ϊ��һ���ڵ㱾����û��˫��
	for (cur = 1; cur < CT->n; cur++)
	{
		newchild = ChilePtrCreate(cur);
		LinkPushBack(&(CT->nodes[CT->nodes[cur].parent].frist), newchild);
	}


}

//��ӡ�����
void CTreePrint(CTree* CT)
{
	assert(CT);
	if (CT->n == 0)
	{
		printf("����Ϊ��\n");
		return;
	}

	int i = 0;
	for (i = 0; i < CT->n; i++)
	{
		printf("%c",CT->nodes[i].data);
	}
	printf("\n");
}



//������Ƿ�Ϊ��
bool CTreeEmpty(CTree* CT)
{
	assert(CT);
	return CT->n == 0;
}

//���� e ��λ��
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

//�ҵ���ǰλ�õ�ֵ������
CTElemType CTreeFindVal(CTree* CT, CTBox* cur)
{
	assert(CT && cur);
	return cur->data;
}

//����ǰ λ�� ��ֵ
void CTreeAssign(CTree* CT, CTBox* cur, CTElemType val)
{
	assert(CT && cur);
	cur->data = val;
}



//���ص�ǰ�ڵ��˫��
CTBox* CTreeParent(CTree* CT, CTBox* cur)
{
	if (cur->parent == -1)
	{
		return NULL;
	}
	return &(CT->nodes[cur->parent]);
}

//���ص�ǰ�ڵ�ĳ���
CTBox* CTreeFristChild(CTree* CT, CTBox* cur)
{
	if (cur->frist == NULL)
	{
		return NULL;
	}
	return &(CT->nodes[cur->frist->child]);

}

//���ص�ǰ�ڵ�����ֵ�
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
	// �ҵ��˵�ǰ�ڵ���±�
	
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
				printf("���ұ��ֵ�\n");
				return NULL;
			}
		}
		tmp = tmp->next;
		return &(CT->nodes[tmp->child]);
	}
}

//�ڵ�ǰλ�õ� �� i ��λ�ò��� e
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

	//�ж��Ƿ���Ҷ�� ���Ƿ��ڳ������
	if (cur->frist == NULL)
	{
		LinkPushBack(&(cur->frist), newchild);
	}
	else
	{
		int k = 1;
		//�����ǰһ����һ��
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

//ɾ����ǰλ�õĵ�	i	��������
void CTreeDelete(CTree* CT, CTBox* cur, int i)
{
	


}


//������
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