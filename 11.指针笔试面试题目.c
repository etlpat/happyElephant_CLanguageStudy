#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>




/////////////////  题目1.
/////////////////       分析sizeof()计算的数组和指针的大小
/////////////////       秘诀是分析处数组名的意义是什么

int main()
{   
	//数组名是首元素地址（仅有两个例外，其他所以数组名都是首元素地址）
	//1.sizeof(数组名)
	//2.&数组名
	//声明两种情况，是死的，数组名的地方只能是数组名，不能进行任何操作，如+0
	

	///////   一维数组

	//////整形数组
	//int a[] = { 1,2,3,4 };
	// 
	//printf("%d\n", sizeof(a));         // 16  --  sizeof(数组名)，计算数组总大小，a是整个数组的地址
	//printf("%d\n", sizeof(a + 0));     // 4/8 --  sizeof(a+0)斌不符合sizeof(数组名)的形式，a是首元素地址
	//printf("%d\n", sizeof(*a));        // 4   --  a是首元素地址，*a是首元素
	//printf("%d\n", sizeof(a + 1));     // 4/8 --  a+1是第二个元素地址
	//printf("%d\n", sizeof(a[1]));      // 4   --  a[1]是整形
	//printf("%d\n", sizeof(&a));        // 4/8 --  &a是数组的地址，地址大小就是4/8
	//printf("%d\n", sizeof(*&a));       // 16  --  &a已经说明a是整个数组,再*&a还是数组
	//printf("%d\n", sizeof(&a + 1));    // 4/8 --  &a是整个数组的地址，&a+1是跳过整个数组后的地址，但还是地址，4/8
	//printf("%d\n", sizeof(&a[0]));     // 4/8 --  []优先级高，a[0]是首元素，&a[0]是地址
	//printf("%d\n", sizeof(&a[0] + 1)); // 4/8 --  地址+1，还是地址
	
	

	//////字符数组
	//printf("\n");
	//char c[] = { 'a','b','c','d','e','f' };

	//printf("%d\n", sizeof(c));         // 6   --  计算数组大小，每个字符1字节
	//printf("%d\n", sizeof(c + 0));     // 4/8 --  地址+0还是地址，4/8
	//printf("%d\n", sizeof(*c));        // 1   --  字符
	//printf("%d\n", sizeof(c[1]));      // 1   --  字符
	//printf("%d\n", sizeof(&c));        // 4/8 --  数组的地址，还是地址4/8
	//printf("%d\n", sizeof(&c + 1));    // 4/8 --  &c是整个数组的地址，&c+1跳出了数组，但还是地址，4/8
	//printf("%d\n", sizeof(&c[0] + 1)); // 4/8 --  地址+1，还是地址
	//printf("\n");

	////strlen()计算模式：传入字符串名称，是首元素地址，向后1字节1字节的找，直到找到'\0'停止，长度不包含'\0'
	//printf("%d\n", strlen(c));         // 随机值 --  c是首元素地址，从首元素开始向后数
	//printf("%d\n", strlen(c + 0));     // 随机值 --  和上一个完全相同
	////printf("%d\n", strlen(*c));      // 报错   --  strlen接收地址，'a'-97，不是地址
	////printf("%d\n", strlen(c[1]));    // 报错   --  同上，报错
	//printf("%d\n", strlen(&c));        // 随机值 --  和上面随机值相同
	//printf("%d\n", strlen(&c + 1));    // 随机值 --  比上面随机值少6，跳过了一个数组
	//printf("%d\n", strlen(&c[0] + 1)); // 随机值 --  比上面随机值少1


	return 0;
}