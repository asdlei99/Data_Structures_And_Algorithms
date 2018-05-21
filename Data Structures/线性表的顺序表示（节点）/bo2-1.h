//����һ���յ�˳�����Ա�L 
void InitList(struct SqList* L)	{
	L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L->elem)	{
		exit(OVERFLOW);
	}
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
}

//����˳�����Ա�L
void DestroyList(struct SqList* L)	{
	free(L->elem);
	L->elem = NULL;
	L->length = 0;
	L->listsize = 0;
}

//����˳�����Ա�L
void ClearList(struct SqList* L)	{
	L->length = 0; 
}

//�ж����Ա�L�Ƿ�Ϊ��
Status ListEmpty(struct SqList* L)	{
	if (L->length == 0)	{
		return TRUE;
	}
	else	{
		return FALSE;
	}
}

//�������Ա�L��Ԫ�صĸ���
int ListLength(struct SqList* L)	{
	return L->length;
}

//��e����L�е�i������Ԫ�ص�ֵ
Status GetElem(struct SqList L, int i, ElemType *e)	{
	if (i < 0 || i > L.length)	{
		return ERROR;
	}
	else	{
		*e = *(L.elem + i - 1);
		return OK;
	}
}

//���ص�һ����e�����ϵcompare()������Ԫ�ص�λ��
int LocateElem(struct SqList L, ElemType e, Status(*compare)(ElemType, ElemType))	{
	int i = 1;	//iΪ��һ��Ԫ�ص�λ�ã���Ϊ���ڵ�0���Ǹñ�ĵ�ַ
	ElemType* p = L.elem;	//pΪ��һ��Ԫ�ص�λ�� 
	while (i <= L.length && !compare(*p++, e))
	i++;
	if (i <= L.length)
		return i;
	else
		return ERROR;
}

//��cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��Ԫ�أ�����pre_e��������ǰ����ǰһ��Ԫ�أ�
//��ʧ�ܣ���pre_e�޶��� 							// *pre_e����һ��λ�����������cur_eԪ��֮ǰ�ĵ�һ��Ԫ��
Status PriorElem(struct SqList L, ElemType cur_e, ElemType* pre_e)	{
	int i = 2;
	ElemType* p = L.elem + 1;
	while (i <= L.length && *p != cur_e)	{
		p++;
		i++;
	}
	if (i > L.length)	{
		return ERROR;
	}
	else	{
		*pre_e = * --p;
		return OK;
	}
}

//��cur_e��L������Ԫ�أ��Ҳ������һ��Ԫ�أ�����next_e�������ĺ�̣�ǰһ��Ԫ�أ�
//��ʧ�ܣ���next_e�޶��� 							// *next_e����һ��λ�����������cur_eԪ��֮��ĵ�һ��Ԫ��  
Status NextElem(struct SqList L, ElemType cur_e, ElemType* next_e)	{
	int i = 1;
	ElemType* p = L.elem;
	while (i < L.length && *p != cur_e)	{
		p++;
		i++;
	}
	if (i == L.length)	{
		return ERROR;
	}
	else	{
		*next_e = * ++p;
		return OK;
	}
}

//��L�е�i��λ��֮ǰ�����µ�����Ԫ��e,��L�ĳ���+1
Status ListInsert(struct SqList* L, int i, ElemType e) 	{
	ElemType *newbase, *q, *p; 
	if (i < 0 || i > L->length + 1)	{	//i��ֵ���Ϸ� 
	 	return ERROR;
	}
	if (L->length == L->listsize)	{	//��ǰ�洢�ռ����������ӷ��䣬�޸� 
		newbase = (ElemType*)realloc(L->elem, (L->listsize + LIST_INCREMENT) * sizeof(ElemType));
		if (!newbase)	{
			exit(OVERFLOW);	//�洢�ռ����ʧ�� 
		}
		L->elem = newbase;	//�����(ElemType*)Ϊ��ַ
		L->listsize += LIST_INCREMENT; 
	}
	q = L->elem + i - 1;	//qΪ�����λ�õĵ�ַ 
	for (p = L->elem + L->length - 1; p >= q; --p)	
		*(p+1) = *p;	//����Ԫ�������Ա�ĺ���(��)�ƶ�һλ
		
	*q = e;			//��e����
	L->length++;
	return OK; 
}

//ɾ�����Ա�L�е�i��Ԫ�أ�����e������ֵ��L�ĳ���-1 
Status ListDelete(struct SqList* L, int i, ElemType *e) {
	ElemType *p, *q;
	if (i < L->length || i > L->length)	{
		return ERROR;
	}
	p = L->elem + i - 1;	//pΪ��ɾ��Ԫ�ص�λ�� 
	*e = *p;
	q = L->elem + L->length - 1;
	for (p++; p < q; p++)	{	// 
		*(p-1) = *p;	//��ɾ��Ԫ��֮���Ԫ�ؾ���ǰ(��)�ƶ�һλ 
		L->length--;
		return OK; 
	} 
}

//���ζ����Ա��е�ÿ��Ԫ�ص���visit()����
//visit()���βμ�&��������ͨ������visit()�ı�Ԫ�ص�ֵ	C++������
void ListTraverse(struct SqList L, void (*visit)(ElemType*))	{
	ElemType* p = L.elem;
	int i = 1;
	for (i = 1; i <= L.length; i++)	{
		visit(p++);
	}
	printf("\n");
}
