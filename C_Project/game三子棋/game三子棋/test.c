#define _CRT_SECURE_NO_WARNINGS 1
//������������Ϸ��������ģ�飩

#include"game.h"//���Լ�������ͷ�ļ�Ҫ��""
//����stdio.h��Щ�⺯��ͷ�ļ������ɷŵ��Լ��� .h �ļ��У�Ȼ����һ���Զ���� .h ͷ�ļ�����




//1.��ӡ�˵����溯��
void menu()
{
	printf("******************************************\n");
	printf("******************************************\n");
	printf("********                         *********\n");
	printf("********      ��    ��    ��     *********\n");
	printf("********                         *********\n");
	printf("******************************************\n");
	printf("******************************************\n");
	printf("********          1.play         *********\n");
	printf("********          0.exit         *********\n");
	printf("******************************************\n");
	printf("******************************************\n");
}





//2.��ʼ��Ϸ���溯�����˵�����+ѡ���Ƿ�ʼ��
int start()
{
	int input;
	system("cls");
	do
	{
		menu();
		printf("����������(1��ʼ  0����)>��\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��Ϸ��ʼ��\n");
			return 1;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("����������Ч\n");
			Sleep(2000);//���ߣ������룬��Ӧ #include<windows.h>
			system("cls");//ϵͳ�����������Ļ����Ӧ #include<stdlib.h>
			break;
		}
	} while (input != 1 && input != 0);
 }






//3.��ղ���ԭ��ʼ���溯��
void clean()
{
	system("cls");
	menu();
	printf("����������(1��ʼ  0����)>��\n1\n��Ϸ��ʼ��\n");
}





//4.��Ϸ���������̣�����
void game()
{
	int t;
	char chess[HANG][LIE] = {0};//����--���ÿ��һ����������Ϣ
	initchess(chess, HANG,LIE);//��ʼ������Ԫ��Ϊ ' '
	prichess(chess,HANG,LIE);	//��ӡ���̺�����

	//������Ϸ����
	while (1)
	{
		////     �������
		playermove(chess, HANG, LIE);//���ѡ������Ԫ�ظ�ֵΪ'*'
		clean();
		prichess(chess, HANG, LIE);
		t = judge(chess, HANG, LIE);//�ж�ʤ��ƽ
		if (t != 'k')
		{
			break;
		}

		////     ��������
		Sleep(1000);//����װ������˼���Ĺ��̣�
		computermove(chess, HANG, LIE);//������ĳ����Ԫ�ظ�ֵΪ'#'
		clean();
		prichess(chess, HANG, LIE);
		t = judge(chess, HANG, LIE);//�ж�ʤ��ƽ
		if (t != 'k')
		{
			break;
		}
	}
	//��ӡʤ��ƽ�Ľ��
	if (t == '*') { printf("\n���ʤ��!\n"); }
	else if (t == '#') { printf("\n����ʤ��!\n"); }
	else if (t == 'm') { printf("\nƽ��\n"); }
}





///////////////////////////////////////////////////������///////////////////////////////////////////////////////
int main()
{
	int a=0;
again:
	srand((unsigned int)time(NULL));//��ʱ�������һ����������ӣ���computermove()�����е�rand()ʹ�ã���Ӧͷ�ļ�#include<stdlib.h>
	                                //ʱ�亯�� time_t time(void *);ʱ�������Ӧͷ�ļ�#include<time.h> 
	int c=start();
	if (c == 1)
	{
		game();
	}
	printf("\n\n����(1)������Ϸ\n����������˳�");
	scanf("%d", &a);
	if (a == 1)
	{
		goto again;
	}
	return 0;
}//////////////////////////////////////////////////////////////////////////////////////////////////////////////