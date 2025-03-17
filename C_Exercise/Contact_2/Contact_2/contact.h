#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

#define DEFAULT_SIZE 3 //��̬�����״ο��ٿռ��С
#define CHANGE_SIZE 2 //��̬�����������ӵĴ�С
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30


enum Option
{
	EXIT,//�˳�
	ADD,//����
	DEL,//ɾ��
	SEARCH,//����
	MODIFY,//�޸�
	SHOW,//չʾ
	SORT,//����
	SAVE//�浵
};


struct PeoInfo  //���� ���� �Ա� �绰 ��ַ
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};


//ͨѶ¼
struct Contact
{
	struct PeoInfo* data;//��̬�ڴ�ָ��,ָ���ÿ��Ԫ��������struct PeoInfo
	int size;//���е�Ԫ�ظ��� 
	int real_size;//ͨѶ¼��ʵ����
};


void Initcontact(struct Contact* ps);
void AddContact(struct Contact* ps);//1
void DelContact(struct Contact* ps);//2
void FindContact(const struct Contact* const ps);//3
void ModifyContact(const struct Contact* const ps);//4
void ShowContact(const struct Contact* const ps);//5
void SaveContact(struct Contact* ps);//7
void freeContact(struct Contact* ps);//0 
void LoadContact(struct Contact* ps);
int check_mem(struct Contact* ps);
