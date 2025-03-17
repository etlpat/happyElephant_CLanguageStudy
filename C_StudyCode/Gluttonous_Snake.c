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


typedef enum Enum //��ͼԪ��
{
	AIR,
	BODY,
	HEAD,
	APPLE,
	WALL

}Enum;


//�������з��Ŷ�Ӧ�����ö�ٳ�Ա
char* map_graphy[] = { "  ","�� ","�� ","@ ","# " };


typedef enum Direction //��ͷǰ���ķ�������Ϊż��������Ϊ������
{
	W,
	A,
	S,
	D

}Direction;



///////////////////////////////////////////////////////////////////////////����////////////////////////////////////////////////////////////////////////////////




void init_map(Enum map[ROW1][COL1])//��ʼ����ͼ
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





void init_snake(Enum map[ROW1][COL1], COORD* snake)//�����������м��������
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





void init_apple(Enum map[ROW1][COL1])//����һ�����ƻ�������ڱ�Ե��
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




void pri_map(Enum map[ROW1][COL1], int snakeNum)//��ӡ��ͼ
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
	printf("�÷� ��%d", snakeNum - 3);
}




COORD keyAction(COORD snakeHead, Direction* pd)//����Ϊ��ͷ����ͷ����ָ��
{
	Direction olddir = *pd;
	Direction newdir = *pd;
	COORD newHead = snakeHead;
	if(_kbhit())//  _kbhit���������룬�����棬���򷵻�0
	{
		char key1, key2;
		key1 = _getch();
		switch (key1)//  _getch�Ӽ��̻���ַ����޻��ԣ���������Զ�������һ�������ûس�
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
			//�����������Ҽ�����������ֵ����һ�� -32����ʾ������������
			//�ڶ������ض�Ӧ��������ASCII 72 80  75 77
		case -32:
			key2 = _getch();//�õ�-32���ٶ�ȡһ�������ֵ
			switch (key2)
			{
			case 72://�ϼ�
				newHead.Y--;
				newdir = W;
				break;
			case 80://�¼�
				newHead.Y++;
				newdir = S;
				break;
			case 75://���
				newHead.X--;
				newdir = A;
				break;
			case 77://�Ҽ�
				newHead.X++;
				newdir = D;
				break;
			default:
				break;
			}
		default:
			break;
		}
		//�������õķ���ö�ٳ��� ����Ϊż��������Ϊ�档
		if ((((int)olddir + (int)newdir)) % 2 == 1|| (int)olddir == (int)newdir)
		//���Ϊ�棬�·����ھɷ������ࣻ������ȣ��¾ɷ���һ�¡����������ֱ�ӷ����·���
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
	else//δ���������
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




//�ߵı䶯
//����û��ƻ����ȥ����β����ͷ��ǰ�������ƻ������β��������ͷ��ǰ
void change(Enum map[ROW1][COL1], COORD* snake, COORD newHead, int snakeNum, int isApple)
{
	if (isApple == 0)//����û��ƻ����ȥ����β����ͷ��ǰ
	{
		map[snake[snakeNum - 1].Y][snake[snakeNum - 1].X] = AIR;
	}

	map[snake[0].Y][snake[0].X] = BODY;
	//�����ߵ�����
	int i;
	for (i = snakeNum - 1; i > 0; i--)
	{
		snake[i] = snake[i - 1];
	}
	snake[0] = newHead;
	map[snake[0].Y][snake[0].X] = HEAD;
}



///////////////////////////////////////////////////////////////////////////������////////////////////////////////////////////////////////////////////////////////

int main()
{
	//�������������
	srand((unsigned)time(NULL));


	//��ʼ����� - <Windows.h>
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//���ñ�׼���
	CONSOLE_CURSOR_INFO cci = { 1,0 };//����̨�α���Ϣ{����С,�ɼ���}����ʼ�����Ϊ���ɼ�
	SetConsoleCursorInfo(handle, &cci);//���ù����Ϣ
	COORD zero = { 0,0 };//���ù���ʼ����


	//��ʼ����ͼ
	Enum map[ROW1][COL1] = { 0 };
	init_map(map);
	

	//��ʼ����
	int snakeNum = 3;
	Direction dir = D;//��ʼ������
	COORD snake[ROW * COL];//���������ʾ�ߵ�ÿ�����壨�ṹ������COORD������Windows.h�У���snake[0]Ϊ��ͷ
	init_snake(map,snake);


	//��ʼ��ƻ��
	init_apple(map);
	

	//��ʼ�����ƶ������ʱ��
	float sleepTime = 100;


	//������Ϸ����
	pri_map(map, snakeNum);


	//������Ϸ
	while (1)
	{
		//ͨ�����ù��λ��---�ѹ���ƶ����ʼ�ĵط�
		SetConsoleCursorPosition(handle, zero);//����_����̨_�α�_λ��


		//������⣬��������ͷ���������߷���
		COORD newHead = keyAction(snake[0], &dir);


		int isApple = 0;
		//ʤ���ж�����������ͷû�����ĵ�snake�����У��ж�����ͷ��λ���Ƿ�Ϊǽ�����壩
		if (map[newHead.Y][newHead.X] == BODY || map[newHead.Y][newHead.X] == WALL)
		{
			Sleep(2000);
			system("cls");
			printf("��Ϸ����");
			break;
		}
		else if (map[newHead.Y][newHead.X] == APPLE)
		{
			isApple = 1;
			snakeNum++;
			sleepTime *= 0.9;
		}


		//�����ߣ�ɾ��β�ͣ���ͷ�򰴼������ƶ�һ��
		change(map, snake, newHead, snakeNum, isApple);
	

		//��֮ǰ����ƻ����ˢ��ƻ��λ��
		if (isApple) {
			init_apple(map);
		}


		//�ش�ӡ��ͼ
		Sleep(sleepTime);
		pri_map(map, snakeNum);


	}


	return 0;
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////














////������չ��


////////  _kbhit()
////������̨�Ƿ��м�������
////kbhit - keyboard hit ����Ӧͷ�ļ� <conio.h>
// 
////���������ĳ������_kbhit����һ������ֵ�����򣬷���0






////////  _getch()
////�ӿ���̨��ȡһ���ַ���������
////��Ӧͷ�ļ� <conio.h>
//
////���ض�ȡ���ַ�������ʱ�����ԣ�����Ҫ���س��Ϳ��Խ�����һ��

