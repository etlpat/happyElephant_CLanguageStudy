//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>



//Ŀ¼��

////////�ַ���������
// 
////���ַ�������
//strlen()
////���Ȳ������Ƶ��ַ�������
//strcpy()
//strcat()
//strcmp()
////���������Ƶ��ַ�������
//strncpy()
//strncat()
//strncmp()
////�ַ�������
//strstr()
//strtok()
////������Ϣ����
//strerror()


////////�ַ�������
//  
////�ַ����ຯ��       
//iscntrl()  //�κο����ַ�
//isspace()  //�հ��ַ�
//isdigit()  //ʮ��������
//isxdigit() //ʮ����������
//islower()  //Сд��ĸ
//isupper()  //��д��ĸ
//isalpha()  //��ĸ
//isalnum()  //��ĸ������
//ispunct()  //������
//isgraph()  //�κ�ͼ���ַ�
//isprint()  //�κοɴ�ӡ�ַ�
////�ַ�ת������ 
//tolower()  ��дתСд
//toupper()  Сдת��д


////////�ڴ���������� 
//memcpy()
//memmove()
//memcmp()
//memset()






////////////////////////////////////////////////////////////////////////�ַ�������////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////�����������ַ���,�������õ�\0���������͡��������ʹ��char*������ֻ�ܶ��ַ���ʹ��
//Ŀ¼��
////���ַ�������
//strlen()
////���Ȳ������Ƶ��ַ�������
//strcpy()
//strcat()
//strcmp()
////���������Ƶ��ַ�������
//strncpy()
//strncat()
//strncmp()
////�ַ�������
//strstr()
//strtok()
////������Ϣ����
//strerror()




//////����<string.h>�µĿ⺯�������Ƶ㣺
//////////1.����������Ϊchar*���ͣ����δ��׵�ַ
//////////2.����(char *strDestination, const char *strSource)����Ŀ���ַ�������Դ�ַ���
//////////3.�󲿷ַ���Ŀ���ַ����׵�ַ 
//////////4.���������ı�ĳ�������ݣ���Ӧ������const
//////////5.�⺯����count���;�Ϊsize_t�޷������Σ���Ϊ������Ϊ��
//////////6.�Լ�ʵ�ֿ⺯��ʱ��assert()���Բ��ǿ�ָ��
//////////7.���Ƴ��ȵ��ַ����������������м��n��������֮ǰ��һ��num������Ҫ�������ַ�����
//////////8.compare��str1>str2����������str1==str2������0��str1<str2,���ظ�











//////////////////////////////////////////    ���ַ������Ⱥ���
//
///////////////////    strlen()
//// 
//////������size_t strlen( const char *string );
////  
//////�ַ�����'\0'��Ϊ������־��strlen���������ַ�����'\0'ǰ����ֵ��ַ�����������'\0'��
//////����ָ����ַ�������Ҫ��'\0'����
//////ע�⺯���ķ���ֵΪsize_t�����޷��ŵ�
//
//
//////strlen()������ʵ��
//////1.�������ķ���
//////2.�ݹ飺��������ʱ�������ַ�������
//////3.ָ���ָ��
//
//
//#include<assert.h>
//
//////�⺯���з�������Ϊsize_t == unsigned int
//////�����У�typedef unsigned int size_t 
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
//	printf("%d\n", strlen(arr));//�⺯��
//	printf("%d\n", my_strlen1(arr));
//	printf("%d\n", my_strlen2(arr));
//	printf("%d\n", my_strlen3(arr));
//	return 0;
//}













////////////////////////////////////////    ���Ȳ������Ƶ��ַ�������
////                                       ����'\0'��Ϊ�жϽ����ı�׼��



///////////////////    strcpy()
////���ַ��������� 
////
//////������char *strcpy( char *strDestination, const char *strSource );
////
//////Դ�ַ���������'\0'������
//////�ὫԴ�ַ����е�'\0'������Ŀ��ռ�
//////Ŀ��ռ�����㹻����ȷ���ܴ��Դ�ַ���(����Խ�����)
//////Ŀ��ռ����ɱ�
//
//#include<assert.h>
//
////��ͳ�취
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
////�򻯺�
//char* my_strcpy2(char* dest, const char* src)
//{
//	assert(dest);
//	assert(src);
//	char* ret = dest;
//	//����srcָ����ַ�����destָ����ַ���������'\0'
//	while (*(dest++) = *(src++))
//	{
//		;
//	}
//	//����dest����ʼ��ַ
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
//	//strcpy(arr1, arr2);//�⺯��
//	my_strcpy1(arr1, arr2);
//	puts(arr1);
//	my_strcpy2(arr1, arr3);
//	puts(arr1);
//	return 0;
//}









/////////////////////    strcat()
////���ַ���׷�ӡ� 
////
//////������char *strcat( char *strDestination, const char *strSource );
//// 
//////strcat������strSource���ӵ�strDestination������'\0'������strSource�ĳ�ʼ�ַ�����strDestination�Ľ������ַ�'\0'��
//////���ƻ�׷���ַ���ʱ��ִ�������顣���Դ�ַ�����Ŀ���ַ����ص�����strcat����Ϊδ���塣
//// 
//////Դ�ַ�����Ŀ���ַ����������'\0'����
//////Ŀ��ռ�����㹻����������Դ�ַ���������(����Խ�����)
//////Ŀ��ռ������޸�
//////���ַ����Լ����Լ�׷�ӣ���β��'\0'�����ǣ���������
//
//#include<assert.h>
//
//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* ret = dest;
//
//	//1.�ҵ�Ŀ���ַ�����'\0'
//	while (*dest)
//	{
//		dest++;
//	}
//	//2.׷��
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
////���Ƚ��ַ����� 
////
//////������int strcmp( const char *string1, const char *string2 );
////
//////��׼�涨�����Ƚ϶�Ӧ�ַ���ASCII��ֵ�Ĵ�С����һ���ַ���ͬ��Ƚ���һ�ԣ�ֱ�����ַ�������Ϊֹ��
//////��һ���ַ������ڵڶ����ַ������򷵻ش���0������
//////��һ���ַ������ڵڶ����ַ������򷵻�0
//////��һ���ַ���С�ڵڶ����ַ������򷵻�С��0������
//
//#include<assert.h>
//
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0') {
//			return 0;//���
//		}
//		str1++;
//		str2++;
//	}
//
//	//--------------------------//�еı���������������жϣ�ֱ�� return (*str1 - *str2);
//
//	if (*str1 > *str2) {
//		return 1;//����
//	}
//	else {
//		return -1; //С��
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
//	if (ret > 0) {//---------//�мǲ�Ҫ��(ret == 1/0/-1)�жϴ�С����ǰ�����������������������Ĳ���һ���������п���ֲ��
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













//////////////////////////////////////////    ���������Ƶ��ַ�������
//
//
//
/////////////////////    strncpy()
////��Ҫ����˵Ҫ�������������ǿ���������û�о�'\0'���桿
// 
// 
//////������char* strncpy(char* strDest, const char* strSource, size_t count);
//////������count���ַ���Դ�ַ�����Ŀ��ռ䡿 
//// 
//////strncpy������strSource�ĳ�ʼ�����ַ����Ƶ�strDest������strDest��
//////���countС�ڻ����strSource�ĳ��ȣ��򲻻��Զ����Ƶ��ַ���׷�ӿ��ַ��� //��count�Ǽ��Ϳ��������ַ�������'\0'��
//////���count����strSource�ĳ��ȣ�Ŀ���ַ������ó��Ȳ�����count�Ŀ��ַ���䡣//��count����Դ�ַ������ȣ��򿽱���Դ�ַ���֮����Ŀ����׷��'\0'��ֱ��count����
//////���Դ�ַ�����Ŀ���ַ����ص�����strncpy����Ϊδ���塣
//
//#include<assert.h>
//
//
////�ҵ�ʵ��
//char* my_strncpy1(char* dest, const char* src, int count)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (count)
//	{
//		*dest++ = *src++;
//		count--;
//		if (*(dest - 1) == '\0')//����ע�⣬��һ�������ø�ֵ��ָ��dest++��ָ���һ�ַ������������ж���Ҫ-1
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
////�����ڹٷ��⺯�����
//char* my_strncpy2(char* dest, const char* src, size_t count)
//{
//	assert(dest && src);
//	char* ret = dest;
//	//�� count!=0 �� *dest!=0 ʱ����ѭ��
//	while (count && (*dest++ = *src++))
//	{
//		count--;
//	}
//	//�ж��Ƿ�Ϊcount����0�����
//	if (count)
//	{
//		while (--count)//����ע�⣬��һ��ѭ���ж������У�*dest����ֵ������û����ѭ����countֵ-1����������--count������һ��Ƿ�Ĵ����ȼ���
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
//////��Ҫ����׷�Ӻ󣬻����ַ�������β���ҽ���һ��'\0'��
//// 
////
//////������char* strncat(char* strDest, const char* strSource, size_t count);
//////��׷��n���ַ���Դ�ַ�����Ŀ���ַ�����β,�Զ���\0��������ν���1����
//// 
//////strncat������ཫstrSource��ǰcount���ַ�׷�ӵ�strDest��strSource�ĳ�ʼ�ַ�����strDest��'\0'��
//////����׷���ַ�����β��'\0',��������'\0'��
//////�����count����strSource�ĳ��ȣ�Ҳֻ׷��һ��'\0'���Ͳ��ٽ���׷�ӡ�
//////������ص����ַ���֮����и��ƣ�����Ϊδ���塣
//
//#include<assert.h>
//
//
//////�ҵ�ʵ��
//char* my_strncat1(char* dest, const char* src, int count)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (*dest++)//���ҵ�Ŀ���ַ�����β\0
//	{
//		;
//	}
//	dest--;//�ⲽ-1��destָ��\0
//	while (count && (*dest++ = *src++))//��*dest�ȱ�\0����������count�ȱ�Ϊ0���ж�*dest�Ƿ�\0
//	{
//		count--;
//	}
//	if (*(dest - 1) != 0)//��Ŀ���ַ�����β��ʾ\0����\0
//	{
//		*dest = '\0';
//	}
//	return ret;
//}
//
//
//////�����ڹٷ��⺯�����
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
//		if (!(*dest++ = *src))//��ֵ���ʽ����ֵ�Ǳ��θ���ֵ,��*est=0��!*destΪ1������if����
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
//	my_strncat1(arr1, arr2, 3);//hellowor\0xxxxxxx//��β��'\0'
//	puts(arr1);
//	my_strncat1(arr1, arr2, 9);//helloworworld\0xxxxxxxxxxxx��β����1��'\0'
//	puts(arr1);
//
//	return 0;
//}










/////////////////////////    strncmp()
////
//////������int strncmp( const char *string1, const char *string2, size_t count );
////
//////strncmp������ASCII˳�����Ƚ�string1��string2�е�ǰcount���ַ���������ָʾ���ַ���֮���ϵ��ֵ��
////////��һ���ַ������ڵڶ����ַ������򷵻ش���0������
////////��һ���ַ������ڵڶ����ַ������򷵻�0
////////��һ���ַ���С�ڵڶ����ַ������򷵻�С��0������
//
//
//int main()
//{
//	//�����ַ��������޸ģ�����p1���﷨��ʽ������p1ȥ�ĳ����ַ������޸�ʱ�����﷨����ֻ�ǳ������
//	const char* p1 = "abcdef";//��const��һ���޸Ļᱨ�﷨���󣬳��������
//	const char* p2 = "abcqwer";
//
//	printf("%d\n", strncmp(p1, p2, 3));//�Ƚ�ǰ����
//	printf("%d\n", strncmp(p1, p2, 4));//�Ƚ�ǰ�ĸ�
//
//	return 0;
//}













//////////////////////////////////////////        �ַ������Һ���



/////////////////////    strstr()
//////���������ַ�����
////
//////������char *strstr( const char *string, const char *strCharSet ); //ǰ�������ҵ��ַ�������Ҫ���ҵ����ַ���
////
////
//////����ֵ������strCharSet��string�е�һ�γ���ʱ���Ǹ����ַ������ַ��ĵ�ַ�����strCharSetָ����ַ�������������string��
//////        ���strCharSetû�г�����string���򷵻�NULL��
//
//
//
//#include<assert.h>
//
////////�����ڹٷ��⺯�����
//char* my_strstr(const char* p1, const char* p2)
//{
//	assert(p1 && p2);
//	char* s1 = p1;//p1 p2��¼Ѱ���Ӵ�����ʼλ�ã�s1 s2��ѭ���н��бȽ�
//	char* s2 = p2;
//	if (*p2 == '\0') {
//		return p1;
//	}
//	while (*p1)
//	{
//		s1 = p1;
//		s2 = p2;
//		//�ҵ���һ����ͬ���ַ�����ʼ���һ�����Ƚ�
//		while (*s1 && *s2 && (*s1 == *s2))//*s1 *s2�ҵ�'\0'������߲���ȣ�ѭ������
//		{
//			s1++;
//			s2++;
//		}
//		//����*s2��\0������ҵ����Ӵ�
//		if (*s2 == '\0') {
//			return p1;
//		}
//		//ÿ��ѭ����p1��ʼλ��+1
//		p1++;
//	}
//	return NULL;
//}
////���������
//// abbbbcdef , bbc���ӣ������������������Ҫ������ָ�룬һ�ּ�¼�Ӵ���ʼλ�ò����׸ı䣬һ�ֿ���ѭ�������ظı䣩
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
//	////////���ַ������ڣ�������p1�ж�Ӧ�ġ���һ�����ַ������ַ���ַ��
//	char* ret1 = strstr(p1, p2); //defghi
//	if (ret1 == NULL)
//		printf("NULL\n");
//	else puts(ret1);
//
//	////////���ַ��������ڣ����� NULL
//	char* ret2 = strstr(p1, p3);//NULL
//	if (ret2 == NULL)
//		printf("NULL\n");
//	else puts(ret2);
//
//	////////���������b�ظ���Σ�abbbcdef,bcd
//	char* ret3 = strstr("abbbcdef", "bcd");//bcdef
//	if (ret3 == NULL)
//		printf("NULL\n");
//	else puts(ret3);
//
//	return 0;
//}










/////////////////////////    strtok()
////���ָ��ַ�����
////�����ַ����зָ�����Ϊ��0��һ��ֻ���޸�һ�Σ���һ�δ�str��֮�󶼴�NULL��
//
////������char *strtok( char *str, const char *sep );
//
// 
////sep�����Ǹ��ַ����������������ָ������ַ����ϡ� 
////��һ������ָ��һ���ַ�������������0��������sep�ַ����е�һ�����߶���ָ����ָ�ı�ǡ�
////strtok�����ҵ�str�е���һ����ǣ���������\0��β������һ��ָ�������ǵ�ָ�롣��ע��strtok������ı�������ַ�����������ʹ��strtok�����зֵ��ַ���һ������ʱ���������ݲ��ҿ��޸ġ���
////strtok�����ĵ�һ��������ΪNULL���������ҵ�str�е�һ����ǣ�strtok���������������ַ����е�λ�á�
////strtok�����ĵ�һ������ΪNULL����������ͬһ���ַ����б������λ�ÿ�ʼ��������һ����ǡ�
////����ַ����в����ڸ���ı�ǣ��򷵻�NULLָ�롣
//
//
//
////strtok���ã�ÿ����һ�Σ�������ķָ�����Ϊ\0��������\0��λ��
////�´ε��ã�����NULL���ɴ�\0֮�����һ���ָ���Ҳ��Ϊ\0

////////////#include<assert.h>//ʧ�ܵĺ���
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
//	char buf[50] = { 0 };//strtok���޸Ĳ������ַ���������һ����ʱ����һ�����и�
//	strcpy(buf, arr);
//	//�и�buf�е��ַ���
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
//	////��ȷ�÷���
//	//bufֻ�õ���һ�Σ�֮��ÿ�ζ�����NULL��������NULL˵�������ڸ���ָ���----��������for(;;)������,�����
//	for (ret = strtok(buf, p); ret != NULL; ret = strtok(NULL, p))
//	{
//		puts(ret);
//	}
//	puts("");
//
//
//
//	char a[] = "114.514.19.19.810";//���ʮ���Ƶı�ʾ��ʽ
//	char* p1 = ".";
//	char* ret1 = NULL;
//	for (ret1 = strtok(a, p1); ret1 != '\0'; ret1 = strtok(NULL, p1))
//	{
//		puts(ret1);
//	}
//
//	return 0;
//}













//////////////////////////////////////////       ������Ϣ���溯��



///////////////////////    strerror()
//////���Ѵ������Ӧ�Ĵ�����Ϣ���������
////
//////������char *strerror( int errnum );
////
//////Strerror����һ��ָ�������Ϣ�ַ�����ָ�롣������strerror�ĵ��ÿ��Ը��Ǹ��ַ�����
//
//#include<errno.h>
//
//int main()
//{
//	//������    ������Ϣ
//	// 0   -   No error
//	// 1   -   Operation not permitted
//	// 2   -   No such file or directory
//	// 3   -   No such process
//	// ...     ...
//	//errno��һ��ȫ�ֵĴ���������������˴��󣬾ͻ�Ѷ�Ӧ�Ĵ����룬��ֵ��errno��
//	//errno��Ӧͷ�ļ�#include<errno.h>
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
//	//���ļ�
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

























////////////////////////////////////////////////////////////////////////�ַ�����////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Ŀ¼��
//is....()
//tolower()
//toupper()
 








////////////////////////////////////////////       �ַ����ຯ��
//// 
//////���溯��ͷ�ļ���#include<ctype.h>
////
//////����           ������Ĳ����������������ͷ�����
//////iscntrl()      //�κο����ַ�
//////isspace()      //�հ��ַ����ո�' '����ҳ'\f'������'\n'���س�'\r'���Ʊ��'\t'���ߴ�ֱ�Ʊ��'\v'
//////isdigit()      //ʮ�������� 0-9
//////isxdigit()     //ʮ���������֣�0-9��a-f, A-F
//////islower()      //Сд��ĸ a-z
//////isupper()      //��д��ĸ A-Z
//////isalpha()      //��ĸ a-z �� A-Z
//////isalnum()      //��ĸ�����֣�a-z , A-Z , 0-9
//////ispunct()      //�����ţ��κβ��������ֻ�����ĸ��ͼ���ַ����ɴ�ӡ��
//////isgraph()      //�κ�ͼ���ַ�
//////isprint()      //�κοɴ�ӡ�ַ�������ͼ���ַ��Ϳհ��ַ�
////
////
//////���Ϻ�����Ϊ �жϲ������ַ����Ƿ�������������Ϸ��ط�0���棩�������ϣ��ͷ���0���٣�
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













//////////////////////////////////////////       �ַ�����Сд��ת������
////
//////tolower()  ��дתСд����������Сд���ı䣩
//////toupper()  Сдת��д����
////
//////������int tolower( int c );
//////������int toupper( int c );
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


//////////////�ַ�����Сд����
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
























 
////////////////////////////////////////////////////////////////////////�ڴ��������////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////memory���ڴ�
//
////��Ӧͷ�ļ���#include<string.h> �� #include<memory.h>
// 
//Ŀ¼��
//memcpy()
//memmove()
//memcmp()
//memset()
//
//////ǰ���<string.h>�µ�strxxx�������ǽ��ܶ��ַ������в���
//////����ȴ���ܲ������Ρ������͡��ṹ�������
//////���Գ�����������ڴ溯��




////////�����ڴ����������Ĺ�ͬ�㣺
////////1.ָ���������void*���ͣ���Ϊֱ�Ӷ��ڴ���в��������Կ��Զ���������ʹ�ã�����void*
////////2.������Ҫ�ϴ� size_t count ��Ҳ������Ҫ�����Ŀռ䣬���ֽ�Ϊ��λ
////////3.����ָ�����Ͷ���void*����count���ֽ�Ϊ��λ��ʹ�ú�������ʱҪ��ָ��ǿתΪ(char*)����
////////4.�������㱣֤���ڴ�����������ڴ�����޸�ʱ�����ǰ����ڴ�ԭ����˳��һ�ֽ�һ�ֽڵ��޸ġ�����ԭ����ʲô���ͣ����ڶ������ֽ�Ϊ��λ��
////////5.�����ص���Բο��ַ�������












///////////////////////////    memcpy()
//////���ڻ�����֮�临���ַ���
////
//////������void *memcpy( void *dest, const void *src, size_t count );    //count��λ���ֽ�
////
////
//////dest���µĻ�����
//////src��Ҫ���ƵĻ�����
//////count��Ҫ�����ڴ�ġ��ֽ���������Ϊ�������;�Ϊvoid*��������Ҫ�ֽ�����ȷ�����������ڴ棩
////
////
//////memcpy������src��count���ֽڿ�����dest�У����Դ��ַ��Ŀ�ĵ�ַ�ص����򲻱�֤�����ص�������Դ��ַ��ԭʼ�ֽں��ٱ����ǡ�ʹ�ú��� memmove() �������ص�����
// 
//////�ص����򸲸ǵ����ӣ� ���arr[]={1,2,3,4,5,6,7};Ҫ�� 1,2,3,4,5 ������ 3,4,5,6,7 �����򣬾ͻ�����ַ������ǣ����ܵ���Դ�ַ������ݷ����ı��bug
//////������ʵ�ϵ�ǰ�������޸�����Щbug����ʹ�ص���memcpyҲ���Դ���Ҳ���ǵ�ǰ������memcopy��memmoveЧ��һ��
//// 
//// 
////// C���Ա�׼�涨��
////// memcpy()  ֻҪ���� ���ص� ���ڴ濽���Ϳ���
////// memmove() �����ص��ڴ�Ŀ��� 
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
//      ////����ǿ������ת�����ǵü����ţ���Ŀ�����������ȼ���ͬʱ������Դ��ҡ��󣬹ʼ����ŷ�ֹǿ������ת��ǰ��++
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
//	struct S arr3[] = { {"����",12},{"����",18} };
//	struct S arr4[4] = { 0 };
//	memcpy(arr4, arr3, sizeof(arr3));
//
//	int a[] = { 1,2,3,4,5,6,7,8,9 };//12345������34567
//	memcpy(a + 2, a, 5 * sizeof(int));//1 2 1 2 1 2 1 8 9 //��Щ�������޸����������
//                                  ////�ڴ��ص�ʱ��Ҫ�õ�memmove()
// 
//	return 0;
//}











/////////////////////////////    memmove()
//////����һ���������ƶ�����һ���������� 
//// 
//// 
//////������void *memmove( void *dest, const void *src, size_t count ); 
//// 
//// 
//////memmove������src��count���ֽڿ�����dest�У����Դ�����Ŀ�������ĳЩ�����ص���memmoveȷ�����ص������ԭʼԴ�ֽڱ����ƺ��ٱ����ǡ� 
//////�÷�������memcpy(),����memmove()���Դ�����ʱ�ڴ��ص��������Ҳ���Դ����ص������
////
////
////// C���Ա�׼�涨��
////// memcpy()  ֻҪ���� ���ص� ���ڴ濽���Ϳ���
////// memmove() �����ص��ڴ�Ŀ��� 
//
//
//#include<assert.h>
//
//void* my_memmove(void* dest, const void* src, size_t count)
//{
//	assert(dest && src);
//	void* ret = dest;
//
//	if ((char*)dest - (char*)src > 0)//��dest��ַ����src����ӽ�β��ʼ�����ſ����ڴ�
//	{
//		((char*)dest) += count - 1;
//		((char*)src) += count - 1;
//		while (count--)
//		{
//			*((char*)dest)-- = *((char*)src)--;
//		}
//	}
//	else//��dest��ַС��src����ӿ�ͷ��ʼ���ſ����ڴ�
//	{
//		while (count--)
//		{
//			*((char*)dest)++ = *((char*)src)++;
//		}
//	}
//	return ret;
//}
//
//////////���� ���ſ��� ����������Ż�Ϊ��
////////// while (count--)
////////// {
//////////  	*((char*)dest + count) = *((char*)src + count)
////////// }
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
//	struct S arr3[] = { {"����",12},{"����",18} };
//	struct S arr4[4] = { 0 };
//	memmove(arr4, arr3, sizeof(arr3));
//
//	int a[] = { 1,2,3,4,5,6,7,8,9 };//�ص������12345������34567
//	memmove(a + 2, a, 5 * sizeof(int));
//
//	int b[] = { 1,2,3,4,5,6,7,8,9 };//�ص������34567������12345
//	 memmove(b, b + 2, 5 * sizeof(int));
//
//	return 0;
//}












///////////////////////////////    memcmp()
//////���Ƚ������������е��ַ�(����С�˱�����˳�����ַ�Ϊ��λ�Ƚ�)��
////
////
//////������int memcmp( const void *buf1, const void *buf2, size_t count );
////
////
//////memcmp�����Ƚ�buf1��buf2�ĵ�һ�������ֽڣ�������ָʾ����֮���ϵ��ֵ
//////�����������ڴ�Ĵ��С��ԭ����˳�򣬴ӵ͵�ַ���ߵ�ַһһ���бȽ�
//// 
//////  ����ֵ  ���黺������һ����ͬ�ֽڵĹ�ϵ
//////  > 0     buf1 >  buf2
//////    0     buf1 == buf2
//////  < 0     buf1 <  buf2
//
//
//
//int main()
//{
//	//01 00 00 00 02 00 00 00 03 00 00 00 ...
//	//01 00 00 00 02 00 00 00 05 00 00 00 ...
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 1,2,5,4,3 };
//
//	int ret = memcmp(arr1, arr2, 9);//�Ƚ�ǰ9���ֽ�
//
//	printf("%d\n", ret);//-1    ��Ϊ��9���ֽ� 03 < 05
//
//	return 0;
//}












/////////////////////////////////    memset()
//////��������������Ϊָ�����ַ���
////
////
//////������void *memset( void *dest, int c, size_t count );//countΪ�����Ŀռ��С����λ�ֽ�
////
////
//////memset��������dest��ʼ���Ѻ���count���ֽڵ��ڴ��������ó���Ҫ������
//
//
//int main()
//{
//	char arr[10] = "";
//	memset(arr, '#', sizeof(arr));
//	//# # # # # # # # # #
//
//	int arr1[10] = { 0 };
//	memset(arr1, 1, 10);
//    //16843009 16843009 257 0 0 0 0 0 0 0   
//	//����memset��һ���ֽ�һ���ֽڽ��п����ģ����Կ������Ϊ 0x 01 01 01 01 01 01 01 01 01 01 00 00 00 00 00 
//	//0x01010101 ��ֵΪ 16843009 ��0x01010000,С���ֽ���洢����ֵΪ0x00000101,Ϊ257
//
//	return 0;
//}


