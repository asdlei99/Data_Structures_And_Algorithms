//��ʼ��ջ 
Status InitStack(SqStack *S)	{
	S->base = (SElemType*)malloc(sizeof(SElemType) * STACK_INIT_SIZE);
	if (!(*S).base)
		exit(OVERFLOW);
	S->top = (*S).base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}


//����ջ
Status DestroyStack(SqStack *S)	{
	
	S->base = S->top = NULL;
	S->stacksize = 0;
	free(S->base);
	return OK;
} 

//���ջ
Status ClearStack(SqStack *S)	{
	S->base = S->top;
	return OK;	
} 

//ջ�Ƿ�Ϊ��
Status StackIsEmpty(SqStack S)	{
	return S.base == S.top;
} 

//ջ�ĳ��� 
int StackLength(SqStack S)	{
	return S.top- S.base;
}

//����ջ��Ԫ�أ�ջΪ�շ���ERROR
Status GetTop(SqStack S, SElemType *e)	{
	if (S.top > S.base)	{
		*e = *(S.top - 1);
		return OK;
	}
	else
		return ERROR;
} 

//����eΪ�µ�ջ��Ԫ�� 
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

//ջ���գ���e����ջ��Ԫ�أ���ɾ��ջ��Ԫ�ط���OK�� ���򷵻�ERROR
Status Pop(SqStack *S, SElemType *e) 	{
	if (S->top == S->base)
		return ERROR;
	*e = * --S->top;
	return OK;
}

//��ջ�׵�ջ�����ε��ú���visit()
Status StackTraverse(SqStack S, void(*visit)(SElemType))	{
	while (S.top > S.base)
		visit(*S.base++);
	printf("\n");
	return OK;
}

