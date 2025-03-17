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



//��static���ú������ڱ�.c�ļ��п��ã���ֹ�������ļ��������ظ�������ģ���ԣ��ɲ��ӣ�
static int FindName(const struct Contact* const ps)//�ҵ������±꣬���򷵻�-1
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
		printf("ͨѶ¼����\n");
	}
	else
	{
		printf("������������>");
		scanf("%s", ps->data[ps->size].name);
		printf("���������䣺>");
		scanf("%d", &(ps->data[ps->size].age));
		printf("�������Ա�>");
		scanf("%s", ps->data[ps->size].sex);
		printf("������绰��>");
		scanf("%s", ps->data[ps->size].tele);
		printf("�������ַ��>");
		scanf("%s", ps->data[ps->size].addr);

		ps->size++;
		printf("����ɹ�\n");
	}
}



void DelContact(struct Contact* ps)//2
{
	//1.����
	printf("������Ҫ�����˵���Ϣ\n");
	int ret = FindName(ps);
	//2.ɾ��
	if (ret == -1)
	{
		printf("Ҫɾ�����˲�����\n");
	}
	else//Ҫɾ����Ԫ�غ�����ڴ���ǰ�ƣ���֮���ǵ�
	{
		//memmove(ps->data + i, ps->data + i + 1, (ps->size - i - 1) * sizeof(ps->data[0]));
		////����
		int j = 0;
		for (j = ret; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ�����\n");
	}
}



void FindContact(const struct Contact* const ps)//3
{
	printf("������Ҫ�����˵����֣�>");
	int ret = FindName(ps);
	if (ret == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
	}
	else
	{
		printf("%-6s\t%-4s\t%-4s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-6s\t%-4d\t%-4s\t%-12s\t%-30s\n", ps->data[ret].name, ps->data[ret].age, ps->data[ret].sex, ps->data[ret].tele, ps->data[ret].addr);
		printf("�������\n");
	}
}

  

void ModifyContact(const struct Contact* const ps)//4
{
	printf("������Ҫ�޸��˵����֣�>");
	int ret = FindName(ps);
	if (ret == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
	}
	else
	{
		printf("������������>");
		scanf("%s", ps->data[ret].name);
		printf("���������䣺>");
		scanf("%d", &(ps->data[ret].age));
		printf("�������Ա�>");
		scanf("%s", ps->data[ret].sex);
		printf("������绰��>");
		scanf("%s", ps->data[ret].tele);
		printf("�������ַ��>");
		scanf("%s", ps->data[ret].addr);
	}
}




void ShowContact(const struct Contact* const ps)//5
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		printf("%-6s\t%-4s\t%-4s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		int i;
		for (i = 0; i < ps->size; i++)
		{
			printf("%-6s\t%-4d\t%-4s\t%-12s\t%-30s\n", ps->data[i].name, ps->data[i].age, ps->data[i].sex, ps->data[i].tele, ps->data[i].addr);
		}
		printf("��ӡ����\n");
	}
}