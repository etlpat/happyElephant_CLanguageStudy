#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"





void menu()
{
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
}





void over()
{
	printf("byd������ǰ�\n");
	char arr[20] = { 0 };
	system("shutdown -s -t 60");
again:
	printf("��ĵ��Ի���60���Ӿͻ�ػ�\n���롰����ɵ�ơ�����ȡ���ػ�\n�����룺");
	scanf("%s", arr);
	if (strcmp(arr, "����ɵ��") == 0)
		system("shutdown -a");
	else
		goto again;
}





int start()
{
	system("cls");
	int a;
	menu();
	printf("����������(1��ʼ  0����)>��");
	while (1)
	{
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			printf("game start!!!\n");
			return 1;
		case 0:
			printf("�˳���Ϸ?\n");
			//over();
			return 0;
		default:
			printf("����������Ч,����������>��\n");
			Sleep(2000);
		}
	}
}






void game()
{
	//�׵���Ϣ�洢
	//1.�����߼����׵���Ϣ
	char realboom[HANGS][LIES] = { 0 };
	// 2.����չ�ֳ����׵���Ϣ
	char showboom[HANGS][LIES] = { 0 };


	//�����ʼ��
	initboom(realboom,HANGS,LIES,'0');//Ҫ��ʼ������Χ:����Ҫ��HANG+2,Ҳ����HANGS
	initboom(showboom,HANGS,LIES,'*');


	//��ӡ������Ԫ��
	//priboom(realboom, HANG, LIE);//����Ҫ��HANG,LIE,���ô�ӡ����Χ���������鱾�ʻ���HANGS,LIES
	//priboom(showboom, HANG, LIE);
	
	//������
	setboom(realboom,HANG,LIE,HANG * LIE / 4);
	//priboom(realboom, HANG, LIE);//����ģʽ
	priboom(showboom, HANG, LIE);

	//��ʼɨ��
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

			printf("\n��[�����]�˳�\n��[1]���¿�ʼ\n");
			scanf("%d", &c);
		}
	} while (c == 1);
	return 0;
}