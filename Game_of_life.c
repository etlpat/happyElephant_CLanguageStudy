#define _CRT_SECURE_NO_WARNINGS 1
//////////��������Ϸ��
//////////ÿ�����󷽸���԰���һ���л��壬���ڱ��ϵ��л�����8�����ڷ���
//////////������Ϸ�ݻ��Ĺ������£�
//////////1.���һ��ϸ����Χ��3��ϸ��Ϊ�������ϸ��Ϊ��������ϸ����ԭ��Ϊ������תΪ������ԭ��Ϊ�����򱣳ֲ��䣩��
//////////2.���һ��ϸ����Χ������ϸ��Ϊ�������ϸ��������״̬���ֲ��䡣
//////////3.����������¸�ϸ��Ϊ��������ϸ����ԭ��Ϊ������תΪ������ԭ��Ϊ�����򱣳ֲ��䣩��



#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#define WIDTH 52   //WIDTH   x  j
#define HEIGHT 27  //HEIGHT  y  i
//map[HEIGHT][WIDTH]   map[i][j]   map[y][x]



//������ͼ
char map[HEIGHT][WIDTH] = { 0 };  //0��ʾ����1��ʾ��


//�����ʼ���ĺ���
void init_map()//��֤����һȦֵ��Ϊ0
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

//��ӡmap����
void print_map()//����ӡ����Χ
{
	int i, j;
	for (i = 0; i < HEIGHT; i++)
	{
		for (j = 0; j < WIDTH; j++)
		{
			if (map[i][j]) {
				printf("�� ");
			}
			else {
				printf("  ");
			}
		}
		puts("");//puts()�Դ����й���
	}
}

//����������Χ8��ϸ�����ĺ���
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


//1.���һ��ϸ����Χ��3��ϸ��Ϊ�������ϸ����
//2.���һ��ϸ����Χ��2��ϸ��Ϊ�������ϸ������
//3.����������¸�ϸ��Ϊ��
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
	//memcpy���ڻ�����֮�临���ַ���
	//������void *memcpy( void *dest, const void *src, size_t count );
	//memcpy������src��count�ֽڿ�����dest�У����Դ��ַ��Ŀ�ĵ�ַ�ص����򲻱�֤�����ص�������Դ��ַ��ԭʼ�ֽں��ٱ����ǡ�ʹ��memmove�������ص�����
}



int main()
{
	////��ȡ����Ȳ���
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ��׼����ľ��
	COORD zero = { 0,0 };//���ó�ʼ����


	////���ع��
	CONSOLE_CURSOR_INFO cci;//��ȡ���λ��
	cci.dwSize = sizeof(cci);//���߹��Ĵ�С
	cci.bVisible = FALSE;//���߹���ǿ�������
	SetConsoleCursorInfo(handle, &cci);


	//��ʼ����ͼ(�ڵ�ͼ���������%50������)
	init_map();

	while (1)
	{
		////����ƶ����ʼ�ĵط�������
		SetConsoleCursorPosition(handle, zero);//���� �����д��� ��� λ��

		////��ӡ��ͼ
		print_map(map);
		////�����ͼ
		update_map(map);
		////getchar();
		Sleep(100);
	}
	return 0;
}