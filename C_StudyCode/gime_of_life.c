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
#include<conio.h>

#define WIDTH 57   //WIDTH   x  j
#define HEIGHT 25  //HEIGHT  y  i
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

	////��ӡ�����ʾ
	switch (*speed)
	{
	case 0:
		printf("\n���٣���0.25\n");
		break;
	case 1:
		printf("\n���٣���0.50\n");
		break;
	case 2:
		printf("\n���٣���1.00\n");
		break;
	case 3:
		printf("\n���٣���1.50\n");
		break;
	case 4:
		printf("\n���٣���2.00\n");
		break;
	}
	printf("��%d��                            \n", *num);
	printf("����:1����;2����;3��ͣ;4�˳�\n");
	return 0;
}


int main()
{
	//AAAAA// ��ȡ�������ʼ����Ȳ���
	//// HANDLE �������ֵ�ϣ���һ��32λ�޷�������ֵ������ϣ���Windowsÿ�������и��������һ��Ψһ�ġ��̶������ID�������ϣ�Windowsʹ�þ������ʶ���細�ڡ�λͼ�����ʵȶ��󣬲�ͨ������ҵ���Щ����
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ��׼����(��׼_���_���)
	COORD zero = { 0,0 };//���ó�ʼ���� //COORD�ǽṹ�壬������X��Y����


	//BBBBB// ͨ�����ù������---�����ع��Ĳ���
	CONSOLE_CURSOR_INFO cci;//����̨_���_��Ϣ(����һ���ṹ���������ƣ���Ա���� dwSize �� bVisible )
	cci.dwSize = sizeof(cci);//ָ�����Ĵ�С��ָʾ��������ַ���Ԫ��İٷֱȣ�
	cci.bVisible = FALSE;//ָ���α�Ŀɼ��ԣ�����α��ǿɼ��ģ���ó�ԱΪTRUE(1)���α겻�ɼ������ԱΪFALSE(0)��
	SetConsoleCursorInfo(handle, &cci);//����_����̨_�α�_��Ϣ����


	//��ʼ����ͼ(�ڵ�ͼ���������%50������)
	init_map();

	int num = 0;
	int sleepTime = 100;
	int speed = 2;
	while (1)
	{
		//AAAAA// ͨ�����ù��λ��---�ѹ���ƶ����ʼ�ĵط�
		SetConsoleCursorPosition(handle, zero);//����_����̨_�α�_λ��

		////��ӡ��ͼ
		print_map(map);
		////�����ͼ
		update_map(map);
		num++;

		////��ҽ��в���
		int t = player(&num, &sleepTime, &speed);
		if (t) {
			break;
		}
		Sleep(sleepTime);
	}
}