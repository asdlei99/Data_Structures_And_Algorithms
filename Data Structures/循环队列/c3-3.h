#define MAX_QSIZE 5		//最大队列长度为5 

struct SqQueue	{
	QElemType *base;
	int front;			//头指针，队列不空指向队列头元素
	int rear;			//尾指针,不空指向下一元素 
};
