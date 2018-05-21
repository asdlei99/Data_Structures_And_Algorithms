//判断两元素是否相等 
Status equal(ElemType c1, ElemType c2)	{
	if(c1 == c2)	{
		return OK;
	} 
	else
		return FALSE;
} 

//判断两元素的大小	> 1,  = 0, < -1 
int compare(ElemType a, ElemType b)	{
	if (a == b)	{
		return 0;
	}
	else 
		return (a - b)/abs(a - b);
}

//输入元素的值，以10进制, e为引用 
void print(ElemType *e)	{
	printf("%d ", *e);
}

//输入元素的值，以字符形式 
void print2(ElemType e)	{
	printf("%c ", e);
}

//数据元素判定函数（平方关系），LocateElem()调用的函数
Status sq(ElemType c1, ElemType c2)	{
	if (c1 == c2 * c2)	{
		return TRUE;
	}
	else
		return FALSE;
}

//ListTraverse()调用的另一个函数（元素之加倍）
void dbl(ElemType *c)	{
	*c *= 2;
}
