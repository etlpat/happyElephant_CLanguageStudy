//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//////////////                         1. 主函数 int main(){   return 0;}
//int main()
//{
//	char x = 'A';
//	printf("%c\n",x);
//	return 0;
//}
// 
// 
// 
//////////////////                       2.  浮点数float
//int main()
//{
//	float num = 99.9f;
//	printf("%f", num);
//    return 0;
//}


//////////////////////                 3.  sizeof  计算所占字节大小
//int main()
//{
//	printf("%d\n", sizeof(char));
//	printf("%d\n", sizeof(short));
//	printf("%d\n", sizeof(int));
//	printf("%d\n", sizeof(long));
//	printf("%d\n", sizeof(long long));
//	printf("%d\n", sizeof(float));
//	printf("%d\n", sizeof(double));
//	return 0;
//}


//////////////////////            4. const : 指明常量，使其之后不会被赋为别的值
//int main()
//{
//	const int a = 5;
//	printf("%d\n", a);
//	a = 6;
//	printf("%d\n", a);
//	return 0;
//}
//
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>


////////////////////                5.  define:定义的标识符常量
//#define A 10
//int main()
//{
//	printf("%d",A);
//	return 0;
//}

// 
// 
////////////////////////             6.  scanf 与 &（取地址）
//int main()
//{
//	int num1;
//	int num2;
//	scanf(" %d %d",& num1,& num2);
//	int sum = num1 + num2;
//	printf("sum=%d\n", sum);
//	return 0;
//}

//////////////////                    7.  枚举常量   与   枚举常量的值
//enum color
//{
//	R,
//	G,
//  B
//};
//int main()
//{
//	printf("%d ",R);
//	printf("%d ",G);
//	printf("%d ",B);
//	return 0;
//}

//int main()
//{
//	int a = 233;
//	{
//		int a = 244;
//		printf("%d\n", a);
//	}
//	return 0;
//}






//////////////////                       8. strlen :string(绳，串，字符串） length = 计算字符串长度
//
//          #include<string.h>
//int main()
//{
//	char a[] = "abc";
//	char b[] = { 'a','b','c',/*'\0'*/};
//	/*printf("%s\n", a);
//	printf("%s\n", b);*/
//	printf("%d\n", strlen(a));
//	printf("%d\n", strlen(b));
//	return 0;
//}



////////////                                            9.  if 函数实例
//#define  _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//int main()
//{
//	int input;
//	printf("进入大学，\n你会好好学习吗？(1/0)>:\n");
//	scanf("%d", &input);
//	if (input == 1)
//		printf("好offer\n");
//	    else
//		printf("卖红薯\n");
//		return 0;
//}
// 
// 
//////////////////                             10.  while 和 if 函数实例
//int main()
//{
//	int line = 0;
//	printf("学习编程\n");
//	while (line <= 2000)
//	{
//		printf("敲一行代码:%d\n",line);
//		line++;
//	}
//	if (line > 2000)
//		printf("成功\n");
//	return 0;
//}
//
// 
// 
// 
// 
////////////////////                          11. 自定义函数 Add(x,y)
//int ADD(int x, int y)
//{
//	int z=x+y;
//	return z;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int sum = ADD( a ,b);
//	/*int num1;
//	int num2;
//	scanf("%d%d", &num1, &num2);
//	int sum = ADD(num1, num2);*/
//	printf("sum=%d\n",sum);
//	return 0;
//}
//
// 
// 
// 
//////////////////////                   12. 下标引用操作符（数组）  和  循环函数的使用
//#include<stdio.h>
//int main()
//{
//	   /*int i = 1;
//	   while (i <= 10);
//	   {
//	    	printf("%d", i);
//	   	    i=i+1;
//	    }*/
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	  //printf("%d ", arr[1]);
//	int x = 0;
//	while (x < 10)
//	{
//		printf("%d ", arr[x]);
//		x = x + 1;
//	}
//	if (x >= 10)
//		printf("good");
//	return 0;
//}



//////////////////                    13.  !:逻辑反操作，0：加   非0：真
//int main()
//{
//	int a = /*1*/0;
//	printf("%d\n", a);
//	printf("%d\n", !a);
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>




////////////////////                        14.  scanf的使用  的   比较大小
//int main()
//{
//	int num1;
//	int num2;
//	scanf(" %d %d",& num1,& num2);
//	if (num1 > num2)
//	   printf("%d>%d", num1, num2);
//	else
//	   printf("%d>%d", num2, num1);
//	return 0;
//}
// 
// 
//////////////                            15.   比较大小（函数）(if else)
//int compare(int a, int b)
//{
//	if (a > b)
//		printf("%d>%d\n",a,b);
//	else
//		printf("%d>%d\n",b,a);
//}
//int main()
//{
//	int num1;
//	int num2;
//	scanf("%d%d", &num1, &num2);
//	compare(num1, num2);
//    return 0;
//}

//#define  _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//
////////////////////                         16.  if else 的应用
// int main()
//{
//	int input;
//	printf("你好Jimmy,这里是一道数学题。\nlim（n→∞）[sin（1/n）/1/n]\n答案是？\n( 1 / 0 / -1 / e )>:\n");
//	scanf("%d", &input);
//	if (input == 1)
//		printf("恭喜你，你是天才\n");
//	else
//		printf("很抱歉，你是失败了\n");
//	return 0;
//}
// 
//////////////////                        17.  符号 ~   ：按位取反
//int main()
//{
//	int a = 0;
//	int b = ~a;
//	printf("%d \n%d", a, b);
//	return 0;
//}

///////////////////                   18.  int b = a++ ：首先 b=a, 之后 a++
//int main()
//{
//	int a = 10;
//	int b = /*a++; ++a;a--;*/--a;
//	printf("%d   ,%d", a, b); 
//	return 0;
//}

//
//////////////////                19.  ( 类型 )：强制类型转化，如下double的2.22被（int）转化为int
//int main()
//{
//	int a =(int) 8.38;
//	printf("%d", a);
//	return 0;
//}



//////////////////                            20.    逻辑与  逻辑或
// 
// 
////////////////////         C语言中，0是假，非0是真
//////////////               &&：逻辑与，两者均真，输出真
//////////////               ||：逻辑或，只要有真，输出真
//#include<stdio.h>
//int main()
//{
//	int a = /*2;*/0;
//	int b = /*4;*/0;
//	int c =/* a && b;*/a || b;
//	printf("%d", c);
//	return 0;
//}



//////////////////                         21.  按位与  按位或
// 
//
///////////按(二进制）位与&:先把十进制换算为二进制，；两数均为1，则输出1，否则输出0      比如101&011=001
///////////按(二进制）位或|:先把十进制换算为二进制，；两数只要有1，则输出1，否则输出0    比如101&011=111
//int main()
//{
//	int a = 5;//101
//	int b = 3;//011
//	int c = /*a &b;*/a | b;
//	printf("%d", c);
//	return 0;
//}
//
//
//
///////////////////////                    22.   %:按位余，输出余数
//int main()
//{
//	int c = 5 % 3;
//	printf("%d", c);
//	return 0;
//}
//




////////////////                           23. exp1 ? exp2 ; exp3    
//////////////////        意思是：判断表达式1成立吗？若成立，执行表达式2 ：若不成立，执行表达式3
//int main()
//{
//	int a =8000;
//	int b = 10;
//	int c = (a > b ? a : b);
//	printf("%d", c);
//	return 0;
//}


//
//#include<stdio.h>
/////////////////////                  24.  typedef:类型重定义，如下吧 int 定义为 i 方便使用
//int main()
//{   
//	typedef int i;
//	i a = 10;
//	printf("%d", a);
//	return 0;
//}

//typedef unsigned int a;
//int main()
//{
//	a num = 1;
//	printf("%d", num);
//	return 0;
//}




 ////////////////////                            25.  static的用法
//#include<stdio.h>
////////////////////////////         static       1、修饰局部变量，延长其生命周期
//////////////////                     原本变量a只在其大括号内起作用，出大括号外则被删除
//////////////////                     加上static后，a第一次赋的值可以保留到第二次计算
//void pri()
//{
//	static int a = 2;
//	a += 2;
//	printf("a = %d\n", a);
//}
//
//int main()
//{
//	int i = 0;
//	while (i <= 8)
//	{
//		pri();
//		i ++ ;
//	}
//	if (i > 8)
//	return 0;
//}

////////////             static：修饰全局变量，改变变量的作用域和函数的链接属性（外部链接属性变内部链接属性）
////////////             extern : 声明外部符号或外部函数
//#include<stdio.h>
//extern int Add(int a, int b);
//int main()
//{
//	extern x;
//	int y = 5;
//	int sum = Add(x, y);
//	printf("sum=%d", sum);
//	return 0;
//}




//////////////                          26 函数方法比大小
//extern ADD(int, int);
//int main()
//{
//	int a = 242332;
//	int b = 2321;
//	int max = MAX(a, b);
//	//////int max = (a > b ? a : b);
//	printf("max=%d\n", max);
//	return 0;
//}




/////////////                            27  用宏的方式取大小

//#define MAX(x, y) (x>y?x:y)
//int main()
//{
//	int a = 22;
//	int b = 123;
//	int max = MAX(a, b);
//	printf("max=%d\n", max);
//	return 0;
//}




//////////////////                         28 打印地址
////////            虽然int是四个字节，理论上打印四个地址，但是计算机只会取首地址
// /////                                   %p:打印地址
//int main()
//{
//	int a = 32;
//	printf("%p\n", &a);
//	return 0;
//}
//
//                                 29  int*  是向内存申请空间存放地址的数据类型
//int main()
//{
//	int a = 32;
//	int* m = &a;
//	printf("%p\n", m);
//	return 0;
//}




////////////                 30  * : 解引用，这里的*p,是将p(a的地址)解引用为a
////////////                   通过*对p解引用操作，找到了p(&a)指向的对象(a)
//int main()
//{
//	int a = 108;
//	int* p = &a;
////	printf("%p\n", p);
//	*p = 23;
//	printf("%d", a);
//	return 0;
//}



////////////                       31 字符数据类型的地址与解引用
//int main()
//{
//	char A = 'w';
//	char* B = &A;
//	*B = 'n';
//	printf("%c\n", A);
//	printf("%c\n", *B);
//	return 0;
//}
//



//
////////////////////                        32   结构体类型 
//////////////////                         struct:构建结构数组    
//
//struct BOOK
//{
//	char name[20];
//	float price;
//};
//int main()
//{
//	struct BOOK b = { "C语言程序设计" , 59.8};
//	printf("书名是《%s》\n", b.name);
//	printf("价格是：%f\n", b.price);
//    return 0;
//}
//
//
//
//
//
////////////////////               33  结构体类型中指针的使用
// 
//////////////////////            .     结构体变量.成员
//////////////////////            ->    结构体指针->成员
//struct A
//{
//	char no1[15];
//	int no2;
//};
//int main()
//{
//	struct A No = { "abcde",123 };
//	struct A* pNo = &No;
//	printf("%s\n",( * pNo).no1);
//	printf("%d\n",( * pNo).no2);
//	printf("%s\n", pNo->no1);
//	printf("%d\n", pNo->no2);
//	return 0;
//}
//
//
//
//
//////////////////            34  strcpy-string copy-字符串拷贝(库函数)-string.h
//////////////////              作用是可以改变数组的内容
//struct cc
//{
//	char a[23];
//	int b;
//};
//int main()
//{
//	struct cc qwer = { "12345",12 };
//	printf("%d\n", qwer.b);
//	qwer.b = 123;
//	printf("%d\n", qwer.b);
//	printf("%s\n", qwer.a);
//	strcpy(qwer.a, "45678");
//	printf("%s\n", qwer.a);
//	return 0;
//}