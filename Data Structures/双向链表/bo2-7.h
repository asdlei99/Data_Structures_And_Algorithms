//��ʼ������ 
void InitList(DuLinkList *L)	{
	*L = (DuLinkList)malloc(sizeof(DuLNode));
	if (L)	{
		(*L)->next = (*L)->prior = *L;
	}	
	else	{
		exit(OVERFLOW);
	}
}

//������������ı�L
void ClearList(DuLinkList L)	{
	DuLinkList p = L->next;
	while (p != L)	{
		p = p->next;
		free(p->prior);
	}
	L->next = L->prior = L;
} 

//�������� 
void DestroyList(DuLinkList *L)	{
	ClearList(*L);
	free(L);
	L = NULL; 
}

//�ж������Ƿ�Ϊ��
Status ListIsEmpty(DuLinkList L)	{
	if (L->next == L && L->prior == L)	{
		return TRUE;
	}
	else
		return FALSE;
} 

//��������ĳ���
int ListLength(DuLinkList L)	{
	int i = 0;
	DuLinkList p = L->next;
	while (p != L)	{
		i++;
		p = p->next;
	}
	return i;
} 

//����i��Ԫ�ش���ʱ������Ԫ�ظ�ֵ��e��������OK,���򷵻�ERROR
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

//L���ڣ�����L�е�һ����e����compare()��ϵ������Ԫ��λ�ã���������Ԫ�ز����ڣ��򷵻�0
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

//��cur_e��L������Ԫ�أ����ǵ�һ�������� pre_e��������ǰ��������OK,����ʧ�ܷ���ERROR
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

//��cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣�����OK������ʧ���򷵻�ERROR 
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

//��˫������L�з��ص�i��Ԫ�صĵ�ַ��iΪ0���򷵻�ͷ����ַ������i��Ԫ�ز����ڣ��򷵻�NULL
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

//�ڴ�ͷ����˫��ѭ�����Ա�L�е�i��λ��֮ǰ����Ԫ��e����i���Ϸ��򷵻�ERROR
Status ListInsert(DuLinkList L, int i, ElemType e)	{
	DuLinkList p, s;
	if (i < 1 || i >ListLength(L) + i)	{
		return ERROR;
	}
	p = GetElemP(L, i - 1);	//��L��ȷ����i������ǰ����λ��ָ��p
	if (!p)	//p = NULL ������i������ǰ��������(��ͷ�Ľڵ�Ϊһ����ǰ��)
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

//ɾ����ͷ�ڵ��˫��ѭ�����Ա�L�ĵ�i��Ԫ��
Status ListDelete(DuLinkList L, int i, ElemType *e)	{
	DuLinkList p;
	if (i < 1)
		return ERROR;
	p = GetElemP(L, i);	//��L��ȷ����i��Ԫ�ص�λ��ָ��p
	if(!p)
		return ERROR;
	*e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return OK; 
} 

//��˫��ѭ�����Ա�L��ͷ�ڵ�����������ÿ������Ԫ�ص��ú���visit()
void ListTraverse(DuLinkList L, void(*visit)(ElemType))	{
	DuLinkList p = L->next;
	while (p != L)	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
} 

//�������visit()
void ListTraverseBack(DuLinkList L, void(*visit)(ElemType))	{
	DuLinkList p = L->prior;
	while (p != L)	{
		visit(p->data);
		p = p->prior;
	}
	printf("\n");
} 
