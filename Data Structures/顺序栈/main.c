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
	
	printf("栈中的元素依次为:");
	StackTraverse(S, print);
	
	Pop(&S, &e);
	printf("弹出的栈顶元素为: e = %d\n", e);
	
	printf("栈是否为空？%d（1：空， 0：否）， ", StackIsEmpty(S));
	
	GetTop(S, &e);
	printf("栈顶元素e = %d, 栈的长度为%d\n", e, StackLength(S));
	
	ClearStack(&S);
	printf("清空栈后，栈是否为空？%d（1：空， 0：否）\n", StackIsEmpty(S));
	
	DestroyStack(&S);
	printf("销毁栈后，S.top = %p, S.base = %p, S.stacksize = %d\n", S.top, S.base, S.stacksize);
	return 0;
}
