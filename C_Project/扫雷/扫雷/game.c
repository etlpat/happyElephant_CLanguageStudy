#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"




//实现刷新屏幕的函数
void clean()
{
	system("cls");
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
	printf("请输入数字(1开始  0结束) > ：1\n");
	printf("game start!!!\n");
}







//初始化棋盘元素的函数
void initboom(char boom[HANGS][LIES], int hangs, int lies, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < hangs; i++)
	{
		for (j = 0; j < lies; j++)
		{
			boom[i][j] = set;
		}
	}
}





//打印棋盘与元素函数（不展示最外围元素）
//数组整体下标范围是[0,HANGS-1]，玩家要看到的则为[1，HANGS-2]即为[1,HANG];
//e.g.真实下标[0,10]，玩家看到下标[1,9],HANGS=11,HANG=9
void priboom(char boom[HANGS][LIES], int hang, int lie)
{
	int a = 1;
	printf("    ");
	for (a = 1; a <= hang; a++)
	{
		printf("%-3d ", a);
	}
	printf("\n");
	int i = 0;
	int j = 0;
	for (i = 0; i < hang + 1; i++)
	{
		printf("  ");
		for (j = 0; j < lie + 1; j++)
		{
			printf("|");
			if (j < lie)
			{
				printf("---");
			}
		}
		printf("\n");
		if (i < hang)
		{
			printf("%-2d", i + 1);
			for (j = 0; j < lie + 1; j++)
			{
				printf("|");
				if (j < lie)
				{
					printf(" %c ", boom[i + 1][j + 1]);//这里i,j都是从0开始，但是玩家那边不展示最外围，所以下标从1开始循环
				}
			}
		}
		printf("\n");
	}
}


//用于打印显示外围的棋盘与元素（测试用）
//void priboom2(char boom[HANGS][LIES], int hang, int lie)
//{
//	int a = 1;
//	printf("    ");
//	for (a = 1; a <= hang; a++)
//	{
//		printf("%-3d ", a);
//	}
//	printf("\n");
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < hang + 1; i++)
//	{
//		printf("  ");
//		for (j = 0; j < lie + 1; j++)
//		{
//			printf("|");
//			if (j < lie)
//			{
//				printf("---");
//			}
//		}
//		printf("\n");
//		if (i < hang)
//		{
//			printf("%-2d", i + 1);
//			for (j = 0; j < lie + 1; j++)
//			{
//				printf("|");
//				if (j < lie)
//				{
//					printf(" %c ", boom[i][j]);
//				}
//			}
//		}
//		printf("\n");
//	}
//}






//设置雷的函数
void setboom(char realboom[HANGS][LIES], int hang, int lie, int num)
{
	int a, i, j;
	for (a = 0; a < num; a++)
	{
again:
		i = rand() % hang + 1;
		j = rand() % lie + 1;
	
			if (realboom[i][j] == '0')
			{
				realboom[i][j] = '1';
			}
			else
			{
				goto again;
			}
	}
}





// 字符'1'-字符'0'=数字1;因为 字符'1' ASCII表值为49;字符'0'  ASCII码表值为48，二者相减值为1; 
// 同理，字符'n'-字符'0'=数字n; 反之，数字n+字符'0'=字符'n'
//计算选中格子周围雷的数量的函数
int num(char realboom[HANGS][LIES],int i,int j)
{
	return realboom[i - 1][j - 1] +
		realboom[i - 1][j] +
		realboom[i - 1][j + 1] +
		realboom[i][j - 1] +
		realboom[i][j] +
		realboom[i][j + 1] +
		realboom[i + 1][j - 1] +
		realboom[i + 1][j] +
		realboom[i + 1][j + 1] - 9 * '0';
}





//下面是写烂了的展开函数

//1.坐标不是雷2.坐标周围没有雷；那么就向周围展开的函数(?????为什么运行不了?????)
//void continuefind(char realboom[HANGS][LIES], char showboom[HANGS][LIES], int i, int j)
//{
//	if (realboom[i][j] == '0')
//	{
//		for (i = i - 1; i <= i + 1; i++)
//		{
//			for (j = j - 1; j <= j + 1; j++)
//			{
//				if (num(realboom, i, j) == 0)
//				{
//					showboom[i][j] = ' ';
//					continuefind(realboom, showboom, i, j);
//				}
//				else
//				{
//					showboom[i][j] = num(realboom, i, j) + '0';
//				}
//			}
//		}
//	}
//}
//void continuefind(char realboom[HANGS][LIES], char showboom[HANGS][LIES], int i, int j)
//{
//	int count = num(realboom, i, j);
//	if (count == 0)
//	{
//		showboom[i][j] = ' ';//没有雷的坐标赋值为空格
//		//递归周围的八个格子
//		if (realboom[i - 1][j - 1] == '*')
//			continuefind(realboom, showboom, i - 1, j - 1);
//		if (realboom[i - 1][j] == '*')
//			continuefind(realboom, showboom, i - 1, j);
//		if (realboom[i - 1][j + 1] == '*')
//			continuefind(realboom, showboom, i - 1, j + 1);
//		if (realboom[i][j - 1] == '*')
//			continuefind(realboom, showboom, i, j - 1);
//		if (realboom[i][j + 1] == '*')
//			continuefind(realboom, showboom, i, j + 1);
//		if (realboom[i + 1][j - 1] == '*')
//			continuefind(realboom, showboom, i + 1, j - 1);
//		if (realboom[i + 1][j] == '*')
//			continuefind(realboom, showboom, i + 1, j);
//		if (realboom[i + 1][j + 1] == '*')
//			continuefind(realboom, showboom, i + 1, j + 1);
//
//	}
//	else
//	{
//		showboom[i][j] = count + '0';
//	}
//}








//玩家开始扫雷
void findboom(char realboom[HANGS][LIES], char showboom[HANGS][LIES], int hang, int lie)
{
	int i, j;
	int win = 0;
	do
	{
		scanf("%d%d", &i, &j);
		if (realboom[i][j] == '0')
		{
	/*		if (num(realboom, i, j) != 0)
				showboom[i][j] = num(realboom, i, j) + '0';
			else
				continuefind(realboom, showboom, i, j);*////////递归失败了QAQ


			showboom[i][j] = num(realboom, i, j) + '0';
			clean();
			priboom(showboom, HANG, LIE);
			win++;

			if (win == (hang * lie - HANG * LIE / 4))
			{
				Sleep(1500);
				printf("恭喜获胜\n");
				Sleep(1500);
				priboom(realboom, HANG, LIE);
					break;
			}
		}
		else if (realboom[i][j] == '1')
		{
			printf("\n\n\n\n\n\n很遗憾，你被炸死了\n\n\n\a");
			Sleep(1000);
			priboom(realboom, HANG, LIE);
			break;
		}
	}while(1);
}