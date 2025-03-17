#define _CRT_SECURE_NO_WARNINGS 1



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////第一次
//#include<stdio.h>


////1.	下载并安装C语言编译系统，设置编辑环境。
//// 
////2.	输入并运行第1章例1 - 1和例1 - 2中程序，并记录遇到的问题和解决方法。
//// 
////3.	输入并运行第2章例2 - 5和例2 - 6中程序，理解ASCII字符和ASCII编码。
//// 
////4.	求下面算术表达式的值（先自己分析，再试着用程序求解，比较得到的结果是否一致）。
////⑴设x = 2，a = 7，y = 4，求表达式: x + a % 3 * x + y % 2 / 4 的值
////⑵设a = 2，b = 3，x = 3.5，y = 2.5，求表达式 : (float)(a + b) / 2 + (int)x % (int)y的值
//// 
////5.	写出下面表达式运算后a的值，设原来a = 10，n = 5。设a和n已定义成整型变量（先自己分析，再试着用程序求解，比较得到的结果是否一致）。
////⑴ a += a   ⑵ a -= 2   ⑶ a *= 2 + 3   ⑷ a /= a + a   ⑸ a %= (n %= 2)   ⑹ a += a -= a *= a
//// 
////6.	输入并运行第3章例3 - 3、例3 - 6中的程序，通过输出结果理解对应的格式说明。
//// 
////7.	输入并运行第3章例3 - 8、例3 - 10中的程序，注意输入数据的格式。
//// 
////8.	设计程序，输入一个圆柱体的半径r和高h，求圆柱体的底周长c、底面积s、侧面积s1、表面积s2和体积v。
//
//
//
//
//
////4.	求下面算术表达式的值（先自己分析，再试着用程序求解，比较得到的结果是否一致）。
////⑴设x = 2，a = 7，y = 4，求表达式: x + a % 3 * x + y % 2 / 4 的值
////⑵设a = 2，b = 3，x = 3.5，y = 2.5，求表达式 : (float)(a + b) / 2 + (int)x % (int)y的值


////(1)
//int main()
//{
//	int x = 2, a = 7, y = 4;
//	int t = (x + a % 3 * x + y % 2 / 4);
//	printf("%d", t);
//	return 0;
//}

////(2)
//int main()
//{
//	int a = 2, b = 3;
//	float x = 3.5, y = 2.5;
//	float t = ((float)(a + b) / 2 + (int)x % (int)y);
//	printf("%f", t);
//	return 0;
//}





////////5.	写出下面表达式运算后a的值，设原来a = 10，n = 5。设a和n已定义成整型变量（先自己分析，再试着用程序求解，比较得到的结果是否一致）。
////////⑴ a += a   ⑵ a -= 2   ⑶ a *= 2 + 3   ⑷ a /= a + a   ⑸ a %= (n %= 2)   ⑹ a += a -= a *= a
//
//int f1(int a){
//	return (a += a);
//}
//int f2(int a) {
//	return (a -= 2);
//}
//int f3(int a) {
//	return (a *= 2 + 3);
//}
//int f4(int a) {
//	return (a /= a + a);
//}
//int f5(int a,int n) {
//	return (a %= (n %= 2));
//}
//int f6(int a) {
//	return (a += a -= a *= a);
//}
//
//int main()
//{
//	int a = 10, n = 5;
//	int n1, n2, n3, n4, n5, n6;
//	n1 = f1(a);
//	n2 = f2(a);
//	n3 = f3(a);
//	n4 = f4(a);
//	n5 = f5(a, n);
//	n6 = f6(a);
//	printf("n1=%d\nn2=%d\nn3=%d\nn4=%d\nn5=%d\nn6=%d\n", n1,n2,n3,n4,n5,n6);
//	return 0;
//}





//////8.	设计程序，输入一个圆柱体的半径r和高h，求圆柱体的底周长c、底面积s、侧面积s1、表面积s2和体积v。
//#define pi 3.141592
//
//double C(int r) {
//	return(2 * pi * r);
//}
//double S(int r) {
//	return(r * r * pi);
//}
//
//double S1(int r, int h) {
//	return (2 * pi * r * h);
//}
//
//double S2(int r, int h) {
//	return (2 * r * r * pi + 2 * pi * r);
//}
//
//double V(int r, int h) {
//	return (r * r * pi * h);
//}
//
//
//int main()
//{
//	double r, h;
//	scanf("%lf%lf", &r, &h);
//	double c = C(r, h);
//	double s = S(r, h);
//	double s1 = S1(r, h);
//	double s2 = S2(r, h);
//	double v = V(r, h);
//	printf("c=%lf\ns=%lf\ns1=%lf\ns2=%lf\nv=%lf\n", c, s, s1, s2, v);
//	return 0;
//}























/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////第二次

////1.	输入并运行第3章例3 - 18、例3 - 19中的程序，理解if语句和switch语句控制逻辑。
////2.	输入一百分制成绩，输出成绩等级A、B、C、D、E。90分以上为A，80~89为B，70~79分为C，60~69分为D，60分以下为E。要求程序能处理错误的输入数据。分别用if语句和switch语句实现。
////3.	输入一个不小于3的正整数，判断是否是素数，若是则输出“Yes”，否则输出“No”。
////4.	输入一个正整数，求该整数各位数字的累加和。
////5.	利用公式：π / 4 = 1 - 1 / 3 + 1 / 5 - 1 / 7 + ……，求π的近似值，直到最后一项的绝对值小于10 - 6为止。（fabs(t)表示t的绝对值，1e - 6 = 1 * 10 - 6）。
////6.	用迭代法求： 。迭代公式为： ，设： 。要求前后两次求出的x的差的绝对值小于10 - 6。
////7.	一个数如果恰好等于它的因子之和, 这个数就称为完数。例如，6是完数，因为6 = 1 + 2 + 3。编程求1000之内的所有完数，并按下面格式输出其因子：6 its factors are 1, 2, 3
////8.	在C语言允许的整数范围内验证哥德巴赫猜想，即任意大于6 的偶数都可以表示为两个素数之和，如：100 = 3 + 97。（先思考，在函数实验时实现）


////2，5，6，7



////2.	输入一百分制成绩，输出成绩等级A、B、C、D、E。90分以上为A，80~89为B，70~79分为C，60~69分为D，60分以下为E。要求程序能处理错误的输入数据。分别用if语句和switch语句实现。
//
//#include<stdio.h>
//#include<assert.h>
////1.if
//int main()
//{
//	int t;
//	do {
//		int a;
//		scanf("%d", &a);
//		assert(0 <= a && a <= 100);
//		if (100 >= a && a >= 90) {
//			printf("A\n");
//		}
//		else if (90 > a && a >= 80) {
//			printf("B\n");
//		}
//		else if (80 > a && a >= 70) {
//			printf("C\n");
//		}
//		else if (70 > a && a >= 60) {
//			printf("D\n");
//		}
//		else if (60 > a) {
//			printf("E\n");
//		}
//		printf("是否结束？（0结束，任意键继续）；>");
//		scanf("%d", &t);
//	} while (t);
//	return 0;
//}


////2.switch
//#include<stdio.h>
//#include<assert.h>
////1.if
//int main()
//{
//	int t;
//	do {
//		int a;
//		scanf("%d", &a);
//		assert(0 <= a && a <= 100);
//		a /= 10;
//		switch (a)
//		{
//		case 0:
//		case 1:
//		case 2:
//		case 3:
//		case 4:
//		case 5:
//			printf("E\n");
//			break;
//		case 6:
//			printf("D\n");
//			break;
//		case 7:
//			printf("C\n");
//			break;
//		case 8:
//			printf("B\n");
//			break;
//		case 9:
//		case 10:
//			printf("A\n");
//			break;
//		}
//		printf("是否结束？（0结束，任意键继续）；>");
//		scanf("%d", &t);
//	} while (t);
//	return 0;
//}







//////5.	利用公式：π / 4 = 1 - 1 / 3 + 1 / 5 - 1 / 7 + ……，求π的近似值，直到最后一项的绝对值小于10 - 6为止。（fabs(t)表示t的绝对值，1e - 6 = 1 * 10 - 6）。
//
//#include<stdio.h>
//int main()
//{
//	double sum = 0;
//	double t=1, i;
//	for (i = 1.0; 1.0/i>(1e-6); i += 2.0)
//	{
//		sum += t / i;
//		t = -t;
//	}
//	sum *= 4;
//	printf("%lf", sum);
//	return 0;
//}
//








//////6.	用迭代法求： 。迭代公式为： ，设： 。要求前后两次求出的x的差的绝对值小于10 - 6。
//
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	double a, x, tmp;
//	scanf("%lf", &a);
//	x = a;
//	do
//	{
//		tmp = x;
//		x = (x + a / x) / 2;
//		tmp = fabs(tmp - x);
//
//	} while (tmp > 10e-6);
//	printf("%lf开更号后值为%lf\n", a,x);
//
//	return 0;
//}









//////7.	一个数如果恰好等于它的因子之和, 这个数就称为完数。例如，6是完数，因为6 = 1 + 2 + 3。编程求1000之内的所有完数，并按下面格式输出其因子：6 its factors are 1, 2, 3
//#define MAX 35
//#include<stdio.h>
//
//int main()
//{
//	int i = 1;
//	int arr[MAX] = { 0 };
//	for (i = 1; i < 1000; i++)
//	{
//		int j = 1, n = 0, sum = 0;
//		for (j = 1; j < i; j++)
//		{
//			if (i % j == 0)
//			{
//				arr[n] = j;
//				n++;
//				sum += j;
//			}
//		}
//		if (sum == i)
//		{
//			printf("%d its factors are %d", i,arr[0]);
//			int m;
//			for (m = 1; m <= n-1; m++)
//				printf(", %d", arr[m]);
//			printf("\n");
//		}
//	}
//	return 0;
//}
//
//
//#include<stdio.h>
//
//void pri(char (*arr)[3])
//{
//	int i, j;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			printf("%c", *(*(arr + i) + j));
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	char arr[3][3] = { 'a','b','\0','d','e','\0','g','h','\0'};
//
//	pri(arr);
//}















/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////第三次
// 
////1.	输入10个整型数据，存入数组a中，找出其最大值、最小值及其所在元素的下标。
////2.	有一个已经排好序的数组，要求输入一个数后，按原来排序的规律将它插入数组中。
////3.	输入10个整型数据，存入数组a中，用选择法或冒泡法对数组中的数据从小到大排序。
////4.	输出一个含有10行的杨辉三角形。
////5.	输入一个英文句子，统计句子中单词的个数。
////6.	输入并运行第5章例5 - 1、例5 - 2中的程序，观察输出结果，理解指针变量的用法。
////7.	输入并运行第5章例5 - 5中的程序，掌握使用指针访问数组元素的方法。
////8.	编程序，输入有一个英文句子，将每个单词的第一个字母改为大写。(使用指针)

////////    2，4，5，8




////2.	有一个已经排好序的数组，要求输入一个数后，按原来排序的规律将它插入数组中。
//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,7,8,9,10 };
//	int i = 0, j, x;
//	scanf("%d", &x);
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i] > x) {
//			break;
//		}
//	}
//	memmove(arr + i + 1, arr + i, sizeof(int) * (sz - i - 1));
//	arr[i] = x;
//	for (j = 0; j < sz; j++) {
//		printf("%d ", arr[j]);
//	}
//}







////4.	输出一个含有10行的杨辉三角形。
//#include<stdio.h>
//#define MAX 10
//int main()
//{
//	int arr[MAX][MAX] = { 0 };
//	int n = 0;
//	for (n = 0; n < MAX; n++)
//	{
//		arr[n][0] = 1;
//		arr[n][n] = 1;
//	}
//	int i, j;
//	for (i = 0; i < MAX; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			if (arr[i][j] != 1)
//			{
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//			}
//		}
//	}
//	int k;
//	for (i = 0; i < MAX; i++)
//	{
//		for (k = 0; k < MAX - i - 1; k++) {
//			printf("  ");
//		}
//		for (j = 0; j <= i; j++)
//		{
//			printf("%3d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}




//////5.	输入一个英文句子，统计句子中单词的个数。
//#define MAX 100
//#include<stdio.h>
//#include<ctype.h>
//int main()
//{
//	char arr[MAX] = { 0 };
//	gets(arr);
//	int count = 0, tmp = 0, i;
//	for (i = 0; i < MAX; i++)
//	{
//		if (isalpha(arr[i]))
//		{
//			if (!tmp)
//			{
//				count++;
//			}
//			tmp = 1;
//		}
//		else if (isspace(arr[i]))
//		{
//			tmp = 0;
//		}
//	}
//	printf("%d", count);
//	return 0;
//}






//////8.	编程序，输入有一个英文句子，将每个单词的第一个字母改为大写。(使用指针)
//#define MAX 100
//#include<stdio.h>
//#include<ctype.h>
//
//char* big(char* arr)
//{
//	int tmp = 0, i;
//	for (i = 0; i < MAX; i++)
//	{
//		if (isalpha(arr[i]))
//		{
//			if (!tmp)
//			{
//				arr[i] = toupper(arr[i]);
//			}
//			tmp = 1;
//		}
//		else if (isspace(arr[i]))
//		{
//			tmp = 0;
//		}
//	}
//	return arr;
//}
//
//int main()
//{
//	char arr[MAX] = { 0 };
//	gets(arr);
//	big(arr);
//	puts(arr);
//	return 0;
//}

















/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////第四次
//1.	设计一函数，判断一个字符串是否是回文。“回文”是一种顺序读和反序读都一样的字符串，例如：“121”“abcba” “ABCCBA”。在主函数中输入字符串并输出判断结果。
//2.	编写一个程序，由主函数和如下函数构成。
//⑴设计函数：input()，输入n个无序的整数存储在一个数组中；
//⑵设计函数：sort()，用起泡法对数组中的n各数据从大到小排序；
//⑶设计函数：search()，用折半查找法在已排序的n个数中查找指定的数据，若存在，返回其所处的位置（即下标），否则返回 - 1。
//在主函数中调用上述函数，验证函数的功能。
//3.	设计递归函数，求：  （x≠0，n是整数），在主函数中调用函数，验证函数的功能。
//4.	输入并运行第6章例6 - 27中的程序，根据输出结果总结局部静态变量的特点。
//5.	输入并运行第7章例7 - 1中的程序。理解结构体类型、构体变量和结构体构体的成员。
//6.	编写一个程序实现如下功能：定义一个点的结构数据类型，实现下列功能：
//⑴输入点的坐标值；⑵求两个点的中点坐标；⑶求两点间距离。
//7.	有5个学生，每个学生有3门课的成绩，从键盘输入学生数据（包括学生号，姓名，三门课成绩），计算出平均成绩，将原有数据和计算出的平均分数存放在磁盘文件“stud”中。
//8.	有两个磁盘文件A和B，各存放一行字母，要求把这两个文件中的信息合并（按字母顺序排列），输出到一个新文件C中。






//1.	设计一函数，判断一个字符串是否是回文。“回文”是一种顺序读和反序读都一样的字符串，例如：“121”“abcba” “ABCCBA”。在主函数中输入字符串并输出判断结果。
//
//
//#include<stdio.h>
//#include<string.h>
//#define MAX 100
//
//int f(char* arr, int sz)
//{
//    char* left = arr;
//    char* right = arr + sz - 1;
//    while (left < right)
//    {
//        if (*left++ != *right--) {
//            return 0;
//        }
//    }
//    return 1;
//}
//
//int main()
//{
//    char arr[MAX] = { 0 };
//    gets(arr);
//    int sz = (int)strlen(arr);
//    if (f(arr,sz)) {
//        puts("是");
//    }
//    else {
//        printf("不是");
//    }
//
//    return 0;
//}





















//2.	编写一个程序，由主函数和如下函数构成。
//⑴设计函数：input()，输入n个无序的整数存储在一个数组中；
//⑵设计函数：sort()，用起泡法对数组中的n各数据从大到小排序；
//⑶设计函数：search()，用折半查找法在已排序的n个数中查找指定的数据，若存在，返回其所处的位置（即下标），否则返回 - 1。
//在主函数中调用上述函数，验证函数的功能。





//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//#define MAX 100
//#define __PRI__
//
//int* input(int* pn)
//{
//	int i = 0;
//	printf("请输入数组中有几个元素？");
//	scanf("%d", pn);
//	int* p = (int*)malloc(sizeof(int) * (*pn));
//	if (p == NULL) {
//		puts("堆区空间不足");
//		return NULL;
//	}
//	printf("请输入数组元素：>");
//	for (i = 0; i < *pn; i++)
//	{
//		scanf("%d", p + i);
//	}
//	return p;
//}
//
//void sort(int* p, int n)
//{
//	int i, j;
//	for (i = 0; i < n - 1; i++)
//	{
//		for (j = 0; j < n - i - 1; j++)
//		{
//			if (p[j] < p[j + 1])
//			{
//				int tmp = p[j];
//				p[j] = p[j + 1];
//				p[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//int search(const int* const p, int n)
//{
//	assert(p);
//	int left = 0, right = n - 1, mid, num;
//	printf("请输入想找的数据：>");
//	scanf("%d", &num);
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//		if (num < p[mid]) {
//			right = mid - 1;
//		}
//		else if (num > p[mid]) {
//			left = mid + 1;
//		}
//		else if (num == p[mid]) {
//			return mid;
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	int n;
//	int* p = input(&n);
//	sort(p, n);
//
//#ifdef __PRI__
//	int i;
//	for (i = 0; i < n; i++)
//		printf("%d ", p[i]);
//	puts("");
//#endif
//
//	int ret = search(p, n);
//	printf("返回值为%d\n", ret);
//
//	free(p);
//	p = NULL;
//	return 0;
//}













//3.	设计递归函数，求：  y=x^n（x≠0，n是整数），在主函数中调用函数，验证函数的功能。

//#include<stdio.h>
//
//double f(double x, int n)
//{
//	if (n == 0)
//	{
//		return 1;
//	}
//	else if (n > 0) {
//		return x * f(x, n - 1);
//	}
//	else {
//		return 1 / f(x, -n);
//	}
//}
//
//
//int main()
//{
//	double x; int n;
//	printf("请输入x和n：>");
//	scanf("%lf %d", &x, &n);
//	double num = f(x, n);
//	printf("(%lf)^%d = %lf\n", x, n, num);
//	return 0;
//}









//7.	有5个学生，每个学生有3门课的成绩，从键盘输入学生数据（包括学生号，姓名，三门课成绩），计算出平均成绩，将原有数据和计算出的平均分数存放在磁盘文件“stud”中。

#include<stdio.h>
#include<string.h>
#include<errno.h>

typedef struct stu
{
	int num[20];
	char name[20];
	float a;
	float b;
	float c;
	float sum;
}stu;

int main()
{
	FILE* pf = fopen("stud.txt", "wb");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}

	stu arr[5] = { 0 };
	printf("请输入五名学生成绩:>\n");
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("学生%d\n", i + 1);
		printf("学生号：");
		scanf("%s", arr[i].num);
		printf("姓名：");
		scanf("%s", arr[i].name);
		printf("成绩1：");
		scanf("%f", &arr[i].a);
		printf("成绩2：");
		scanf("%f", &arr[i].b);
		printf("成绩3:");
		scanf("%f", &arr[i].c);
		arr[i].sum = (arr[i].a + arr[i].b + arr[i].c) / 3;
		printf("平均成绩为：%f\n", arr[i].sum);

		fwrite(arr + i, sizeof(stu), 1, pf);
		printf("学生%d信息已经读入文件\n", i + 1);
		puts("");

	}

	fclose(pf);
	pf = NULL;
	return 0;
}
















