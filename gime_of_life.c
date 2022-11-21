#define _CRT_SECURE_NO_WARNINGS 1
//////////《生命游戏》
//////////每个矩阵方格可以包含一个有机体，不在边上的有机体有8个相邻方格。
//////////生命游戏演化的规则如下：
//////////1.如果一个细胞周围有3个细胞为生，则该细胞为生（即该细胞若原先为死，则转为生，若原先为生，则保持不变）。
//////////2.如果一个细胞周围有两个细胞为生，则该细胞的生死状态保持不变。
//////////3.在其他情况下该细胞为死（即该细胞若原先为生，则转为死；若原先为死，则保持不变）。



#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>

#define WIDTH 57   //WIDTH   x  j
#define HEIGHT 25  //HEIGHT  y  i
//map[HEIGHT][WIDTH]   map[i][j]   map[y][x]



//声明地图
char map[HEIGHT][WIDTH] = { 0 };  //0表示死，1表示生


//随机初始化的函数
void init_map()//保证最外一圈值均为0
{
	srand((unsigned)time(NULL));
	int i, j;
	for (i = 1; i < HEIGHT - 1; i++)
	{
		for (j = 1; j < WIDTH - 1; j++)
		{
			map[i][j] = rand() % 2;
		}
	}
}

//打印map函数
void print_map()//不打印最外围
{
	int i, j;
	for (i = 0; i < HEIGHT; i++)
	{
		for (j = 0; j < WIDTH; j++)
		{
			if (map[i][j]) {
				printf("■ ");
			}
			else {
				printf("  ");
			}
		}
		puts("");//puts()自带换行功能
	}
}

//计算坐标周围8格细胞数的函数
int cell_num(i, j)
{
	return (map[i - 1][j - 1] +
		map[i - 1][j] +
		map[i - 1][j + 1] +
		map[i][j - 1] +
		map[i][j + 1] +
		map[i + 1][j - 1] +
		map[i + 1][j] +
		map[i + 1][j + 1]
		);
}


//1.如果一个细胞周围有3个细胞为生，这个细胞生
//2.如果一个细胞周围有2个细胞为生，则该细胞不变
//3.在其他情况下该细胞为死
void update_map()
{
	char map2[HEIGHT][WIDTH] = { 0 };
	int i, j;
	for (i = 1; i < HEIGHT - 1; i++)
	{
		for (j = 1; j < WIDTH - 1; j++)
		{
			int cell = cell_num(i, j);
			if (cell == 3) {
				map2[i][j] = 1;
			}
			else if (cell == 2) {
				map2[i][j] = map[i][j];
			}
			else {
				map2[i][j] = 0;
			}
		}
	}
	memcpy(map, map2, HEIGHT * WIDTH * sizeof(char));
	//memcpy：在缓冲区之间复制字符。
	//声明：void *memcpy( void *dest, const void *src, size_t count );
	//memcpy函数将src的count字节拷贝到dest中，如果源地址和目的地址重叠，则不保证复制重叠区域内源地址的原始字节后再被覆盖。使用memmove来处理重叠区域。
}


int player(int* num, int* sleepTime, int* speed)
{
	while (_kbhit())
	{
		switch (_getch())//0<=speed<=4
		{
		case '1':
			if ((*speed) > 0)
			{
				(*sleepTime) += 50;
				(*speed)--;
			}
			break;
		case '2':
			if ((*speed) < 4)
			{
				(*sleepTime) -= 50;
				(*speed)++;
			}
			break;
		case '3':
			system("pause");
			break;
		case '4':
			return 1;
		}
	}

	////打印玩家提示
	switch (*speed)
	{
	case 0:
		printf("\n倍速：×0.25\n");
		break;
	case 1:
		printf("\n倍速：×0.50\n");
		break;
	case 2:
		printf("\n倍速：×1.00\n");
		break;
	case 3:
		printf("\n倍速：×1.50\n");
		break;
	case 4:
		printf("\n倍速：×2.00\n");
		break;
	}
	printf("第%d代                            \n", *num);
	printf("按键:1减速;2加速;3暂停;4退出\n");
	return 0;
}


int main()
{
	////获取句柄等操作
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//获取标准输出的句柄
	COORD zero = { 0,0 };//设置初始坐标


	////隐藏光标
	CONSOLE_CURSOR_INFO cci;//获取光标位置
	cci.dwSize = sizeof(cci);//告诉光标的大小
	cci.bVisible = FALSE;//告诉光标是看不见的
	SetConsoleCursorInfo(handle, &cci);


	//初始化地图(在地图上随机生成%50的生命)
	init_map();

	int num = 0;
	int sleepTime = 100;
	int speed = 2;
	while (1)
	{
		////光标移动到最开始的地方（？）
		SetConsoleCursorPosition(handle, zero);//设置 命令行窗口 光标 位置

		////打印地图
		print_map(map);
		////计算地图
		update_map(map);
		num++;

		////玩家进行操纵
		int t = player(&num, &sleepTime, &speed);
		if (t) {
			break;
		}
		Sleep(sleepTime);
	}
}