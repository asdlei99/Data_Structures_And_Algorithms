//��ʼ�����У�����һ���յĶ���
void InitQueue(LinkQueue &Q)    {
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q.front)
        exit(OVERFLOW);
    Q.front->next = NULL;
}

//���ٶ���
void DestroyQueue(LinkQueue &Q) {
    while (Q.front) {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }
}

//��ն���
void ClearQueue(LinkQueue &Q)   {
    DestroyQueue(Q);
    InitQueue(Q);
}

//�ж϶����Ƿ�Ϊ��
Status QueueEmpty(LinkQueue Q)  {
    if (Q.front->next == NULL)
        return TRUE;
    else
        return FALSE;
}

//�����Q�ĳ���
int QueueLength(LinkQueue Q)    {
    int i = 0;
    QueuePtr p = Q.front;
    while (p != Q.rear) {
        i++;
        p = p->next;
    }
}

//�����в��գ�����e���ض�ͷԪ�أ�������OK�����򷵻�ERROR
Status GetHead(LinkQueue Q, QElemType &e)   {
    QueuePtr p;
    if (Q.front == Q.rear)  //����Ϊ��
        return ERROR;
    else {
        p = Q.front->next;
        e = p->data;
        return OK;
    }
}

//����Ԫ��eΪ����Q���µĶ�βԪ��
void EnQueue(LinkQueue &Q, QElemType e) {
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
    if (!p)     //�ڴ����ʧ��
        exit(OVERFLOW);
    p->data = e;    //��ֵe��ֵ���½ڵ� �����е��½ڵ����p.front
    p->next = NULL; //�ڽ��½ڵ��ָ����������Ϊ��
    Q.rear->next = p;   //ԭ���ж�β����ָ��ָ���µĽ��
    Q.rear = p;     //βָ��ָ���½ڵ�
}


//�����в�����ɾ��Q�Ķ�ͷԪ�أ���e������ֵ
Status DeQueue(LinkQueue &Q, QElemType e)   {
    QueuePtr p;
    if (Q.front == Q.rear)  //����Ϊ��
        return ERROR;
    p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)    //���ɾ�����Ƕ�β���
        Q.rear = Q.front;
    free(p);
    return OK;
}

//�Զ����е�ÿ��Ԫ�ص���visit()����
void QueueTraverse(LinkQueue Q, void(*visit)(QElemType))    {
    QueuePtr p = Q.front->next;
    while (p) {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
}
