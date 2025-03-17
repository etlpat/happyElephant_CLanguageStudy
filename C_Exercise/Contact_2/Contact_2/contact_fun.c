#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"


////char name[MAX_NAXE]
////int age
////char sex[MAX_SEX]
////char tele[MAX_TELE]
////char addr[MAX_ADDR]


void Initcontact(struct Contact* ps)
{
	ps->data = (struct PeoInfo*)malloc(3 * sizeof(struct PeoInfo));//���ٶ�̬�ڴ�
	if (ps->data == NULL)
	{
		printf("��ʼ��ʱ�����ڴ治��\n");
		return;
	}
	ps->size = 0;
	ps->real_size = DEFAULT_SIZE;

	//���ļ����Ѿ���ŵ�ͨѶ¼��Ϣ���ص�ͨѶ¼��
	LoadContact(ps);
}




void LoadContact(struct Contact* ps)//�ѱ��浽�ı�����Ϣ����ͨѶ¼������
{
	struct PeoInfo tmp = { 0 };
	FILE* pfRead = fopen("contact.txt", "rb");
	if (pfRead == NULL)
	{
		printf("LoadContact:%s\n", strerror(errno));
		return;
	}

	//��ȡ�ļ�����ͨѶ¼��
	while (fread(&tmp, sizeof(tmp), 1, pfRead))//����fread���ļ���Ϣ��һ����ÿ�ε�tmp,����ʱ��ȡ0���0���������
	{
		check_mem(ps);
		ps->data[ps->size] = tmp;
		ps->size++;
	}

	fclose(pfRead);
	pfRead = NULL;
}



int check_mem(struct Contact* ps)//��⶯̬�ռ䣬�������ӿռ䣬����ɶҲ����
{
	int num = ps->real_size - ps->size;
	if (num == 0)
	{
		//����
		struct PeoInfo* ptr = (struct PeoInfo*)realloc(ps->data, (ps->real_size + CHANGE_SIZE) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->real_size += CHANGE_SIZE;
		}
		else//����ʧ��
		{
			return 0;
		}
	}
	else if (num > CHANGE_SIZE)
	{
		//��������
		struct PeoInfo* ptr = (struct PeoInfo*)realloc(ps->data, (ps->real_size - (num / CHANGE_SIZE) * CHANGE_SIZE) * sizeof(struct PeoInfo));
		ps->data = ptr;
		ps->real_size -= (num / CHANGE_SIZE) * CHANGE_SIZE;
	}
	return 1;
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
	if (check_mem(ps))
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
	else
	{
		printf("�ڴ治�㣬���ʧ��\n");
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

	//3.ɾ�����������
	check_mem(ps);
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


void freeContact(struct Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}





void SaveContact(struct Contact* ps)
{
	FILE* pfWrite = fopen("contact.txt", "wb");//�����ļ��ö�������ʽ�洢��������������ı���˵ʡ�ռ䣩
	if (pfWrite == NULL)
	{
		printf("SaveContact:%s\n", strerror(errno));
		return ;
	}
	//дͨѶ¼�����ݵ��ļ���
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->data[i]), sizeof(ps->data[i]), 1, pfWrite);
	}
	fclose(pfWrite);
	pfWrite = NULL;

	printf("����ɹ�\n");
}