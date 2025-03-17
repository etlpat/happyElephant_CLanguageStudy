#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"


////////////////////////////////////////////////////大体功能////////////////////////////////////////////////////

//1.可供存放1000个好友信息（）
//2.增加好友信息
//3.删除指定名字的好友信息
//4.查找好友信息
//5.修改好友信息
//6.打印好友信息

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
	printf("########           0.退出             ######\n");
	printf("############################################\n");
}





////////////////////////////////////////////////////////主函数/////////////////////////////////////////////////


int main()
{
	int input = 0;

	//创建通信录
	struct Contact con;//con就是通讯录，里边包含1000给元素的数组和size
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

		case EXIT:
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
