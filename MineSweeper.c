#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>	
#include<conio.h>


//////////////////////////////////////////////////////////////////////全局变量的定义//////////////////////////////////////////////////////////////////////

//这里行列(不含边框)
#define ROW 16 //行  Y i
#define COL 20 //列  X j
#define MINE_NUM 32//雷数


typedef enum Block//枚举类型(地图信息)
{
	AIR, //空气
	MINE,//地雷
	ZERO,
	ONE,
	TWO,
	THREE,
	FOUR, 
	FIVE,
	SIX,
	SEVEN, 
	EIGHT,
	FLAG,//旗子 //这样设计枚举常量，AIR + FLAG = FLAG
	FLAG_AND_MINE//棋子和地雷 MINE + FLAG = FLAG_AND_MINE

}BLOCK;//中文：一块（地）


//这个字符串数组的符号和上面的枚举一一对应
char* map_graph[] = { "□ ","□ ","   ","① ","② ","③ ","④ ","⑤ ","⑥ ","⑦ ","⑧ ","☆ ","★ " };


//元素为枚举类型的地图
BLOCK map[ROW + 2][COL + 2] = { 0 };//有效区域 [1][1] 到 [ROW][COL]


typedef enum Acrion//枚举类型(按键信息)
{
	MOVE,   //移动
	LEFT,   //左键 -- 开雷
	MIDDLE, //中间 -- 若周围棋子标满，自动点开周围8格
	RIGHT   //右键 -- 标棋

}ACTION;//玩家按键行为



//////////////////////////////////////////////////////////////////////函数声明//////////////////////////////////////////////////////////////////////

void pri_map();

void pri_player(HANDLE handle, short X, short Y);

void init_map();

ACTION get_action(short* pX, short* pY);

void update_place(HANDLE handle, short X, short Y);

int left_event(HANDLE handle, short X, short Y);

int middle_event(HANDLE handle,short X, short Y);

void right_event(short X, short Y);

int mine_num(short X, short Y);

int have_air();

void pri_mine(HANDLE handle);


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////主函数//////////////////////////////////////////////////////////////////////



int main()
{
	//设置随机数种子
	srand((unsigned)time(NULL));


	//隐藏光标信息【Windows.h】
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//获取标准句柄
	CONSOLE_CURSOR_INFO cci = { 1,0 };//控制台_游标_信息
	//（这是一个结构体，成员为 dwSize[指定光标大小(光标填充单元格的百分比,1-100)] 和 bVisible[光标可见性(0/1)]）
	SetConsoleCursorInfo(handle, &cci);//设置控制台游标信息


	//////开始游戏

	//设置玩家坐标--和数组坐标操持一致
	COORD old_player = { 1,1 }; //COORD是成员为 X Y 的结构体（玩家操作前坐标）
	COORD player = { 1,1 }; //COORD是成员为 X Y 的结构体（玩家操作后坐标）


	//初始化地图（埋雷）
	init_map();

	//打印地图\玩家
	pri_map();
	pri_player(handle, player.X, player.Y);

	int num = 0;

	while (1)
	{
		old_player = player;


		//获取按键并对MOVE行为进行反馈，返回枚举类型ACTION
		ACTION a = get_action(&(player.X), &(player.Y));

		switch (a)
		{

		case MOVE://上下左右移动
			update_place(handle, old_player.X, old_player.Y);//这是把玩家走后腾开的那一块地块重新打印回来
			pri_player(handle, player.X, player.Y);
			break;

		case LEFT://点雷
			num = left_event(handle, player.X, player.Y);
			pri_player(handle, player.X, player.Y);
			break;

		case MIDDLE://点开周围一圈
			num = middle_event(handle,player.X, player.Y);
			break;

		case RIGHT://标旗
			right_event(player.X, player.Y);
			pri_player(handle, player.X, player.Y);
			break;
		}

		//胜负判定
		if (num == -1) {
			break;
		}
		else if (have_air() == 0)
		{
			num = 1;
			break;
		}
	}
	//一次游戏循环结束
	if (num == 1) {
		Sleep(1000);
		system("cls");
		printf("游戏胜利\n");
	}
	else {
		pri_mine(handle);
		Sleep(3000);
		system("cls");
		printf("游戏失败\n");
	}


	return 0;
}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////下面是函数的实现//////////////////////////////////////////////////////////////////////


void pri_map()//打印地图
{
	int i, j;
	for (i = 1; i <= ROW; i++)
	{
		for (j = 1; j <= COL; j++)
		{
			printf("□ ");
		}
		puts("");
	}
}



void pri_player(HANDLE handle, short X, short Y)//打印玩家
{
	//"□ "宽为2（含空格） ----------- 打印位置 X Y 比实际位置少1,因为边框不打印
	COORD tmp = { 2 * (X - 1), Y - 1 };
	SetConsoleCursorPosition(handle, tmp);//设置光标位置
	printf("♀");
}



void pri_mine(HANDLE handle)//游戏失败后打印所有地雷
{
	int i = 1, j = 1;
	for (i = 1; i <= ROW; i++)
	{
		for (j = 1; j <= COL; j++)
		{
			if (map[i][j] == MINE)
			{
				COORD tmp = { 2 * (j - 1), i - 1 };
				SetConsoleCursorPosition(handle, tmp);
				printf("%s", map_graph[FLAG_AND_MINE]);
			}
		}
	}
}



void init_map()//初始化地图+埋雷
{
	int i, x, y;
	for (i = 0; i < MINE_NUM; i++)
	{
		y = rand() % ROW + 1; // [1,ROW]
		x = rand() % COL + 1; // [1,COL]
		if (map[y][x] == AIR)
		{
			map[y][x] = MINE;
		}
		else
		{
			i--;
		}
	}
}



void update_place(HANDLE handle, short X, short Y)//地块更新,把枚举类型打印成对应下标的数组元素图标
{
	COORD tmp = { 2 * (X - 1), Y - 1 };
	SetConsoleCursorPosition(handle, tmp);
	printf("%s", map_graph[map[Y][X]]);
	//这里把 map[Y][X] 枚举对应的值放入与之对应的 map_graph[] 数组中
}


int have_air()//地图上有AIR为真（1），无AIR为假（0），用于胜负判定
{
	int i, j;
	for (i = 1; i <= ROW; i++)
	{
		for (j = 1; j <= COL; j++)
		{
			if (map[i][j] == AIR)
			{
				return 1;
			}
		}
	}
	return 0;
}



ACTION get_action(short* pX, short* pY)//包含对player的按键操作，返回枚举类型ACTION
{
	char key1, key2;
		key1 = _getch();
		switch (key1)
		{
		case 'W':
		case 'w':
			if (*pY > 1)
			{
				(*pY)--;
			}
			break;
		case 'S':
		case 's':
			if (*pY < ROW)
			{
				(*pY)++;
			}
			break;
		case 'A':
		case 'a':
			if (*pX > 1)
			{
				(*pX)--;
			}
			break;
		case 'D':
		case 'd':
			if (*pX < COL)
			{
				(*pX)++;
			}
			break;
		case 'Z':
		case 'z':
			return LEFT;
		case 'X':
		case 'x':
			return MIDDLE;
		case 'C':
		case 'c':
			return RIGHT;
			break;
			//按住上下左右键，返回2个值，第一个 -32，表示按了上下左右
			//第二个返回对应上下左右ASCII 72 80  75 77
		case -32:
			key2 = _getch();//得到-32，再读取一次输入的值
			switch (key2)
			{
			case 72://上键
				if (*pY > 1)
				{
					(*pY)--;
				}
				break;
			case 80://下键
				if (*pY < ROW)
				{
					(*pY)++;
				}
				break;
			case 75://左键
				if (*pX > 1)
				{
					(*pX)--;
				}
				break;
			case 77://右键
				if (*pX < COL)
				{
					(*pX)++;
				}
				break;
			}
		}
		return MOVE;
}



int mine_num(short X, short Y)//统计并返回数周围8格的雷数
{
	int count = 0;
	if (map[Y - 1][X - 1] == MINE || map[Y - 1][X - 1] == FLAG_AND_MINE)count++;
	if (map[Y - 1][X] == MINE || map[Y - 1][X] == FLAG_AND_MINE)count++;
	if (map[Y - 1][X + 1] == MINE || map[Y - 1][X + 1] == FLAG_AND_MINE)count++;
	if (map[Y][X - 1] == MINE || map[Y][X - 1] == FLAG_AND_MINE)count++;
	if (map[Y][X + 1] == MINE || map[Y][X + 1] == FLAG_AND_MINE)count++;
	if (map[Y + 1][X - 1] == MINE || map[Y + 1][X - 1] == FLAG_AND_MINE)count++;
	if (map[Y + 1][X] == MINE || map[Y + 1][X] == FLAG_AND_MINE)count++;
	if (map[Y + 1][X + 1] == MINE || map[Y + 1][X + 1] == FLAG_AND_MINE)count++;
	return count;
}



////(Z/z)左键按下后的事件
int left_event(HANDLE handle, short X, short Y)//点开格子，若周围无雷，点开一片
{
	int num = mine_num(X, Y);
	switch (map[Y][X])
	{
	case AIR://是AIR情况才可以左键操作
		map[Y][X] = ZERO + num;
		update_place(handle, X, Y);
		if (map[Y][X] == ZERO)
		{                    //递归条件：递归对象坐标是AIR，且在范围内
			if (map[Y - 1][X - 1] == AIR && X - 1 >= 1 && X - 1 <= COL && Y - 1 >= 1 && Y - 1 <= ROW)
				left_event(handle, X - 1, Y - 1);
			if (map[Y][X - 1] == AIR && X - 1 >= 1 && X - 1 <= COL && Y >= 1 && Y <= ROW)
				left_event(handle, X - 1, Y);
			if (map[Y + 1][X - 1] == AIR && X - 1 >= 1 && X - 1 <= COL && Y + 1 >= 1 && Y + 1 <= ROW)
				left_event(handle, X - 1, Y + 1);
			if (map[Y - 1][X] == AIR && X >= 1 && X <= COL && Y - 1 >= 1 && Y - 1 <= ROW)
				left_event(handle, X, Y - 1);
			if (map[Y + 1][X] == AIR && X >= 1 && X <= COL && Y + 1 >= 1 && Y + 1 <= ROW)
				left_event(handle, X, Y + 1);
			if (map[Y - 1][X + 1] == AIR && X + 1 >= 1 && X + 1 <= COL && Y - 1 >= 1 && Y - 1 <= ROW)
				left_event(handle, X + 1, Y - 1);
			if (map[Y][X + 1] == AIR && X + 1 >= 1 && X + 1 <= COL && Y >= 1 && Y <= ROW)
				left_event(handle, X + 1, Y);
			if (map[Y + 1][X + 1] == AIR && X + 1 >= 1 && X + 1 <= COL && Y + 1 >= 1 && Y + 1 <= ROW)
				left_event(handle, X + 1, Y + 1);
		}
		break;
	case MINE://是雷返回-1
		return -1;
	}
	return 0;
}



int flag_num(short X, short Y)//统计并返回数周围8格的旗数
{
	int count = 0;
	if (map[Y - 1][X - 1] == FLAG || map[Y - 1][X - 1] == FLAG_AND_MINE)count++;
	if (map[Y - 1][X] == FLAG || map[Y - 1][X] == FLAG_AND_MINE)count++;
	if (map[Y - 1][X + 1] == FLAG || map[Y - 1][X + 1] == FLAG_AND_MINE)count++;
	if (map[Y][X - 1] == FLAG || map[Y][X - 1] == FLAG_AND_MINE)count++;
	if (map[Y][X + 1] == FLAG || map[Y][X + 1] == FLAG_AND_MINE)count++;
	if (map[Y + 1][X - 1] == FLAG || map[Y + 1][X - 1] == FLAG_AND_MINE)count++;
	if (map[Y + 1][X] == FLAG || map[Y + 1][X] == FLAG_AND_MINE)count++;
	if (map[Y + 1][X + 1] == FLAG || map[Y + 1][X + 1] == FLAG_AND_MINE)count++;
	return count;
}



//(X/x)中键按下后的事件
int middle_event(HANDLE handle, short X, short Y)//（若本坐标是数字，且周围8格旗数==数字，点开周围8格）
{
	if (map[Y][X] >= ONE && map[Y][X] <= EIGHT && (flag_num(X, Y) == map[Y][X] - ZERO))//假如是数字且数字等于旗数
	{
		if (map[Y - 1][X - 1] <= MINE && X - 1 >= 1 && X - 1 <= COL && Y - 1 >= 1 && Y - 1 <= ROW)//点开周围一圈
			left_event(handle, X - 1, Y - 1);
		if (map[Y][X - 1] <= MINE && X - 1 >= 1 && X - 1 <= COL && Y >= 1 && Y <= ROW)
			left_event(handle, X - 1, Y);
		if (map[Y + 1][X - 1] <= MINE && X - 1 >= 1 && X - 1 <= COL && Y + 1 >= 1 && Y + 1 <= ROW)
			left_event(handle, X - 1, Y + 1);
		if (map[Y - 1][X] <= MINE && X >= 1 && X <= COL && Y - 1 >= 1 && Y - 1 <= ROW)
			left_event(handle, X, Y - 1);
		if (map[Y + 1][X] <= MINE && X >= 1 && X <= COL && Y + 1 >= 1 && Y + 1 <= ROW)
			left_event(handle, X, Y + 1);
		if (map[Y - 1][X + 1] <= MINE && X + 1 >= 1 && X + 1 <= COL && Y - 1 >= 1 && Y - 1 <= ROW)
			left_event(handle, X + 1, Y - 1);
		if (map[Y][X + 1] <= MINE && X + 1 >= 1 && X + 1 <= COL && Y >= 1 && Y <= ROW)
			left_event(handle, X + 1, Y);
		if (map[Y + 1][X + 1] <= MINE && X + 1 >= 1 && X + 1 <= COL && Y + 1 >= 1 && Y + 1 <= ROW)
			left_event(handle, X + 1, Y + 1);


		if (map[Y - 1][X - 1] == MINE || map[Y - 1][X] == MINE || map[Y - 1][X + 1] == MINE || //假如周围一圈有雷
			map[Y][X - 1] == MINE || map[Y][X + 1] == MINE ||
			map[Y + 1][X - 1] == MINE || map[Y + 1][X] == MINE || map[Y + 1][X + 1] == MINE)
		{
			return -1;
		}
	}
	return 0;
}



//(C/c)右键按下后的事件
void right_event(short X, short Y)//（插/拔旗）
{
	if (map[Y][X] >= FLAG)//这里要看枚举常量的值
	{
		map[Y][X] -= FLAG;
	}
	else if (map[Y][X] <= MINE)
	{
		map[Y][X] += FLAG;
	}
}



