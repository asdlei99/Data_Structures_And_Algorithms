Status InitList(LinkList *L)  
{  
    //操作结果：构造一个空的线性表L  
    *L = (LinkList)malloc(sizeof(struct LNode));   //产生头结点,并使L指向此头结点  
    if(!(*L)) exit(OVERFLOW);    //存储分配失败  
    (*L)->next = NULL;        //指针域为空  
    return OK;  
} 

void DestroyList(LinkList *L)	{
	LinkList p;
	while (*L)	{
		p = (*L)->next;
		free(*L);
		*L = p;
	}
}

void ClearList(LinkList L)	{
	LinkList p,q;  
    p = L->next;       //p指向第一个结点  
    while(p)           //没到表尾  
    {  
        q = p->next;  
        free(p);  
        p = q;  
    }  
    L->next = NULL;     //头结点指针域为空  
}

Status ListIsEmpty(LinkList L)	{
	return (L->next == NULL);
}

int ListLength(LinkList L)	{
	int i = 0;  
    LinkList p = L->next;  
    while(p)  
    {  
        i++;  
        p = p->next;  
    }  
    return i;  
}

Status GetElem(LinkList L, int i, ElemType* e)	{
	int j=1;                   //j为计数器  
    LinkList p = L->next;    //p指向第一个结点  
    while(p && j<i)          //顺指针向后查找,直到p指向第i个元素或p为空  
    {  
        p = p->next;  
        j++;  
    }  
    if(!p || j>i) return ERROR;   //第i个元素不存在  
    (*e) = p->data;               //得到第i个元素  
    return OK;
}

int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType))	{
	int i = 0;  
    LinkList p = L->next;  
    while(p)  
    {  
        i++;  
        if(compare(p->data,e))  //找到这样的数据元素  
            return i;  
        p = p->next;  
    }  
    return 0;  
}

Status PriorElem(LinkList L, ElemType cur_e, ElemType* pre_e)	{
	LinkList p = L->next;  
    while(p->next)  
    {  
        if(cur_e == p->next->data)  
        {  
            *pre_e =  p->data;  
            return OK;  
        }  
        p = p->next;  
    }  
	return ERROR;
}

Status NextElem(LinkList L,ElemType cur_e,ElemType *next_e)  
{  
    // 初始条件：线性表L已存在  
    // 操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，返回OK;否则操作失败，next_e无定义，返回INFEASIBLE  
    LinkList p = L->next;  
    while(p->next)  
    {  
        if(p->data == cur_e)  
        {  
            *next_e = p->next->data;  
            return OK;  
        }  
        p = p->next;  
    }  
    return INFEASIBLE;  
}  

Status ListInsert(LinkList L, int i, ElemType e)	{
	int j = 0;
	LinkList s, p = L;
	while (p && j<i-1)	{
		j++;
		p = p->next;
	}
	if (!p || (j > i-1))	
		return ERROR;
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

Status ListDelete(LinkList L, int i, ElemType* e)	{
	LinkList p=L,q;  
    int j = 0;  
    while(p->next&&j<i-1)      //寻找第i个结点,并令p指向其前趋  
    {  
        p=p->next;  
        j++;  
    }  
    if(!(p->next)||j<i-1) return ERROR;  //删除位置不合理  
    q = p->next;                         //删除并释放结点  
    p->next = q->next;  
    *e = q->data;  
    free(q);  
    return OK;  
}

void ListTraverse(LinkList L, void (*visit)(ElemType))	{
	LinkList p = L->next;  
    while(p)  
    {  
        (*visit)(p->data);  
        p = p->next;  
    }  
    printf("\n");
}
