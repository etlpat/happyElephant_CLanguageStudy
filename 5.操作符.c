//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>




// 优先级从上到下依次降低
// 
//	运算符											| 说明			| 结合性
// ————————————————————————————————————————
//	()	[]	->(成员选择(指针))	.(成员选择(对象))	|				| 从左到右
// ————————————————————————————————————————
//	! ~	+(正) -(负) ++ -- *(解引用) &(取地址)		| 单目运算符	| 从右到左
// ————————————————————————————————————————
//	*	/	%										|				| 从左到右
//  +	-											|				| 从左到右
//	<<(左移)	>>(右移)							|				| 从左到右
//	<  <=  >  >=									|				| 从左到右
//	==	!=											| 双目运算符	| 从左到右
//	& (按位与)										|				| 从左到右
//	^ (按位异或)									|				| 从左到右
//	| (按位非)										|				| 从左到右
//	&& (逻辑与)										|				| 从左到右
//	|| (逻辑或)										|				| 从左到右
// ————————————————————————————————————————
//	? : (条件操作符)								| 三目运算符	| 从右到左
// ————————————————————————————————————————
//	= += -= *= /= %= <<= >>= &= ^= |=				| 复合赋值符	| 从右向左
// —-——————————————————————————————————————-
//  , , (逗号运算符)								| 多目运算符	| 从左向右
// ————————————————————————————————————————











////                                  1.算数操作符
//// +  -  *  /  %

//int main()
//{
//	int a = 5;
//	printf("%d\n", a / 2);
//
//	double b = 5.0;
//	printf("%lf\n", b / 2);//保证'/'两端任意一个是小数（有.0）才能算出小数
//
//	//%必须保证两边是整数
//
//	return 0;
//}









////                               2.移位操作符（用补码进行运算）
//// <<  >>

//右移操作符
//算术右移：右边丢弃，左边补原符号位----【当前见到】的基本是算数右移
//符号右移：右边丢弃，左边补0
//左移：左边丢弃，右边补0,有乘二 或 二的n次方的效果

//不要移动负数位，如>>-1，应为该行为未定义


//int main()
//{
//	//用储存在内存中的[补码]来进行位移
//
//	//右移
//	int a = 16;//00000000 00000000 00000000 00010000 //正数原反补码一样
//	int b = a >> 1;//[0]0000000 00000000 00000000 00001000 | [0]
//
//	int c = -5;  //10000101(-5)（原） -> 11111010（反） -> 11111011（补） >>1  11111101（补） -> 11111100（反） -> 10000011（原）(-3) 【这里把32比特位省略成8位来演示】
//	int d = c >> 5;
//
//	//左移
//	int e = 13;
//	int f = e << 1;
//
//
//	printf("a=%d,b=%d  ", a, b);
//	printf("c=%d,d=%d  ", c, d);
//	printf("e=%d,f=%d  ", e, f);
//}









////                                 3.位操作符（用于正数）（用补码进行运算）
////  & | ^  按(二进制)位 与/或/异或

//3 & 5 ：011 & 101 = 001(都是1输出1)
//3 | 5 ：011 | 101 = 111(有1就输出1)
//3 ^ 5 ：011 ^ 101 = 110(相同为0 相异为1)
//00000000 00000000 00000000 00000101 ^ 00000000 00000000 00000000 000000011 = 00000000 00000000 00000000 00000110





////不引入参数实现两个数字互换
//int main()
//{
//	int a = 3;
//	int b = 5;
//	//法1
//	//a = a + b;
//	//b = a - b;
//	//a = a - b;
//	//printf("%d %d\n\n", a, b);
//
//	//法2
//	a = a ^ b;//a变密码
//	b = b ^ a;//b变a
//	a = b ^ a;//a变a
//	printf("%d %d", a, b);
//	return 0;
//}

////     a 10101101110010110
////     b 01011010101001010
////   ^
////密码 c 11110111011011100
////------------------------------
////密码 c 11110111011011100
////   ^
////     a 10101101110010110
////  =  b 01011010101001010
////------------------------------
////密码 c 11110111011011100
////   ^
////     b 01011010101001010
////  =  a 10101101110010110

//因为 0^0=0 ; 1^1=0 , 1^0=1
//若a^b=c则 c^b=a ; c^a=b




////   计算一个数的补码中有多少个1
// 
// 
//00000000 00000000 00000010 11101011
//00000000 00000000 00000000 00000001

//11111111 11111111 11111001 01001001
//00000000 00000000 00000000 00000001




////   计算一个数的补码中有多少个1
//int main()
//{
//	int num = 0;
//	int count = 0;
//	scanf("%d", &num);
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		int x = 1 << i;
//		if (x == (x & num))//这里注意符号运算的优先级问题，记得加括号
//		{
//			count++;
//		}
//	}
//	printf("%d", count);
//	return 0;
//}
////或者
//int main()
//{
//	int num = 0;
//	int count = 0;
//	scanf("%d", &num);
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (1 == ((num >> i) & 1))
//		{
//			count++;
//		}
//	}
//	printf("%d", count);
//	return 0;
//}






////实现加减法(???)
//int add(int a,int b)
//{
//	//这里返回b是:当b为真,进行递归;当b为假,返回a
//	return b ? add(a ^ b, (a & b) << 1) : a;
//}

//由于1+1=10（二进制）          ,0+0=0,1+0=1,
//当前位运算后结果为1^1=0       ,0^0=0,1^0=1
//进位是1&1=1                   ,0&0=0,1&0=0
//所以实际上
//a+b就是(a^b+((a&b)<<1))           [本位 同为0 异为1 ; 进位 同1为1 同0为0 相异为0  (这里0 1表示本位的0 1)]
// e.g.   00101001 ^ 10000000 = 10101001
//add(a, b) = add(a ^ b, ((a & b) << 1))     add[a=本次结果 , b=进位结果]
//之后就是考虑递归何时结束
//当无位可进递归结束
//{因为1010 & 0101 = 0
//所以1010 + 0101时，b为假}
//这时就不需要进位了
//所以b的定义其实是：上一次计算后的进位
//若上一次运算完没有进位，什么已经计算完了

//1101 + 1010 = 10111
//add(01101, 01010)
//add(00111, 10000)
//add(10111, 00000)
//
//10111 + 11011
//add(010111, 011011)
//    011011
//add(001100, 100110)
//    100110
//add(101010, 001000)
//    001000
//add(100010, 010000)
//    010000
//add(110010, 000000)












////                                                  4.赋值操作符
////  =
//// 复合赋值符
//// +=   -=   *=   /=   %=   >>=   <<=   &=   |=   ^=
// 
// 
//int main()
//{
//  // 后面的赋值会覆盖前面的值
//	//int a = 1;
//	//a = 2;
//	//printf("%d", a);//当然会输出2
//
//
//  //语法支持连续赋值，但是尽量不要用，可读性不高
//	int a,b,c=5;
//	/*a = b= c + 2;*/
//	//这种写法不如下面
//	b = c + 2;
//	a = b;
//	printf("%d", a); 
//	  
//	return 0;
//}


//符合操作符例子如下
// a = a>>1  相当于  a>>=1
// a = a^b   相当于  a^=b


//if(a>b>c);
//a > b, 如果成立，会返回1，否则会返回0
//相当于(a>b)>c,(1)>c 或 (0)>c











////                                       5.单目操作符（只有一个操作数）
//// 
//// !(逻辑反操作)  
//// -(负值)  
//// +(正值)   
//// &(取地址) 
//// sizeof()(操作的类型长度(字节))   
//// ~(按(二进制)位取反)
//// --(前置、后置--)   
//// ++(前置、后置++) 
//// *(直接访问操作符(解引用操作符))   
//// (类型)(强制类型转换)





//// !   逻辑反操作，非零变0  0变1(非零)  a=10,!a=0
////如下为一般用法
//int main()
//{
//	int a = 0;
//	int b = 1;
//	if (!a)//假如a为假，if成立
//	{
//		printf("hhh\n");
//	}
//	if (b)//假如b为真，if成立
//	{
//		printf("HHH\n");
//	}
//	return 0;
//}



//int main()
//{
//	int a = 10;
//	int* pa = &a;//取地址操作符
//	*pa = 20;//解引用操作符
//	printf("%p\n", pa);
//	printf("%d\n", a);
//	return 0;
//}




//sizeof() : 可以通过[变量名称]或者[数据类型]确定大小
//sizeof算变量名称可以去括号，算数据类型不可去
//int main()
//{
//	int a = 10;
//	char c = 'r';
//	int* p = &c;
//	int arr[][10] = { 1,2 };
//	printf("%d\n", sizeof(a));//4 ；大小等于sizeod(int)
//	printf("%d\n", sizeof(c));//1 ；大小等于sizeod(char)
//	printf("%d\n", sizeof(p));//8 ；大小等于sizeod(char*) ；指针大小只可能是4/8字节，看是32位还是64位平台
//	printf("%d\n", sizeof(arr));//40 ；数组大小就是数组里面每个元素所占空间的和
//	printf("%d\n", sizeof(int [1][10]));//这是数组的类型，对于数组来说，去掉数组名就是它的类型
//	return 0;
//}

//sizeof相关的题目
//int main()         
//{
//	short s = 0;
//	int a = 10;
//	//////a = s + 2;
//	//////printf("%d\n", sizeof(a));//把s赋到a中，主体是a，要按a的规则走，打印下来是int的大小
//	printf("%d\n", sizeof(s = a + 5));//2,不管是否在sizeof内外运算，所占空间都要与主体大小对应，这里是s的大小
//	printf("%d\n", s);//sizeof括号内表达式不是真的参与运算，s值不发生变化
//	return 0;
//}





//  ~  按(二进制)位取反(补码)
//00000000 00000000 00000000 00000000(0原、反、补码)=0
//11111111 11111111 11111111 11111111(0取反的补码)
//11111111 11111111 11111111 11111110(0取反的反码)
//10000000 00000000 00000000 00000001(0取反的原码)=-1
//int main()
//{
//	int a = 0;
//	printf("%d", ~a);
//	return 0;
//}



//  ~ 有关的题目
//        把00000000 00000000 00000000 00001011（数值为11）
//      变成00000000 00000000 00000000 00001111 问（1）
//之后再变回00000000 00000000 00000000 00001011 问（2）

//（1）00000000 00000000 00000000 00001011
//   | 00000000 00000000 00000000 00000100
// 即可00000000 00000000 00000000 00001111
// 
//（2）<1>
//     00000000 00000000 00000000 00001111
//   & 11111111 11111111 11111111 11111011 = ~(00000000 00000000 00000000 00000100)
// 即可00000000 00000000 00000000 00001011
//或者（2）<2>
//     00000000 00000000 00000000 00001111
//   ^ 00000000 00000000 00000000 00000100
// 即可00000000 00000000 00000000 00001011
// 
//int main()
//{
//	int a = 11;
//	int b = a | (1 << 2);
//	printf("%d\n", b);
//	//int c = b & (~(1 << 2));
//	/*或者*/
//	int c = b ^ (1 << 2);
//	printf("%d", c);
//	return 0;
//}





//// a++  ++a
//int main()
//{
//	int a = 10;
//	printf("%d\n", a++);//先打印(先使用),后++
//	a = 10;
//	printf("%d\n", a+=1);//a+=10相当于a=a+10，无先后顺序
//	int b = 10;
//	printf("%d\n", ++b);//先++，后打印
//	return 0;
//}





//void f(int a[], char c[])
//{
//	printf("%d %d", sizeof(a), sizeof(c));//结果 8 8
//	//结果 8 8 ，因为是首元素地址，这里是64位平台，所以地址肯定都是8字节，与int char什么的无关
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	char ch[10] = { 0 };
//	printf("%d %d\n", sizeof(arr), sizeof(ch));//结果 40 10
//	f(arr, ch);
//	return 0;
//}









////                                         6.(类型)强制类型转换
// 
////////仅对紧跟强制类型转换操作符的操作数进行转换，因此注意加括号
////////和隐式类型转换一样，只是临时的类型转换，只在本表达式中以转换的形式呈现，出了表达式还是其原本的形式
//// 
//int main()
//{
//	int a = (int)3.14;
//	printf("%d\n", a);
//	float b = 3.14;
//	int c = (int)b;
//	printf("%d\n", c);
//	int d = 3.14;
//	printf("%d\n", (int)d);
//	return 0;
//}










//                                            7.关系操作符
//  >   >=   <   <=   !=   ==











//                                            8.逻辑操作符
// 
//  &&   ||     逻辑与/或
//按位与/或 &、| 是转化为二进制    ；   逻辑与/或是直接将两边判断

/////注意，&&优先级大于||
///// && 和 || 优先级表现为：&&相当于给周围框定括号  
/////              a || b && c ,相当于 a || (b && c)
/////              a && b || c ,相当于(a && b) || c

//int main()
//{
//	int a = 4; int b = 9; int c = 0;
//	printf("%d %d %d %d", a && b, a || b, a && c, a || c);//结果为真输出1，假输出0
//	return 0;
//}


//  //逻辑与&&的特点：从左到右，左边为0，就不去计算右边的结果了
//  //逻辑或||的特点：从左到右，左边非0，就不去计算右边的结果了
//  //只要结果已确定，就不会再向后执行
//int main()
//{
//	int i, a = 0, b = 2, c = 3, d = 4;
//	i = a++ && ++b && d++;
//	printf("%d %d %d %d\n", a, b, c, d);//结果1 2 3 4 ; a为0，就不往后执行了，但是a使用过，所以a仍自增
//	a = 0; b = 2; c = 3; d = 4;
//	i = a++ || ++b || d++;
//	printf("%d %d %d %d\n", a, b, c, d);//结果1 3 3 4 ; a为0，无法判断真假，向后进行，遇到b，可判断为真，不继续向后进行了
//	return 0;
//}









////                                       9.条件操作符(三目操作符)
////  exp1 ? exp2 : exp3

//int main()
//{
//	int a;
//	scanf("%d", &a);
//	int b = (a > 5 ? 3 : -3);
//	printf("%d", b);
//	return 0;
//}









////                                         10.逗号操作符  
////从左到右依次执行，整个表达式的结果是[最后一个表达式的结果]
//// exp1,exp2,......,expN

//e.g.
//int a=1,b=2;int c=(a>b,a=b+10,b=a+1);//最后c=13
//if(a=b+1,c=a/2,d>0);//d>0是判断条件，但是判断前先执行运算
//while(a=f(c),b=g(d),a>0)//也是，效果像do while











////                                       11.下标引用、函数调用和结构成员
////  []  ()   structXXX{...};
//// 
//// 
//// []下标引用操作符 : 数组名+[下标]
////int arr[10]={0};  arr[4]=20;    
////   下标引用操作符[]的操作数是 数组名arr 和 下标4
////
////
//// ()函数调用操作符 
////假设有求最大值的函数max(),使用时m=max(a,b);
////   函数调用操作符()的操作数是 函数名 和 ()内每一个元素
//
//
//
//struct STUDENT//在主函数外【创建了一个结构体类型】叫struct STUDENT（可以类比数组也算一个类型,只不过结构体元素的数据类型是固定的）
//{
//	char name[20];
//	int age;
//	char id[20];
//};
//int main()
//{
//	//使用struct STUDENT这个类型创建了一个学生对象叫s1,并以这个类型向内存申请一块空间来初始化对象
//	struct STUDENT s1 = { "张三",20,"2019010203" };
//	printf("%s\n", s1.name);//类比并区别 数组调用元素时arr[下标]，这里是 类型名si.元素名称name
//	printf("%d\n", s1.age);
//	printf("%s\n", s1.id);
//
//	struct STUDENT* ps = &s1;
//	printf("%s\n", (*ps).name);//可用两种形式的地址来打印结构体内的元素
//	printf("%s\n", ps->name);
//	return 0;
//}
















////////////////////           表达式求值【先类型转换，后看优先级结合性】
////表达式求值的顺序一部分十由操作符的优先级和结合性决定
////同样，有些表达式的操作数在求值的过程中可能需要转换为其他类型




////////【隐式类型转换】(偷偷进行类型转换)【分为整型提升、算术转换】
//////C的整形算数运算总是至少以缺省型类型的精度来进行的
//////为了获得这个精度，表达式中的字符和短整型操作数在使用之前 [必须] 转换为普通整形，这种转换被成为【整型提升】
//
//////【隐式类型转换】【1.整形提升】【字节小于int的】
//////【整型提升的意义】在于：表达式的整型运算要在CPU的相应运算器件内执行，
//////CPU内整型运算器(ALU)的操作数的字节长度一般就是int的字节长度，同时也是CPU的通用寄存器的长度。
//////因此，即使两个char类型的相加，在CPU执行时实际上也要先转换为CPU内整型操作数的标准长度。
//////通用CPU是难以直接实现两个8比特字节直接相加运算（虽然机器指令中可能有这种字节相加指令）。
//////所以，表达式中各种长度可能小于int长度的整型值，都必须先转换为int或unsigned int，然后才能送入CPU去执行运算。
//
//////【整形提升规则】
//////有符号整形提升：最高位补充符号位
////////char 1字节=8比特位
////////若是11100001，提升以后结果就是11111111 11111111 11111111 11100001
////////若是00000001，提升以后结果就是00000000 00000000 00000000 00000001
//////无符号整形提升：高位补0
//////(计算表达式时,全转换为式子中最长的 ; short\char至少转化为int ; float至少转化为double)
//
//////【需要注意】 
////////整形提升是对应你变量的类型来提升，变量类型为char就提升为32位有符号数，unsigned char就提升位32位无符号数
////////整型提升的过程与下面打印时的%d或是%u无关
//
//
//////e.g 1.
//////char a,b,c;  c=a+b;  
//////a和b被提升为普通整形，然后执行加法运算。加法运算结束之后，结果会被截断，然后再存储于a中。
//
//int main()
//{
//	char a = 3;
//	//00000000 00000000 00000000 00000011 : 这是3的二进制序列(原=反=补)
//	//00000011--a: 这是3存入char中，发生截断
//	char b = 127;
//	//00000000 00000000 00000000 01111111 : 这是127的二进制序列(原=反=补)
//	//01111111--b: 这是127存入char中，发生截断
//
//	char c = a + b;
//	//加法时，a,b先进行整形提升(按符号位进行提升(有符号数，最左边是1就补1，0就补0；无符号数全补0))
//	//00000000 00000000 00000000 00000011 : 整形提升后a的值
//  //+ 00000000 00000000 00000000 01111111 : 整形提升后b的值
//	//00000000 00000000 00000000 10000010 : a,b相加后的值(补码)
//	//存放到 char c中时，截断放入
//	//10000010--c(补码)
//
//	printf("%d", c);
//	//以%d的形式打印整形，char c要进行整形提升，按char的方式提升
//	//11111111 11111111 11111111 10000010 - 整形提升后c的补码
//	//11111111 11111111 11111111 10000001 - 反码
//	//10000000 00000000 00000000 01111110 - 原码(-126)  
//
//	return 0;
//}





//////e.g 2.
//int main()
//{
//	char a = 0xb6;//1011 0110 - a
//	short b = 0xb600;//1011 0110 0000 0000 - b
//	int c = 0xb6000000;//1011 0110 0000 0000 0000 0000 0000 0000
//	// ==(比较)也算运算
//	if (a == 0xb6) {//a整型比较时提升为1111 1111 1111 1111 1111 1111 1011 0110(补码)
//		            //100...0 0100 1000(原码)=(-72)，为0x48，和原来不同
//		printf("a\n");
//	}
//	if (b == 0xb600) {//short和上面char一样，整型提升后比较，与之前不相同了
//		printf("b\n");
//	}
//	if (c == 0xb6000000) {//int 不用整型提升，正常比较
//		printf("c\n");
//	}
//
//	return 0;
//}




////e.g3.
//int main()
//{
//	char c = 1;//0000 0001
//	printf("%u\n",sizeof(c ) );//1
//	printf("%u\n",sizeof(+c) );//4 (+ 也算一种运算，需要整型提升，sizeof这个表达式的结果就计算了一个整形的大小)
//	printf("%u\n",sizeof(!c) );//1
//	return 0;
//}






//////////【隐式类型转换】【2.算术转换】
//// 【隐式类型转换】【字节大于int的】
////如果某个操作符的各个操作数属于不同的类型，那么其中一个操作数的类型转换为另一个操作数的类型，否则操作就无法进行
////下面的层次体系称为寻常算术转换
//long double //8
//double //8
//float //4
//unsigned long int //4      越往上，所占内存越大
//long int //4
//unsigned int //4
//int //4
//如果某个操作数的类型在上面这个列表中的排名较低，那么首先转换为另外一个操作数的类型后执行运算
//【通俗的讲，上面类型同时出现两个，短的转换为长的】
//警告：但是算数运算要合理，要不然会有一些潜在的问题







////////////////操作符的属性
////复杂表达式求值三个影响因素
////(1).操作符的优先级 (2).操作符的结合性 (3).是否控制求值顺序
// 
//////(3) .是否控制求值顺序：比如以下
////1.&&左假就不继续运行 
////2.||左真就不继续运行 
////3.?: exp1真，算exp2,不算exp3;exp1假,相反 
////4.逗号操作符，从左到右执行，但是结果是最右表达式


//如下例子（问题代码）
// 
//问题代码1 
// a*b+c*d+e*f
//(1) 1.a*b 2.c*d 3.a*b+c*d 4.e*f 5.a*b+c*d+e*f 或者
//(2) 1.a*b 2.c*d 3.e*f 4.a*b+c*d 5.a*b+c*d+e*f
//若是这种代码运算表达式，有多种可能顺序，有可能对导致得出的结果不一样，不能写这种代码


//问题代码2
//c+ --c
//我们无法大致+操作符的左操作数的获取是在右操作数之前还是之后求值
//可能左变先放上c，之后c--，也有可能先--，后放上左边的值，有歧义  


////问题代码3
//int fun() {
//	static int count = 1;
//	return count++;
//}
//int main() {
//	int a; 
//	a = fun() - fun() * fun();
//	printf("%d", a);
//	return 0;
//}
////此代码也是问题代码，因为虽然+ *顺序已知，但是函数调用的顺序是未知的


//////问题代码4
//int main()
//{
//	int i = 1;
//	int a = (++i) + (++i) + (++i);
//	printf("%d", a);
//}
////////此代码可能是【(++i) + (++i)】 + (++i)：先执行前两个++i，i=3，【】内结果为6，之后再执行【】外的++i,i=4,最后结果是10
////////有可能是执行3次++i，i=4，再执行3次和，结果为12
