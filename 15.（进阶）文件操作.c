//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>
//#include<errno.h>




////// C语言文件操作
//// 
//// 什么是文件
//// 文件名
//// 文件类型
//// 文件缓冲区
//// 文件指针
//// 文件的打开和关闭
//// 文件的顺序读写
//// 文件的随机读写
//// 文件的结束判定










///////////////////////////////////////////////本章函数

//fopen()
//FILE* fopen(const char* filename, const char* mode);
//打开文件，创建文件信息区(FILE结构体)，返回结构体区的指针(FILE*)

//fclose() 
//int fclose( FILE *stream );
//关闭文件流 

//fputc()
//将字符写入流
//int fputc( int c, FILE *stream );

//fgetc()
//从流中读取一个字符
//int fgetc( FILE *stream );

//fputs()
//将字符串写入流(写入一行)
//int fputs( const char *string, FILE *stream );

//fgets()
//从流中获取一个字符串(获取一行)
//char *fgets( char *string, int n, FILE *stream );

//fprintf()
//将格式化数据打印到流中
//int fprintf( FILE *stream, const char *format [, argument ]...);

//fscanf()
//从流中读取格式化的数据
//int fscanf( FILE *stream, const char *format [, argument ]... );

//sprintf()
//将格式化的数据写入字符串
//int sprintf( char *buffer, const char *format [, argument] ... );

//sscanf()
//从字符串中读取格式化的数据
//int sscanf( const char *buffer, const char *format [, argument ] ... );

//fwrite()
//将数据以二进制形式写入文件流
//size_t fwrite( const void *buffer, size_t size, size_t count, FILE *stream );

//fread()
//从文件流中读取二进制形式数据
//size_t fread( void *buffer, size_t size, size_t count, FILE *stream );

//fseek()
//将文件指针移动到指定位置(以文件指针的当前位置为起点,根据偏移量来调整文件指针)
//int fseek( FILE *stream, long offset, int origin );

//ftell()
//返回文件指针当前位置相对于起始位置的偏移量
//long ftell( FILE *stream );

//rewind()
//让文件指针的位置回到文件的起始位置
//void rewind( FILE *stream );

//perror()
//打印错误信息
//void perror( const char *string );

//feof()
//判断读取位置是否在结尾
//int feof( FILE *stream );


///////////////////////////////////////////////////////////////////////////






















////  什么是文件？
//磁盘上的文件就是文件
//但在程序设计中，文件分两种：【程序文件】、【数据文件】

// 【程序文件】
//包括源文件(.c)、目标文件(windows环境后缀为.obj)、可执行程序(windows环境后缀为.exe)
// 【数据文件】
//文件内容不一定是程序，而是程序运行时读写的数据，比如程序运行需要从中读取数据的文件，或者输出内容的文件


//以前各章所处理的数据的输入输出都是以终端为对象的，即从终端的键盘输入数据，运行结果显示到显示器上。
//其实有时候我们会把信息输出到磁盘上，当需要的时候再从磁盘上把数据读取到内存中使用，这里处理的就是磁盘上的文件







////  文件名
//一个文件要有一个唯一的文件标识，以便用户识别和引用
//文件包含3部分：【文件路径+文件名主干+文件后缀】
//例如：c:\code\test.txt
//为了方便起见，文件标识常被称为文件名







////  文件类型
//根据数据的组织形式，数据文件被称为【文本文件】或者【二进制文件】。
//数据在内存中以二进制的形式存储，如果不加转换的【以二进制形式输出到外存】，就是二进制文件。
//如果要求在外存上以ASCII码的形式存储，则需要在存储前转换。【以ASCII字符的形式存储】的文件就是文本文件。

// 一个数据在内存中是怎么存储的呢？
//【字符】一律以ASCII形式存储，【数值型数据】既可以用ASCII形式存储，也可以用二进制形式存储
//如果有10000，如果以ASCII码形式输出到硬盘，则磁盘中占5个字节（'1','0','0','0','0'，每个字符1字节）；
//             如果以二进制形式输出，则硬盘上只占4个字节（1个整型4字节，十六进制小端输出 00002710）








////  文件缓冲区
//ANSIC标准(C语言标准)采用【缓冲区文件系统】处理的数据文件的，所谓缓冲区文件系统是指系统自动地在内存中为程序的每一个正在使用的文件开辟一块缓冲区。
//【从内存向磁盘输出数据】会先送到内存的缓冲区中，装满缓冲区后才一起送到磁盘上。
//【从磁盘向计算机读入数据】，则从磁盘文件中读取数据输入到内存缓冲区（充满缓冲区），然后从缓冲区逐个地将数据送到程序数据区（程序变量等）.
//缓冲区的大小根据C编译器系统决定








////  文件指针
//缓冲文件系统中，关键的概念是【文件类型指针】，简称【文件指针】
//每个被使用的文件都在内存中开辟了一个相应的【文件信息区】，用来存放文件的相关信息（如文件名字、文件状态以及文件当前的位置等）
//这些信息是保存在一个结构体变量中的，该结构体类型有系统声明，取名【FILE】 

//struct file {
//	 char* ptr;
//	 int cnt;
//	 char* base;
//	 int flag;
//	 int file;
//	 int charbuf;
//	 int bufsiz;
// 	char* tmpfname;
//};

//不同的编译器的FILE类型包括的内容大同小异。
//每当打开一个文件的时候，系统会根据文件的情况自动创建一个FILE结构的变量，并填充其中信息。
//一般是通过一个FILE的指针来维护这个结构体，使用起来更加方便。
// 
//例如 FILE* pf -- 文件指针变量
//定义pd是一个指向FILE类型的指针变量，可以是ps指向某个文件的文件信息区（上一个结构体变量），通过文件信息区就能访问该文件。
//也就是说，【通过文件指针变量就能找到与它相关的文件】






















/////////////////////////////  文件的打开和关闭
////文件读写前应该打开文件，使用后应该关闭文件
////写程序的时候，在打开文件同时，都会返回应该FILE*的指针指向该文件，相当于建立了指针和文件的关系。
////ANSIC(标准C语言)规定使用fopen函数来打开文件，fclose来关闭文件。






//////////////////////    fopen() -- 打开文件函数,<stdio.h> 
////file open,打开文件，创建文件信息区(FILE结构体)，返回结构体区的指针(FILE*)
// 
////声明：FILE *fopen( const char *filename, const char *mode );
//
////参数：char *filename -- 文件名
////      char *mode  --  打开方式(下面的表格)
//
////返回值：打开文件成功，会创建一个文件信息区(FILE类型的结构体变量)；打开失败则不创建
////        打开文件成功，返回FILE*类型信息区的指针
////        打开失败，不创建信息区，返回NULL



//  【提示】：下面表格中： r:(读)read  w:(写)write  a:(追加)add  b:(二进制)binary
//  ----------------------------------------------------------------------------------------
//  |文件打开(使用)方式  | 含义                                       | 如果指定文件不存在
//  ----------------------------------------------------------------------------------------
//  |  "r" (只读)        | 为了输入数据，打开一个已保存的文本文件     | 出错
//  |  "w" (只写)        | 为了输出数据，打开一个文本文件             | 建立一个新文件
//  |  "a" (追加)        | 向文本文件尾添加数据                       | 出错
//  |  "rb" (只读)       | 为了输入数据，打开一个二进制文件           | 出错
//  |  "wb" (只写)       | 为了输出数据，打开一个二进制文件           | 建立一个新文件
//  |  "ab" (追加)       | 向二进制文件尾添加数据                     | 出错
//  |  "r+" (读写)       | 为了读和写，打开一个文本文件               | 出错
//  |  "w+" (读写)       | 为了读和写，新建一个文本文件               | 建立一个新文件
//  |  "a+" (读写)       | 打开一个文本文件，在文件结尾进行读写       | 建立一个新文件
//  |  "rb+" (读写)      | 为了读和写，打开一个二进制文件             | 出错
//  |  "wb+" (读写)      | 为了读和写，新建一个二进制文件             | 建立一个新文件
//  |  "ab+" (读写)      | 打开一个二进制文件，在文件结尾读和写       | 建立一个新文件
//  ----------------------------------------------------------------------------------------
// 
// r读：打开当前路径下文件。
// w写：在当前路径新建文件。*注意：打开位置若有同名文件，会销毁旧文件，拿新的覆盖掉
// a追加：打开已有文件，并可以在其之后追加新数据



//int main()
//{
//	////////【fopen打开文件】test.txt
//
//	////【相对路径】，相对于当前代码在哪个路径底下
//	//// . 表示当前路径
//	//// .. 表示上级路径
//	FILE* pf = fopen("test.txt", "r");//文件就在当前文件夹
//	FILE* pf = fopen(".\\test.txt", "r");//文件就在当前文件夹，和上一个一样
//	FILE* pf = fopen("..\\test.txt", "r");//文件在当前路径的上一级路径
//	FILE* pf = fopen("..\\..\\test.txt", "r");//文件在当前路径的上两级路径
//
//	////【绝对路径】，明确的指出了文件的具体路径
//	FILE* pf = fopen("C:\\Users\\lenovo\\source\\repos\\test - 1\\test - 1\\test.txt", "r");//这里\\的目的是，防止\变成转义字符
//	FILE* pf = fopen("C:/Users/lenovo/source/repos/test - 1/test - 1/test.txt", "r");//这里 \\ 和 / 都可以
//
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	return 0;
//}


//注意：当写路径时，/会和下一个字符被当成转义字符，所以要写成 // 
//  默认情况向下的路径中，windows是\,linux和unix下是/ 但在win中没有区别。
// 在WINDOWS里面很多情况下/和\是可以通用的，尤其是在地址栏中。但是，正规的地址表示还是应该用/，比如C：/WINDOWS等。
// 
//  由于 \ 也是转义字符的起始字符。由此， 路径中的 \ 通常需要使用 \\，如果是 / 就不用转义了
//  例如：C中文件操作，c:\\kkk\\dd.txt ；c : / kkk / dd.txt一样










//////////////////////    fclose() -- 关闭文件函数,<stdio.h> 
////关闭文件流 
//
////声明：int fclose( FILE *stream );
//
////参数：指向(结构体)文件信息区的（FALE*类型）指针
//
////返回值：若关文件动作成功则返回0，有错误发生时则返回EOF，并把错误代码存到errno




//////文件的打开和关闭演示
//int main()
//{
//	//打开文件
//	FILE* pf = fopen("test.txt", "r");//打开一个文本文件
//	//FILE* pf = fopen("test1.txt", "w");//创建一个新的文本文件，若同路径下有同名文件，直接摧毁并用新的覆盖
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//打开成功
//	
//	//读文件
//	
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


























/////////////////////////////        文件的顺序读写

//  ---------------------------------------------------
//  |函数名       | 功能                | 适用于
//  ---------------------------------------------------
//  |  fgetc      | 字符输入函数        | 所以输入流（即可以从键盘、文件中获取信息）
//  |  fputc      | 字符输出函数        | 所有输出流（即可以输出到屏幕、文件中）
//  |  fgets      | 文本行输入函数      | 所以输入流
//  |  fputs      | 文本行输出函数      | 所有输出流
//  |  fscanf     | 格式化输入函数      | 所以输入流
//  |  fprintf    | 格式化输出函数      | 所有输出流
//  |  fread      | 二进制输入          | 文件
//  |  fwrite     | 二进制输出          | 文件
//  ---------------------------------------------------


//从键盘输入
//输出到屏幕
//键盘&屏幕都是外部设备
//
//键盘 - 标准输入设备
//屏幕 - 标准输出设备
//以上二者，是一个程序的默认打开的两个流设备
// 
//一个程序运行，默认打开三个流，类型（FILE*）
//stdin - 标准输入设备
//stdout - 标准输出设备
//stderr
//
//int main()
//{
//	int ch = fgetc(stdin);//直接从标准输入流(键盘)读取数据
//	fputc(ch, stdout);  //直接把数据输出到标准输出流(屏幕)
//	return 0;
//}







//////////////////////////////////    fputc()
////将字符写入流 - <stdio.h>
////适用于所有输出流 - 可以输出到屏幕、文件中
// 
////声明：int fputc( int c, FILE *stream );
//
////参数：c:代写字符  stream:流（指向FILE结构的指针）
////返回值：返回写入的字符


//int main()
//{
//	FILE* pf = fopen("test.txt", "w");//只写
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//
//	//写文件
//	fputc('h', pf);
//	fputc('e', pf);
//	fputc('h', pf);
//	fputc('e', pf);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}







//////////////////////////////////    fgetc()
////从流中读取一个字符 - <stdio.h>
////适用于所有输入流 - 可以从键盘、文件中获取信息
//
////声明：int fgetc( FILE *stream );
//
////参数：stream:流（指向FILE结构的指针）
////返回值：返回读取的字符


//int main()
//{
//	FILE* pf = fopen("test.txt", "r");//只读
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//
//	//读文件（此时文件里有东西）
//	printf("%c", fgetc(pf));//读完一个自动读下一个
//	printf("%c", fgetc(pf));
//	printf("%c", fgetc(pf));
//	printf("%c", fgetc(pf));
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}







//////////////////////////////////    fputs()
////将字符串写入流(写入一行) - <stdio.h>
////适用于所有输出流 - 可以输出到屏幕、文件中
//
// 
////声明：int fputs( const char *string, FILE *stream );
// 
////参数：char *string：要输出的字符串的首地址
////      FILE* stream  ：流（指向FILE结构的指针）
//
////返回值：成功返回非负值，是白返回EFO


//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//
//	//读文件
//	fputs("hello\n", pf);
//	fputs("world", pf);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}







//////////////////////////////////    fgets()
////从流中获取一个字符串(获取一行) - <stdio.h>
////适用于所有输入流 - 可以从键盘、文件中获取信息
//
// 
////声明：char *fgets( char *string, int n, FILE *stream );
// 
////参数：char *string：用来存放文件中数据的【字符串首地址】
////      int n：可读取的最大字符数，即【用来存放数据的字符串的大小】
////      FILE* stream  ：流（指向FILE结构的指针）
//
////返回值：返回用来存放文本数据的字符串string的(char*)首地址 
// 
// 
// 
//////重点： 
//////  fgets函数从输入流参数中读取一个字符串，并将其存储在string中
//////  区别于gets()：gets()只能从标准输入流(键盘)获取信息；而fgets()可从所有输入流(键盘、文件)获取信息
//
//////注意：
//////  若从文本中读入的某串字符串在文本中换过行，则string结尾的'\0'前一个字符是'\n'


//int main()//操作文件
//{
//	char arr[100] = { 0 };
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//
//	//读文件
//	fgets(arr, sizeof(arr), pf);
//	printf("%s", arr);
//	fgets(arr, sizeof(arr), pf);
//	printf("%s", arr);
//	puts("");
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//
////注意，若文本中字符串换过行，则本行 '\0' 前有 '\n'，打印时不用换行







//////////////////////////////////    fprintf()
////将格式化数据打印到流中 - <stdio.h>
////适用于所有输出流 - 可以输出到屏幕、文件中
//
// 
////声明：int fprintf( FILE *stream, const char *format [, argument ]...);
// 
// 
////参数： FILE* stream  ：流（指向FILE结构的指针）
////       后面的参数就和printf参数一样，如"%d\n%c\n%s",a,c,arr
//
// 
////返回值：返回写入的字符数，发出错误时返回一个负数


//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//
//int main()
//{
//	struct S s = { 10,3.14f,"abc" };
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//
//	//格式化的形式输入到文件
//	fprintf(pf, "%d\n%f\n%s", s.n, s.score, s.arr);
//
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}







//////////////////////////////////    fscanf()
////从流中读取格式化的数据 - <stdio.h>
////适用于所有输入流 - 可以从键盘、文件中获取信息
//
////声明：int fscanf( FILE *stream, const char *format [, argument ]... );
//
//
////参数： FILE* stream  ：流（指向FILE结构的指针）
////       后面的参数就和scanf参数一样，如"%d %c %s",&a,&c,arr



//下面默认文件中数据为
//10
//3.14f
//abc

//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//
//int main()
//{
//	struct S s = { 0 };
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//
//	//格式化获取文件中是数据，输入到s中
//	fscanf(pf, "%d %f %s", &(s.n), &(s.score), &s.arr);
//	printf("%d %f %s", s.n, s.score, s.arr);
//	
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


////格式化输入、输出函数也可以适用于标准输入、输出流
//int main()
//{
//	struct S {
//		int n;
//		float score;
//		char arr[10];
//	};
//	struct S s = { 0 };
//
//	fscanf(stdin, "%d %f %s", &(s.n), &(s.score), s.arr);
//	fprintf(stdout, "%d %f %s", s.n, s.score, s.arr);
//
//	return 0;
//}






////////////////////////////////////////////补充： sprintf()和sscanf()


//////////////////////////////////    sprintf()
////将格式化的数据写入字符串 - <stdio.h>
//
////声明：int sprintf( char *buffer, const char *format [, argument] ... );
//
////参数：用于储存输出数据的(char*)字符串首地址
////      后面的参数就和printf参数一样，如"%d\n%c\n%s",a,c,arr
//
//
////注意：该函数将参数中数据转化成【字符】存放到字符串中，打印出来的所有空格、符号、数字都是字符串的元素


//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//
//int main()
//{
//	struct S s = { 100,3.14,"abc" };
//	int arr[100] = { 0 };
//
// 	//把格式化是数据转化成字符串存入arr中
//	sprintf(arr, "%d %.2f %s", s.n, s.score, s.arr);
//	//此时字符串arr内容为100 3.14 abc\0
//	printf("%s\n", arr);
//
//	return 0;
//}






//////////////////////////////////    sscanf()
////从字符串中读取格式化的数据 - <stdio.h>
//
////声明：int sscanf( const char *buffer, const char *format [, argument ] ... );
//
////参数：从该字符串中拿出数据
////      后面的参数就和scanf参数一样，如"%d\n%c\n%s",&a,&c,arr
//
//
////注意：该函数是把数据从字符串中拿取出来，存放到其参数中取地址的变量中。


//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//
//int main()
//{
//	struct S s = { 100,3.14,"abc" };
//	struct S tmp = { 0 };
//	int arr[100] = { 0 };
//
//	//把格式化是数据转化成字符串存入arr中
//	sprintf(arr, "%d %.2f %s", s.n, s.score, s.arr);
//	//此时字符串arr内容为100 3.14 abc\0
//	
//	//从arr中读取格式化的数据到结构体tmp中
//	sscanf(arr, "%d %f %s", &(tmp.n), &(tmp.score), tmp.arr);
//	printf("%d\n%f\n%s", tmp.n, tmp.score, tmp.arr);
//
//	return 0;
//}








//////////////////////////////////    fwrite()
////将数据以二进制形式写入文件流
////只适用于文件
// 
// 
////声明：size_t fwrite( const void *buffer, size_t size, size_t count, FILE *stream );
//
////参数：void *buffer：指向要写入数据的指针
////      size：要写入数据的大小
////      count：要写入几个数据
////      FILE* stream：流（指向FILE结构的指针）
//
////返回值：返回实际写入的完整项数，如果发生错误，该数可能小于count


//struct S
//{
//	char name[20];
//	int age;
//	double score;
//};
//
//int main()
//{
//	struct S s = { "张三", 20, 66.6 };
//
//	FILE* pf = fopen("test.txt", "wb");//只写（二进制形式）
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	//二进制形式写文件
//	fwrite(&s, sizeof(s), 1, pf);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}








//////////////////////////////////    fread()
////从文件流中读取二进制形式数据
////只适用于文件
// 
// 
////声明：size_t fread( void *buffer, size_t size, size_t count, FILE *stream );
//
////参数：void *buffer：用来存储读从文件取出的数据的指针
////      size：要读取数据的大小
////      count：要读取几个数据
////      FILE* stream：流（指向FILE结构的指针）
//
////返回值：返回实际读取了几项，如果发生错误或在达到count之前遇到文件结束，则该数可能小于count，一项也未读取返回0


//这里默认文件内数据是结构体{ "张三", 20, 66.6 }的二进制形式

//struct S
//{
//	char name[20];
//	int age;
//	double score;
//};
//
//int main()
//{
//	struct S tmp = { 0 };
//
//	FILE* pf = fopen("test.txt", "rb");//只读（二进制形式）
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	//读取二进制文件
//	fread(&tmp, sizeof(tmp), 1, pf);
//	printf("%s %d %lf", tmp.name, tmp.age, tmp.score);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}









/////////////////////////////////////////////////  以上函数总结：
////////////从输入流获取数据；将数据输出到输出流
////具体解释如下


// scanf和printf：    是针对【标准输入流/标准输出流】的格式化输入/输出语句
// fscanf和fprintf：  是针对【所有输入流/所有输出流】的格式化输入/输出语句
// sscanf和sprintf：  sscanf是从字符串中读取格式化的数据，sprintf是把格式化的数据存储到字符串中
//
//
////以下为【从xxx读入数据，读入到a,b中】 - xxx为类scanf函数的第一个指针类型的参数，没有该参数即默认为标准输入流
//scanf("%d %d",&a,&b);是从键盘读取数据，存放到变量a,b
//fscanf(stdin,"%d %d",&a,&b);是从标准输入流(键盘)读取数据，存放到a,b中
//fscanf(pf,"%d %d",&a,&b);是从文件流中读取数据，存放到a,b中
//sscanf(arr,"%d %d",&a,&b);是从字符串中读取数据，存放到a,b中
//
// 
////以下为【把a,b的数据输出到xxx中】 - xxx为类printf函数的第一个指针类型的参数，没有该参数即默认为标准输出流
//printf("%d %d",a,b);是把a,b输出到屏幕
//fprintf(stdout,"%d %d",a,b);是把a,b输出到标准输出流(屏幕)
//fprintf(pf,"%d %d",a,b);是把a,b输出到文件流中
//sprintf(arr,"%d %d",a,b);a,b输出到字符串中



//getchar();//从标准输入流读入字符
//fgetc(stdin);//从标准输入流读入字符
//fgetc(pf);//从文件流读入字符
// 
//putchar('a');//将字符输出到标准输出流
//fputc('a');//将字符输出到标准输出流
//fputc('a', pf);//将字符输出到文件流



//gets();//从标准输入流读入字符串
//fgets(arr,sizeof(arr),stdin);//从标准输入流读入字符串存入arr中
//fgets(arr, sizeof(arr), pf); //从文件流读入字符串存入arr中
// 
//puts("abc");//将字符串输出到标准输出流
//fputs("abc",stdout);//将字符串输出到标准输出流
//fputs("abc", pf);//将字符串输出到文件流



//fread(&s, sizeof(s), 1, pf);//从文件流中读取二进制数据存入s中
//fwrite(&s, sizeof(s), 1, pf);//将s以二进制形式写入文件流中


























/////////////////////////////        文件的随机读写



//////////////////////////////////    fseek()
////将文件指针移动到指定位置（【以文件指针的当前位置为起点】，【根据偏移量来调整】文件指针）- <stdio.h>
//
////声明：int fseek( FILE *stream, long offset, int origin );
//
////参数：FILE *stream：流（指向FILE结构的指针）
////      long offset：偏移量（单位字节，分正负）。如偏移量为2，向后移动2字节；如偏移量为-2，向前移动2字节
////      int origin：文件指针的当前位置
//// 
////      PS. origin包含以下3种：1.SEEK_CUR：文件当前位置
////                             2.SEEK_END：文件末尾位置（默认指向【最后一个字符再后面一个位置】）
////                             3.SEEK_SET：文件起始位置（默认指向第一个字符）



////这里默认文件内为 abcdef
//
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//
//	//定位文件指针1
//	fseek(pf, 2, SEEK_CUR);
//	//abcdef，当前位置，即起始位置'a'，指针向后偏移2，指向'c'
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	////定位文件指针2
//	fseek(pf, -2, SEEK_END);
//	//abcdef，末尾位置默认为'f'的后一个位置，指针向前偏移2，指向'e'
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}








//////////////////////////////////    ftell()
////返回文件指针当前位置相对于起始位置的偏移量 - <stdio.h>
// 
////声明： long ftell( FILE *stream );
//
////参数：FILE *stream：流（指向FILE结构的指针）
//
////返回值：返回文件指针当前位置相对于起始位置的偏移量



////这里默认文件内为 abcdef
//
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//
//	//定位文件指针（文件内容为abcdef）
//	fseek(pf, -2, SEEK_END);//这是指向e
//
//	//返回相对于起始位置的偏移量
//	int pos = ftell(pf);
//	printf("%d\n", pos);//4
//	
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}









//////////////////////////////////    rewind()
////让文件指针的位置回到文件的起始位置
//
////声明：void rewind( FILE *stream );
//
////参数：FILE *stream：流（指向FILE结构的指针）



////这里默认文件内为 abcdef
//
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//
//	//定位文件指针（文件内容为abcdef）
//	fseek(pf, -2, SEEK_END);//这是指向e
//
//	//让文件指针返回起始位置
//	rewind(pf);
//	int pos = ftell(pf);
//	printf("%d\n", pos);//0
//	
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


























/////////////////////////////        打印错误信息


//////////////////////////////////    perror()
////打印错误信息 - <stdio.h> or <stdlib.h>
//
////声明：void perror( const char *string );
//
////参数：我们要打印的字符串
//
////作用：参数为我们自己填写的字符串string，让打印结果更灵活
////      首先打印string，后面跟着冒号，然后是产生错误的最后一个库调用的系统错误消息，最后是换行符。
////      如果参数直接填空字符串 "" ，则不打印冒号 
////      如果string是空指针或指向空字符串的指针，perror只打印系统错误消息。




//int main()
//{
//	FILE* pf = fopen("????.txt", "r");//这里文件夹内没有在这个文件
//	if (pf == NULL)
//	{
//		perror("OPEN FILE ????.TXT");
//		//这里结果是  OPEN FILE ????.TXT: Invalid argument（自带换行）
//		return 0;
//	}
//	//...
//	return 0;
//}

////可以看出，该函数会【先打印我们提供的字符串】然后【: 错误码打对应的错误信息\n】
////          如果参数填写 "" ，则不打印冒号 














/////////////////////////////        文件结束判定
////被错误使用的feof（当读取位置在结尾时，返回真；当读取位置不在结尾，返回0）
////牢记：在文件读取的过程中，不能使用fefo函数的返回值直接来判断文件是否结束
////      而是应用于【当文件读取结束时，判断时读取失败结束，还是遇到文件结尾结束】
// 
//
// 
////1.【文本文件读取是否结束】：判断返回值是否为EOF（fgetc），或者（NULL）（fgets）；
//// 
////   例如：fgetc判断是否为EOF(-1) -- 字符类函数，读到文件结束时返回EOF(EOF是宏，值-1)
////         fgets判断返回值是否为NULL  -- 字符串类函数，读到文件结束时返回NULL
////
// 
////2.【二进制文件读取是否结束】：判断返回值是否小于实际要读的个数
//// 
////   例如：fread判断返回值是否小于实际要读的个数 - fread返回实际要读的个数，当返回值小于实际个数时，说明这次肯定读完了
//
// 
// 
////***********************************************************************
////综上【文件结束】：可能是读取到结尾时结束，也可能是遇到问题中断结束
////     若是文件结束的同时，feof为真(读取位置在结尾)，则表示文件是正常关闭
////***********************************************************************
// 
//  
////注意：如果一个文件打开，里面什么都没有，第一次读到的就是EOF




//////////////////////////////////   feof()
////【当文件读取结束时】，用该函数判断文件结束原因（文件读取失败or文件结束） - <stdio.h>
//
////声明：int feof( FILE *stream );
//
////参数：FILE *stream：流（指向FILE结构的指针）
//
////返回值：若读取指针位置是结尾，返回真
////        若读取指针位置不是结尾，返回0
//
//
////***********************************************************************
////【文件结束】：可能是读取到结尾时结束，也可能是遇到问题中断结束
//// 若是文件结束的同时，feof为真(读取位置在结尾)，则表示文件是正常关闭
////***********************************************************************



//int main()
//{
//	int c;
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("File open failed");//打印错误信息
//		return 0;
//	}
//
//	//fgetc 当读取失败时或文件结束时，都返回EOF
//	while ((c = fgetc(pf)) != EOF)//循环打印(fgetc用完一次指针自动向后移1)
//	{
//		putchar(c);
//	}
//	puts("");
//
//
//	//判断结束原因
//	if (ferror(pf))//如果遇到错误结束，ferror(pf)返回真
//	{
//		puts("读取失败");
//	}
//	else if(feof(pf))//如果是文件结束而退出，feof(pf)返回真
//	{
//		puts("遇到结束标志而结束");
//	}
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

 