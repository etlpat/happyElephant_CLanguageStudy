#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>









////////////////////////////////////////////////////////////////////////字符串函数////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////操作对象是字符串,或多或少用到\0，参数类型、返回类型大多char*，所以只能对字符串使用
//目录：
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




//////几个<string.h>下的库函数的相似点：
//////////1.函数参数均为char*类型，传参传首地址
//////////2.参数(char *strDestination, const char *strSource)，左目标字符串，右源字符串
//////////3.大部分返回目标字符串首地址 
//////////4.若函数不改变某数组内容，对应参数加const
//////////5.库函数中count类型均为size_t无符号整形，因为不可能为负
//////////6.自己实现库函数时，assert()断言不是空指针
//////////7.限制长度的字符串函数，函数名中间加n，参数比之前多一个num，即想要操作的字符个数
//////////8.compare，str1>str2，返回正；str1==str2，返回0；str1<str2,返回负











//////////////////////////////////////////    求字符串长度函数
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
////【字符串拷贝】 
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
////【字符串追加】 
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
////【比较字符串】 
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
//	const char* p1 = "abcde";
//	const char* p2 = "abc";
//	const char* p3 = "abc";
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
//////如果count大于strSource的长度，目标字符串将用长度不超过count的空字符填充。//【count大于源字符串长度，则拷贝完源字符串之后，在目标后边追加'\0'，直到count个】
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
//////【要点是追加后，还是字符串，结尾有且仅有一个'\0'】
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










/////////////////////////    strncmp()
////
//////声明：int strncmp( const char *string1, const char *string2, size_t count );
////
//////strncmp函数按ASCII顺序来比较string1和string2中的前count个字符，并返回指示子字符串之间关系的值。
////////第一个字符串大于第二个字符串，则返回大于0的数字
////////第一个字符串等于第二个字符串，则返回0
////////第一个字符串小于第二个字符串，则返回小于0的数字
//
//
//int main()
//{
//	//常量字符串不可修改，但是p1的语法形式不限制p1去改常量字符串，修改时不报语法错误，只是程序崩溃
//	const char* p1 = "abcdef";//加const，一旦修改会报语法错误，程序更合理
//	const char* p2 = "abcqwer";
//
//	printf("%d\n", strncmp(p1, p2, 3));//比较前三个
//	printf("%d\n", strncmp(p1, p2, 4));//比较前四个
//
//	return 0;
//}













//////////////////////////////////////////        字符串查找函数



/////////////////////    strstr()
//////【查找子字符串】
////
//////声明：char *strstr( const char *string, const char *strCharSet ); //前：被查找的字符串，后：要查找的子字符串
////
////
//////返回值：返回strCharSet在string中第一次出现时，那个子字符串首字符的地址；如果strCharSet指向空字符串，则函数返回string。
//////        如果strCharSet没有出现在string中则返回NULL。
//
//
//
//#include<assert.h>
//
////////类似于官方库函数《妙》
//char* my_strstr(const char* p1, const char* p2)
//{
//	assert(p1 && p2);
//	char* s1 = p1;//p1 p2记录寻找子串的起始位置，s1 s2在循环中进行比较
//	char* s2 = p2;
//	if (*p2 == '\0') {
//		return p1;
//	}
//	while (*p1)
//	{
//		s1 = p1;
//		s2 = p2;
//		//找到第一个相同的字符，开始向后一个个比较
//		while (*s1 && *s2 && (*s1 == *s2))//*s1 *s2找到'\0'，或二者不相等，循环结束
//		{
//			s1++;
//			s2++;
//		}
//		//仅有*s2是\0的情况找到了子串
//		if (*s2 == '\0') {
//			return p1;
//		}
//		//每次循环，p1初始位置+1
//		p1++;
//	}
//	return NULL;
//}
////特殊情况：
//// abbbbcdef , bbc（坑，这种特殊情况决定了要用两种指针，一种记录子串起始位置不轻易改变，一种可在循环中来回改变）
//// abcdeabc , def
//// abcde , def
//
//
//
//int main()
//{
//	const char* p1 = "abcdefghi";
//	const char* p2 = "def";
//	const char* p3 = "defQ";
//
//	////////子字符串存在，返回再p1中对应的【第一个子字符串首字符地址】
//	char* ret1 = strstr(p1, p2); //defghi
//	if (ret1 == NULL)
//		printf("NULL\n");
//	else puts(ret1);
//
//	////////子字符串不存在，返回 NULL
//	char* ret2 = strstr(p1, p3);//NULL
//	if (ret2 == NULL)
//		printf("NULL\n");
//	else puts(ret2);
//
//	////////特殊情况（b重复多次）abbbcdef,bcd
//	char* ret3 = strstr("abbbcdef", "bcd");//bcdef
//	if (ret3 == NULL)
//		printf("NULL\n");
//	else puts(ret3);
//
//	return 0;
//}










/////////////////////////    strtok()
////【分割字符串】
////【把字符串中分隔符改为、0，一次只能修改一段，第一次传str，之后都传NULL】
//
////声明：char *strtok( char *str, const char *sep );
//
// 
////sep参数是个字符串，定义了用作分隔符的字符集合。 
////第一个参数指定一个字符串，它包含了0个或多个由sep字符串中的一个或者多个分隔符分割的标记。
////strtok函数找到str中的下一个标记，并将其用\0结尾，返回一个指向这个标记的指针。（注：strtok函数会改变操作的字符串，所以在使用strtok函数切分的字符串一般是临时拷贝的内容并且可修改。）
////strtok函数的第一个参数不为NULL，函数将找到str中第一个标记，strtok函数将保存它在字符串中的位置。
////strtok函数的第一个参数为NULL，函数将在同一个字符串中被保存的位置开始，查找下一个标记。
////如果字符串中不存在更多的标记，则返回NULL指针。
//
//
//
////strtok作用：每调用一次，把最近的分隔符改为\0，并保存\0的位置
////下次调用，传递NULL即可从\0之后把下一个分隔符也改为\0

////////////#include<assert.h>//失败的函数
////////////char* my_strtok(char* str, const char* sep)
////////////{
////////////	assert(sep);
////////////	static int m = -1;
////////////	int start = m+1;
////////////	int t = 0;
////////////	if (m < 0) {
////////////		m = 0;
////////////	}
////////////	else {
////////////		m++;
////////////	}
////////////	while (str[m])
////////////	{
////////////		for (t = 0;  sep[t] && str[m] != sep[t]; t++)
////////////		{
////////////			;
////////////		}
////////////		if (str[m] == sep[t])
////////////		{
////////////			str[m] = '\0';
////////////			return str + start;
////////////		}
////////////		m++;
////////////	}
////////////	if (str[start])
////////////	{
////////////		return str + start;
////////////	}
////////////	else
////////////	{
////////////		return NULL;
////////////	}
////////////}


//int main()
//{
//	char arr[] = "hhh@baidu.com";
//	char* p = "@.";
//
//	char buf[50] = { 0 };//strtok会修改操作的字符串，所以一般临时拷贝一个来切割
//	strcpy(buf, arr);
//	//切割buf中的字符串
//
//	char* ret = strtok(buf, p);//hhh\0baidu.com\0
//	puts(ret);//hhh
//
//	ret = strtok(NULL, p);//hhh\0baidu\0com\0
//	puts(ret);//baidu
//
//	ret = strtok(NULL, p);//hhh\0baidu\0com\0
//	puts(ret);//com
//
//	return 0;
//}



//int main()
//{
//	char arr[] = "hhh@baidu.com";
//	char* p = "@.";
//	char buf[50] = { 0 };
//	strcpy(buf, arr);
//
//	char* ret;
//
//	////正确用法：
//	//buf只用调用一次，之后每次都调用NULL，当返回NULL说明不存在更多分隔符----完美契合for(;;)的特性,《巧妙》
//	for (ret = strtok(buf, p); ret != NULL; ret = strtok(NULL, p))
//	{
//		puts(ret);
//	}
//	puts("");
//
//
//
//	char a[] = "114.514.19.19.810";//点分十进制的表示方式
//	char* p1 = ".";
//	char* ret1 = NULL;
//	for (ret1 = strtok(a, p1); ret1 != '\0'; ret1 = strtok(NULL, p1))
//	{
//		puts(ret1);
//	}
//
//	return 0;
//}













//////////////////////////////////////////       错误信息报告函数



///////////////////////    strerror()
//////【把错误码对应的错误信息翻译出来】
////
//////声明：char *strerror( int errnum );
////
//////Strerror返回一个指向错误消息字符串的指针。后续对strerror的调用可以覆盖该字符串。
//
//#include<errno.h>
//
//int main()
//{
//	//错误码    错误信息
//	// 0   -   No error
//	// 1   -   Operation not permitted
//	// 2   -   No such file or directory
//	// 3   -   No such process
//	// ...     ...
//	//errno是一个全局的错误码变量，发生了错误，就会把对应的错误码，赋值到errno中
//	//errno对应头文件#include<errno.h>
//
//	char* s = strerror(errno);
//	puts("");
//
//	int i;
//	for (i = 0; i <= 10; i++) {
//		char* str = strerror(i);
//		puts(str);
//	}
//	puts("");
//
//	//打开文件
//	FILE* pf = fopen("test.txt", "r");;
//	if (pf == NULL){
//		printf("%s\n", strerror(errno));
//	}
//	else {
//		printf("open file success\n");
//	}
//
//	return 0;
//}

























////////////////////////////////////////////////////////////////////////字符函数////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//目录：
//is....()
//tolower()
//toupper()
 








////////////////////////////////////////////       字符分类函数
//// 
//////下面函数头文件：#include<ctype.h>
////
//////函数           如果他的参数符合下列条件就返回真
//////iscntrl()      //任何控制字符
//////isspace()      //空白字符：空格' '，换页'\f'，换行'\n'，回车'\r'，制表符'\t'或者垂直制表符'\v'
//////isdigit()      //十进制数字 0-9
//////isxdigit()     //十六进制数字，0-9，a-f, A-F
//////islower()      //小写字母 a-z
//////isupper()      //大写字母 A-Z
//////isalpha()      //字母 a-z 或 A-Z
//////isalnum()      //字母或数字，a-z , A-Z , 0-9
//////ispunct()      //标点符号，任何不属于数字或者字母的图形字符（可打印）
//////isgraph()      //任何图形字符
//////isprint()      //任何可打印字符，包括图形字符和空白字符
////
////
//////以上函数均为 判断参数（字符）是否符合条件：符合返回非0（真）；不符合，就返回0（假）
// 
//
//#include<ctype.h>
//
//int main()
//{
//	char ch = 'z';
//	int ret1 = islower(ch);
//	int ret2 = isdigit('2');
//
//	printf("%d\n", ret1);
//	printf("%d\n", ret2);
//
//	return 0;
//}













//////////////////////////////////////////       字符（大小写）转换函数
////
//////tolower()  大写转小写函数（输入小写不改变）
//////toupper()  小写转大写函数
////
//////声明：int tolower( int c );
//////声明：int toupper( int c );
//
//#include<ctype.h>
//
//int main()
//{
//	char a = tolower('Q');
//	char b = toupper('q');
//	printf("%c %c\n", a, b);
//
//	return 0;
//}


//////////////字符串大小写互换
//#include<ctype.h>
//int main()
//{
//	char arr[] = "hello WORLD";
//	int i = 0;
//	while (arr[i])
//	{
//		if (isupper(arr[i]))
//		{
//			arr[i] = tolower(arr[i]);
//		}
//		else if (islower(arr[i]))
//		{
//			arr[i] = toupper(arr[i]);
//		}
//		i++;
//	}
//	puts(arr);
//	return 0;
//}
























 
////////////////////////////////////////////////////////////////////////内存操作函数////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////memory：内存
//
////对应头文件：#include<string.h>
// 
//目录：
//memcpy()
//memmove()
//memcmp()
//memset()
//
//////前面的<string.h>下的strxxx函数都是仅能对字符串进行操作
//////但是却不能操作整形、浮点型、结构体等数组
//////所以出现了下面的内存函数










///////////////////////////    memcpy()
//////【在缓冲区之间复制字符】
////
//////声明：void *memcpy( void *dest, const void *src, size_t count );    //count单位是字节
////
////
//////dest：新的缓冲区
//////src：要复制的缓冲区
//////count：要复制内存的【字节数】（因为参数类型均为void*，所以需要字节数来确定拷贝多少内存）
////
////
//////memcpy函数将src的count个字节拷贝到dest中，如果源地址和目的地址重叠，则不保证复制重叠区域内源地址的原始字节后再被覆盖。使用函数 memmove() 来处理重叠区域。
// 
//////重叠区域覆盖的例子： 如果arr[]={1,2,3,4,5,6,7};要把 1,2,3,4,5 拷贝到 3,4,5,6,7 的区域，就会出现字符串覆盖，可能导致源字符串内容发生改变的bug
//////但是事实上当前编译器修复了这些bug，即使重叠，memcpy也可以处理，也就是当前编译器memcopy和memmove效果一样
//// 
//// 
////// C语言标准规定：
////// memcpy()  只要处理 不重叠 的内存拷贝就可以
////// memmove() 处理重叠内存的拷贝 
// 
//
// 
//#include<assert.h>
//
//void* my_memcpy(void* dest, const void* src, size_t count)
//{
//	assert(dest && src);
//	void* ret = dest;
//	while (count--)
//	{
//		*((char*)dest)++ = *((char*)src)++;
//	}
//	return ret;
//}
//
//
//struct S
//{
//	char name[20];
//	int age;
//};
//
//int main() {
//	int arr[2][3] = { 1,2,3,4,5,6 };
//	int arr2[3][3] = { 0 };
//	memcpy(arr2, arr, sizeof(arr));
//
//	struct S arr3[] = { {"张三",12},{"李四",18} };
//	struct S arr4[4] = { 0 };
//	memcpy(arr4, arr3, sizeof(arr3));
//
//	int a[] = { 1,2,3,4,5,6,7,8,9 };//12345拷贝到34567
//	memcpy(a + 2, a, 5 * sizeof(int));//1 2 1 2 1 2 1 8 9 //有些编译器修复了这种情况
//                                  ////内存重叠时就要用到memmove()
// 
//	return 0;
//}










/////////////////////////////    memmove()
//////【将一个缓冲区移动到另一个缓冲区】 
//// 
//// 
//////声明：void *memmove( void *dest, const void *src, size_t count ); 
//// 
//// 
//////memmove函数将src的count个字节拷贝到dest中，如果源区域和目标区域的某些区域重叠，memmove确保在重叠区域的原始源字节被复制后再被覆盖。 
//////用法类似于memcpy(),不过memmove()可以处理拷贝时内存重叠的情况，也可以处理不重叠的情况
////
////
////// C语言标准规定：
////// memcpy()  只要处理 不重叠 的内存拷贝就可以
////// memmove() 处理重叠内存的拷贝 
//
//
//#include<assert.h>
//
//void* my_memmove(void* dest, const void* src, size_t count)
//{
//	assert(dest && src);
//	void* ret = dest;
//
//	if ((int)dest - (int)src > 0)//若dest地址大于src，则从结尾开始往倒着拷贝内存
//	{
//		((char*)dest) += count - 1;
//		((char*)src) += count - 1;
//		while (count--)
//		{
//			*((char*)dest)-- = *((char*)src)--;
//		}
//	}
//	else//若dest地址小于src，则从开头开始正着拷贝内存
//	{
//		while (count--)
//		{
//			*((char*)dest)++ = *((char*)src)++;
//		}
//	}
//	return dest;
//}
//
//
//struct S
//{
//	char name[20];
//	int age;
//};
//
//int main()
//{
//	struct S arr3[] = { {"张三",12},{"李四",18} };
//	struct S arr4[4] = { 0 };
//	memmove(arr4, arr3, sizeof(arr3));
//
//	int a[] = { 1,2,3,4,5,6,7,8,9 };//重叠情况：12345拷贝到34567
//	memmove(a + 2, a, 5 * sizeof(int));
//
//
//	int b[] = { 1,2,3,4,5,6,7,8,9 };//重叠情况：34567拷贝到12345
//	memmove(b, b + 2, 5 * sizeof(int));
//
//	return 0;
//}








