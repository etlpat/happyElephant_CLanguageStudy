#define HANG 10
#define LIE 10

#define HANGS HANG+2
#define LIES LIE+2


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>


void initboom(char boom[HANGS][LIES],int hangs,int lies,char set);
void priboom(char boom[HANGS][LIES], int hang, int lie);
void priboom2(char boom[HANGS][LIES], int hang, int lie);
void setboom(char realboom[HANGS][LIES], int hang, int lie, int num);
void findboom(char realboom[HANGS][LIES], char showboom[HANGS][LIES], int hang, int lie);