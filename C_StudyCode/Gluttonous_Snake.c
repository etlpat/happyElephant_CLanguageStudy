#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>


#define ROW 25
#define COL 55
#define ROW1 (15 + 2)
#define COL1 (25 + 2)


typedef enum Enum //地图元素
{
	AIR,
	BODY,
	HEAD,
	APPLE,
	WALL

}Enum;


//该数组中符号对应上面的枚举成员
char* map_graphy[] = { "  ","□ ","■ ","@ ","# " };


typedef enum Direction //蛇头前进的方向（上下为偶数，左右为奇数）
{
	W,
	A,
	S,
	D

}Direction;



///////////////////////////////////////////////////////////////////////////函数////////////////////////////////////////////////////////////////////////////////




void init_map(Enum map[ROW1][COL1])//初始化地图
{
	int i, j;
	for (i = 0; i < ROW1; i++)
	{
		for (j = 0; j < COL1; j++)
		{
			if (i == 0 || i == ROW1 - 1 || j == 0 || j == COL1 - 1) {
				map[i][j] = WALL;
			}
			else {
				map[i][j] = AIR;
			}
		}
	}
}





void init_snake(Enum map[ROW1][COL1], COORD* snake)//把蛇生成在中间横向三格
{
	snake[0].X = COL1 / 2 + 1;
	snake[0].Y = ROW1 / 2;
	snake[1].X = COL1 / 2;
	snake[1].Y = ROW1 / 2;
	snake[2].X = COL1 / 2 - 1;
	snake[2].Y = ROW1 / 2;
	map[snake[0].Y][snake[0].X] = HEAD;
	map[snake[1].Y][snake[1].X] = BODY;
	map[snake[2].Y][snake[2].X] = BODY;
}





void init_apple(Enum map[ROW1][COL1])//设置一个随机苹果（不在边缘）
{
	int i, j;
	while (1)
	{
		i = rand() % (ROW1 - 4) + 2;
		j = rand() % (COL1 - 4) + 2;
		if (map[i][j] == AIR) {
			map[i][j] = APPLE;
			break;
		}
	}
}




void pri_map(Enum map[ROW1][COL1], int snakeNum)//打印地图
{
	int i, j;
	for (i = 0; i < ROW1; i++)
	{
		for (j = 0; j < COL1; j++)
		{
			printf("%s", map_graphy[(int)map[i][j]]);
		}
		puts("");
	}
	printf("得分 ：%d", snakeNum - 3);
}




COORD keyAction(COORD snakeHead, Direction* pd)//参数为蛇头坐标和方向的指针
{
	Direction olddir = *pd;
	Direction newdir = *pd;
	COORD newHead = snakeHead;
	if(_kbhit())//  _kbhit若键盘输入，返回真，否则返回0
	{
		char key1, key2;
		key1 = _getch();
		switch (key1)//  _getch从键盘获得字符，无回显，且输入后自动进行下一步，不用回车
		{
		case 'W':
		case 'w':
			newHead.Y--;
			newdir = W;
			break;
		case 'S':
		case 's':
			newHead.Y++;
			newdir = S;
			break;
		case 'A':
		case 'a':
			newHead.X--;
			newdir = A;
			break;
		case 'D':
		case 'd':
			newHead.X++;
			newdir = D;
			break;
			//键入上下左右键，返回两个值，第一个 -32，表示按了上下左右
			//第二个返回对应上下左右ASCII 72 80  75 77
		case -32:
			key2 = _getch();//得到-32，再读取一次输入的值
			switch (key2)
			{
			case 72://上键
				newHead.Y--;
				newdir = W;
				break;
			case 80://下键
				newHead.Y++;
				newdir = S;
				break;
			case 75://左键
				newHead.X--;
				newdir = A;
				break;
			case 77://右键
				newHead.X++;
				newdir = D;
				break;
			default:
				break;
			}
		default:
			break;
		}
		//我们设置的方向枚举常量 上下为偶数，左右为奇。
		if ((((int)olddir + (int)newdir)) % 2 == 1|| (int)olddir == (int)newdir)
		//相加为奇，新方向在旧方向两侧；方向相等，新旧方向一致。这两种情况直接返回新方向
		{
			*pd = newdir;
			return newHead;
		}
		else
		{
			if (newdir == W) {
				newHead.Y += 2;
			}
			else if (newdir == S) {
				newHead.Y -= 2;
			}
			else if (newdir == A) {
				newHead.X += 2;
			}
			else if (newdir == D) {
				newHead.X -= 2;
			}
			return newHead;
		}
	}
	else//未按键的情况
	{
		if (olddir == W) {
			newHead.Y --;
		}
		else if (olddir == S) {
			newHead.Y ++;
		}
		else if (olddir == A) {
			newHead.X --;
		}
		else if (olddir == D) {
			newHead.X ++;
		}
		return newHead;
	}
}




//蛇的变动
//假如没吃苹果，去掉蛇尾，蛇头向前；假如吃苹果，蛇尾不动，蛇头向前
void change(Enum map[ROW1][COL1], COORD* snake, COORD newHead, int snakeNum, int isApple)
{
	if (isApple == 0)//假如没吃苹果，去掉蛇尾，蛇头向前
	{
		map[snake[snakeNum - 1].Y][snake[snakeNum - 1].X] = AIR;
	}

	map[snake[0].Y][snake[0].X] = BODY;
	//更改蛇的坐标
	int i;
	for (i = snakeNum - 1; i > 0; i--)
	{
		snake[i] = snake[i - 1];
	}
	snake[0] = newHead;
	map[snake[0].Y][snake[0].X] = HEAD;
}



///////////////////////////////////////////////////////////////////////////主函数////////////////////////////////////////////////////////////////////////////////

int main()
{
	//设置随机数种子
	srand((unsigned)time(NULL));


	//初始化光标 - <Windows.h>
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//设置标准句柄
	CONSOLE_CURSOR_INFO cci = { 1,0 };//控制台游标信息{光标大小,可见性}，初始化光标为不可见
	SetConsoleCursorInfo(handle, &cci);//设置光标信息
	COORD zero = { 0,0 };//设置光标初始坐标


	//初始化地图
	Enum map[ROW1][COL1] = { 0 };
	init_map(map);
	

	//初始化蛇
	int snakeNum = 3;
	Direction dir = D;//初始方向朝右
	COORD snake[ROW * COL];//坐标数组表示蛇的每节身体（结构体坐标COORD声明在Windows.h中）；snake[0]为蛇头
	init_snake(map,snake);


	//初始化苹果
	init_apple(map);
	

	//初始化蛇移动间隔的时间
	float sleepTime = 100;


	//绘制游戏界面
	pri_map(map, snakeNum);


	//进入游戏
	while (1)
	{
		//通过设置光标位置---把光标移动到最开始的地方
		SetConsoleCursorPosition(handle, zero);//设置_控制台_游标_位置


		//按键检测，返回新蛇头，更改行走方向
		COORD newHead = keyAction(snake[0], &dir);


		int isApple = 0;
		//胜负判定（趁着新蛇头没被更改到snake数组中，判断新蛇头的位置是否为墙或身体）
		if (map[newHead.Y][newHead.X] == BODY || map[newHead.Y][newHead.X] == WALL)
		{
			Sleep(2000);
			system("cls");
			printf("游戏结束");
			break;
		}
		else if (map[newHead.Y][newHead.X] == APPLE)
		{
			isApple = 1;
			snakeNum++;
			sleepTime *= 0.9;
		}


		//更改蛇（删除尾巴，蛇头向按键方向移动一格）
		change(map, snake, newHead, snakeNum, isApple);
	

		//若之前吃了苹果，刷新苹果位置
		if (isApple) {
			init_apple(map);
		}


		//重打印地图
		Sleep(sleepTime);
		pri_map(map, snakeNum);


	}


	return 0;
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////














////函数拓展：


////////  _kbhit()
////检查控制台是否有键盘输入
////kbhit - keyboard hit ，对应头文件 <conio.h>
// 
////如果按下了某个键，_kbhit返回一个非零值。否则，返回0






////////  _getch()
////从控制台获取一个字符，不回显
////对应头文件 <conio.h>
//
////返回读取的字符，键入时不回显，不需要按回车就可以进入下一步

