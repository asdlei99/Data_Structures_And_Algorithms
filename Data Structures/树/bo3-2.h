//初始化队列，构造一个空的队列
void InitQueue(LinkQueue &Q)    {
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q.front)
        exit(OVERFLOW);
    Q.front->next = NULL;
}

//销毁队列
void DestroyQueue(LinkQueue &Q) {
    while (Q.front) {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }
}

//清空队列
void ClearQueue(LinkQueue &Q)   {
    DestroyQueue(Q);
    InitQueue(Q);
}

//判断队列是否为空
Status QueueEmpty(LinkQueue Q)  {
    if (Q.front->next == NULL)
        return TRUE;
    else
        return FALSE;
}

//求队列Q的长度
int QueueLength(LinkQueue Q)    {
    int i = 0;
    QueuePtr p = Q.front;
    while (p != Q.rear) {
        i++;
        p = p->next;
    }
}

//若队列不空，则用e返回队头元素，并返回OK，否则返回ERROR
Status GetHead(LinkQueue Q, QElemType &e)   {
    QueuePtr p;
    if (Q.front == Q.rear)  //队列为空
        return ERROR;
    else {
        p = Q.front->next;
        e = p->data;
        return OK;
    }
}

//插入元素e为队列Q的新的队尾元素
void EnQueue(LinkQueue &Q, QElemType e) {
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
    if (!p)     //内存分配失败
        exit(OVERFLOW);
    p->data = e;    //将值e赋值给新节点 队列中的新节点就是p.front
    p->next = NULL; //在讲新节点的指针区域设置为空
    Q.rear->next = p;   //原队列队尾结点的指针指向新的结点
    Q.rear = p;     //尾指针指向新节点
}


//若队列不空则，删除Q的队头元素，用e返回其值
Status DeQueue(LinkQueue &Q, QElemType e)   {
    QueuePtr p;
    if (Q.front == Q.rear)  //队列为空
        return ERROR;
    p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)    //如果删除的是队尾结点
        Q.rear = Q.front;
    free(p);
    return OK;
}

//对队列中的每个元素调用visit()函数
void QueueTraverse(LinkQueue Q, void(*visit)(QElemType))    {
    QueuePtr p = Q.front->next;
    while (p) {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
}
