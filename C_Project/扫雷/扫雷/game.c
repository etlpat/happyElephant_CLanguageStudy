#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"




//ʵ��ˢ����Ļ�ĺ���
void clean()
{
	system("cls");
	printf("*******************************************\n");
	printf("*******************************************\n");
	printf("*********                         *********\n");
	printf("*********       ɨ      ��        *********\n");
	printf("*********                         *********\n");
	printf("*******************************************\n");
	printf("*******************************************\n");
	printf("*********         1.play          *********\n");
	printf("*********         0.exit          *********\n");
	printf("*******************************************\n");
	printf("*******************************************\n");
	printf("����������(1��ʼ  0����) > ��1\n");
	printf("game start!!!\n");
}







//��ʼ������Ԫ�صĺ���
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





//��ӡ������Ԫ�غ�������չʾ����ΧԪ�أ�
//���������±귶Χ��[0,HANGS-1]�����Ҫ��������Ϊ[1��HANGS-2]��Ϊ[1,HANG];
//e.g.��ʵ�±�[0,10]����ҿ����±�[1,9],HANGS=11,HANG=9
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
					printf(" %c ", boom[i + 1][j + 1]);//����i,j���Ǵ�0��ʼ����������Ǳ߲�չʾ����Χ�������±��1��ʼѭ��
				}
			}
		}
		printf("\n");
	}
}


//���ڴ�ӡ��ʾ��Χ��������Ԫ�أ������ã�
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






//�����׵ĺ���
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





// �ַ�'1'-�ַ�'0'=����1;��Ϊ �ַ�'1' ASCII��ֵΪ49;�ַ�'0'  ASCII���ֵΪ48���������ֵΪ1; 
// ͬ���ַ�'n'-�ַ�'0'=����n; ��֮������n+�ַ�'0'=�ַ�'n'
//����ѡ�и�����Χ�׵������ĺ���
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





//������д���˵�չ������

//1.���겻����2.������Χû���ף���ô������Χչ���ĺ���(?????Ϊʲô���в���?????)
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
//		showboom[i][j] = ' ';//û���׵����긳ֵΪ�ո�
//		//�ݹ���Χ�İ˸�����
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








//��ҿ�ʼɨ��
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
				continuefind(realboom, showboom, i, j);*////////�ݹ�ʧ����QAQ


			showboom[i][j] = num(realboom, i, j) + '0';
			clean();
			priboom(showboom, HANG, LIE);
			win++;

			if (win == (hang * lie - HANG * LIE / 4))
			{
				Sleep(1500);
				printf("��ϲ��ʤ\n");
				Sleep(1500);
				priboom(realboom, HANG, LIE);
					break;
			}
		}
		else if (realboom[i][j] == '1')
		{
			printf("\n\n\n\n\n\n���ź����㱻ը����\n\n\n\a");
			Sleep(1000);
			priboom(realboom, HANG, LIE);
			break;
		}
	}while(1);
}