#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>









//void pri(int* arr)//形参已经是指针
//{
//	printf("%d\n", sizeof(arr));//8(64位系统)
//}
//int main()
//{
//	int arr[10] = { 0 };
//	printf("%d\n",sizeof(arr));//64
//	pri(arr);
//	return 0;
//}







//////////////////////////////////////        1.字符指针




/////////     可以不用数组，而是用指针p来描述字符串，此时的字符串为一个常量字符串
//int main()
//{
//	                   //"abcdef"是一个常量字符串
//	char* p = "abcdef";//可以用一个[指针]来充当[首元素地址]来描述一个[常量字符串]
//	printf("%c\n", *p);
//	printf("%s\n", p);//%s的逻辑是运行到'\0'为止
//	
//	*p = 'W';         //这里p描述的是[常量字符串]的首元素地址,不能随便赋值
//	printf("%s\n", p);//会报错：  引发了异常: 写入访问权限冲突
//	return 0;
//}

//////////  所以最好使用const修饰指针,防止指针被改动
//int main()
//{
//	const char* p = "abcdef"; //让代码更安全
//	printf("%s", p);
//	return 0;
//}




/////////////    关于常量字符串的题目
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdef";
//	const char* p1 = "abcdef";
//	const char* p2 = "abcdef";
//	if (arr1 == arr2)
//		printf("1相等\n");
//	else
//		printf("1不相等\n");
//	if (p1 == p2)
//		printf("2相等\n");
//	else
//		printf("2不相等\n");
//	return 0;
//}
////结果 1不相等 2相等
/// 1:因为是两个数组，其首元素地址肯定不相同
/// 2:这里是常量字符串，因为其不会改变，所以为了节省空间，规定常量字符串再内存中只有一个，储存于内存的静态区。
/// 常量字符串的首元素地址 p1 p2 都相同 ；但是地址p1 p2的地址(int**)不同



















////////////////////////////////////           2.指针数组（用于存放指针的数组）

//int main()//诸如此类就是指针数组
//{
//	int a = 1, b = 2, c = 3, d = 4;
//	int* pa[4] = { &a,&b,&c,&d };
//	char* pch[10] = { 0 };
//  int** Ppa = {0};
//	return 0;
//}




////////   指针数组的应用：存放数组首元素地址
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 6,7,8,9,0 };
//	int arr3[] = { 4,5,6,7,8 };
//	int* Parr[] = {arr1,arr2,arr3};
//	int i = 0, j = 0;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", *(Parr[i] + j));
//		}
//		printf("\n");
//	}
//	return 0;
//}


















////////////////////////////////////                     3.数组指针（指向 数组的指针）


///////////////////////      数组指针的定义方法 int(*p)[10] = &arr; p为数组指针;
///////////////////////        (*p)外边的是指针指向对象的类型，（）内*p代表它是指针，p是指针变量的名字
//
//int main()
//{
//	int* pa = NULL;       //pa是整形指针 - 指向整形的指针 - 可以存放整形的地址
//	char* pch = NULL;    //pch是字符指针 - 指向字符的指针 - 可以存放字符的地址
//	                   //数组指针 - 指向数组的指针 - 存放数组的地址
//	//arr - 首元素地址
//	//&arr[0] - 首元素地址
//	//&arr - 数组的地址
//
//	
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	int* p0 = arr;   //这是取数组首元素地址
//
//	int(*p)[10] = &arr;      // 所以用int(*p)[10]表示，其中int[10]是数组的类型
//	//若int* p,无法于整形指针区别；若int *p[10]，[]的优先级比*高，先和[]结合，表示存放指针的数组；
//	//上面p为数组指针
//
//	return 0;
//}



///////////////////////   区分下面p1 p2
////int *p1[10] ---- 存放指针的数组 -- 指针数组
////int(*p2)[10] --- 指向数组的指针 -- 数组指针 //p2的类型是 int(*)[10]





//////////////////     题目：标出pa的类型
//int main()
//{
//	char* arr[5];
//    ////问：###pa### = &arr ?                 //该指针指向数组的类型为char*[5]
//	char* (*pa)[5] = &arr;  ////  (*pa)代表pa变量为指针；外面的char*[5]是指针指向对象的类型 
//	return 0;
//}






//////////////////////////数组指针的简单应用
//// 
////////////////////  数组指针int(*p)[10]=&arr;  *p的作用相当于arr
///////////////////           int arr[10]
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	int(*pa)[10] = &arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		//       /////用法1，arr[i]变成(*p)[i]，相当于arr[i]
//		//printf("%d", (*pa)[i]);
//	           
//		//       ////用法2，pa解引用为*pa，相当于arr,可以当首元素地址使用
//		//printf("%d", *(*pa + i));
//	}
//}







///////////////////////数组指针具体应用
/////////（原理是：二维数组名 为 第一行的一维数组的地址）
//
//void pri1(int ARR[3][3], int x, int y)//（参数的数组的形式）
//{
//	int i, j;
//	for (i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", ARR[i][j]);
//		}
//		printf("\n");
//	}
//}
//
////二维数组int arr[3][3]传参，传的是（二维数组首元素）地址 ，是（一维数组）的地址，是int(*p)[3]
//void pri2(int(*p)[3], int x, int y)//（参数是指针的形式）
//{
//	int i, j;
//	for (i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			             /////因为p[i]是以p为首元素地址访问下标为i的元素 == *(p+i)
//			             //所以可以写成下面几种形式
//			printf("%d ", *(*(p + i) + j));
//			printf("%d ", (*(p + i))[j]);
//			printf("%d ", *(p[i] + j));
//			printf("%d ", p[i][j]);   //相当于(p[i])[j] == (每行的数组名)[j]
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
//	pri1(arr, 3, 3);//数组名传参，数组形式接收
//	printf("\n");
//
//
//	//arr -- 二维数组名 -- 首元素地址
//	//二维数组的首元素是什么？
//	//这里要把二维数组看作一维数组，每一行（每一个{}）看作一个元素
//	//那么arr[3][3]有三个元素，每一行是一个元素
//	//那么{{1,2,3},{4,5,6},{7,8,9}}的首元素就是{1,2,3}，是一维数组
//	//二维数组数组名是首元素地址，就是第一行的地址，是一个一维数组的地址
//	pri2(arr, 3, 3);
//    printf("\n");
//
//	return 0;
//}






/////////////////下标引用操作符[]的本质 *(p + i)
//////////p为指针，p[i]表示 -- 以p为起始地址，访问下标为i的元素
//////////         p[i] == *(p + i)
// 
//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", arr[i]);//数组名+下标引用操作符
//		printf("%d ", *(arr + i));//数组首元素地址+下标，解引用
//		printf("%d ", *(p + i));//和上一个一样
//		printf("%d ", p[i]);//以p为起始地址，访问下标为i的元素
//		 
//		                  //////由上面得出，p[i] == *(p + i)
//		printf("\n");
//	}
//	return 0;
//}






////////////////////区分下面是什么 -- [] 优先级比 *   高
// 
////  int *p                   //是一个指针，指向整形
////  int arr[5]               //是一个5个元素的整形数组
////  int *parr1[10]           //是一个数组，有10个元素，元素类型是int*，parr1是指针数组
////  int (*parr2)[10]         //是一个指针，指向一个有10个整形元素的数组                                 //parr2的类型为 int(* )[10]
////  int (*parr3[10])[5]      //是一个有10个元素的数组，每个元素是个数组指针，指向有5个整形元素的数组    //去掉parr3[10]，剩下的就是元素类型 int(* )[5]






















////////////////////////////////////            4.数组传参和指针传参




//////////////////////     一维数组传参
// 
/////////传参时，可以在形参部分写【数组】或【指针】
//
//void test1(int arr1[])//拿数组接收，可不写大小
//{ }
//void test2(int arr1[10])//拿数组接收
//{ }
//void test3(int *arr1)//拿指针接受
//{ }
//void Test1(int *arr2[20])//拿数组接收
//{ }
//void Test2(int **arr2)//拿指针接收
//{ }
//int main()
//{
//	int arr1[10] = { 0 };
//	int* arr2[20] = { 0 };
//	test1(arr1); test2(arr1); test3(arr1);
//	Test1(arr2); Test2(arr2);
//	return 0;
//}





////////////////////////     二维数组传参
//
//void test1(int arr[3][5])//用数组来接收
//{ }
//void test2(int arr[][5])//二维数组行可以省略，列不可以省略
//{ }
//void test3(int(*arr)[5])//用二维数组的首元素地址（第一行一维数组的地址）来接收
//{ }
//
//int main()
//{
//	int arr[3][5] = { 0 };
//	test1(arr);
//	test2(arr);
//	test3(arr);
//	return 0;
//}





////////////////////////     一级指针传参

//void test(int *p)//用指针接收
//{ }
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	int x = 10;
//	int* pa = arr;
//	int* px = &x;
//	test(pa);      //可传 指针变量
//	test(arr);     //可传数组首元素地址
//	test(px);      //可传指针变量
//	test(&x);      //可传变量地址
//	return 0;
//}







//////////////////////////     二级指针传参
//
//void test(int** p)//用二级指针接收
//{ }
//int main()
//{
//	int* arr[10];
//	int** pa = arr;
//	int n = 10;
//	int* p = &n;
//	int** Pp = &p;
//	test(Pp);      //可传二级指针变量
//	test(&p);      //可传一级指针的地址
//	test(arr);     //可传指针数组首元素地址
//	test(pa);      //可传二级指针变量
//	return 0;
//}






















////////////////////////////////////               5.函数指针


//////////////////////  函数指针 - 指向函数的指针

////////////////函数名 和 &函数名 都是函数地址
//int add(int x,int y)
//{
//	return x + y;
//}
//int main()
//{
//	int a = 10, b = 20;
//	printf("%d\n", add(a,b));
//
//	////////////函数指针可以类比数组指针的形式，但是区别于数组，[函数名]与[&函数名]的意义一致
//	printf("%p\n", add);            //函数名可以作为函数地址
//	printf("%p\n", &add);           //&函数名可以作为函数地址
//
//
//	////////////   函数指针的类型
//	////  ()的优先级比*高，使用若(*p)不加括号，p先与后面括号结合，是函数
//  ////
//	int(*p)(int, int) = add;         
//	int(*p1)(int x, int y) = add;  //写不写x y效果一致
//	printf("%p\n", p);
//	printf("%p\n", p1);
//
//
//	///////////   函数地址解引用，可以当作函数来使用
//	printf("%d", (*p)(3, 2));
//
//	return 0;
//}







////////  对于数组指针 int(*p)[10];  指针p的类型是int(*)[10]
////////  同理，对于函数指针 int(*pa)(int, int);  函数指针pa的类型为int(*)(int, int)；函数add的类型也是int(*)(int, int)








///////////////////  函数指针的例子
//r
//void pri(char* arr) //函数pri类型的为void(*)(char*)
//{
//	printf("%s\n", arr);
//}
//
//int main()
//{
//	void(*p)(char*) = pri;//函数指针的类型
//	pri("hello warld");
//	(*p)("hello warld");//*p作为函数来使用
//	return 0;
//}









/////////////////////   函数指针使用时的其他写法
////////    可 *pa调用函数 ；可pa直接调用函数； （语法上无论解引用多少次都可调用函数）
//
//int add(int x,int y)
//{
//	return x + y;
//}
//int main()        //优先级问题记得注意加()
//{
//	int(*pa)(int, int) = add;//add 和 &add 意义相同
//
//	printf("%d\n", add(2, 3));
//
//	printf("%d\n", (*pa)(2, 3));//pa【可理解为】将函数地址存到pa中：对指向函数的指针变量解引用，找到函数
//	printf("%d\n", pa(2, 3));//pa【可理解为】函数名身就是个地址，相当于把函数地址直接 赋给pa
//	
//
//	printf("%d\n", (***pa)(2, 3));//无聊解引用多少次，pa都可以调用函数
//	printf("%d\n", (********pa)(2, 3));
//	//////这里发现，函数地址无论解引用多少次，结果都可以当作函数使用
//	//////但是,如果 * 真的有意义，先解引用一次求出一个结果，再把这个结果继续解引用，反复多次，结果肯定有问题
//	//////然而事实是无论解引用多少次，运算结果都没有问题
//	//////所以【*】在函数指针前都是【摆设，没有实际价值】
//	//////所以用函数指针调用函数是，直接写【p】即可
//	//////从理解层面出发，【*p】也可以写，但是实际上也没有解引用
//
//	return 0;
//}









///////////////////    区分下面代码的意义

/////////代码（1）
//int main()
//{
//	(*(void(*)())0)();
//}
//	////1.  void(*)()            是一个函数指针类型
//	////2.  (void(*)())0         这是对0进行强制类型转换，0变成了函数地址
//	////3.  *(void(*)())0        对函数地址解引用，就找到这个函数了
//	////4.  (*(void(*)())0)()    对这个函数传参，因为这个函数无参使用不传参
//	////所以这个代码其实是一次【函数调用】，调用0地址处的--参数无参，返回类型为void的这个函数
	
	 


/////////代码（2）
//void(*signal(int, void(*)(int)))(int);
//////1.  void(*)(int)   是一个函数指针类型，在这里作为一个参数类型
//////2.  (int, void(*)(int))   是函数的两个参数
//////3.  signal  是函数名
//////4.  去掉函数名和函数参数，剩下的void(*  )(int)就是这个函数的返回类型
//////所以这是一次【函数声明】，函数名为signal，函数参数是(int, void(*)(int))，返回类型是函数指针void(*  )(int)
//
/////////p.s.函数声明的方式可以是【int add(int, int);】或者【int add(int x, int y);】
//
//
//////代码2化简，以增强可读性
//////将void(*signal(int, void(*)(int)))(int);化简为如下：
//typedef void(*T)(int);//对原本函数指针类型重新定义一个名称T
//T signal(int, T);







//////////////////         P.S. 类型重定义typedef
//
//typedef unsigned int U; //这是类型重定义的格式
////////需要注意的是，类似：函数指针类型--int(*)(int,int)；数组指针类型--int(*)[10]
////////                    新定义的名称要放在(* )内
//typedef int(*A)[10];
//typedef void(*B)(char, char);





















////////////////////////////////////                     6.函数指针数组
//////////函数指针数组 -- 存放函数指针的数组


//int Add(int a, int b) {
//	return a + b;
//}
//int Sub(int a, int b) {
//	return a - b;
//}
//int Mul(int a, int b) {
//	return a * b;
//} 
//int Div(int a, int b) {
//	return a / b;
//}
//
//int main()
//{
//	int(*pa)(int, int) = Add;
//	int(*parr[4])(int, int) = { Add,Sub,Mul,Div }; 
//	////1.先写数组名parr
//	////2.parr[4],数组名+[]，确定parr是一个数组
//	////3.确定数组元素类型，为函数指针，类型为int(*)(int,int)
//	////4.给数组parr[4]添加元素类型，int(*parr[4])(int,int)
//	////     ////（注意数组的元素类型为指针，由于优先级问题，parr[4]要写到(* )内）
//
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%2d\n", parr[i](2, 3));
//	}
//	return 0;
//}







///////////////////   函数指针数组的定义形式
//////  数组是存放相同类型数据的储存空间

//////  指针数组：int *arr[10]  
//每个元素都是 int*

//////  函数指针数组
//// int(*parr1[10])();
//每个元素都是int(*)()



///////练习：char* my_strcpy(char* dest, const char* str);
////写出：1.能够指向该函数的指针pf 2.能存放4个该类函数的指针数组pfarr
//指针：  char*(*pf)(char*, const char*)
//数组：  char*(*pfarr[4])(char*, const char* )//注意const也要写下来











////////////////////     函数指针数组的用途：【转移表】
//////// 【转移表】比如说：输入1，通过下标1找到数组种对应的函数来调用
////////////////////       例子：（计算器）
////////add-加；subtract-减；multiply-乘；divide-除
// 
// 
//#include<stdlib.h>
//#include<time.h>
//
//int Add(int a, int b) {
//	return a + b;
//}
//int Sub(int a, int b) {
//	return a - b;
//}
//int Mul(int a, int b) {
//	return a * b;
//} 
//int Div(int a, int b) {
//	return a / b;
//}
//void menu()
//{
//	printf("*********************************\n");
//	printf("*****   1.add       2.sub   *****\n");
//	printf("*****   3.mul       4.div   *****\n");
//	printf("*****        0.exit         *****\n");
//	printf("*********************************\n");
//}
//
//int main()
//{
//	int input;
//	do {
//		system("cls");
//		menu();
//		printf("输入数字以选择运算模式：>");
//		scanf("%d", &input);
//		if (input < 0 || input>4){
//			printf("输入错误，请重新输入\n");
//			Sleep(1000);
//			continue;
//		}
//		else if(input>0&&input<5){
//			int(*arr[])(int, int) = { Add,Sub,Mul,Div };//这种函数指针数组使用的方法被称为【转移表】
//			printf("请输入两个操作数：>  ");
//			int a, b;
//			scanf("%d %d", &a, &b);
//			printf("结果为% d\n", arr[input - 1](a, b));   //若这里不用函数指针数组，需要switch，比较麻烦
//			getchar();//吞掉回车
//			getchar();//达到等待效果
//		}
//	} while (input);
//	return 0;
//}
















////////////////////////////////////                    7.指向函数指针数组的指针
/////////////  依次找到每层的优先级 即可破解


//int Add(int a, int b) {
//	return a + b;
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	int(*p)[10] = &arr;//取出数组的地址
//
//	int(*pf)(int, int) = Add;//函数指针
//	int(*pfArr[10])(int, int) = { 0 };//pfArr是一个数组，函数指针的数组
//
//	//PpfArr是一个指向[函数指针数组]的指针
//	int(*(*PpfArr)[10])(int, int) = &pfArr[10];
//	//
//	//PpfArr 是一个数组指针，指针指向的数组有10个元素
//	//指向的数组的每个元素的类型是一个函数指针 int(*)(int,int)
//
//	return 0;
//}
































////////////////////////////////////                         8.回调函数


//////【回调函数】就是一个[通过函数指针调用]的函数。
//////如果你把函数的指针（地址）作为参数传递给另一个函数，当这个指针被用来调用其所指
//////向的函数时，我们就说这是回调函数。回调函数不是由该函数的实现方直接调用，而是在
//////特定的事件或条件发生时由另外一方调用的，用于对该事件或条件进行响应。

//////简单来说就是(函数1)传参时，传了一个(函数指针2)作为参数，之后在(函数1)中使用符合(函数指针2)格式的一系列函数






//////////     以下为回调函数简单的例子： 函数也可以调用函数
////////// f2实参为f1的函数名，形参是f1对应的函数指针及其类型，这样可以在f2内使用f1
////////// f1实参是字符串，形参是字符串
//
//void f1(char* str)//打印字符串的函数
//{
//	printf("%s\n", str);
//}
//
//void f2(void(*f)(char*))//打印hehe并调用f1的函数
//{
//	printf("hehe\n");
//	f("haha");
//}
//
//int main()
//{
//	f2(f1);
//	return 0;
//}





/////////////////////   下面用计算器为例子展示回调函数的用法
//#include<stdlib.h>
//#include<time.h>
//int Add(int a, int b) {
//	return a + b;
//}
//int Sub(int a, int b) {
//	return a - b;
//}
//int Mul(int a, int b) {
//	return a * b;
//}
//int Div(int a, int b) {
//	return a / b;
//}
//void menu()
//{
//	printf("*********************************\n");
//	printf("*****   1.add       2.sub   *****\n");
//	printf("*****   3.mul       4.div   *****\n");
//	printf("*****        0.exit         *****\n");
//	printf("*********************************\n");
//}
//void F(int(*pf)(int, int))//本函数进行了回调函数
//{
//	int a, b;
//	printf("请输入两个操作数：> ");
//	scanf("%d%d", &a, &b);
//	printf("值为 %d", pf(a, b));
//}
//int main()
//{
//	int input;
//	do {
//		system("cls");
//		menu();
//		printf("输入数字以选择运算模式：>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			F(Add);//将 函数，或者说函数指针 作为参数进行传递
//			break;
//		case 2:
//			F(Sub);
//			break;
//		case 3:
//			F(Mul);
//			break;
//		case 4:
//			F(Div);
//			break;
//		case 0:
//			printf("退出计算器\n");
//			break;
//		default:
//			printf("输入错误，请重新输入\n");
//		}
//		getchar();
//		getchar();
//	} while (input);
//	return 0;
//}







//////////////////////     冒泡函数（只能排整型类的数据，不通用）
//
//void bubble_sort(int arr[], int sz)
//{
//	int i, j;
//	for (i = 0; i < sz - 1; i++)//走sz-1趟
//	{
//		int a = 1;//优化
//		for (j = 0; j < sz - i - 1; j++)//每趟交换sz-i-1次
//		{   //每一趟要保证把本趟中最大的元素送到后面
//			if (arr[j] > arr[j + 1])
//			{
//				int t = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = t;
//				a = 0;
//			}
//		}
//		if (a == 1) {//若本趟没元素交换，顺序已好，直接跳出
//			break;
//		}
//	}
//}









//////////指针类型 void*
////void* 可以接收任意类型的地址：(垃圾桶)，任何地址都可以往里仍
////指针类型决定[1.其解引用能访问的字节数]和[2.指针加减整数的跨度]
//// 
////void* 类型的指针：（1）不能解引用（无具体类型，访问几字节不确定）
////void* 类型的指针：（2）不能加减整数（无具体类型，不知道跨度）









//////////////////////     库函数 - qsort（quick sort - 快速排序），对应<stdlib.h>

#include<stdlib.h>

////////库函数qsort的声明，具体见MSDN
////////void qsort(void* base,//数组名
////////	       size_t num, //数组元素个数
////////	       size_t width,//数组元素字节数（sizeof()）
////////	       int(* compare)(const void* elem1, const void* elem2)//比较函数，该函数参数为数组元素
////////           );//（传入不同类型数组，对应的的比较方式不同，要自己写比较函数）


////////  
////////  比较函数compare在MSDN中的说法
////////  int(* compare)(const void* elem1, const void* elem2);//#注意，这里void*可以接收任意类型的地址#//
////////  该函数必须比较元素，然后返回以下值之一:
////////
////////   Return Value     Description（条件）
////////     < 0          （elem1 less than elem2）
////////	     0          （elem1 equivalent to elem2）
////////     > 0          （elem1 greater than elem2）
//////// 
////////  也就是e1<e2,返回负数；e1=e2，返回0；e1>e2，返回整数





//这个比较函数的类型 要符合qsort声明中 函数指针的类型
int cmp_int(const void* e1, const void* e2)//两个比较元素的指针；
{  
	//void*类型指针无法解引用，要强制类型转换
	return *(int*)e1 - *(int*)e2;
}

void test_int()//测试整形数组的qsort使用
{
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);//库函数qsort的使用
	//（数组名,元素个数,元素字节数,对应类型的比较函数(由使用者自己编写)）
	int i = 0;
	for (i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}



int cmp_float(const void* e1, const void* e2)
{
	////// *(float*)e1 - *(float*)e2 对于浮点数不能用，
	//////因为该函数返回值int,相减得到-1和1之间的数全变为0
	if (*(float*)e1 < *(float*)e2)
		return -1;
	else if (*(float*)e1 == *(float*)e2)
		return 0;
	else
		return 1;
}

void test_float() // 测试浮点型数组的qsort使用
{
	float f[] = { 6.0, 5.0, 4.0, 3.0 ,2.0, 1.0 };
	int sz = sizeof(f) / sizeof(f[0]);
	qsort(f, sz, sizeof(f[0]), cmp_float);
	int i = 0;
	for (i = 0; i < sz; i++) {
		printf("%f ", f[i]);
	}
	printf("\n");
}



struct stu//创建结构体变量
{
	char name[20];
	int age;
};

int cmp_str_age(const void* e1, const void* e2)//这里参数为结构体指针
{
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;//注意优先级问题加括号
}

void test_str()//测试结构体数组的qsort使用
{
	struct stu S[] = { {"张三",56},{"李四",28},{"王五",18} }; 
	int sz = sizeof(S) / sizeof(S[0]);
	qsort(S, sz, sizeof(S[0]), cmp_str_age);
	int i = 0;
	for (i = 0; i < sz; i++) {
		printf("%s(%d)  ", S[i].name,S[i].age);
	}
	printf("\n");
}




int main()
{
	test_int();
	test_float();
	test_str();
	return 0;
}

















////////////////////////////////////9.指针和数组面试题的解析