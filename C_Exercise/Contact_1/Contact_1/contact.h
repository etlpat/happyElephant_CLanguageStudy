#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 1000
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
	SORT//����
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
	struct PeoInfo data[MAX];//���MAX����Ϣ
	int size;//��¼��ǰ���е�Ԫ�ظ��� 
};


void Initcontact(struct Contact* ps);
void AddContact(struct Contact* ps);//1
void DelContact(struct Contact* ps);//2
void FindContact(const struct Contact* const ps);//3
void ModifyContact(const struct Contact* const ps);//4
void ShowContact(const struct Contact* const ps);//5



