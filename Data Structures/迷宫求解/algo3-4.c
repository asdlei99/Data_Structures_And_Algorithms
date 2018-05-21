#include "c1.h"
#include "c3-1.h"
#include "bo3-1.h"

#define MAXLENGTH 25										//�����Թ����Ϊ25 x 25�� 

typedef int MazeType[MAXLENGTH][MAXLENGTH];					//�����Թ�Ϊ���� 

//�Թ��������ͽ�� 
struct PosType	{
	int x;
	int y;
};

//ȫ�ֱ���
PosType begin, end;											//�Թ��ĳ���� 
PosType direc[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};		//����, �ĸ����������ĸ�����E, S, W, N�� 
MazeType m;													//�Թ����� 
int x, y;													//�Թ�������

//����Թ�
void Print()	{
	int i, j;
	
	for (i = 0; i < x; i++)	{
		for (j = 0; j < y; j++)
			printf("%3d", m[i][j]);
		printf("\n");
	} 
} 

//��ʼ���Թ�����
void Init()	{
	int i, j, x1, y1;
	printf("�����Թ�������������(������ǽ): ");
	scanf("%d, %d", &x, &y);
	
	//���Թ����ܱ�ֵ��Ϊ0 	
	for (i = 0; i < y; i++)	{								
		m[0][i] = 0;										//�� 
		m[x - 1][0] = 0;									//�� 
	}
	for (i = 0; i < x - 1; i++)	{
		m[i][0] = 0;										//��					
		m[j][y - 1] = 0;									//�� 
	}
	
	//�����ǽ���Ϊ1
	for (i = 0; i < x - 1; i++) 
		for(j = 1; j < y - 1; j++)
			m[i][j] = 1;
	
	printf("�������Թ���ǽ�ĵ�Ԫ����");
	scanf("%d", &j);
	for (i = 0; i < j= j; i++)	{
		scanf("%d, %d", &x1, &y1);
		m[x1][y1] = 0;
	}
	
	printf("�Թ��ṹ����: ");
	Print();
} 
