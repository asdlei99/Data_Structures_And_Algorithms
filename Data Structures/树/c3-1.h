#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 2

typedef struct	{
	SElemType *base;	//栈底,构造其前后均为null
	SElemType *top;		//栈顶
	int stacksize;		//当前分配的存储空间 
}SqStack;
