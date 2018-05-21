Status InitList(LinkList *L)  
{  
    //�������������һ���յ����Ա�L  
    *L = (LinkList)malloc(sizeof(struct LNode));   //����ͷ���,��ʹLָ���ͷ���  
    if(!(*L)) exit(OVERFLOW);    //�洢����ʧ��  
    (*L)->next = NULL;        //ָ����Ϊ��  
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
    p = L->next;       //pָ���һ�����  
    while(p)           //û����β  
    {  
        q = p->next;  
        free(p);  
        p = q;  
    }  
    L->next = NULL;     //ͷ���ָ����Ϊ��  
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
	int j=1;                   //jΪ������  
    LinkList p = L->next;    //pָ���һ�����  
    while(p && j<i)          //˳ָ��������,ֱ��pָ���i��Ԫ�ػ�pΪ��  
    {  
        p = p->next;  
        j++;  
    }  
    if(!p || j>i) return ERROR;   //��i��Ԫ�ز�����  
    (*e) = p->data;               //�õ���i��Ԫ��  
    return OK;
}

int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType))	{
	int i = 0;  
    LinkList p = L->next;  
    while(p)  
    {  
        i++;  
        if(compare(p->data,e))  //�ҵ�����������Ԫ��  
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
    // ��ʼ���������Ա�L�Ѵ���  
    // �����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣�����OK;�������ʧ�ܣ�next_e�޶��壬����INFEASIBLE  
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
    while(p->next&&j<i-1)      //Ѱ�ҵ�i�����,����pָ����ǰ��  
    {  
        p=p->next;  
        j++;  
    }  
    if(!(p->next)||j<i-1) return ERROR;  //ɾ��λ�ò�����  
    q = p->next;                         //ɾ�����ͷŽ��  
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
