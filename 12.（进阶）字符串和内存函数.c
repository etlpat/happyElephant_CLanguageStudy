#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>


////求字符串长度
//strlen()
////长度不受限制的字符串函数
//strcpy()
//strcat()
//strcmp()
////长度受限制的字符串函数
//strncpy()
//strncat()
//strncmp()
////字符串查找
//strstr()
//strtok()
////错误信息报告
//strerror()
////字符操作
////内存操作函数
//memcpy()
//memmove()
//memset()
//memcmp()








//////////////////////////////////////////    求字符串长度
//
///////////////////    strlen()
//// 
//////声明：size_t strlen( const char *string );
////  
//////字符串将'\0'作为结束标志，strlen函数返回字符串中'\0'前面出现的字符个数（不含'\0'）
//////参数指向的字符串必须要以'\0'结束
//////注意函数的返回值为size_t，是无符号的
//
//
//////strlen()函数的实现
//////1.计数器的方法
//////2.递归：不创建临时变量求字符串长度
//////3.指针减指针
//
//
//#include<assert.h>
//
//////库函数中返回类型为size_t == unsigned int
//////定义中，typedef unsigned int size_t 
//
//int my_strlen1(const char* str)
//{
//	assert(str != NULL);
//	int count = 0;
//	while (*str)
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
//int my_strlen2(const char* str)
//{
//	assert(str != NULL);
//	if (*str != '\0') {
//		return 1 + my_strlen2(str + 1);
//	}
//	else {
//		return 0;
//	}
//}
//
//int my_strlen3(const char* str)
//{
//	assert(str != NULL);
//	char* end = str;
//	while (*end)
//	{
//		end++;
//	}
//	return end - str;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	printf("%d\n", strlen(arr));//库函数
//	printf("%d\n", my_strlen1(arr));
//	printf("%d\n", my_strlen2(arr));
//	printf("%d\n", my_strlen3(arr));
//	return 0;
//}













////////////////////////////////////////    长度不受限制的字符串函数
////                                       （以'\0'作为判断结束的标准）



///////////////////    strcpy()
////
//////声明：char *strcpy( char *strDestination, const char *strSource );
////
//////源字符串必须以'\0'结束。
//////会将源字符串中的'\0'拷贝到目标空间
//////目标空间必须足够大，以确保能存放源字符串(否则越界访问)
//////目标空间必须可变
//
//#include<assert.h>
//
////传统办法
//char* my_strcpy1( char *dest, const char *src )
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* ret = dest;
//	while (*dest)
//	{
//		*dest = *src;
//		dest++;
//		src++;
//	}
//	return ret;
//}
//
////简化后
//char* my_strcpy2(char* dest, const char* src)
//{
//	assert(dest);
//	assert(src);
//	char* ret = dest;
//	//拷贝src指向的字符串到dest指向的字符串，包含'\0'
//	while (*(dest++) = *(src++))
//	{
//		;
//	}
//	//返回dest的起始地址
//	return ret;
//}
//
//
//int main()
//{
//	char arr1[] = "abcdefgh";
//	char arr2[] = "hehe";
//	char arr3[] = "haha";
//
//	//strcpy(arr1, arr2);//库函数
//	my_strcpy1(arr1, arr2);
//	puts(arr1);
//	my_strcpy2(arr1, arr3);
//	puts(arr1);
//	return 0;
//}









/////////////////////    strcat()
////
//////声明：char *strcat( char *strDestination, const char *strSource );
//// 
//////strcat函数将strSource附加到strDestination，并以'\0'结束。strSource的初始字符覆盖strDestination的结束空字符'\0'。
//////复制或追加字符串时不执行溢出检查。如果源字符串和目标字符串重叠，则strcat的行为未定义。
//// 
//////源字符串和目标字符串必须均以'\0'结束
//////目标空间必须足够大，能容纳下源字符串的内容(否则越界访问)
//////目标空间必须可修改
//////若字符串自己给自己追加？结尾的'\0'被覆盖，程序会崩溃
//
//#include<assert.h>
//
//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* ret = dest;
//
//	//1.找到目的字符串的'\0'
//	while (*dest)
//	{
//		dest++;
//	}
//	//2.追加
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//
//
//int main()
//{
//	char arr1[30] = "hello";
//	char arr2[] = "world";
//
//	strcat(arr1, arr2);
//	puts(arr1);
//
//	my_strcat(arr1, arr2);
//	puts(arr1);
//
//	return 0;
//}










/////////////////////    strcmp()
////
//////声明：int strcmp( const char *string1, const char *string2 );
////
//////标准规定：（比较对应字符的ASCII码值的大小，若一对字符相同则比较下一对，直到两字符串结束为止）
//////第一个字符串大于第二个字符串，则返回大于0的数字
//////第一个字符串等于第二个字符串，则返回0
//////第一个字符串小于第二个字符串，则返回小于0的数字
//
//#include<assert.h>
//
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0') {
//			return 0;//相等
//		}
//		str1++;
//		str2++;
//	}
//
//	//--------------------------//有的编译器不做下面的判断，直接 return (*str1 - *str2);
//
//	if (*str1 > *str2) {
//		return 1;//大于
//	}
//	else {
//		return -1; //小于
//	}
//}
//
// 
//int main()
//{
//	char* p1 = "abcde";
//	char* p2 = "abc";
//	char* p3 = "abc";
//
//	int ret = strcmp(p1, p2);
//	if (ret > 0) {//---------//切记不要用(ret == 1/0/-1)判断大小：当前编译器是这样，但是其他的并不一定，不具有可移植性
//		printf("p1 > p2\n");
//	}
//	else if (ret == 0) {
//		printf("p1 == p1\n");
//	}
//	else {
//		printf("p1<p2\n");
//	}
//
//	printf("%d\n", my_strcmp(p1, p2));
//	printf("%d\n", my_strcmp(p2, p3));
//
//	return 0;
//}













//////////////////////////////////////////    长度受限制的字符串函数
//
//
//
/////////////////////    strncpy()
////【要点是说要拷贝几个，就是拷贝几个，没有就'\0'代替】
// 
// 
//////声明：char* strncpy(char* strDest, const char* strSource, size_t count);
//////【拷贝count个字符从源字符串到目标空间】 
//// 
//////strncpy函数将strSource的初始计数字符复制到strDest并返回strDest。
//////如果count小于或等于strSource的长度，则不会自动向复制的字符串追加空字符。 //【count是几就拷贝几个字符，不补'\0'】
//////如果count大于strSource的长度，目标字符串将用长度不超过count的空字符填充。//【count大于源字符串长度，则拷贝玩源字符串之后，在目标后边追加'\0'，直到count个】
//////如果源字符串和目标字符串重叠，则strncpy的行为未定义。
//
//#include<assert.h>
//
//
////我的实现
//char* my_strncpy1(char* dest, const char* src, int count)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (count)
//	{
//		*dest++ = *src++;
//		count--;
//		if (*(dest - 1) == '\0')//这里注意，上一步解引用赋值后，指针dest++，指向后一字符，所以这里判断是要-1
//		{
//			break;
//		}
//	}
//	if (count)
//	{
//		while (count--)
//		{
//			*dest++ = '\0';
//		}
//	}
//	return  ret;
//}
//
// 
////类似于官方库函数《妙》
//char* my_strncpy2(char* dest, const char* src, size_t count)
//{
//	assert(dest && src);
//	char* ret = dest;
//	//当 count!=0 或 *dest!=0 时进行循环
//	while (count && (*dest++ = *src++))
//	{
//		count--;
//	}
//	//判断是否为count减到0的情况
//	if (count)
//	{
//		while (--count)//这里注意，上一次循环判断条件中，*dest赋了值，但是没进入循环让count值-1。所以这里--count，把上一次欠的次数先减掉
//		{
//			*dest++ = '\0';
//		}
//	}
//	return ret;
//}
//
//
//
//int main()
//{
//	char str1[] = "abcdefgh";
//	char str2[] = "aaaaaaaa";
//	char str3[] = "HHH";
//	strncpy(str1, str3, 2);//HHcdefgh
//	strncpy(str2, str3, 6);
//	puts(str1);
//	puts(str2);
//
//	return 0;
//}










///////////////////////    strncat()
//////【要点是追加后，结尾有且仅有一个'\0'】
//// 
////
//////声明：char* strncat(char* strDest, const char* strSource, size_t count);
//////【追加n个字符从源字符串到目标字符串结尾,自动补\0且无论如何仅补1个】
//// 
//////strncat函数最多将strSource的前count个字符追加到strDest。strSource的初始字符覆盖strDest的'\0'。
//////【若追加字符串结尾无'\0',会主动补'\0'】
//////【如果count大于strSource的长度，也只追加一个'\0'，就不再进行追加】
//////如果在重叠的字符串之间进行复制，则行为未定义。
//
//#include<assert.h>
//
//
//////我的实现
//char* my_strncat1(char* dest, const char* src, int count)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (*dest++)//先找到目标字符串结尾\0
//	{
//		;
//	}
//	dest--;//这步-1让dest指向\0
//	while (count && (*dest++ = *src++))//若*dest先变\0，结束；若count先变为0，判断*dest是否补\0
//	{
//		count--;
//	}
//	if (*(dest - 1) != 0)//若目标字符串结尾表示\0，补\0
//	{
//		*dest = '\0';
//	}
//	return ret;
//}
//
//
//////类似于官方库函数《妙》
//char* my_strncat2(char* dest, const char* src, int count)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (*dest++)
//	{
//		;
//	}
//	dest--;
//	while (count--)
//	{
//		if (!(*dest++ = *src))//赋值表达式返回值是本次赋的值,当*est=0，!*dest为1，进入if条件
//		{
//			return(ret);
//		}
//	}
//	*dest = '\0';
//	return ret;
//}
//
//
//int main()
//{
//	char arr1[30] = "hello\0xxxxxxxxxxxxxxxxxxxxxxxx";
//	char arr2[] = "world";
//
//	my_strncat1(arr1, arr2, 3);//hellowor\0xxxxxxx//结尾补'\0'
//	puts(arr1);
//	my_strncat1(arr1, arr2, 9);//helloworworld\0xxxxxxxxxxxx结尾仅补1个'\0'
//	puts(arr1);
//
//	return 0;
//}

















//strncmp()