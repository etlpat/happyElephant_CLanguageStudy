#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

#define DEFAULT_SIZE 3 //动态数组首次开辟空间大小
#define CHANGE_SIZE 2 //动态数组扩容增加的大小
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30


enum Option
{
	EXIT,//退出
	ADD,//增加
	DEL,//删除
	SEARCH,//查找
	MODIFY,//修改
	SHOW,//展示
	SORT,//排序
	SAVE//存档
};


struct PeoInfo  //名字 年龄 性别 电话 地址
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};


//通讯录
struct Contact
{
	struct PeoInfo* data;//动态内存指针,指向的每个元素类型是struct PeoInfo
	int size;//已有的元素个数 
	int real_size;//通讯录真实容量
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
