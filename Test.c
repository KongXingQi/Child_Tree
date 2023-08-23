#include"CTree.h"



void CTreeTest1()
{
	CTree T;
	CTreeInit(&T);
	CTreePrint(&T);
	CTreeCreate(&T);
	CTreePrint(&T);
	CTBox* cur = CTreeFind(&T, 'D');

	CTreeAssign(&T, cur, 'K');
	CTreePrint(&T);


	CTreeDestroy(&T);
}

void CTreeTest2()
{
	CTree T;
	CTreeInit(&T);
	CTreeCreate(&T);
	CTreePrint(&T);
	CTBox* cur = CTreeFind(&T, 'H');
	printf("Ë«Ç×%c\n", CTreeFindVal(&T, (CTreeParent(&T, cur))));
	//printf("³¤×Ó%c\n", CTreeFindVal(&T, (CTreeFristChild(&T, cur))));
	printf("ÓÒÐÖ%c\n", CTreeFindVal(&T, (CTreeRightSibling(&T, cur))));
	CTreeInsert(&T, cur, 1, 'K');
	cur = CTreeFind(&T, 'D');
	CTreeInsert(&T, cur, 2, 'N');
	CTreePrint(&T);


	//CTreeDelete(&T, cur, 2);
	//CTreePrint(&T);


}


int main()
{
	//CTreeTest1();
	CTreeTest2();
	return 0;
}