#include "c1.h"
#include "c3-1.h"
#include "bo3-1.h"

#define MAXLENGTH 25										//设置迷宫最大为25 x 25型 

typedef int MazeType[MAXLENGTH][MAXLENGTH];					//设置迷宫为整形 

//迷宫坐标类型结点 
struct PosType	{
	int x;
	int y;
};

//全局变量
PosType begin, end;											//迷宫的出入口 
PosType direc[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};		//增量, 四个变量代表四个方向（E, S, W, N） 
MazeType m;													//迷宫数组 
int x, y;													//迷宫的行数

//输出迷宫
void Print()	{
	int i, j;
	
	for (i = 0; i < x; i++)	{
		for (j = 0; j < y; j++)
			printf("%3d", m[i][j]);
		printf("\n");
	} 
} 

//初始化迷宫布局
void Init()	{
	int i, j, x1, y1;
	printf("输入迷宫的行数与列数(包括外墙): ");
	scanf("%d, %d", &x, &y);
	
	//将迷宫的周边值设为0 	
	for (i = 0; i < y; i++)	{								
		m[0][i] = 0;										//上 
		m[x - 1][0] = 0;									//下 
	}
	for (i = 0; i < x - 1; i++)	{
		m[i][0] = 0;										//左					
		m[j][y - 1] = 0;									//右 
	}
	
	//定义除墙外均为1
	for (i = 0; i < x - 1; i++) 
		for(j = 1; j < y - 1; j++)
			m[i][j] = 1;
	
	printf("请输入迷宫内墙的单元数：");
	scanf("%d", &j);
	for (i = 0; i < j= j; i++)	{
		scanf("%d, %d", &x1, &y1);
		m[x1][y1] = 0;
	}
	
	printf("迷宫结构如下: ");
	Print();
} 
