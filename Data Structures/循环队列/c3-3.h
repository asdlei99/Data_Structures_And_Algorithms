#define MAX_QSIZE 5		//�����г���Ϊ5 

struct SqQueue	{
	QElemType *base;
	int front;			//ͷָ�룬���в���ָ�����ͷԪ��
	int rear;			//βָ��,����ָ����һԪ�� 
};
