#define _CRT_SECURE_NO_WARNINGS 1
//测试三子棋游戏（主函数模块）

#include"game.h"//引自己创建的头文件要用""
//类似stdio.h这些库函数头文件，都可放到自己的 .h 文件中，然后引一次自定义的 .h 头文件即可




//1.打印菜单界面函数
void menu()
{
	printf("******************************************\n");
	printf("******************************************\n");
	printf("********                         *********\n");
	printf("********      三    子    棋     *********\n");
	printf("********                         *********\n");
	printf("******************************************\n");
	printf("******************************************\n");
	printf("********          1.play         *********\n");
	printf("********          0.exit         *********\n");
	printf("******************************************\n");
	printf("******************************************\n");
}





//2.开始游戏界面函数（菜单界面+选择是否开始）
int start()
{
	int input;
	system("cls");
	do
	{
		menu();
		printf("请输入数字(1开始  0结束)>：\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("游戏开始！\n");
			return 1;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入数字无效\n");
			Sleep(2000);//休眠（）毫秒，对应 #include<windows.h>
			system("cls");//系统函数，清空屏幕，对应 #include<stdlib.h>
			break;
		}
	} while (input != 1 && input != 0);
 }






//3.清空并复原初始界面函数
void clean()
{
	system("cls");
	menu();
	printf("请输入数字(1开始  0结束)>：\n1\n游戏开始！\n");
}





//4.游戏（主干流程）函数
void game()
{
	int t;
	char chess[HANG][LIE] = {0};//数组--存放每走一步的棋盘信息
	initchess(chess, HANG,LIE);//初始化数组元素为 ' '
	prichess(chess,HANG,LIE);	//打印棋盘和棋子

	//进入游戏环节
	while (1)
	{
		////     玩家下棋
		playermove(chess, HANG, LIE);//玩家选定数组元素赋值为'*'
		clean();
		prichess(chess, HANG, LIE);
		t = judge(chess, HANG, LIE);//判断胜负平
		if (t != 'k')
		{
			break;
		}

		////     电脑下棋
		Sleep(1000);//（假装电脑有思考的过程）
		computermove(chess, HANG, LIE);//玩家随机某数组元素赋值为'#'
		clean();
		prichess(chess, HANG, LIE);
		t = judge(chess, HANG, LIE);//判断胜负平
		if (t != 'k')
		{
			break;
		}
	}
	//打印胜负平的结果
	if (t == '*') { printf("\n玩家胜利!\n"); }
	else if (t == '#') { printf("\n电脑胜利!\n"); }
	else if (t == 'm') { printf("\n平局\n"); }
}





///////////////////////////////////////////////////主函数///////////////////////////////////////////////////////
int main()
{
	int a=0;
again:
	srand((unsigned int)time(NULL));//以时间戳生成一个随机数种子，供computermove()函数中的rand()使用，对应头文件#include<stdlib.h>
	                                //时间函数 time_t time(void *);时间戳，对应头文件#include<time.h> 
	int c=start();
	if (c == 1)
	{
		game();
	}
	printf("\n\n输入(1)重新游戏\n输入任意键退出");
	scanf("%d", &a);
	if (a == 1)
	{
		goto again;
	}
	return 0;
}//////////////////////////////////////////////////////////////////////////////////////////////////////////////