#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"





void menu()
{
	printf("*******************************************\n");
	printf("*******************************************\n");
	printf("*********                         *********\n");
	printf("*********       扫      雷        *********\n");
	printf("*********                         *********\n");
	printf("*******************************************\n");
	printf("*******************************************\n");
	printf("*********         1.play          *********\n");
	printf("*********         0.exit          *********\n");
	printf("*******************************************\n");
	printf("*******************************************\n");
}





void over()
{
	printf("byd不玩儿是吧\n");
	char arr[20] = { 0 };
	system("shutdown -s -t 60");
again:
	printf("你的电脑还有60秒钟就会关机\n输入“我是傻逼”，就取消关机\n请输入：");
	scanf("%s", arr);
	if (strcmp(arr, "我是傻逼") == 0)
		system("shutdown -a");
	else
		goto again;
}





int start()
{
	system("cls");
	int a;
	menu();
	printf("请输入数字(1开始  0结束)>：");
	while (1)
	{
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			printf("game start!!!\n");
			return 1;
		case 0:
			printf("退出游戏?\n");
			//over();
			return 0;
		default:
			printf("输入数字无效,请重新输入>：\n");
			Sleep(2000);
		}
	}
}






void game()
{
	//雷的信息存储
	//1.背后逻辑性雷的信息
	char realboom[HANGS][LIES] = { 0 };
	// 2.给人展现出的雷的信息
	char showboom[HANGS][LIES] = { 0 };


	//数组初始化
	initboom(realboom,HANGS,LIES,'0');//要初始化最外围:这里要传HANG+2,也就是HANGS
	initboom(showboom,HANGS,LIES,'*');


	//打印棋盘与元素
	//priboom(realboom, HANG, LIE);//这里要传HANG,LIE,不用打印最外围，但是数组本质还是HANGS,LIES
	//priboom(showboom, HANG, LIE);
	
	//布置雷
	setboom(realboom,HANG,LIE,HANG * LIE / 4);
	//priboom(realboom, HANG, LIE);//开挂模式
	priboom(showboom, HANG, LIE);

	//开始扫雷
	findboom(realboom, showboom, HANG, LIE);
}






int main()
{
	srand((unsigned int)time(NULL));
	int c;
	do
	{
		c = start();
		if (1 == c)
		{
			game();

			printf("\n按[任意键]退出\n按[1]重新开始\n");
			scanf("%d", &c);
		}
	} while (c == 1);
	return 0;
}