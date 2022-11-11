#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>



////int arr[]={1,2,3,4,5,1,2,3,4},找出5
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


////////////////////////////////?
//void f(int*  arr[][3])
//{
//	int i, j, n=0;
//	for (i = 0; i < 3; i++) {
//		for (n = 0 ,j = 0; j < 3; j++) {  //n为每行元素之和
//			n += *(arr+3*i+j);
//		}
//		printf("%d ", n);
//	}	
//}
//
//int main()
//{
//	int arr[3][3] = { {1,1,1},{2,2,2},{3,3,3} };
//	f(arr);
//	return 0;
//}


//void init(int* arr)
//{
//	int i;
//	for (i = 0; i < 9; i++)
//	{
//		*(arr + i) = 0;
//	}
//}
//
//int main()
//{
//	int arr[9] = { 1,2,3,4,5,6,7,8,9 };
//	init(arr);
//	return 0;
//}










////1. 两数之和
////给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
////你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
////你可以按任意顺序返回答案。
////
////示例 1：
////输入：nums = [2, 7, 11, 15], target = 9
////输出：[0, 1]
////解释：因为 nums[0] + nums[1] == 9 ，返回[0, 1] 。
//#define num 10
//
//int* pri(int arr[], int sz)
//{
//	int i;
//	for (i = 0; i < sz; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	return arr;
//}
//
//void judge(int* arr, int x, int sz)
//{
//	int i, j, n=0;
//	for (i = 0; i < sz; i++)//i从0到sz-1递增
//	{
//		for (j = i+1; j < sz; j++)//j从i+1到sz-1递增，可以保证不和i重复
//		{
//			if (arr[i] + arr[j] == x)
//			{
//				printf("%2d+%-2d=%-2d，下标为%2d,%-2d\n", arr[i], arr[j], x, i, j);
//				n++;
//			}
//		}
//	}
//	if (n == 0)
//	{
//		printf("没有想要的结果\n");
//	}
//}
//
//int main()
//{
//	int arr[num] = { 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	printf("输入数组元素\n");
//	pri(arr, sz);
//	printf("输入目标数字\n");
//	int target;
//	scanf("%d", &target);
//	judge(arr, target, sz);
//	return 0;
//}










//////350. 两个数组的交集 II
//////给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。
//////返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致
//////（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
//////
//////示例 1：
//////输入：nums1 = [1, 2, 2, 1], nums2 = [2, 2]
//////输出：[2, 2]
//////
//////示例 2:
//////输入：nums1 = [4, 9, 5], nums2 = [9, 4, 9, 8, 4]
//////输出：[4, 9]
////////
////////提示：
////////1 <= nums1.length, nums2.length <= 1000
////////0 <= nums1[i], nums2[i] <= 1000

void strsca(char arr[], int sz)
{
	int i;
	for (i = 0; i < sz; i++)
	{
		arr[i] = getchar();
		if (arr[i] == 10)
		{
			arr[i] = '\0';  //回车时，getchar()获得的值时'\n'，对应ASCII值为10
			break;
		}
	}
}

void pri(char arr[], int sz)
{
	int i;
	for (i = 0; i < sz && arr[i] != '\0'; i++)
	{
		printf("%c ", arr[i]);
	}
}

void initarr(void(*pf)(char*,int),char arr1[], char arr2[], int sz)
{
	printf("请输入数组1：>");
	pf(arr1, sz);
	printf("请输入数组2：>");
	pf(arr2, sz);
}

int main()
{
	char arr1[20] = { 0 };
	char arr2[20] = { 0 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	initarr(strsca, arr1, arr2, sz);
	pri(arr1, sz);
	printf("\n");
	pri(arr2, sz);

	return 0;
}





//
//
//void strsca(char arr[])
//{
//	int i;
//	for (i = 0; i < 20; i++)
//	{
//		arr[i] = getchar();
//		if (arr[i] == 10)
//		{
//			arr[i] = '\0';  //回车时，getchar()获得的值时'\n'，对应ASCII值为10
//			break;
//		}
//	}
//}
//int main()
//{
//	char arr[20] = { 0 };
//	strsca(arr);
//	int i = 0;
//	//for (i = 0; i < 20; i++)
//	//{
//	//	arr[i] = getchar();
//	//	if (arr[i] == 10)
//	//	{
//	//		arr[i] = '\0';
//	//		break;
//	//	}
//	//}
//	for (i = 0; i < 20&&arr[i]!='\0'; i++)
//	{
//		printf("%c ", arr[i]);
//	}
//
//	return 0;
//}