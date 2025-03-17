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
	EXIT,//退出
	ADD,//增加
	DEL,//删除
	SEARCH,//查找
	MODIFY,//修改
	SHOW,//展示
	SORT//排序
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
	struct PeoInfo data[MAX];//存放MAX个信息
	int size;//记录当前已有的元素个数 
};


void Initcontact(struct Contact* ps);
void AddContact(struct Contact* ps);//1
void DelContact(struct Contact* ps);//2
void FindContact(const struct Contact* const ps);//3
void ModifyContact(const struct Contact* const ps);//4
void ShowContact(const struct Contact* const ps);//5



