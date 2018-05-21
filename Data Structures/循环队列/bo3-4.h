//��ʼ������ 
void InitQueue(SqQueue *Q)	{
	Q->base = (QElemType*)malloc(MAX_QSIZE * sizeof(QElemType));
	if (!Q->base)
		exit(OVERFLOW);
	Q->front = Q->rear = 0;
}

//���ٶ���
void DestroyQueue(SqQueue *Q)	{
	if (Q->base)
		free(Q->base);
	Q->base = NULL;
	Q->front = Q->rear = 0; 
} 

//��ն���
void ClearQueue(struct SqQueue *Q)	{
	Q->front = Q->rear = 0;
} 

//�Ƿ�Ϊ�ն���
Status QueueIsEmpty(struct SqQueue Q)	{
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
} 

//��ȡ��ͷ
Status GetHead(struct SqQueue Q, QElemType *e)	{
	if (Q.front == Q.rear)
		return ERROR;
	*e = Q.base[Q.front];
		return OK;
} 

//����e����β
Status EnQueue(struct SqQueue *Q, QElemType e)	{
	if ((Q->rear + 1) % MAX_QSIZE == Q->front)	//������ 
		return ERROR;
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAX_QSIZE;
	return OK;
} 

//���س���
int QueueLength(struct SqQueue Q)	{
	return (Q.rear - Q.front + MAX_QSIZE) % MAX_QSIZE;
} 

//ɾ����ͷ 
Status DeQueue(SqQueue *Q, QElemType *e)	{
	if (Q->front == Q->rear)
		return ERROR;
	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAX_QSIZE;
	return OK;
}

//��������Ԫ�ص���visit()���� 
void QueueTraverse(SqQueue Q, void(*visit)(QElemType))	{
	int i = Q.front;
	while (i != Q.rear)	{
		visit(Q.base[i]);
		i = (i + 1) % MAX_QSIZE;
	}
	printf("\n");
}
