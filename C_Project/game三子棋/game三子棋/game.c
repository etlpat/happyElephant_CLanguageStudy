#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//棋盘样式
// * | * | * 
//---|---|---
// * | * | *  
//---|---|---
// * | * | * 





//1.用于初始化棋盘的函数
void initchess(char chess[HANG][LIE], int hang, int lie)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < hang; i++)
	{
		for (j = 0; j < lie; j++)
		{
			chess[i][j] =  ' ' ;//把数组中每个元素初始化为一个空格
		}
	}
}





//2.打印棋盘和棋子(数组元素)的函数
void prichess(char chess[HANG][LIE], int hang, int lie)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < hang; i++)
	{
		for (j = 0; j < lie; j++)//每一行开始时，打印(数据) ' * '和 '|'
		{
			printf(" %c ", chess[i][j]);
			if (j < lie - 1)
				printf("|");
		}
		printf("\n");
		if (i < hang - 1)
		{
			for (j = 0; j < lie; j++)////每一行结束后，打印(分割行) '\n'  '---' 和 '|'
			{
				printf("---");
				if (j < lie - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}





//3.实现玩家下棋，将棋子'*'替换原本数组中的' '的函数
void playermove(char chess[HANG][LIE], int hang, int lie)
{
	int x, y;
	printf("请玩家输入坐标（x,y）>:\n");
	while (1)
	{
		scanf("%d%d", &x, &y);
		if (x <= hang && x > 0 && y <= lie && y > 0)
		{
			if (chess[x-1][y-1] == ' ')
			{
				chess[x-1][y-1] = '*';
				break;
			}
			else
			{
				printf("此位置已被占用，请再次输入>:\n");
			}
		}
		else
		{
			printf("输入非法坐标，请再次输入>:\n");
		}
	}
}





//4.实现电脑下棋，将棋子'#'替换原本数组中的' '的函数
void computermove(char chess[HANG][LIE], int hang, int lie)
{
	int x, y;
	while (1)
	{
		x = rand() % hang;
		y = rand() % lie;
		if (chess[x][y] == ' ')
		{
			chess[x][y] = '#';
			break;
		}
	}
}






//5.判断 胜/负/平/继续 并输出对应返回值的函数
char judge(char chess[HANG][LIE], int hang, int lie)
{
	int x; int y; int i, j;
	//判断横行三个相等
	for (x = 0; x < hang; x++)
	{
		if (chess[x][0] == chess[x][1] && chess[x][1] == chess[x][2] && chess[x][0] != ' ') { return chess[x][0]; }
	}
	//判断竖行三个相等
	for (y = 0; y < lie; y++)
	{
		if (chess[0][y] == chess[1][y] && chess[1][y] == chess[2][y] && chess[0][y] !=' ') { return chess[0][y]; }
	}
	//判断斜三个是否相等
	if (chess[0][0] == chess[1][1] && chess[1][1] == chess[2][2] && chess[0][0] != ' ') { return chess[0][0]; }
	else if (chess[0][2] == chess[1][1] && chess[1][1] == chess[2][2] && chess[2][0] != ' ') { return chess[0][2]; }
	//判断数组是否全满平局
	else
		for (i = 0; i < hang; i++)
		{
			for (j = 0; j < lie; j++)
			{
				if(chess[i][j]==' ')
				{
					return 'k';
				}
			}
		}
	return 'm';
}