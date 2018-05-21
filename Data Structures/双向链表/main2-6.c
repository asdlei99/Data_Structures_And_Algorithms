#include "c1.h"
typedef int ElemType;
#include "c2-4.h"
#include "bo2-7.h"
#include "fun2-2.h"

int main()	{
	DuLinkList L;
	int i, n = 4;
	Status j;
	ElemType e;
	InitList(&L);
	
	for (i = 1; i <= 5; i++)	{
		ListInsert(L, i, i);
	}
	
	printf("�����������: ");
	ListTraverseBack(L, print);
	
	j = GetElem(L, 2, &e);
	if (j)
		printf("�����еĵ�2��Ԫ�ص�ֵΪ%d\n", e);
	else
		printf("�����ڵ�2��Ԫ��");
	
	i = LocateElem(L, n, equal);
	if (i)
		printf("����%d��Ԫ���ǵ�%d��\n", n, i);
	else
		printf("û�е���%d��Ԫ��\n", n);
	
	j = PriorElem(L, n, &e);
	if (j)
		printf("%d��ǰ����%d, ", n, e);
	else
		printf("������%d��ǰ��\n");
	
	j = NextElem(L, n , &e);
	if (j)
		printf("%d�ĺ����%d\n", n, e);
	else
		printf("������%d�ĺ��\n"); 
	
	ListDelete(L, 2, &e);
	printf("ɾ����2����㣬ֵΪ%d�� ������Ϊ ", e);
	ListTraverse(L, print);
	
	printf("�����Ԫ�ظ���Ϊ%d, ", ListLength(L));
	
	printf("�����Ƿ�Ϊ��?%d(1:�ǣ� 0:��)\n", ListIsEmpty(L));
	
	ClearList(L);
	printf("��պ������Ƿ�Ϊ��?%d(1:�ǣ� 0:��)\n", ListIsEmpty(L));
	DestroyList(&L);
		
	return 0;
}
