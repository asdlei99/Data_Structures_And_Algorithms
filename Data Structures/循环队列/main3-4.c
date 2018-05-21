#include "c1.h"
#include "c3-3.h"
#include "bo3-4.h"
#define ElemType QElemType
#include "fun2-2.h"

int main()	{
	Status j;
	int i = 0, m;
	QElemType d;
	SqQueue Q;
	
	InitQueue(&Q);
	printf("��ʼ�����к󣬶����Ƿ�Ϊ�գ�%u��1:�գ� 0:��\n", QueueIsEmpty(Q));
	printf("���������ζ���Ԫ�أ�������%d����, -1 Ϊ��ǰ������: ", MAX_QSIZE- 1 );
	do	{
		scanf("%d", &d);
		if (d == -1)
			break;
		i++;
		EnQueue(&Q, d);
	} while (i < MAX_QSIZE - 1);
	
	printf("���еĳ���Ϊ: %d", QueueLength(Q));
	printf("���ڶ����Ƿ�Ϊ�գ�%u��1:�գ� 0:��\n", QueueIsEmpty(Q));
	
	printf("����%d���ɶ�ͷɾ��Ԫ�أ���β����Ԫ��: \n", MAX_QSIZE);
	for (m = 1; m <= MAX_QSIZE; m++)	{
		DeQueue(&Q, &d);
		printf("ɾ����Ԫ����%d��������������Ԫ��: ", d);
		scanf("%d", &d);
		EnQueue(&Q, d);
	} 
	
	m = QueueLength(Q);
	
	printf("���ڶ����е�Ԫ��Ϊ: ");
	QueueTraverse(Q, print);
	printf("�����β������%d��Ԫ��", i + MAX_QSIZE);
	
	if (m - 2 > 0)
		printf("�����ɶ�ͷɾ��%d��Ԫ�أ�", m - 2);
	while (QueueLength(Q) > 2)	{
		DeQueue(&Q, &d);
		printf("ɾ����ֵΪ%d.", d);
	}
	
	j = GetHead(Q, &d);
	if (j)
		printf("���ڶ�ͷԪ��Ϊ:%d\n", d);
	ClearQueue(&Q);
	printf("��ն��к󣬶����Ƿ�Ϊ�գ�%u��1:�գ� 0:��\n", QueueIsEmpty(Q));
	DestroyQueue(&Q);
	
	return 0;
}
