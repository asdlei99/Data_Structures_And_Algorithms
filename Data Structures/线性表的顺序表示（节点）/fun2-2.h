//�ж���Ԫ���Ƿ���� 
Status equal(ElemType c1, ElemType c2)	{
	if(c1 == c2)	{
		return OK;
	} 
	else
		return FALSE;
} 

//�ж���Ԫ�صĴ�С	> 1,  = 0, < -1 
int compare(ElemType a, ElemType b)	{
	if (a == b)	{
		return 0;
	}
	else 
		return (a - b)/abs(a - b);
}

//����Ԫ�ص�ֵ����10����, eΪ���� 
void print(ElemType *e)	{
	printf("%d ", *e);
}

//����Ԫ�ص�ֵ�����ַ���ʽ 
void print2(ElemType e)	{
	printf("%c ", e);
}

//����Ԫ���ж�������ƽ����ϵ����LocateElem()���õĺ���
Status sq(ElemType c1, ElemType c2)	{
	if (c1 == c2 * c2)	{
		return TRUE;
	}
	else
		return FALSE;
}

//ListTraverse()���õ���һ��������Ԫ��֮�ӱ���
void dbl(ElemType *c)	{
	*c *= 2;
}
