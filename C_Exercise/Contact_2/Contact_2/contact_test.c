#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"


////////////////////////////////////////////////////改进功能////////////////////////////////////////////////////
////
////  默认存放3个人的信息
////  当通讯录满，扩容，增加两个人的空间
////  可以保存信息 
////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


void menu1()
{
	printf("############################################\n");
	printf("############################################\n");
	printf("############     通  讯  录     ############\n");
	printf("############################################\n");
}

void menu2()
{
	printf("############################################\n");
	printf("########  1.添加信息      2.删除信息  ######\n");
	printf("########  3.查找信息      4.修改信息  ######\n");
	printf("########  5.显示信息      6.排序      ######\n");
	printf("########  7.保存信息      0.退出      ######\n");
	printf("############################################\n");
}





////////////////////////////////////////////////////////主函数/////////////////////////////////////////////////


int main()
{
	int input = 0;

	//创建通信录
	struct Contact con;//con就是通讯录
	//初始化通讯录
	Initcontact(&con);

	menu1();
	do
	{
		menu2();
		printf("请选择：>");
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
			//退出前先保存数据
			SaveContact(&con);
			//释放动态开辟的内存
			freeContact(&con);
			printf("退出通讯录\n");
			break;

		default:
			printf("选择错误\n");
			break;
		}

		system("pause");

	} while (input);

	return 0;
}
