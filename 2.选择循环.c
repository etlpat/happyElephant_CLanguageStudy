//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>


////////////////                       1   选择语句
///////////////                本质是：如果表达式结果为真（非0），则语句执行

//int main()
//{
//	int age;
//	scanf("%d", &age);
//	if (age < 18)
//		printf("未成年\n");
//	else if (age >= 18 && age < 30)
//		printf("青年\n");
//	else if (age >= 30 && age < 50)
//		printf("壮年\n");
//	else if (age >= 50 && age <= 90)
//		printf("老年\n");
//	else
//		printf("??\n");
//	return 0;
//}
////或者
//int main()
//{
//	int age;
//	scanf("%d", &age);
//	if (age < 18)
//		printf("未成年");
//	else
//	{
//		if (age >= 18 && age < 30)
//			printf("青年");
//		else
//		{
//			if (age >= 30 && age<50)
//				printf("壮年");
//			else
//			{
//				if (age >= 50 && age < 90)
//					printf("老年");
//				else
//					printf("??");
//			}
//		}
//	}
//	return 0;
//}


//////////         如果条件成立，若要执行多条语句，则应使用代码块
// //////          if else 整体只算[一个]语句
//int main()
//{
//	int i;
//	scanf("%d", &i);
//	int a = 0;
//	if (i < 3)
//	{
//		i++;
//		a += 2;
//	}
//	else
//	{
//		i--;
//		a -= 2;
//	}
//	printf("%d,%d", i, a);
//	return 0;
//}
//
//
/////////////////                   else 匹配的是离他最近的未被匹配的 if
////////////////                    如下，看似打印hhhhh，确实什么也打不了
//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)
//		if (b == 2)
//			printf("hh");
//	else
//	printf("hhhhhh");
//	return 0;
//}
//
//
//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)
//		if (b == 2)
//			printf("hh");
//		else
//			printf("hhhhhh");
//	return 0;
//}
//
//
//
/////////////////               2   = 赋值  和  == 判断相等的易错点
//int main()
//{
//	int a = 0;
//	if (a = 2)
//		printf("hh");
//	return 0;
//}
///////////////                  看似什么也不输出，其实输出hh，因为 = 是赋值
//
//int main()
//{
//	int a = 0;
//	if (2==a)
//		printf("hh");
//	return 0;
//}
////////////////                  所以最好用以 2==a 的形式，这样就算==错写为=，也只是报错，不会出现bug
//
//
//
//
////////////////               3   输出1~100间的奇数
//int main()
//{
//	int i = 1;
//	while (i <= 100)
//	{
//		if (1 == i%2)
//			printf("%d\n", i);
//		i++;
//	}
//	return 0;
//}








/////////////////                 4      switch case 语句
/////////////////                      如下，从switch(变量)进入选择结果，按照变量的值跳入对应的case，并【持续向下】执行
/////////////////                      switch\case后面一定是整形表达式，因为switch判断条件是等于，精度要求高
/////////////////                               字符型、布尔型、枚举型都可以转化成整形进行判断
/////////////////                      case:后面必须是常量表达式
/////////////////                      break用来跳出循环，否则程序从在你跳入的case一直向下执行，直到switch语句结束或者遇到下一个break
/////////////////                      default:(默认)，如果输入的变量不在case:的范围内，则执行default(默认)  （确实用法相当于else)
/////////////////                      switch 语句中可以嵌套 if 或 switch 语句
//int main()
//{
//	int day;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//		printf("星期1\n");
//		break;
//	case 2:
//		printf("星期2\n");
//		break;
//	case 3:
//		printf("星期3\n");
//		break;
//	case 4:
//		printf("星期4\n");
//		break;
//	case 5:
//		printf("星期5\n");
//		break;
//	case 6:
//		printf("星期6\n");
//		break;
//	case 7:
//		printf("星期7\n");
//		break;
//  default:
//      printf("输入错误");
//	}
//	return 0;
//}



/////////////////                   5      case后面不一定都加break
/////////////////                         此处若加break,则会从中间跳出，执行不到printf，所以这种情况不加break
//int main()
//{
//	int day;
//	scanf("%d", & day);
//	switch (day)
//	{
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("工作日\n");
//		break;
//	case 6:
//	case 7:
//		printf("休息日\n");
//		break;
//	default:
//		printf("输入错误\n");
//	}
//	return 0;
//}




////////////////                                6   while语句
////////////////              continue:终止本次循环continue后面的代码，并跳回循环代码块，回到开头的判断部分
////////////////              break:直接跳出循环

//int main()
//{
//	int i = 0;
//	while (i < 10)
//	{
//		i++;
//		if (5 == i)
//			continue; /*break;*/
//		printf("%d\n", i);
//	}
//
//	return 0;
//}
// 
// 
// 
//int main()
//{
//	int i;
//	for (i = 1; i <=10; i++)
//	{
//		if (5 == i)
//			continue;
//		printf("%d  ", i);
//	}
//	printf("\ni = %d\n", i);
//	return 0;
//}


////////////////              7     for循环：for(表达式1; 表达式2;表达式3)
////////////////                            作用: 初始化;  判断  ;  调整
////////执行顺序：表达式1(初始化)->表达式2(判断)->执行循环体内语句->表达式3(调整)->2判断->循环体内语句执行->3调整->.......
// ////////////                     for 循环中也可出现 break 和 continue
//int main()
//{
//	int i;
//	for (i = 1; i<=10;i++)
//	{
//		printf("%d\n", i);
//	}
//	return 0;
//}


////////////////              8    对比下面两段代码
//////         二者区别在于 i++(调整) 的位置不同，for语句的调整在循环代码块外部(顶端),while语句的调整在代码块内部
//////         所以读取continue跳到循环语句开端处后，for语句执行调整 会继续运行 ，但while 语句不会调整变量的数组 进入死循环
// 
// 
//int main()
//{
//	int i;
//	for (i = 1; i <= 10; i++)
//	{
//		if (5 == i)
//			continue;
//		printf("%d ", i);
//	}
//	return 0;
//}


//int main()
//{
//	int i=1;
//	while (i <= 10)
//	{
//		if (5 == i)
//			continue;
//		printf("%d ", i);
//		i++;
//	}
//	return 0;
//}
//



////////////                               9  getchar？？？？
//int main()
//{
//   int ch = 0;
//   //EOF-end of file 文件结束标志
//   while ((ch = getchar()) != EOF)
//   {
//	   putchar(ch);
//   }
//	return 0;
//}







//////////               10  scanf本身会识别一个回车，这里getchar()相当于被空识别了。
//////////               getchar（）函数读取下一个输入字符；如果只有一个getchar，就读取换行符了
//////////               所以需要两个getchar才能让程序正常生效
//int main()
//{
//	char num[20] = { 0 };
//	printf("请输入字符串：\n");
//	scanf("%s", num);//输入字符串 不用&
//	printf("请确认（1 or 0)\n");
////////	getchar();
//	int a = getchar();//getchar输入的是字符形式的'1'，所以下面if中的1也要打成字符形式
//	if (a==49)
//	{
//		printf("确认成功\n");
//	}
//	else
//	{
//		printf("放弃确认\n");
//	}
//	return 0;
//}





//////////////               11    for语句的建议：建议语句的循环变量采用"前闭后开"的写法
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	//10次循环
//	//10次打印  (是否是"前闭后开"依情况而定）
//	//10个元素
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d  ", arr[i]);
//	}
//	return 0;
//}



////////////               12     for循环发初始化，判断，调整都可以省略
////////////                   判断部分省略，那么判断条件：恒为真
////////////                   若不熟练，不建议使用
// 
//int main()
//{
//	for (;;)
//	{
//		printf("hhhh");
//	}
//	return 0;
//}




///////////     13  此时原本打印100次，但是要是去掉for括号内的初始化，则只运行10次，因为i运行第2次的时候，j已经是10，未再被初始化
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (/*i = 0*/; 1 < 10; i++)
//	{
//		for (/*j = 0*/; j < 10; j++)
//		{
//			printf("呵呵\n");
//		}
//	}
//	return 0;
//}



//
////////////                        14    循环可以有多个循环变量
//int main()
//{
//	int x;
//	int y;
//	for (x = 0, y = 0; x <= 4 && y < 5; x++, y++)
//	{
//		printf("嗨嗨嗨\n");
//	}
//	return 0;
//}




////////////////          15   赋值=带来的错误：这里for判断中，若i=0，始终未不打印；若i=非0，始终打印
////////////////           因为  1.=是赋值  2.判断语句的本质：若为真(非0)，进入循环，并且死循环；若为假(0)，结束循环
//int main()
//{
//	int i=0;
//	/*for (; i = 10; i++)*/
//	for (; i =0; i++)
//		printf("hh");
//	return 0;
//}





//
////////////////              16   do while 语句(由于至少执行一次，使用场景有限，很少使用)
//int main()
//{
//	int i = 1;
//	do
//	{
//		printf("%d ", i);
//		i++;
//	}
//	while (i <= 10);
//	return 0;
//}

////////////          17   do while 语句中，break(跳出循环) 与 continue(跳回循环开头) 用法与之前一致
//int main()
//{
//	int i = 1;
//	do
//	{
//		if (5 == i)
//			break;
//		/*continue;*/
//		printf("%d  ", i);
//		i++;
//	} while (i<=10);
//	return 0;
//}





//////////////                      18   n的阶乘(n!)
//int main()
//{
//	int n =9 ;
	//int i;
	//int j = 1;
	//for (i = 1; i <= n;i++)
	//{
	//	j = j * i;
	//}
//	printf("%d", j);
//	return 0;
//}


//////////                          19   计算：1!+ 2!+ 3！+...+n!

///////       1. 函数法
	//int JC(n)//计算n的阶乘的函数
	//{
	//	int i;
	//	int j = 1;
	//	for (i = 1; i <= n; i++)
	//	{
	//		j = j * i;
	//	}
	//	return j;
	//}
	//int main()
	//{
	//	int x; int q; int R=0;
	//	scanf("%d", &x);
	//		for (q = 1; q <= x; q++)
	//		{
	//			R = R + JC(q);
	//		}
	//		printf("%d", R);
	//	return 0;
	//}



//////////                                  2.嵌套法
//int main()
//{
//	int i;//阶乘次数
//  int n;//阶乘和的次数
//	int ret = 1;//阶乘的值
//	int sum = 0;//阶乘的和
//	for (n = 1; n <= 10; n++)
//	{
//		for (i = 1, ret = 1; i <= n; i++)//n的阶乘  
////////      注意，这里要初始化n=1，否则每次加法循环过程中，n会接着上次的结果相乘
//		{
//			ret = ret * i;
//		}
//		sum = sum + ret;
//	}
//	printf("%d", sum);
//	return 0;
//}


//
////////////////                              阶乘和的标准答案：
//int main()
//{
//	int n;//运行次数
//	int ret = 1;//每次阶乘的值
//	int sum = 0;//每个阶乘的和
//	for (n = 1; n <= 10; n++)
//	{
//		ret = ret * n;
//		sum = sum + ret;
//	}
//	return 0;
//}





////////////////                            20   查找数组的下标
////////////////                        1.逐一寻找法(数组有序无序均可寻找)
//int main()
//{   
//	int i;//for循环,数组元素下标
//	int k;//要查找的数组中元素
//	scanf("%d", &k);
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int num = sizeof(arr) / sizeof(arr[0]);//数组元素个数
//	for (i = 0; i < num; i++)
//	{
//		if (k == arr[i])
//		{
//			printf("%d", i);
//			break;
//		}
//	}
//	if (i >= num)
//		printf("不在范围中");
//	return 0;
//}




//////////////////                            21   查找数组的下标
/////////////////                      (难）  2.二分法找下表，检索速度块，需要数组有序
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	     //下标： 0  1  2  3  4  5  6  7  8   9  
//	int k;//所需要查找的数字
//	scanf("%d", &k);
//	int num = sizeof(arr) / sizeof(arr[0]);//数组元素个数
//	int left = 0;//数组左边数字的下标
//	int right = num - 1;//数组右边数字的下标
//	while (left<=right)
//	{
//		int mid = (left + right) / 2;//左右下标的平均整数
//		if (k < arr[mid])
//		{
//			right = mid - 1;
//		}
//		else if (k > arr[mid])
//		{
//			left = mid + 1;
//		}
//		else if (k = arr[mid])
//		{
//			printf("结果为 %d ", mid);
//			break;
//		}
//	}
//	if (left > right)
//		printf("不存在");
//	return 0;
//}





////////////////                  22   实现从两端到中间的效果(?)
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>
//#include<windows.h>
//#include<stdlib.h>
//int main()
//{
//	char arr1[] = "Hi,Jimmy FaQ!!!";
//	char arr2[] = "###############";
//	int left = 0;
//	/*int right = sizeof(arr2) / sizeof(arr2[0]) - 2;*/
//	int right = strlen(arr2) - 1;
//	for (; left <= right; left++, right--)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s", arr2);
//		Sleep(1000);//用于休息一秒,须引用"#include<windows.h>"
//		system("cls");//执行系统命令的一个函数-cls__用于清空屏幕,须引用"#include<stdlib.h>"
//	}
//	printf("%s\n", arr2);
//	return 0;
//}




//
//////////////                     23    输入三次密码
//#include<string.h>
//int main()
//{
//	int i;
//	for (i = 0; i < 3; i++)
//	{
//		char m[20] = { 0 };
//		scanf("%s", m);
//		if (strcmp(m,"114514")==0)//  ==不能用来比较两个字符串是否相等 应该用一个库函数-strcmp，左=右，返回值是0
//		{
//			printf("输入正确");
//			break;
//		}
//		else if(i<2)
//			printf("重新输入\n");
//	}
//	if(3==i)
//	printf("密码输入次数已用完");
//	return 0;
//}






//////////////////               24   三个数比大小
//int main()
//{
//	int a;
//	int b;
//	int c;
	//scanf("%d%d%d", &a,&b, &c);
	//	if (a < b)
	//	{
	//		int t = a;
	//		a = b;
	//		b = t;
	//	}
	//	if (a < c)
	//	{
	//		int t = a;
	//		a = c;
	//		c = t;
	//	}
	//	if (b < c)
	//	{
	//		int t = b;
	//		b = c;
	//		c = t;
	//	}
//			printf("%d>%d>%d", a, b, c);
//	return 0;
//}






////////////////       25    判断1000~2000年间的闰年，并计算个数(闰年：规则1、可被4整除，不可被100整除 规则2、可被400整除)
//int main()
//{
//	int n = 0;
//	int i;
//	for (i = 1000; i <= 2000; i++)
//	{
//		if (i % 4 == 0 && i % 100 != 0)
//		{
//			printf("%d ", i);
//			n++;
//		}
//		else if (i % 400 == 0)
//		{
//			printf("%d ", i);
//			n++;
//		}
//	}
//	printf("\n%d\n", n);
//	return 0;
//}

//
//////////////                 或者
//int main()
//{
//	int i;
//	int n = 0;
//	for (i = 1000; i <= 2000; i++)
//	{
//		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
//		{
//			printf("%d ", i);
//			n++;
//		}
//	}
//	printf("\n%d\n", n);
//	return 0;
//}





//////////////               26    打印100~200间素数：不能被比它小的数整除的数叫素数
//int main()
//{
//	int i;
//	int j;
//	int n = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		for (j = 2;j <i; j++)//产生2~（i-1）的数字
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		////这里有两种数，1.直接被break跳出来的j  2.完成整伦循环出来的素数j，此时i==j
//		if (i == j)
//		{
//			printf("%d  ", j);
//			n++;
//		}
//	}
//	printf("\n%d  ", n);
//	return 0;
//}





  ////////////          27   以上算法可以优化(运行时间)
  ///////////           一个非素数，肯定由两个数相乘得来，两个数中肯定有一个小于它的开平方
 ////////////              因此只需要让j小于更号i即可节省运算时间
//#include<math.h>
//int main()
//{
//	int i;
//	int j;
//	int n = 0;
//	for (i = 101; i <= 200; i+=2)
//	{
//		for (j = 2;j <sqrt(i); j++)//sqrt(i),开更号，数学库函数，对应#include<math.h>
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		if (j>=sqrt(i))
//		{
//			printf("%d  ", i);
//			n++;
//		}
//	}
//	printf("\n%d  ", n);
//	return 0;
//}




//////////////                28     1~100中出现过多少个9？
//int main()
//{
//	int i = 1;
//	int n = 0;
//	for (i = 1;i <= 100; i++)
//	{
//		if ( i % 10 == 9)
//			n++;
//		if ( i / 10 ==9)
//			n++;
//	}
//	printf("%d", n);
//	return 0;
//}





//////////                  29   1/1-1/2+1/3-1/4+1/5......+1/99-1/100
//int main()
//{
//	double a=0.0; double b=0.0;
//	double i;   int j;
//	double m = 0.0;
//	for (i = 1; i <= 100; i+=2)
//	{
//		a = a + 1.0 / i;
//	}
//	for (j = 2; j <= 100; j += 2)
//	{
//		b = b + 1.0 / j;
//	}
//	m = a-b ;
//		printf("%lf", m);
//	return 0;
//}


//////////////                 更简单的解法
//int main()
//{
//	double a = 0.0;
//	int i = 1;
//	int u = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		a = a + (1.0 / i) * u;
//			u = -u;
//	}
//	printf("%lf", a);
//	return 0;
//}




////////////                  20    求几个数的最大值
//int main()
//{
//	int arr[] = {333,545.53535,5,555,5555,1,323332,12112};
//	int  n = arr[0];//若此处n=0，假如数组全是负数，则最大值还是0，出bug
//	int i = 0; 
//	int j = sizeof(arr) / sizeof(arr[0]) - 1;
//	for (i = 0; i<=j; i++)
//	{
//		if (arr[i] > n)
//			n = arr[i];
//	}
//	printf("%d", n);
//	return 0;
//}



////////////                          31    乘法口角
//int main()
//{
//	int x = 1;
//	int y = 1;
//	for (y = 1; y <10; y++)
//	{
//		for (x = 1; x <= y; x++)
//		{
//			int z = x * y;
//				printf("%d * %d=(%-2d)  ", y, x, z);//这里%-2d表示打印时中间打印两位，为了工整(%2d：右对齐，%-2d：左对齐)
//		}
//		printf("\n");//每一次小循环y值加1，要再一次循环后换行
//	}
//	return 0;
//}








//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
////////////                           32    goto  直接跳到指定步骤
// 
////                                          格式如下
//// 
//int main()
//{
//	printf("hhhh\n");
//	goto a;
//	printf("哈哈哈哈\n");
//	a:
//	printf("hhhh\n");
//	return 0;
//}





//////////////                     33      goto 的应用--关机程序
//int main() 
//{
//	char arr[20] = { 0 };
//	system("shutdown -s -t 60");              //shutdown -s  设置关机       -t 60 关机时间      system():用来执行系统命令
//again:
//	printf("输入“我是傻逼”，就取消关机\n请输入：");
//	scanf("%s", arr);
//	if (strcmp(arr, "我是傻逼") == 0)         //用于比较字符串的函数
//		system("shutdown -a");                //shutdown -a  取消关机
//	else
//		goto again;  //-------------- -这里goto again,直接跳到上面 again:
//	return 0;
//}






//////////将x进制转化为y进制
//int main() 
//{
//	int x, y, a, b, sum1 = 0, sum2 = 0;
//	printf("输入x进制数的值:");
//	scanf("%d", &a);
//	printf("x的进制是:");
//	scanf("%d", &x);
//	int i;
//	for (i = 1; a != 0; i *= x)
//	{
//		int tem = (a % 10) * i;
//		sum1 = sum1 + tem;
//		a /= 10;
//	}
//	printf("转化的10进制为%d\n",sum1);
//	int j;
//	printf("y的进制是:");
//	scanf("%d", &y);
//	for (j = 1; sum1 != 0; j *= 10)
//	{
//		int tem = (sum1 % y) * j;
//		sum2 = sum2 + tem;
//		sum1 /= y;
//	}
//	printf("转化的y进制为%d", sum2);
//	return 0;
//}