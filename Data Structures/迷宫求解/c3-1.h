#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 2

typedef struct	{
	SElemType *base;	//ջ��,������ǰ���Ϊnull
	SElemType *top;		//ջ��
	int stacksize;		//��ǰ����Ĵ洢�ռ� 
}SqStack;
