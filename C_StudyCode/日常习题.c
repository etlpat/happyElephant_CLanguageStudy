﻿#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>






////int arr[]={1,2,3,4,5,1,2,3,4},找出在数组中只有一个的元素
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,1,2,3,4 };
//	int i, j;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		for (j = 0; j < sz; j++)
//		{
//			if(arr[i] == arr[j] && i != j)
//			{
//				break;
//			}
//			if (j == sz - 1)
//			{
//				printf("%d", arr[i]);
//			}
//		}
//
//	}
//
//	return 0;
//}









//////////////   冒泡排序
//int main()
//{
//	int arr[] = { 2,5,8,4,23,4,57,8,4,31,46,80,1 };
//	int i = 0 , j = 0, x;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz-1; i++)
//	{
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (*(arr + j) > *(arr + j + 1))
//			{
//				int t = *(arr + j);
//				*(arr + j) = *(arr + j + 1);
//				*(arr + j + 1) = t;
//			}
//		}
//
//	}
//	for (x = 0; x < sz; x++)
//	{
//		printf("%d ", *(arr + x));
//	}
//	return 0;
//}









////////////////   设计函数使数组元素逆序
//
//void f(int* arr,int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz / 2 + 1; i++)
//	{
//		int t = *(arr + i);
//		*(arr + i) = *(arr + sz - 1 - i);
//		*(arr + sz - 1 - i) = t;
//	}
//}
//
//void p(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	f(arr,sz);
//	p(arr, sz);
//	return 0;
//}







////////////////   关于相同地址不同类型之间转换的结果
//void main()
//{
//	char a[5] = "1234";
//	short* p;
//	p = (short*)a;
//	printf("%d\n", *p);
//	p++;
//	printf("%d\n", *p);
//}









////////////////    字符串在内存中存储的逆应用
////（char字符串 - 十进制ASCII值 - 十六进制ASCII值（根据系统不同可能会倒过来））
//int main()
//{
//	int a = 5325126;
//	printf("%s", (char*)&a);
//	return 0;
//}







/////////////////        同样大的两数组AB,将数组A中元素和数组B中元素交换
//void swap(int* a, int * b, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz - i; i++)
//	{
//		int t = *(a + i);
//		*(a + i) = *(b + i);
//		*(b + i) = t;
//	}
//}
//
//void p(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int A[] = { 1,2,3,4,5 };
//	int B[] = { 6,7,8,9,0 };
//	int sz = sizeof(A) / sizeof(A[0]);
//	p(A,sz);
//	p(B,sz);
//	swap(A, B,sz);
//	printf("\n");
//	p(A,sz);
//	p(B,sz);
//	return 0;
//}








/////////////////  全局变量不初始化，默认为0
//int i;
//int main()
//{
//	i--;
//	if (i > sizeof(i)) { printf(">"); }
//	if (i < sizeof(i)) { printf("<"); }
//	//【sizeof()】在计算时数值肯定>=0,规定其值为【无符号数】，无符号整型与有符号整型比较时，整形要进行【算术转换】为无符号整形
//	//i原本为-1；转换无符号数后为111111.....1111111，非常大，所以输出>
//	return 0;
//}










////一维数组的动态和
////给你一个数组nums ,数组「动态和」的计算公式为：runningSum[i] = sum(nums[0]…nums[i]) 
////请返回 nums 的动态和。
////示例
////输入：nums = [1, 2, 3, 4]
////输出：[1, 3, 6, 10]
////解释：动态和计算过程为[1, 1 + 2, 1 + 2 + 3, 1 + 2 + 3 + 4] 

//void f(int* arr, int sz)
//{
//	int i = 0, x = 0;
//	for (i = 0; i < sz; i++)
//	{
//		int j;
//		for (j = i, x = 0; j >= 0; j--)
//		{
//			x = x + arr[j];
//		}
//		printf("%d ", x);
//	}
//
//}
//
//int main()
//{
//	int arr[] = { 1,3,5,7,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	f(arr, sz);
//}









////////赎金信
////////给你两个字符串：A和B，判断 B能不能由A里面的字符构成。
////////如果可以，返回 true ；否则返回 false 。
////////A中的每个字符只能在B中使用一次。
////////
////////示例 1：
////////输入：A = "a", B = "b"
////////输出：false
////////
////////示例 2：
////////输入：A = "aa", B = "ab"
////////输出：false
////////
////////示例 3：
////////输入：A = "aa", B = "aab"
////////输出：true

//int com(char* a, char* b, int sza, int szb) {////用于判断a是否含于b的函数
//	int i, j ,m=0 ,n=0;
//	if (sza > szb) {
//		return 0;
//	}
//	else {
//		for (i = 0; i < sza; i++) {
//			m++ ;
//			for (j = 0; j < szb; j++) {
//				if (a[i] == b[j]) {
//					b[j] = '0';
//					n++;
//					break;
//				}
//			}
//		}
//		if (m == n) {
//			return 1;
//		}
//		else {
//			return 0;
//		}
//	}
//}
//
//int main()
//{
//	char A[] = "aabcde";
//	char B[] = "aabcdefgh";
//	char C[] = "abcdefgh";
//	int szA = sizeof(A) / sizeof(A[0]);
//	int szB = sizeof(B) / sizeof(B[0]);
//	int szC = sizeof(C) / sizeof(C[0]);
//
//	int b = com(A, B,szA,szB);
//	if (b == 0) {
//		printf("false\n");
//	}
//	else if (b == 1) {
//		printf("true\n");
//	}
//    int c = com(A, C,szA,szC);
//	if (c == 0) {
//		printf("false\n");
//	}
//	else if (c == 1) {
//		printf("true\n");
//	}
//}









////////统计一个数在内存中中 1 的个数
//
//int num1(int a)//位操作符会把数字在内存中会转成二进制补码计算
//{
//	int i = 0;
//	int n = 0;;
//	for (i = 0; i < 32; i++){
//		if (((1 << i) & a) == (1 << i)) {//这里 == 的优先级大于 & ，不加括号会Bug
//			n++;
//		}
//	}
//	return n;
//}
//
//int num2(unsigned int a)//这里必须把传来的参数变成无符号数，这样才能算负数
////比如-1，按有符号数算，是1000....0001(且最高位还是符号位)，但是按无符号数算是11111....11111
//{
//	int sum = 0; 
//	do {
//		if (a % 2 == 1)
//		{
//			sum++;
//		}
//		a /= 2;
//	} while (a);
//	return sum;
//}
//
//
//int num3(int a)//高级方法，&
//{
//	int i = 0;
//	do {
//		a = a & (a - 1);
//		i++;
//	} while (a);
//
// }
//////解释：
////假设n为26 （11010）
////n=n&(n-1)
////n  = 11010(开始）
////n-1= 11001
////n  = 11000(&1次)
////n-1= 10111
////n  = 10000(&2次)
////n-1= 01111
////n  = 00000(&3次)
//////上述方法
//////因为n-1时，原本最低位处1肯定变为0
//////所以n和(n-1)每&一次，就会消除掉一个最低位的1
//////  &的次数就是1的个数
//
//
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	int n = num1(a);
//	int m = num2(a);
//	int t = num3(a);
//	printf("%d %d %d", n,m,t);
//	return 0;
//}











/////////////////   关于有无符号数与整形提升

//int main()
//{
//	unsigned int a = -1;//-1的补码为1111...1111 //a的值为4294967295
//	int b = -1;                                 //b的值为-1
//	printf("%d\n", a);//打印有符号整形
//	printf("%u\n", a);//打印无符号整形
//	return 0;
//}
//int main()
//{
//	unsigned char a = -12;//a值为244   -12 = 1000 1100(原) - 11110011(反) - 11110100(补)
//	printf("%d", a);
//	return 0;
//}


//int main()
//{
//	char a = -16;  //  10010000 - 11101111 - 11110000
//	unsigned char b = 14;
//	if (a > b) { printf(">"); }
//	else { printf("<"); }//由于整形提升为int 所以比较的时候为有符号数
//}








/////////////////求两个二进制数中不同位的个数

////计算两数补码有几位不同的函数
////由于^，同0异1，所以将两数字相^得到新数字x，之后求x中有几个1即可
//void f(int a, int b)
//{
//	int i = 0;
//	int c = a ^ b;
//	do {
//		c = c & (c - 1);
//		i++;
//	} while (c);
//	printf("有%d位不同\n", i);
//}
//
//int main()
//{
//	int a, b;
//	scanf("%d%d", &a, &b);
//	f(a, b);
//	return 0;
//}










///////////////   分别获取并打印二进制的奇数、偶数位
//
//
//void pri(int a)
//{	
//	int i = 0, sum1 = 0, sum2 = 0;
//	printf("奇数");
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d", (a >> i) & 1);
//	}
//	printf("\n偶数");
//	for (i = 31; i >=0; i-=2)
//	{
//		printf("%d", (a >> i) & 1);
//	}
//	printf("\n");
//
//}
//
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	pri(a);
//
//	return 0;
//}










////////////////         乘法口诀表，输入9就是9*9口诀表，输入12就是12*12口诀表

//void pri(int x)
//{
//	int i, j;
//	for (i = 1; i <= x; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%2d*%-2d=%-3d  ", i, j, i * j);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int x;
//	scanf("%d", &x);
//	pri(x);
//	return 0;
//}










/////////////////    递归实现字符串内容逆序
//
//char f(char* arr, int start, int end)//用来逆序的函数
//{
//	//步骤：1.a和f的交换  2.逆序bcde
//	char t = *(arr + start);
//	*(arr + start) = *(arr + end);
//	*(arr + end) = t;
//	if (start + 1 >= end - 1)
//	{
//		return 0;
//	}
//	f(arr, start + 1, end - 1);
//}
//
//void f2(char* arr)
//{
//	char t = arr[0];
//	int len = strlen(arr);
//	arr[0] = arr[len - 1];
//	arr[len - 1] = '\0';
//	if (strlen(arr + 1) >= 2) {
//		f2(arr + 1);
//	}
//	arr[len - 1] = t;
//}
//
//int main()
//{
//	int i;
//	char arr[] = "abcdef";
//	int a = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz - 1; i++)
//	{
//		printf("%c", arr[i]);
//	}
//	printf("\n");
//	f(arr, a, sz - 2);
//	for (i = 0; i < sz - 1; i++)
//	{
//		printf("%c", arr[i]);
//	}
//	printf("\n");
//	f2(arr);
//	for (i = 0; i < sz - 1; i++)
//	{
//		printf("%c", arr[i]);
//	}
//	return 0;
//}













/////////////////       用函数实现一个某数的某次方运算

//double f(int a, int x)//实现将某个数次方的函数
//{
//	if (x > 0)
//	{
//		return a * f(a,x-1);
//	}
//	else if (x == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		return (1.0 / (a * f(a, -(x + 1))));
//	}
//}
//
//int main()
//{
//	int a, x;
//	scanf("%d%d", &a, &x);
//	double y = f(a, x);
//	printf("%.4lf", y);
//	return 0;
//}













//////////////////     用递归和循环函数分别实现斐波那契数列 
//////////////////     1 1 2 3 5 8

//int f1(int a)//实现求某位斐波那契数的函数
//{
//	if (a == 1 || a == 2)
//	{
//		return 1;
//	}
//	else
//	{
//		return f1(a - 1) + f1(a - 2);
//	}
//}
//
//int f2(int t)
//{
//	int i = 1;
//	int a = 1, b = 1, c = 2;
//	if (t == 1 || t == 2)
//	{
//		return 1;
//	}
//	for (i = 0; i < t-3; i++)
//	{
//		a = b;
//		b = c;
//		c = a + b;
//	}
//	return c;
//}
//
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	int b = f1(a);
//	printf("\n%d\n", b);
//	int c = f2(a);
//	printf("%d\n", c);
//
//	return 0;
//}










///////////// 将数字变成 0 的操作次数
//
//////给你一个非负整数 num ，请你返回将它变成 0 所需要的步数。 如果当前数字是偶数，你需要把它除以 2 ；否则，减去 1 。
//////
//////示例 1：
//////输入：num = 14
//////输出：6
//////解释：
//////步骤 1) 14 是偶数，除以 2 得到 7 。
//////步骤 2） 7 是奇数，减 1 得到 6 。
//////步骤 3） 6 是偶数，除以 2 得到 3 。
//////步骤 4） 3 是奇数，减 1 得到 2 。
//////步骤 5） 2 是偶数，除以 2 得到 1 。
//////步骤 6） 1 是奇数，减 1 得到 0 。
//// 
//////示例 2：
//////输入：num = 8
//////输出：4
//////解释：
//////步骤 1） 8 是偶数，除以 2 得到 4 。
//////步骤 2） 4 是偶数，除以 2 得到 2 。
//////步骤 3） 2 是偶数，除以 2 得到 1 。
//////步骤 4） 1 是奇数，减 1 得到 0 。
//
//int num(int a)
//{
//	int m = 0;
//	while (a)
//	{
//		if (0 == a % 2)
//		{
//			a /= 2;
//		}
//		else
//		{
//			a -= 1;
//		}
//		m++;
//	}
//	return m;
//}
//
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	int n = num(a);
//	printf("所需要的步骤为%d\n", n);
//	return 0;
//}













//////最富有客户的资产总量
//
//////给你一个 m x n 的整数网格 accounts ，其中 accounts[i][j] 是第 i​​​​​​​​​​​​ 位客户在第 j 家银行托管的资产数量。返回最富有客户所拥有的 资产总量 。
//////客户的 资产总量 就是他们在各家银行托管的资产数量之和。最富有客户就是 资产总量 最大的客户。
//
//////示例 1：
//////输入：accounts = [[1, 2, 3], [3, 2, 1]]
//////输出：6
//////解释：
//////第 1 位客户的资产总量 = 1 + 2 + 3 = 6
//////第 2 位客户的资产总量 = 3 + 2 + 1 = 6
//////两位客户都是最富有的，资产总量都是 6 ，所以返回 6 。
// 
//////示例 2：
//////输入：accounts = [[1, 5], [7, 3], [3, 5]]
//////输出：10
//////解释：
//////第 1 位客户的资产总量 = 6
//////第 2 位客户的资产总量 = 10
//////第 3 位客户的资产总量 = 8
//////第 2 位客户是最富有的，资产总量是 10

//#include<stdlib.h>
//void scanarr(int arr[3][3])
//{
//	int i = 0, j =0;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			printf("请输入arr[%d][%d]=", i, j);
//			scanf("%d", &arr[i][j]);
//			system("cls");
//		}
//	}
//}
//
//void priarr(int arr[3][3])
//{
//	int i, j;
//	for (i = 0; i < 3; i++)
//	{
//		printf("第%d个人: ", i + 1);
//		for (j = 0; j < 3; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int judge(int arr[3][3])
//{
//	int i, j, n;
//	int a = 0;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0, n = 0; j < 3; j++)//n为每个人的总资产
//		{
//			n += arr[i][j];
//		}
//		printf("\n第%d个人总资产为%d\n", i + 1, n);
//		if (n > a)//讲资产最多的赋给a
//		{
//			a = n;
//		}
//	}
//	return a;
//}
//int main()
//{
//	int arr[3][3] = { 0 };
//	scanarr(arr);
//	priarr(arr);
//	int num = judge(arr);
//	printf("\n最多资产为%d\n", num);
//	return 0;
//}














/////////////写一个函数逆序字符串的内容
//#include<string.h>
//#include<assert.h>
//void f(char* arr, int sz)//逆序字符串的函数
//{
//	assert(arr != NULL);
//	int left = 0, right = sz - 1;
//	while (left < right)
//	{
//		char tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	char arr[81] = {0};
//	//scanf("%s", &arr);//scanf输入字符串不读取空格
//	gets(arr);//库函数gers():读取一行
//	int sz = strlen(arr);
//	f(arr, sz);
//
//	//打印
//	int i;
//	for (i = 0; i < sz; i++)
//		printf("%c", arr[i]);
//	return 0;
//}
////
//////scanf输入%s字符串时的注意点
////// 1.留'\0'的位置
////// 若向 char arr[10]中用scanf输入字符串，只能输入9个字符，给'\0'留一个位置
////// 2.空格问题
////// 例如：scanf输入字符串时，总是在字符处停止扫描，如输入‘I am a student’，输出只为‘I’
////// 原因：scanf输入字符串的时候不会接收Space空格，回车Enter，Tab键，则认为输入结束。scanf函数直接从输入缓冲区中取数据，而并非从键盘(也就是终端)缓冲区读取。
//////
//////解决方法
//////方法一：输入多个字符串，中间空格隔开
//////方法二：get_s()替代scanf_s()；
////
////
////
////////# include <stdio.h>
////////char* gets(char* str);
//////上面是gets函数的头文件和声明
//////scanf传参时直接传char*类型的地址，一般为字符串的首元素地址（数组名）










//////打印 1-10000 间所以的自幂数
//////如果在一个固定的进制中，一个n位自然数等于自身各个数位上数字的n次幂之和，则称此数为自幂数。
//////例如：在十进制中，153是一个三位数，各个数位的3次幂之和为1 ^ 3 + 5 ^ 3 + 3 ^ 3 = 153，所以153是十进制中的自幂数。
//////在n进制中，所有小于n的正整数都为自幂数，比如2进制中1是自幂数，3进制中1和2都是自幂数，4进制中1，2和3都是自幂数......
//#include <math.h>
//int f(int i)//计算位数的函数
//{
//	int a = 0;
//	do
//	{
//		a++;
//	}while (i /= 10);
//	return a;
//}
//
//int main()
//{
//	int i;
//	for (i = 1; i <= 100000; i++)
//	{
//		int a = f(i);//计算位数的函数
//		int sum = 0, j, t = i;
//		for (j = 0; j < a; j++)//用sum将每一位数次方和加起来
//		{
//			//int n,x=1;
//			//for (n = 0; n < a; n++)//某一位的次方
//			//{
//			//	x *= t % 10;
//			//}
//			int x ;
//			x = pow(t % 10, a);//求次方的函数 pow(x,3)就是x的三次方
//
//			sum += x;
//			t /= 10;
//		}
//		if (i == sum)//判断是否符合
//		{
//			printf("%d ", sum);
//		}
//	}
//	return 0;
//}
////////上面求次方的时候可以用库函数pow
//////// 次方pow和开发sqrt一样，头文件是math.h
//////// pow(底数，次方数)，返回其次方运算后的值--double类型
//////// sum += pow(t%10,a);，警告 从“double”转换到“int”，可能丢失数据，可以强制类型转换为(int)














///////////打印菱形
//
////    *      //  n   1    n
////   ***     // n-1  3   n-1
////  *****    // n-2  5   n-2
//// *******   // ...  .  ...
////*********  //n-n  2n+1 n-n
//// *******
////  *****
////   ***
////    *
//
//void pri1(int n)//打印上一半 加中间一行
//{
//	int i;
//	int x = (n - 1) / 2;
//	for (i = 0; i < (n - 1) / 2 + 1; i++, x--)//打印(n-1)/2行
//	{
//		int j;
//		for (j = 0; j < x; j++)//每行打印的图形
//		{
//			printf(" ");
//		}
//		for (j = 0; j < n - 2 * x; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//}
//
//void pri2(int n)//打印下一半加中间
//{
//	int i;
//	int x = 1;
//	for (i = 0; i < (n - 1) / 2 && n - 2 * x>0; i++, x++)//打印(n-1)/2行
//	{
//		int j;
//		for (j = 0; j < x; j++)//每行打印的图形
//		{
//			printf(" ");
//		}
//		for (j = 0; j < n - 2 * x; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int n;
//	printf("输入一个奇数来确定菱形的大小：>");
//	do {
//		scanf("%d", &n);
//		if (n > 0){
//			if (n % 2 == 0) {
//				printf("您输入的是偶数，请重新输入:>");
//			}
//		}
//		else {
//			printf("输入非法，请重新输入:>");
//		}
//	} while (n % 2 != 1);
//	pri1(n);
//	pri2(n);
//
//	return 0;
//}















////////喝汽水，一瓶1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少瓶
//
//////法1
////int main()
////{
////	int money;
////	scanf("%d", &money);
////	int full = money;//满瓶汽水
////	int hollow = 0;//空瓶汽水
////	int n = 0;
////	while (full>0)//最终结果只可能是1空瓶，0满瓶；只要没喝完就执行循环
////	{
////		hollow += full;//喝汽水，空瓶==之前的空瓶加这次喝的满瓶
////		n += full;//记录一共的满瓶气水数
////		full = 0;//满瓶喝完成空瓶
////		full = hollow / 2;//交换后的满瓶数
////		hollow %= 2;//交换后的空瓶数
////	}
////	printf("%d", n);
////	return 0;
////}
//
//
////////法2
////int main()
////{
////	int money = 0;
////	int total = 0;//计数器
////	int empty = 0;
////	scanf("%d", &money);
////	//买回来的汽水喝掉
////	total = money;
////	empty = money;
////	//换回来的汽水喝掉
////	while (empty >= 2)
////	{
////		total += empty / 2;//每一次换后喝掉的
////		empty = empty / 2 + empty % 2;//每一次剩的全部空瓶
////	}
////	printf("%d", total);
////	return 0;
////
////}
//
//
//////法3：从价值交换的角度来说，2块买4个空瓶，3块买6个空瓶，可以0.5元等价1空瓶；最后手里肯定剩1空瓶
//////所以假设n块，相当于买2n给空瓶，剩1个不能换，实际喝2n-1个












/////////////设置一个函数调整数组内容，把奇数全放在数组前面，偶数放奇数后面
//
//////方法1：插入法，寻找从左到右奇数，插入到第一个偶数前面,奇数偶数整体顺序不变
////void swap(int *a1,int *a2)
////{
////	int tmp = *a1;
////	*a1 = *a2;
////	*a2 = tmp;
////}
////
////void transform(int* arr, int i, int j)//把偶偶偶奇，奇搬运到最前面，变成奇偶偶偶的函数
////{
////	int a;
////	for (a = j; a > i; a--)
////	{
////		swap(&arr[a], &arr[a - 1]);
////	}
////}
////
////void f(int* arr, int sz)//1,3,5,2,4,6,7,8,9,10
////{
////	int i = 0, j = 0;
////	for (i = 0; i < sz; i++)
////	{
////		if (arr[i] % 2 == 0)//假如这个数是偶数
////		{
////			for (j = i + 1; j < sz; j++)//找到偶数后面第一个奇数
////			{
////				if (arr[j] % 2 != 0) {
////					transform(arr, i, j);//偶偶偶奇->奇偶偶偶
////					break;
////				}
////			}
////		}
////	}
////}
////
////int main()
////{
////	int arr[] = { 1,1,2,3,3,4,5,6,7,8,8,9,0,0 };
////	int sz = sizeof(arr) / sizeof(arr[0]);
////
////	f(arr, sz);
////	int i;
////	for (i = 0; i < sz; i ++ )
////		printf("%d ", arr[i]);
////	return 0;
////}
//
//
//
//
////////方法2：双指针，左找偶，右找奇，两交换//简单但是奇偶和原来顺序不一致
////
////void swap(int *a1,int *a2)
////{
////	int tmp = *a1;
////	*a1 = *a2;
////	*a2 = tmp;
////}
////
////void f(int arr[], int sz)//将数字改成左奇右偶的函数
////{
////	int left = 0;
////	int right = sz - 1;
////	for (; left < right; left++, right--)
////	{
////		int i = left, j = right;
////		//左边找偶数
////		while (i < j && arr[i] % 2 == 1) {
////			i++;
////		}
////		//右边找奇数
////		while (j > i && arr[j] % 2 == 0) {
////			j--;
////		}
////		swap(&arr[i], &arr[j]);
////	}
////}
////
////int main()
////{
////	int arr[] = { 1,1,1,1,3,3,2,3,3,4,5,6,7,8,8,9,0,0,1,1,1,1,1,2 };
////	int sz = sizeof(arr) / sizeof(arr[0]);
////	f(arr, sz);
////
////	int i;
////	for (i = 0; i < sz; i++)
////		printf("%d ", arr[i]);
////
////	return 0;
////}










////////打印杨辉三角
////    1
////   1 1
////  1 2 1
//// 1 3 3 1
////1 4 6 4 1
////.............
////1| 1
////2| 1 1
////3| 1 2 1
////4| 1 3 3 1
////5| 1 4 6 4 1
//
//#define MAX 10
//int main()
//{
//	int arr[MAX][MAX] = { 0 };
//	int n = 0;
//	for (n = 0; n < MAX; n++)//先把第一列和每行最后一个都变成1
//	{
//		arr[n][0] = 1;
//		arr[n][n] = 1;
//	}
//	int i,j;
//	for (i = 0; i < MAX; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			if (arr[i][j] != 1)
//			{
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];//每个值等于左上的值+上面的值
//			}
//		}
//	}
//
//	int k;
//	for (i = 0; i < MAX; i++)
//	{
//		for (k = 0; k < MAX - i - 1; k++) {//用空格把∟三角形变成等腰的
//			printf("  ");
//		}
//		for (j = 0; j <= i; j++)
//		{
//			printf("%3d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//
//
//	return 0;
//}














//////猜凶手
////4个嫌疑犯中有一个凶手
////A：不是我
////B：是C
////C：是D
////D：C在胡说
//////三个人是真话，一个人是假话


//int main()
//{
//	char killer;
//	for (killer = 'a'; killer <= 'd'; killer++)//killer循环从a到d
//	{
//		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)//假如4个条件有3个真，一个假，加起来结果是3
//		{
//			printf("%c\n", killer);
//		}
//	}
//}


//int main()//死方法
//{
//	int A, B, C, D;
//	A = 1, B = 0, C = 0, D = 0;
//	if (C == 1 && D == 1 && D == 0)
//		printf("A");
//	A = 0, B = 1, C = 0, D = 0;
//	if (A == 0 && D == 1 && D == 0)
//		printf("B");
//	A = 0, B = 0, C = 1, D = 0;
//	if (A == 0 && C == 1 && D == 0)
//		printf("C");
//	A = 0, B = 0, C = 0, D = 1;
//	if (A == 0 && C == 1 && D == 1)
//		printf("D");
//}












//////猜名次
/////////5名运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
//////A选手说：B第2, A第3
//////B选手说：B第2，E第4
//////C选手说：C第1，D第2
//////D选手说：C第5，D第3
//////E选手说：E第4，A第1
//////比赛后，没人只说对一半，求名次
//
//int main()//穷举法+善用真为1假为0
//{
//	int a, b, c, d, e;
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//						if ((b == 2) + (a == 3) == 1 &&
//							(b == 2) + (e == 4) == 1 &&
//							(c == 1) + (d == 2) == 1 &&
//							(c == 5) + (d == 3) == 1 &&
//							(e == 4) + (a == 1) == 1 &&
//							(a * b * c * d * e == 120))//保证每个名次只有一个人
//						{
//							printf("a%d b%d c%d d%d e%d\n", a, b, c, d, e);
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}









////////////////问会输出什么？
//int main()
//{
//	char arr1[] = "hello";
//	char arr2[] = "hello";
//	char *a1 = "hello";
//	char *a2 = "hello";
//	if (arr1 == arr2)//两数组值相同，但是首元素地址不同
//	{
//		printf("1");
//	}
//	if (a1 == a2)//俩是常量字符串，首元素地址相同；指针a1 a2的地址不同
//	{
//		printf("2");
//	}
//	return 0;
//}







/////////////////把一个数分解为素数的乘机
////
////int f(int i)//判断i是否为素数，是则返回1的函数
////{
////	int j ,n=1;
////	for (j = 2; j < i; j++)
////	{
////		if (i % j == 0)
////		{
////			n=0;
////		}
////	}
////	return n;
////}
////
////int main()
////{
////	int i, n, a = 1;
////	scanf("%d", &n);
////	while (1)//通过循环把偶数变为奇数
////	{
////		if (n % 2 == 0)
////		{
////			n /= 2;
////			printf("2 ");
////		}
////		else 
////			break;
////	}
////	for (i = 2; i <= n; i++)//寻找一个数的素数之积
////	{
////
////		while (n%i==0&&f(i)==1)
////		{
////			printf("%d ", i);
////			n /= i;
////		}
////
////		if (n== 1)
////		{
////			printf("ok");
////			break;
////		}
////	}
////	return 0;
////}









//////////////////请问输出结果是什么
//int main()
//{
//	int a[5] = { 5,4,3,2,1 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));//4,1
//	return 0;
//}









////////////实现一个函数，可以左旋字符串中k个字符
////////例如：abcd左旋一个字符得到bcda
////////      abcd左旋两个字符得到cdab
//#include<string.h>
//#include<assert.h>
//
//void f1(char arr[],int num)//数组，交换字符个数   
//{
//	int a;
//	for (a = 0; a < num; a++)//交换几个字符
//	{
//		int i;
//		for (i = 0; i < strlen(arr)-1; i++)//循环操作把第一个交换到最后一个
//		{
//			char tmp = arr[i];
//			arr[i] = arr[i + 1];
//			arr[i + 1] = tmp;
//		}
//	}
//}
//
////挑战用递归实现该函数
//void f2(char arr[], int num)//左旋mun个字符的函数
//{
//	if (num > 0) {
//		int i;
//		for (i = 0; i < strlen(arr)-1; i++)//循环操作把第一个交换到最后一个
//		{
//			char tmp = arr[i];
//			arr[i] = arr[i + 1];
//			arr[i + 1] = tmp;
//		}
//		f(arr, num - 1);
//	}
//}
//
//
/////////三步转换法
////// abcdef
////// ba fedc //将想num前后字符串各自翻转
////// cdefba  //再将整体字符串反转
//
//void reverse(char* left, char* right)
//{
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//void f3(char* arr, int num)
//{
//	assert(arr);
//	assert(num < strlen(arr));
//	reverse(arr, arr + num - 1);//先逆序想左旋的num个字符串
//	reverse(arr + num, arr + strlen(arr) - 1);//再逆序剩下的字符串
//	reverse(arr, arr + strlen(arr) - 1);//将逆序的结果整体逆序
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	f3(arr, 3);
//	printf("%s", arr);
//	return 0;
//}














//////////给定一个字符串2是否是由字符串1旋转的得到的。
//////////如果是请输出：“是旋转得来的。” ；不是请输出：“不是旋转得来的。”
//////////例：
//////////字符串1：ABCDEFG
//////////字符串2：EFGABCD
//////////字符串2 是否是由 字符串1 旋转得到的。（旋转即为上一个字符串左旋或右旋n个后的结果）
//////////结果：是旋转得来的。
//#include<string.h>
//#include<assert.h>
//#define MAX 20
//
//
//
////////1.遍历法
////int cmp(char* ch1, char* ch2)//比较字符串的函数
////{
////	int a = 1;
////	while (*ch1)
////	{
////		if (*ch1 != *ch2) {
////			a = 0;
////			break;
////		}
////		ch1++;
////		ch2++;
////	}
////	return a;
////}
////
////void reverse(char* left, char* right)
////{
////	while (left < right)
////	{
////		char tmp = *left;
////		*left = *right;
////		*right = tmp;
////		left++;
////		right--;
////	}
////}
////
////void f(char* ch, int num)//左旋n个字符的函数
////{
////	assert(ch);
////	assert(num <= strlen(ch));
////	reverse(ch, ch + num - 1);
////	reverse(ch + num , ch + strlen(ch)-1);
////	reverse(ch, ch + strlen(ch)-1);
////}
////
////int judge(char* ch1, char* ch2)
////{
////	if (strlen(ch1) != strlen(ch2))
////	{
////		printf("不是旋转得来的\n");
////		return 0;
////	}
////		int i,a=0;
////	for (i = 0; i < strlen(ch1); i++)//左旋i次,每次旋转1个字符
////	{
////		f(ch1, 1);
////		if (1 == cmp(ch1, ch2))//比较两字符串是否相等
////		{
////			printf("是旋转得来的\n");
////			return 1;
////		}
////	}
////		printf("不是旋转得来的\n");
////		return 0;
////}
////
////int main()
////{
////	char ch1[MAX];
////	char ch2[MAX];
////	gets(ch1);
////	gets(ch2);
////	judge(ch1, ch2);
////	return 0;
////}
//
// 
// 
//
////////2.追加法(自己实现追加)
////
////int cmp(char* arr, char* ch,int len)//计较函数，若arr内包含ch，返回1，否则返回0
////{
////	int i, j;
////	for (i = 0; i < len+1; i++)
////	{
////		int a = 1;
////		for (j = 0; j < len; j++)
////		{
////			if (*(arr + i + j) != *(ch + j)){
////				a = 0;
////				break;
////			}
////		}
////		if (a == 1) {
////			return 1;
////		}
////	}
////	return 0;
////}
////
////int judge(char* ch1, char* ch2)
////{
////	assert(ch1);
////	assert(ch2);
////	if (strlen(ch1) != strlen(ch2)) {
////		printf("不是旋转得来的\n");
////		return 0;
////	}
////	int len = strlen(ch2);
////
////
////	char arr[2 * MAX] = { 0 };
////	int i, j;
////	for (i = 0,j = 0; i < 2 * len; i++, j++)
////	{
////		if (j == len) {
////			j = 0;
////		}
////			*(arr + i) = *(ch1 + j);
////	}
////	*(arr + 2 * len) == '\0';
////	
////
////	if (1 == cmp(arr, ch2, len)){
////		printf("是旋转得来的\n");
////	}
////	else {
////		printf("不是旋转得来的\n");
////	}
////}
////
////int main()
////{
////	char ch1[MAX];
////	char ch2[MAX];
////	gets(ch1);
////	gets(ch2);
////	judge(ch1, ch2);
////	return 0;
////}
//
//
//
//
//////////////////////////////////库函数知识点补充
//
//////// strcat （追加字符串）
//////// char *strcat( char *strDestination, const char *strSource );
//////// 
////////int main()//这样把arr2追加到arr1后面，arr1内容变成abcdef
////////{
////////	char arr1[30] = "abc";
////////	char arr2[] = "def";
////////	strcat(arr1, arr2);//----------------strcat(被追加的字符串,追加的字符串)；但是不可以自己追加自己
////////	printf("%s\n", arr1);//abcdef
////////}
////////
//////// 自己给自己追加，程序会崩溃，原因是strcat会把要 arr2从首字符开始，倒\0为止，追加到 arr1后边，其中arr2 的首字符会代替arr1的\0；
//////// 若是自己追加到自己后面，自己的首字符会先覆盖掉自己的\0，导致无法停止，程序崩溃
//
//
//////// strncat (追加字符串)
//////// char *strncat( char *strDest, const char *strSource, size_t count );
//////// 因为参数中有具体追加个数，所以不用管\0的问题，可以自己追加自己
//
//////// strstr （在字符串中找它的子字符串）函数
//////// char *strstr( const char *string, const char *strCharSet );
//////// 如果子字符串存在，则返回其在母字符串中对应的首字符地址；否则返回NULL
//
//
//
//
//////// 3.追加法（库函数实现）//笔试时，能用库函数就用库函数
////#include<string.h>
////int is_left_move(char* str1, char* str2)//判断是否为旋转的来的函数
////{
////	int len1 = strlen(str1);
////	int len2 = strlen(str2);
////	if (len1 != len2) {
////		return 0;
////	}
////
////	//1.在str1字符串后面追加一个str1,用strncat，不能用strcat
////	strncat(str1, str1, len1);
////
////	//2.判断str2是否为str1的子字符串，用strstr，找子串库函数
////	char* ret = strstr(str1, str2);
////	if (ret == NULL) {
////		return 0;
////	}
////	else {
////		return 1;
////	}
////}
////
////int main()
////{
////	char ch1[MAX];
////	char ch2[MAX];
////	gets(ch1);
////	gets(ch2);
////	
////	int ret = is_left_move(ch1, ch2);
////	if (ret == 1) {
////		printf("是旋转得来的\n");
////	}
////	else {
////		printf("不是旋转得来的\n");
////	}
////	return 0;
////}














///////////////////杨氏矩阵
//////有一个数字矩阵，矩阵的每行从左到右，从上到下是递增的，请编写程序在这样的矩阵中找到某个数字是否存在
//////要求：时间复杂度小于o(N)//若是数组有N个元素，最坏的情况是寻找N次，时间复杂度就是o(N)
//////所以说不能用遍历法
//
//
//////法1：普通法
////int search_hang(int* arr,int a)
////{
////	int left = 0;
////	int right = 4;
////	while (left <= right)//二分查找，注意有的情况右==左
////	{
////		int mid = (left + right) / 2;
////		if (arr[mid] < a) {
////			left = mid + 1;
////		}
////		if (arr[mid] > a) {
////			right = mid - 1;
////		}
////		if (arr[mid] == a) {
////			return 1;
////		}
////	}
////	return 0;
////}
////
////int search(int arr[][5], int a)
////{
////	if(arr[0][0] > a || arr[4][4] < a) {
////		return 0;
////	}
////	int high = 0;
////	while (high<=4)//从↗一行一行往下找
////	{
////		if (arr[high][4] >= a) {
////			return search_hang(arr[high],a);
////		}
////		high++;
////	}
////	return 0;
////}
////
////int main()
////{
////	int arr[5][5] = { {1,2,3,4,5},{4 ,5 ,6 ,7 ,8},{7 ,8 ,9 ,10,11},{9 ,10,11,12,13},{11,12,13,14,15} };
////	// 1 ,2 ,3 ,4 ,5
////	// 4 ,5 ,6 ,7 ,8
////	// 7 ,8 ,9 ,10,11
////	// 9 ,10,11,12,13
////	// 11,12,13,14,15
////	int a;
////	scanf("%d", & a);
////	int t =search(arr, a);
////	if (t == 1) {
////		printf("有");
////	}
////	else {
////		printf("没有");
////	}
////
////}
//
//
//
//
//
//
//////法2（一次循环去掉一行或一列，从右上角从左上角寻找的方法）
//
//int search(int arr[][5], int a, int* px, int* py)
//{
//	int x = 0;
//	int y = *py;
//	////int arr[x][y]是右上角元素坐标
//
//	while (x <= *px && y >= 0)//从右上角从左下角收缩范围
//	{
//		if (arr[x][y] > a) {
//			y--;
//		}
//		else if (arr[x][y] < a) {
//			x++;
//		}
//		else if (arr[x][y] == a) {
//			*px = x;//这样可以把最终的行列传回主函数
//			*py = y;
//			return 1;
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	int arr[5][5] = { {1,2,3,4,5},{4 ,5 ,6 ,7 ,8},{7 ,8 ,9 ,10,11},{9 ,10,11,12,13},{11,12,13,14,15} };
//	int a;
//	int x = 4, y = 4;
//	scanf("%d", &a);
//	// 1 ,2 ,3 ,4 ,5
//	// 4 ,5 ,6 ,7 ,8
//	// 7 ,8 ,9 ,10,11
//	// 9 ,10,11,12,13
//	// 11,12,13,14,15
//
//	//这个 x y 地址，既有传入的作用，又有传出的作用 ----- 故称为返回型参数
//	int t = search(arr, a, &x, &y);
//	if (t == 1) {
//		printf("有,下标为 %d,%d",x,y);
//	}
//	else {
//		printf("没有");
//	}
//}




















////题目描述:输入一个字符串，输出反序后的字符串。
//
//#include<stdio.h>
//#include<string.h>
//
//char* f(char* start, char* end)
//{
//    char* ret = start;
//    while (start < end)
//    {
//        char tmp = *start;
//        *start = *end;
//        *end = tmp;
//        start++;
//        end--;
//    }
//    return ret;
//}
//int main(void)
//{
//    char arr[50] = { 0 };
//    gets(arr);
//    int sz = strlen(arr);
//    char* a = f(arr, arr + sz - 1);
//    printf("%s", arr);
//    return 0;
//}



















/////题目描述:对于给定的一个字符串，统计其中数字字符出现的次数。
//
//#include<stdio.h>
//#include<string.h>
//#include<ctype.h>
//int main(void)
//{
//	int t;
//	scanf("%d", &t);
//	getchar();
//	while (t--)
//	{
//		int n = 0;
//		char arr[50] = { 0 };
//		gets(arr);
//		int i = 0;
//		for (i = 0; i < strlen(arr); i++)
//		{
//			if (isdigit(arr[i]))
//				n++;
//		}
//		printf("%d\n", n);
//	}
//	return 0;
//}















////题目描述:输入两个字符串a和b，将b串中的最大字符插入到a串中最小字符后面。
//
//#include <stdio.h>
//#include <string.h>
//
//char isbig(char* str)
//{
//    char a = str[0];
//    while (*str++)
//    {
//        if (*str > a)
//        {
//            a = *str;
//        }
//    }
//    return a;
//}
//
//char* issmall(char* str)
//{
//    char a = str[0];
//    char* pa = str;
//    while (*str)
//    {
//        if (*str < a)
//        {
//            a = *str;
//            pa = str;
//        }
//        str++;
//    }
//    return pa;
//}
//
//char* f(char* str, char a)
//{
//    char* ret = str;
//    char* pa = issmall(str);
//    char* p = pa;
//    int num = strlen(p);
//    p += num;
//    while (num--)
//    {
//        *p = *(p - 1);
//        p--;
//    }
//    *(pa+1) = a;
//    return  ret;
//}
//
//int main(void)
//{
//    char str1[100] = { 0 };
//    char str2[100] = { 0 };
//    gets(str1);
//    gets(str2);
//    char a = isbig(str2);
//    char* p = f(str1, a);
//    printf("%s", p);
//    return 0;
//}















//////题目描述：编写程序，输入字符串s1和s2以及插入位置f，在字符串s1中的指定位置f处插入字符串s2。
//////如输入"BEIJING"， "123"， 3，则输出:"BEI123JING"。
// 
//#include<stdio.h>
//#include<string.h>
//
//char* f(char* dest, char* src, int n)
//{
//	char* ret = dest;
//
//	char* pa = dest + strlen(dest) + strlen(src) - 1;
//	char* pb = dest + strlen(dest) - 1;
//	while (pb >= dest + n)
//	{
//		*pa-- = *pb--;
//	}
//
//	strncpy(dest + n, src, strlen(src));
//	return ret;
//}
//
//int main(void)
//{
//	char str1[200] = { 0 };
//	char str2[100] = { 0 };
//	gets(str1);
//	gets(str2);
//	int n;
//	scanf("%d", &n);
//	char* p = f(str1, str2, n);
//	printf("%s", p);
//	return 0;
//}
















//////题目描述:输入一段字符(由空格、字母和数字几种组成，保证开头不为空格)，里面有若干个字符串，求这些字符串的长度和，
//////        并输出最长字符串内容,如果有多个输出最先出现的那个字符串。以stop作为最后输入的字符串。
//////样例输入：
//////My name is Amy
//////My name is Jane
//////stop
//////样例输出：
//////11 name
//////12 name
//////提示：
//////字符串长度不超过100。
//
//#include<stdio.h>
//#include <string.h>
//int main(void)
//{
//	while (1)
//	{
//		char a[100] = { 0 };
//		gets(a);
//		char* arr = a;
//		if (strcmp(arr, "stop") == 0)
//		{
//			break;
//		}
//		char* p = NULL;char* tmp = NULL;
//		int sum = 0, n = 0, ntmp = 0;
//		while (*arr)
//		{
//			ntmp = 0;
//			while (*arr && (*arr == ' '))
//			{
//				arr++;
//			}
//			tmp = arr;
//
//			while (*arr && (*arr != ' '))
//			{
//				ntmp++;
//				arr++;
//			}
//			sum += ntmp;
//			if (n < ntmp)
//			{
//				n = ntmp;
//				p = tmp;
//			}
//		}
//		printf("%d ", sum);
//		for (; *p && *p != ' '; p++)
//		{
//			printf("%c", *p);
//		}
//		puts("");
//	}
//	return 0;
//}


















//////题目描述：输入3行，每行n个字符串，按由小到大的顺序输出
//////样例输入：
//////cde
//////afg
//////abc
//////样例输出：
//////abc
//////afg
//////cde
//
//#include<stdio.h>
//#include<string.h>
//
//
//int main(void)
//{
//	char arr[3][100] = { 0 };
//	int i;
//	for (i = 0; i < 3; i++)
//		gets(arr[i]);
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), strcmp);
//	for (i = 0; i < 3; i++)
//		puts(arr[i]);
//	return 0;
//}
//
//
//void swap(char* e1, char* e2, int width)
//{
//	int i;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *(e1 + i);
//		*(e1 + i) = *(e2 + i);
//		*(e2 + i) = tmp;
//	}
//}
//
//void my_qsort(void* arr, int sz, int width, int(*cmp)(const void* p1, const void* p2))
//{
//	int i, j;
//	for (i = 0; i < sz - 1; i++)
//	{
//		for (j = 0; j < sz - i - 1; j++)
//		{
//			if (cmp(((char*)arr + j * width), ((char*)arr + (j + 1) * width)) > 0)
//			{
//				swap(((char*)arr + j * width), ((char*)arr + (j + 1) * width), width);
//			}
//		}
//	}
//}
//
//int main(void)
//{
//	char arr[3][100] = { 0 };
//	int i;
//	for (i = 0; i < 3; i++)
//		gets(arr[i]);
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	my_qsort(arr, sz, sizeof(arr[0]), strcmp);
//	for (i = 0; i < 3; i++)
//		puts(arr[i]);
//	return 0;
//}















////本关任务:将十个数进行从大到小的顺序进行排列。
//
//#include<stdio.h>
//#include<stdlib.h>
//int cmp_int(const void* p1, const void* p2)
//{
//    return *(int*)p2 - *(int*)p1;
//}
//int main(void)
//{
//    int i = 0;
//    int arr[10] = { 0 };
//    for (i = 0; i < 10; i++)
//    {
//        scanf("%d", arr + i);
//    }
//    qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), cmp_int);
//    for (i = 0; i < 10; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}
















////题目描述:找出具有m行n列二维数组Array的“鞍点”，即该位置上的元素在该行上最大，在该列上最小，其中1<=m,n<=10。
//#include<stdio.h>
//int main()
//{
//    int arr[100][100];
//    int m, n;
//    scanf("%d %d", &m, &n);
//    int i, j;
//    for (i = 0; i < m; i++)
//    {
//        for (j = 0; j < n; j++)
//        {
//            scanf("%d", &arr[i][j]);
//        }
//    }
//    for (i = 0; i < m; i++)
//    {
//        int max = 0, row = 0, col = 0;
//        for (j = 0; j < n; j++)
//        {
//            if (arr[i][j] > max)
//            {
//                max = arr[i][j];
//                row = i;
//                col = j;
//            }
//        }
//        int t = 1, ii = 0;
//        for (ii = 0; ii < m; ii++)
//        {
//            if (arr[ii][col] < max)
//            {
//                t = 0;
//                break;
//            }
//        }
//        if (t)
//        {
//            printf("Array[%d][%d]=%d", row, col, max);
//            return 0;
//        }
//
//    }
//    printf("None");
//    return 0;
//}













////题目描述:输入10个互不相同的整数并保存在数组中，找到该最大元素并删除它，输出删除后的数组
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//    int arr[10] = { 0 };
//    int arr1[9] = { 0 };
//    int i;
//
//    for (i = 0; i < 10; i++)
//        scanf("%d", &arr[i]);
//    int max = arr[0], x = 0;
//    for (i = 1; i < 10; i++)
//    {
//        if (arr[i] > max)
//        {
//            max = arr[i];
//            x = i;
//        }
//    }
//    while (x < 10)
//    {
//        arr[x] = arr[x + 1];
//        x++;
//    }
//    memcpy(arr1, arr, sizeof(arr1));
//    for (int i = 0; i < 9; i++)
//    {
//        printf("%d ", arr1[i]);
//    }
//    return 0;
//}



















////本关任务：编写函数求区间[200,3000]中所有的回文数，回文数是正读和反读都是一样的数。如525, 1551
//
//#include<stdio.h>
//
//int f(int i)
//{
//    int a = i;
//    int n = 1;
//    int sum = 0;
//    int t = 1;
//    while (a /= 10)
//    {
//        n *= 10;
//    }
//    while (n)
//    {
//        sum += (i / n)*t;
//        i %= n;
//        n /= 10;
//        t *= 10;
//    }
//    return sum;
//}
//
//int main()
//{
//    int i;
//    int n = 0;
//    for (i = 200; i <= 3000; i++)
//    {
//        n = f(i);
//        if (n==i)
//        {
//            printf("%d\n", i);
//        }
//    }
//    return 0;
//}














////题目描述:有如下表达式 s = 1 + 1 / 3 + (1 * 2) / (3 * 5) + (1 * 2 * 3) / (3 * 5 * 7) + .... + (1 * 2 * 3 * .... * n) / (3 * 5 * 7 * ... * (2 * n + 1))。
//
//#include<stdio.h>
//
//double f(int n)
//{
//    double up = 1.0, down = 1.0, sum = 1.0; int i;
//    for (i = 1; i <= n; i++)
//    {
//        up *= i;
//        down *= 2 * i + 1.0;
//        sum += up / down;
//    }
//    return sum;
//}
//
//int main(void)
//{
//
//    int n;
//    scanf("%d", &n);
//    double a = f(n);
//    printf("%.10lf", a);
//
//    return 0;
//}
















////题目描述:求Sn=1!+2!+3!+4!+5!+…+n!之值，其中n是一个数字。
//
//#include<stdio.h>
//long long f(int a)
//{
//    long long sum = 0, t = 1;
//    int i;
//    for (i = 1; i <= a; i++)
//    {
//        t *= i;
//        sum += t;
//    }
//    return sum;
//}
//int main(void)
//{
//    int n;
//    scanf("%d", &n);
//    long long a = f(n);
//    printf("%lld", a);
//    return 0;
//}






















////题目描述:两个不同的自然数A和B，如果整数A的全部因子(包括1，不包括A本身)之和等于B；且整数B的全部因子(包括1，不包括B本身)之和等于A，则将整数A和B称为亲密数。求3000以内的全部亲密数。
//
//#include<stdio.h>
//
//int f(int i)
//{
//    int sum = 0, t = 1;
//    for (t = 1; t < i; t++)
//    {
//        if (!(i % t))
//        {
//            sum += t;
//        }
//    }
//    return sum;
//}
//
//int main()
//{
//    int n = 3000;
//    int i, j;
//    for (i = 2; i <= n; i++)
//    {
//        j = f(i);
//        if ((i < j) && (j < n) && (i == f(j)))
//        {
//            printf("(%d,%d)", i, j);
//        }
//    }
//    return 0;
//}






















////题目描述:写两个函数，分别求两个整数的最大公约数和最小公倍数，用主函数调用这两个函数，并输出结果。两个整数由键盘输入。
//
//#include<stdio.h>
//
////编写最大公约数GCD函数
//
//long long f1(long long x, long long y)
//{
//	if (x < y)
//	{
//		long long tmp = y;
//		y = x;
//		x = tmp;
//	}
//	for (long long i = y; i >= 1; i--)
//	{
//		if (x % i == 0 && y % i == 0)
//		{
//			return i;
//		}
//	}
//}
//
////编写最小公倍数LCM函数
//long long f2(long long x, long long y)
//{
//	long long i = 1;
//	while (x * i % y)
//	{
//		i++;
//	}
//	return x * i;
//}
//
//
//int main()
//{
//	long long a, b;
//	scanf("%lld %lld", &a, &b);
//	if (a <= 0 || b <= 0)
//	{
//		printf("Input Error");
//		return 0;
//	}
//	long long t1 = f1(a, b);
//	long long t2 = f2(a, b);
//	printf("%lld %lld", t1, t2);
//	return 0;
//}














//////对比getchar()与_getch()
//#include<conio.h>
//int main()
//{
//	char a = getchar();
//	char b = _getch();//无回显，且输入字符后不用敲回车
//
//	puts("");
//	putchar(a);
//	puts("");
//	putchar(b);
//
//	return 0;
//}












////////_kbhit()，判断是否敲键盘，若敲了键盘则返回1
//#include<conio.h>
//#include<time.h>
//int main()
//{
//	while(1)
//	{ 
//		if (_kbhit())
//		{
//			char b = _getch();//无回显，且输入字符后不用敲回车
//			puts("b");
//		}
//		else {
//			puts("1");
//		}
//		Sleep(1000);
//	}
//	return 0;
//}






















//判断语句内置++和外置++的区别
// if(a++ < b++) 和 if (a < b){a++, b++;} 的区别

////【例1】
//int main()
//{
//	int a = 2, b = 1;
//	if (a++ < b++)
//		;
//	printf("%d %d", a, b);//3,2
//	return 0;
//}

////【例2】
//int main()
//{
//	int a = 2, b = 1;
//	if (a < b)
//	{
//		a++, b++;
//	}
//	printf("%d %d", a, b);//2,1
//	return 0;
//}

////////上面发现，无论判断条件是否成立，都要执行判断语句，即内部的++都要执行
////////但是判断条件不成立，内置++【例1】在判断语句中会执行；外置++【例2】不执行