#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"


////////////////////////////////////////////////////�Ľ�����////////////////////////////////////////////////////
////
////  Ĭ�ϴ��3���˵���Ϣ
////  ��ͨѶ¼�������ݣ����������˵Ŀռ�
////  ���Ա�����Ϣ 
////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


void menu1()
{
	printf("############################################\n");
	printf("############################################\n");
	printf("############     ͨ  Ѷ  ¼     ############\n");
	printf("############################################\n");
}

void menu2()
{
	printf("############################################\n");
	printf("########  1.�����Ϣ      2.ɾ����Ϣ  ######\n");
	printf("########  3.������Ϣ      4.�޸���Ϣ  ######\n");
	printf("########  5.��ʾ��Ϣ      6.����      ######\n");
	printf("########  7.������Ϣ      0.�˳�      ######\n");
	printf("############################################\n");
}





////////////////////////////////////////////////////////������/////////////////////////////////////////////////


int main()
{
	int input = 0;

	//����ͨ��¼
	struct Contact con;//con����ͨѶ¼
	//��ʼ��ͨѶ¼
	Initcontact(&con);

	menu1();
	do
	{
		menu2();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;

		case DEL:
			DelContact(&con);
			break;

		case SEARCH:
			FindContact(&con);
			break;

		case MODIFY:
			ModifyContact(&con);
			break;

		case SHOW:
			ShowContact(&con);
			break;

		case SORT:
			//
			break;

		case SAVE:
			SaveContact(&con);
			break;

		case EXIT:
			//�˳�ǰ�ȱ�������
			SaveContact(&con);
			//�ͷŶ�̬���ٵ��ڴ�
			freeContact(&con);
			printf("�˳�ͨѶ¼\n");
			break;

		default:
			printf("ѡ�����\n");
			break;
		}

		system("pause");

	} while (input);

	return 0;
}
