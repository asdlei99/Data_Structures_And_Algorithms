//初始化链表 
void InitList(DuLinkList *L)	{
	*L = (DuLinkList)malloc(sizeof(DuLNode));
	if (L)	{
		(*L)->next = (*L)->prior = *L;
	}	
	else	{
		exit(OVERFLOW);
	}
}

//清空链表，但不改变L
void ClearList(DuLinkList L)	{
	DuLinkList p = L->next;
	while (p != L)	{
		p = p->next;
		free(p->prior);
	}
	L->next = L->prior = L;
} 

//销毁链表 
void DestroyList(DuLinkList *L)	{
	ClearList(*L);
	free(L);
	L = NULL; 
}

//判断链表是否为空
Status ListIsEmpty(DuLinkList L)	{
	if (L->next == L && L->prior == L)	{
		return TRUE;
	}
	else
		return FALSE;
} 

//返回链表的长度
int ListLength(DuLinkList L)	{
	int i = 0;
	DuLinkList p = L->next;
	while (p != L)	{
		i++;
		p = p->next;
	}
	return i;
} 

//当第i个元素存在时，将钙元素赋值给e，并返回OK,否则返回ERROR
Status GetElem(DuLinkList L, int i, ElemType *e)	{
	int j = 1;
	DuLinkList p = L->next;
	while (p != L && j < i)	{
		j++;
		p = p->next;
	}
	if (p == L || j > i)	{
		return ERROR;
	}
	*e = p->data;
	return OK;
} 

//L存在，返回L中第一个与e满足compare()关系的数据元素位置，若该数据元素不存在，则返回0
int LocateElem(DuLinkList L, ElemType e, Status(*compare)(ElemType, ElemType))	{
	int i = 0;
	DuLinkList p = L->next;
	while (p != L)	{
		i++;
		if (compare(p->data, e))	{
			return i;
		}
		p = p->next;
	}
	return 0;
} 

//若cur_e是L的数据元素，且是第一个，则用 pre_e返回它的前驱，返回OK,操作失败返回ERROR
Status PriorElem(DuLinkList L, ElemType cur_e, ElemType *pre_e)	{
	DuLinkList p = L->next->next;
	while (p != L)	{
		if (p->data == cur_e)	{
			*pre_e = p->prior->data;
			return OK;
		}
		p = p->next;
	}
	return ERROR;
} 

//若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，返回OK，操作失败则返回ERROR 
Status NextElem(DuLinkList L, ElemType cur_e, ElemType *next_e)	{
	DuLinkList p = L->next;
	while (p != L) {
		if (p->prior->data == cur_e)	{
		 	*next_e = p->data;
		 	return OK;
		}
		p = p->next; 
	}
	return ERROR;
}

//在双向链表L中返回第i个元素的地址，i为0，则返回头结点地址，若第i个元素不存在，则返回NULL
DuLinkList GetElemP(DuLinkList L, int i)	{
	int j;
	DuLinkList p = L;
	if (i < 0 || i > ListLength(L))	{
		return ERROR;
	}
	for (j = 1; j <= i; j++)	{
		p = p->next;
	}
	return p;
} 

//在带头结点的双链循环线性表L中第i个位置之前插入元素e，若i不合法则返回ERROR
Status ListInsert(DuLinkList L, int i, ElemType e)	{
	DuLinkList p, s;
	if (i < 1 || i >ListLength(L) + i)	{
		return ERROR;
	}
	p = GetElemP(L, i - 1);	//在L中确定第i个结点的前驱的位置指针p
	if (!p)	//p = NULL ，即第i个结点的前驱不存在(设头的节点为一结点的前驱)
		return ERROR;
	s = (DuLinkList)malloc(sizeof(DuLinkList));
	if (!s)	
		return ERROR;
	s->data = e;
	s->prior = p;
	s->next = p->next;
	s->next->prior = s;
	p->next = s;
	return OK; 
} 

//删除带头节点的双链循环线性表L的第i个元素
Status ListDelete(DuLinkList L, int i, ElemType *e)	{
	DuLinkList p;
	if (i < 1)
		return ERROR;
	p = GetElemP(L, i);	//在L中确定第i个元素的位置指针p
	if(!p)
		return ERROR;
	*e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return OK; 
} 

//由双链循环线性表L的头节点出发，正序对每个数据元素调用函数visit()
void ListTraverse(DuLinkList L, void(*visit)(ElemType))	{
	DuLinkList p = L->next;
	while (p != L)	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
} 

//逆序调用visit()
void ListTraverseBack(DuLinkList L, void(*visit)(ElemType))	{
	DuLinkList p = L->prior;
	while (p != L)	{
		visit(p->data);
		p = p->prior;
	}
	printf("\n");
} 
