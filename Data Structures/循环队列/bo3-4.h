//初始化队列 
void InitQueue(SqQueue *Q)	{
	Q->base = (QElemType*)malloc(MAX_QSIZE * sizeof(QElemType));
	if (!Q->base)
		exit(OVERFLOW);
	Q->front = Q->rear = 0;
}

//销毁队列
void DestroyQueue(SqQueue *Q)	{
	if (Q->base)
		free(Q->base);
	Q->base = NULL;
	Q->front = Q->rear = 0; 
} 

//清空队列
void ClearQueue(struct SqQueue *Q)	{
	Q->front = Q->rear = 0;
} 

//是否为空队列
Status QueueIsEmpty(struct SqQueue Q)	{
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
} 

//获取队头
Status GetHead(struct SqQueue Q, QElemType *e)	{
	if (Q.front == Q.rear)
		return ERROR;
	*e = Q.base[Q.front];
		return OK;
} 

//插入e到队尾
Status EnQueue(struct SqQueue *Q, QElemType e)	{
	if ((Q->rear + 1) % MAX_QSIZE == Q->front)	//队列满 
		return ERROR;
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAX_QSIZE;
	return OK;
} 

//返回长度
int QueueLength(struct SqQueue Q)	{
	return (Q.rear - Q.front + MAX_QSIZE) % MAX_QSIZE;
} 

//删除队头 
Status DeQueue(SqQueue *Q, QElemType *e)	{
	if (Q->front == Q->rear)
		return ERROR;
	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAX_QSIZE;
	return OK;
}

//队列所有元素调用visit()函数 
void QueueTraverse(SqQueue Q, void(*visit)(QElemType))	{
	int i = Q.front;
	while (i != Q.rear)	{
		visit(Q.base[i]);
		i = (i + 1) % MAX_QSIZE;
	}
	printf("\n");
}
