//构造一个空的顺序线性表L 
void InitList(struct SqList* L)	{
	L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L->elem)	{
		exit(OVERFLOW);
	}
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
}

//销毁顺序线性表L
void DestroyList(struct SqList* L)	{
	free(L->elem);
	L->elem = NULL;
	L->length = 0;
	L->listsize = 0;
}

//重置顺序线性表L
void ClearList(struct SqList* L)	{
	L->length = 0; 
}

//判断线性表L是否为空
Status ListEmpty(struct SqList* L)	{
	if (L->length == 0)	{
		return TRUE;
	}
	else	{
		return FALSE;
	}
}

//返回线性表L中元素的个数
int ListLength(struct SqList* L)	{
	return L->length;
}

//用e返回L中第i个数据元素的值
Status GetElem(struct SqList L, int i, ElemType *e)	{
	if (i < 0 || i > L.length)	{
		return ERROR;
	}
	else	{
		*e = *(L.elem + i - 1);
		return OK;
	}
}

//返回第一个与e满足关系compare()的数据元素的位序
int LocateElem(struct SqList L, ElemType e, Status(*compare)(ElemType, ElemType))	{
	int i = 1;	//i为第一个元素的位置，因为排在第0的是该表的地址
	ElemType* p = L.elem;	//p为第一个元素的位序 
	while (i <= L.length && !compare(*p++, e))
	i++;
	if (i <= L.length)
		return i;
	else
		return ERROR;
}

//若cur_e是L的数据元素，且不是第一个元素，则用pre_e返回它的前驱（前一个元素）
//若失败，则pre_e无定义 							// *pre_e定义一个位置来接受这个cur_e元素之前的第一个元素
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

//若cur_e是L的数据元素，且不是最后一个元素，则用next_e返回它的后继（前一个元素）
//若失败，则next_e无定义 							// *next_e定义一个位置来接受这个cur_e元素之后的第一个元素  
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

//在L中第i个位置之前插入新的数据元素e,且L的长度+1
Status ListInsert(struct SqList* L, int i, ElemType e) 	{
	ElemType *newbase, *q, *p; 
	if (i < 0 || i > L->length + 1)	{	//i的值不合法 
	 	return ERROR;
	}
	if (L->length == L->listsize)	{	//当前存储空间已满，增加分配，修改 
		newbase = (ElemType*)realloc(L->elem, (L->listsize + LIST_INCREMENT) * sizeof(ElemType));
		if (!newbase)	{
			exit(OVERFLOW);	//存储空间分配失败 
		}
		L->elem = newbase;	//上面的(ElemType*)为地址
		L->listsize += LIST_INCREMENT; 
	}
	q = L->elem + i - 1;	//q为插入的位置的地址 
	for (p = L->elem + L->length - 1; p >= q; --p)	
		*(p+1) = *p;	//后面元素往线性表的后面(右)移动一位
		
	*q = e;			//将e插入
	L->length++;
	return OK; 
}

//删除线性表L中第i个元素，并用e返回其值，L的长度-1 
Status ListDelete(struct SqList* L, int i, ElemType *e) {
	ElemType *p, *q;
	if (i < L->length || i > L->length)	{
		return ERROR;
	}
	p = L->elem + i - 1;	//p为被删除元素的位置 
	*e = *p;
	q = L->elem + L->length - 1;
	for (p++; p < q; p++)	{	// 
		*(p-1) = *p;	//被删除元素之后的元素均往前(左)移动一位 
		L->length--;
		return OK; 
	} 
}

//依次对线性表中的每个元素调用visit()函数
//visit()的形参加&表明可以通过调用visit()改变元素的值	C++的引用
void ListTraverse(struct SqList L, void (*visit)(ElemType*))	{
	ElemType* p = L.elem;
	int i = 1;
	for (i = 1; i <= L.length; i++)	{
		visit(p++);
	}
	printf("\n");
}
