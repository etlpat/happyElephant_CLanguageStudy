#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"


////char name[MAX_NAXE]
////int age
////char sex[MAX_SEX]
////char tele[MAX_TELE]
////char addr[MAX_ADDR]


void Initcontact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}



//加static，让函数仅在本.c文件中可用，防止和其他文件中名字重复，增加模块性（可不加）
static int FindName(const struct Contact* const ps)//找到返回下标，否则返回-1
{
	char TmpName[MAX_NAME] = { 0 };
	scanf("%s", TmpName);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, TmpName))
		{
			return i;
		}
	}
	return -1;
}



void AddContact(struct Contact* ps)//1
{
	if (ps->size >= MAX)
	{
		printf("通讯录已满\n");
	}
	else
	{
		printf("请输入姓名：>");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入年龄：>");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入性别：>");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入电话：>");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入地址：>");
		scanf("%s", ps->data[ps->size].addr);

		ps->size++;
		printf("输入成功\n");
	}
}



void DelContact(struct Contact* ps)//2
{
	//1.查找
	printf("请输入要查找人的信息\n");
	int ret = FindName(ps);
	//2.删除
	if (ret == -1)
	{
		printf("要删除的人不存在\n");
	}
	else//要删除的元素后面的内存往前移，将之覆盖掉
	{
		//memmove(ps->data + i, ps->data + i + 1, (ps->size - i - 1) * sizeof(ps->data[0]));
		////或者
		int j = 0;
		for (j = ret; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除完毕\n");
	}
}



void FindContact(const struct Contact* const ps)//3
{
	printf("请输入要查找人的名字：>");
	int ret = FindName(ps);
	if (ret == -1)
	{
		printf("要查找的人不存在\n");
	}
	else
	{
		printf("%-6s\t%-4s\t%-4s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
		printf("%-6s\t%-4d\t%-4s\t%-12s\t%-30s\n", ps->data[ret].name, ps->data[ret].age, ps->data[ret].sex, ps->data[ret].tele, ps->data[ret].addr);
		printf("查找完毕\n");
	}
}

  

void ModifyContact(const struct Contact* const ps)//4
{
	printf("请输入要修改人的名字：>");
	int ret = FindName(ps);
	if (ret == -1)
	{
		printf("要修改的人不存在\n");
	}
	else
	{
		printf("请输入姓名：>");
		scanf("%s", ps->data[ret].name);
		printf("请输入年龄：>");
		scanf("%d", &(ps->data[ret].age));
		printf("请输入性别：>");
		scanf("%s", ps->data[ret].sex);
		printf("请输入电话：>");
		scanf("%s", ps->data[ret].tele);
		printf("请输入地址：>");
		scanf("%s", ps->data[ret].addr);
	}
}




void ShowContact(const struct Contact* const ps)//5
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		printf("%-6s\t%-4s\t%-4s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
		int i;
		for (i = 0; i < ps->size; i++)
		{
			printf("%-6s\t%-4d\t%-4s\t%-12s\t%-30s\n", ps->data[i].name, ps->data[i].age, ps->data[i].sex, ps->data[i].tele, ps->data[i].addr);
		}
		printf("打印结束\n");
	}
}