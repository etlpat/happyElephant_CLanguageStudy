#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//������ʽ
// * | * | * 
//---|---|---
// * | * | *  
//---|---|---
// * | * | * 





//1.���ڳ�ʼ�����̵ĺ���
void initchess(char chess[HANG][LIE], int hang, int lie)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < hang; i++)
	{
		for (j = 0; j < lie; j++)
		{
			chess[i][j] =  ' ' ;//��������ÿ��Ԫ�س�ʼ��Ϊһ���ո�
		}
	}
}





//2.��ӡ���̺�����(����Ԫ��)�ĺ���
void prichess(char chess[HANG][LIE], int hang, int lie)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < hang; i++)
	{
		for (j = 0; j < lie; j++)//ÿһ�п�ʼʱ����ӡ(����) ' * '�� '|'
		{
			printf(" %c ", chess[i][j]);
			if (j < lie - 1)
				printf("|");
		}
		printf("\n");
		if (i < hang - 1)
		{
			for (j = 0; j < lie; j++)////ÿһ�н����󣬴�ӡ(�ָ���) '\n'  '---' �� '|'
			{
				printf("---");
				if (j < lie - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}





//3.ʵ��������壬������'*'�滻ԭ�������е�' '�ĺ���
void playermove(char chess[HANG][LIE], int hang, int lie)
{
	int x, y;
	printf("������������꣨x,y��>:\n");
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
				printf("��λ���ѱ�ռ�ã����ٴ�����>:\n");
			}
		}
		else
		{
			printf("����Ƿ����꣬���ٴ�����>:\n");
		}
	}
}





//4.ʵ�ֵ������壬������'#'�滻ԭ�������е�' '�ĺ���
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






//5.�ж� ʤ/��/ƽ/���� �������Ӧ����ֵ�ĺ���
char judge(char chess[HANG][LIE], int hang, int lie)
{
	int x; int y; int i, j;
	//�жϺ����������
	for (x = 0; x < hang; x++)
	{
		if (chess[x][0] == chess[x][1] && chess[x][1] == chess[x][2] && chess[x][0] != ' ') { return chess[x][0]; }
	}
	//�ж������������
	for (y = 0; y < lie; y++)
	{
		if (chess[0][y] == chess[1][y] && chess[1][y] == chess[2][y] && chess[0][y] !=' ') { return chess[0][y]; }
	}
	//�ж�б�����Ƿ����
	if (chess[0][0] == chess[1][1] && chess[1][1] == chess[2][2] && chess[0][0] != ' ') { return chess[0][0]; }
	else if (chess[0][2] == chess[1][1] && chess[1][1] == chess[2][2] && chess[2][0] != ' ') { return chess[0][2]; }
	//�ж������Ƿ�ȫ��ƽ��
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