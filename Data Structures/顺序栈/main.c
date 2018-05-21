#include "c1.h"
typedef int SElemType;
#include "c3-1.h" 
#include "bo3-1.h"
#define ElemType SElemType
#include "fun2-2.h"

int main()	{
	int j;
	SqStack S;
	SElemType e;
	
	InitStack(&S);
	
	for (j = 1; j <= 12; j++)	{
		Push(&S, j);
	}
	
	printf("ջ�е�Ԫ������Ϊ:");
	StackTraverse(S, print);
	
	Pop(&S, &e);
	printf("������ջ��Ԫ��Ϊ: e = %d\n", e);
	
	printf("ջ�Ƿ�Ϊ�գ�%d��1���գ� 0���񣩣� ", StackIsEmpty(S));
	
	GetTop(S, &e);
	printf("ջ��Ԫ��e = %d, ջ�ĳ���Ϊ%d\n", e, StackLength(S));
	
	ClearStack(&S);
	printf("���ջ��ջ�Ƿ�Ϊ�գ�%d��1���գ� 0����\n", StackIsEmpty(S));
	
	DestroyStack(&S);
	printf("����ջ��S.top = %p, S.base = %p, S.stacksize = %d\n", S.top, S.base, S.stacksize);
	return 0;
}
