#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>


#define WIDTH 90
#define HIGTH 25

////初始化：光标一类的‘=
////对蛇初始化：堆区创建蛇的数组
////绘制游戏界面
////对蛇进行绘制，苹果
////对时间初始化
//int mian()
//{
//	//获取当前时间，如到达一定时间，移动蛇
//	    //对蛇本身做更改：删除尾巴，向前移动一格
//	    //胜负判定、吃苹果判定
//	    //按键检测
//	//每隔一段时间，改变苹果位置
//	return 0;
//}


HANDLE hdl;

int mian()
{
	//初始化光标
	hdl = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci = { 1,0 };
	SetConsoleCursoRInfo(hdl, &cci);
	SetConsoleTitle("Gluttonous Snake!!!");


}
