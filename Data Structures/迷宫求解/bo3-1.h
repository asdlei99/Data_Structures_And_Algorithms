//初始化栈 
Status InitStack(SqStack *S)	{
	S->base = (SElemType*)malloc(sizeof(SElemType) * STACK_INIT_SIZE);
	if (!(*S).base)
		exit(OVERFLOW);
	S->top = (*S).base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}


//销毁栈
Status DestroyStack(SqStack *S)	{
	
	S->base = S->top = NULL;
	S->stacksize = 0;
	free(S->base);
	return OK;
} 

//清空栈
Status ClearStack(SqStack *S)	{
	S->base = S->top;
	return OK;	
} 

//栈是否为空
Status StackIsEmpty(SqStack S)	{
	return S.base == S.top;
} 

//栈的长度 
int StackLength(SqStack S)	{
	return S.top- S.base;
}

//返回栈顶元素，栈为空返回ERROR
Status GetTop(SqStack S, SElemType *e)	{
	if (S.top > S.base)	{
		*e = *(S.top - 1);
		return OK;
	}
	else
		return ERROR;
} 

//插入e为新的栈顶元素 
Status Push(SqStack *S, SElemType e)	{
	if (S->top - S->base == S->stacksize)	{
		S->base = (SElemType*)realloc(S->base, sizeof(SElemType) * (STACK_INCREMENT + S->stacksize));
		if (!S->base)
			exit(OVERFLOW);
		S->top = S->base + S->stacksize;
		S->stacksize += STACK_INCREMENT;
	}
	*((*S).top++) = e;  
	return OK;
}

//栈不空，用e返回栈顶元素，并删除栈顶元素返回OK， 否则返回ERROR
Status Pop(SqStack *S, SElemType *e) 	{
	if (S->top == S->base)
		return ERROR;
	*e = * --S->top;
	return OK;
}

//从栈底到栈顶依次调用函数visit()
Status StackTraverse(SqStack S, void(*visit)(SElemType))	{
	while (S.top > S.base)
		visit(*S.base++);
	printf("\n");
	return OK;
}

