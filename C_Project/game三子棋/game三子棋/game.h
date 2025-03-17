#define HANG 3//用宏定义 HANG LIE 的原因:方便的实现后期数值的改动
#define LIE 3

#include<stdio.h>
#include<stdlib.h>//cls;rand();srand()
#include<windows.h>//Sleep()
#include<time.h> //time()

//函数的声明
void initchess(char chess[HANG][LIE], int hang, int lie);//把其他源文件中的函数，声明到主函数存在的源文件中
void prichess(char chess[HANG][LIE], int hang, int lie);
void playermove(char chess[HANG][LIE], int hang, int lie);
void computermove(char chess[HANG][LIE], int hang, int lie);
char judge(char chess[HANG][LIE], int hang, int lie);
