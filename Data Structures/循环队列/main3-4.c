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
	printf("初始化队列后，队列是否为空？%u（1:空， 0:否）\n", QueueIsEmpty(Q));
	printf("请输入整形队列元素（不超过%d个）, -1 为提前结束符: ", MAX_QSIZE- 1 );
	do	{
		scanf("%d", &d);
		if (d == -1)
			break;
		i++;
		EnQueue(&Q, d);
	} while (i < MAX_QSIZE - 1);
	
	printf("队列的长度为: %d", QueueLength(Q));
	printf("现在队列是否为空？%u（1:空， 0:否）\n", QueueIsEmpty(Q));
	
	printf("连续%d次由队头删除元素，队尾插入元素: \n", MAX_QSIZE);
	for (m = 1; m <= MAX_QSIZE; m++)	{
		DeQueue(&Q, &d);
		printf("删除的元素是%d，请输入待插入的元素: ", d);
		scanf("%d", &d);
		EnQueue(&Q, d);
	} 
	
	m = QueueLength(Q);
	
	printf("现在队列中的元素为: ");
	QueueTraverse(Q, print);
	printf("共向队尾插入了%d个元素", i + MAX_QSIZE);
	
	if (m - 2 > 0)
		printf("现在由对头删除%d个元素，", m - 2);
	while (QueueLength(Q) > 2)	{
		DeQueue(&Q, &d);
		printf("删除的值为%d.", d);
	}
	
	j = GetHead(Q, &d);
	if (j)
		printf("现在队头元素为:%d\n", d);
	ClearQueue(&Q);
	printf("清空队列后，队列是否为空？%u（1:空， 0:否）\n", QueueIsEmpty(Q));
	DestroyQueue(&Q);
	
	return 0;
}
