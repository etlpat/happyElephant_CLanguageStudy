#define HANG 3//�ú궨�� HANG LIE ��ԭ��:�����ʵ�ֺ�����ֵ�ĸĶ�
#define LIE 3

#include<stdio.h>
#include<stdlib.h>//cls;rand();srand()
#include<windows.h>//Sleep()
#include<time.h> //time()

//����������
void initchess(char chess[HANG][LIE], int hang, int lie);//������Դ�ļ��еĺ��������������������ڵ�Դ�ļ���
void prichess(char chess[HANG][LIE], int hang, int lie);
void playermove(char chess[HANG][LIE], int hang, int lie);
void computermove(char chess[HANG][LIE], int hang, int lie);
char judge(char chess[HANG][LIE], int hang, int lie);
