//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//////////////                         1. ������ int main(){   return 0;}
//int main()
//{
//	char x = 'A';
//	printf("%c\n",x);
//	return 0;
//}
// 
// 
// 
//////////////////                       2.  ������float
//int main()
//{
//	float num = 99.9f;
//	printf("%f", num);
//    return 0;
//}


//////////////////////                 3.  sizeof  ������ռ�ֽڴ�С
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


//////////////////////            4. const : ָ��������ʹ��֮�󲻻ᱻ��Ϊ���ֵ
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


////////////////////                5.  define:����ı�ʶ������
//#define A 10
//int main()
//{
//	printf("%d",A);
//	return 0;
//}

// 
// 
////////////////////////             6.  scanf �� &��ȡ��ַ��
//int main()
//{
//	int num1;
//	int num2;
//	scanf(" %d %d",& num1,& num2);
//	int sum = num1 + num2;
//	printf("sum=%d\n", sum);
//	return 0;
//}

//////////////////                    7.  ö�ٳ���   ��   ö�ٳ�����ֵ
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






//////////////////                       8. strlen :string(���������ַ����� length = �����ַ�������
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



////////////                                            9.  if ����ʵ��
//#define  _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//int main()
//{
//	int input;
//	printf("�����ѧ��\n���ú�ѧϰ��(1/0)>:\n");
//	scanf("%d", &input);
//	if (input == 1)
//		printf("��offer\n");
//	    else
//		printf("������\n");
//		return 0;
//}
// 
// 
//////////////////                             10.  while �� if ����ʵ��
//int main()
//{
//	int line = 0;
//	printf("ѧϰ���\n");
//	while (line <= 2000)
//	{
//		printf("��һ�д���:%d\n",line);
//		line++;
//	}
//	if (line > 2000)
//		printf("�ɹ�\n");
//	return 0;
//}
//
// 
// 
// 
// 
////////////////////                          11. �Զ��庯�� Add(x,y)
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
//////////////////////                   12. �±����ò����������飩  ��  ѭ��������ʹ��
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



//////////////////                    13.  !:�߼���������    0:��  �� ��0:��
//int main()
//{
//	int a = /*1*/0;
//	printf("%d\n", a);
//	printf("%d\n", !a);
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>




////////////////////                        14.  scanf��ʹ��  ��   �Ƚϴ�С
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
//////////////                            15.   �Ƚϴ�С��������(if else)
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
////////////////////                         16.  if else ��Ӧ��
// int main()
//{
//	int input;
//	printf("���Jimmy,������һ����ѧ�⡣\nlim��n���ޣ�[sin��1/n��/1/n]\n���ǣ�\n( 1 / 0 / -1 / e )>:\n");
//	scanf("%d", &input);
//	if (input == 1)
//		printf("��ϲ�㣬�������\n");
//	else
//		printf("�ܱ�Ǹ������ʧ����\n");
//	return 0;
//}
// 
//////////////////                        17.  ���� ~   ����λȡ��
//int main()
//{
//	int a = 0;
//	int b = ~a;
//	printf("%d \n%d", a, b);
//	return 0;
//}

///////////////////                   18.  int b = a++ ������ b=a, ֮�� a++
//int main()
//{
//	int a = 10;
//	int b = /*a++; ++a;a--;*/--a;
//	printf("%d   ,%d", a, b); 
//	return 0;
//}

//
//////////////////                19.  ( ���� )��ǿ������ת��������double��2.22����int��ת��Ϊint
//int main()
//{
//	int a =(int) 8.38;
//	printf("%d", a);
//	return 0;
//}



//////////////////                            20.    �߼���  �߼���
// 
// 
////////////////////         C�����У�0�Ǽ٣���0����
//////////////               &&���߼��룬���߾��棬�����
//////////////               ||���߼���ֻҪ���棬�����
//#include<stdio.h>
//int main()
//{
//	int a = /*2;*/0;
//	int b = /*4;*/0;
//	int c =/* a && b;*/a || b;
//	printf("%d", c);
//	return 0;
//}



//////////////////                         21.  ��λ��  ��λ��
// 
//
///////////��(�����ƣ�λ��&:�Ȱ�ʮ���ƻ���Ϊ�����ƣ���������Ϊ1�������1���������0      ����101&011=001
///////////��(�����ƣ�λ��|:�Ȱ�ʮ���ƻ���Ϊ�����ƣ�������ֻҪ��1�������1���������0    ����101&011=111
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
///////////////////////                    22.   %:��λ�࣬�������
//int main()
//{
//	int c = 5 % 3;
//	printf("%d", c);
//	return 0;
//}
//




////////////////                           23. exp1 ? exp2 ; exp3    
//////////////////        ��˼�ǣ��жϱ��ʽ1��������������ִ�б��ʽ2 ������������ִ�б��ʽ3
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
/////////////////////                  24.  typedef:�����ض��壬���°� int ����Ϊ i ����ʹ��
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




 ////////////////////                            25.  static���÷�
//#include<stdio.h>
////////////////////////////         static����̬�ġ�       1�����ξֲ��������ӳ�����������
//////////////////                     ԭ������aֻ����������������ã�������������ɾ��
//////////////////                     ����static��a��һ�θ���ֵ���Ա������ڶ��μ���
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

////////////             static������ȫ�ֱ������ı������������ͺ������������ԣ��ⲿ�������Ա��ڲ��������ԣ�
////////////             extern : �����ⲿ���Ż��ⲿ����
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




//////////////                          26 ���������ȴ�С
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




/////////////                            27  �ú�ķ�ʽȡ��С

//#define MAX(x, y) (x>y?x:y)
//int main()
//{
//	int a = 22;
//	int b = 123;
//	int max = MAX(a, b);
//	printf("max=%d\n", max);
//	return 0;
//}




//////////////////                         28 ��ӡ��ַ
////////            ��Ȼint���ĸ��ֽڣ������ϴ�ӡ�ĸ���ַ�����Ǽ����ֻ��ȡ�׵�ַ
// /////                                   %p:��ӡ��ַ
//int main()
//{
//	int a = 32;
//	printf("%p\n", &a);
//	return 0;
//}
//
//                                 29  int*  �����ڴ�����ռ��ŵ�ַ����������
//int main()
//{
//	int a = 32;
//	int* m = &a;
//	printf("%p\n", m);
//	return 0;
//}




////////////                 30  * : �����ã������*p,�ǽ�p(a�ĵ�ַ)������Ϊa
////////////                   ͨ��*��p�����ò������ҵ���p(&a)ָ��Ķ���(a)
//int main()
//{
//	int a = 108;
//	int* p = &a;
////	printf("%p\n", p);
//	*p = 23;
//	printf("%d", a);
//	return 0;
//}



////////////                       31 �ַ��������͵ĵ�ַ�������
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
////////////////////                        32   �ṹ������ 
//////////////////                         struct:�����ṹ����    
//
//struct BOOK
//{
//	char name[20];
//	float price;
//};
//int main()
//{
//	struct BOOK b = { "C���Գ������" , 59.8};
//	printf("�����ǡ�%s��\n", b.name);
//	printf("�۸��ǣ�%f\n", b.price);
//    return 0;
//}
//
//
//
//
//
////////////////////               33  �ṹ��������ָ���ʹ��
// 
//////////////////////            .     �ṹ�����.��Ա
//////////////////////            ->    �ṹ��ָ��->��Ա
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
//////////////////            34  strcpy-string copy-�ַ�������(�⺯��)-string.h
//////////////////              �����ǿ��Ըı����������
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