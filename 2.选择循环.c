//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>


////////////////                       1   ѡ�����
///////////////                �����ǣ�������ʽ���Ϊ�棨��0���������ִ��

//int main()
//{
//	int age;
//	scanf("%d", &age);
//	if (age < 18)
//		printf("δ����\n");
//	else if (age >= 18 && age < 30)
//		printf("����\n");
//	else if (age >= 30 && age < 50)
//		printf("׳��\n");
//	else if (age >= 50 && age <= 90)
//		printf("����\n");
//	else
//		printf("??\n");
//	return 0;
//}
////����
//int main()
//{
//	int age;
//	scanf("%d", &age);
//	if (age < 18)
//		printf("δ����");
//	else
//	{
//		if (age >= 18 && age < 30)
//			printf("����");
//		else
//		{
//			if (age >= 30 && age<50)
//				printf("׳��");
//			else
//			{
//				if (age >= 50 && age < 90)
//					printf("����");
//				else
//					printf("??");
//			}
//		}
//	}
//	return 0;
//}


//////////         ���������������Ҫִ�ж�����䣬��Ӧʹ�ô����
// //////          if else ����ֻ��[һ��]���
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
/////////////////                   else ƥ��������������δ��ƥ��� if
////////////////                    ���£����ƴ�ӡhhhhh��ȷʵʲôҲ����
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
/////////////////               2   = ��ֵ  ��  == �ж���ȵ��״��
//int main()
//{
//	int a = 0;
//	if (a = 2)
//		printf("hh");
//	return 0;
//}
///////////////                  ����ʲôҲ���������ʵ���hh����Ϊ = �Ǹ�ֵ
//
//int main()
//{
//	int a = 0;
//	if (2==a)
//		printf("hh");
//	return 0;
//}
////////////////                  ����������� 2==a ����ʽ����������==��дΪ=��Ҳֻ�Ǳ����������bug
//
//
//
//
////////////////               3   ���1~100�������
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








/////////////////                 4      switch case ���
/////////////////                      ���£���switch(����)����ѡ���������ձ�����ֵ�����Ӧ��case�������������¡�ִ��
/////////////////                      switch\case����һ�������α��ʽ����Ϊswitch�ж������ǵ��ڣ�����Ҫ���
/////////////////                               �ַ��͡������͡�ö���Ͷ�����ת�������ν����ж�
/////////////////                      case:��������ǳ������ʽ
/////////////////                      break��������ѭ���������������������caseһֱ����ִ�У�ֱ��switch����������������һ��break
/////////////////                      default:(Ĭ��)���������ı�������case:�ķ�Χ�ڣ���ִ��default(Ĭ��)  ��ȷʵ�÷��൱��else)
/////////////////                      switch ����п���Ƕ�� if �� switch ���
//int main()
//{
//	int day;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//		printf("����1\n");
//		break;
//	case 2:
//		printf("����2\n");
//		break;
//	case 3:
//		printf("����3\n");
//		break;
//	case 4:
//		printf("����4\n");
//		break;
//	case 5:
//		printf("����5\n");
//		break;
//	case 6:
//		printf("����6\n");
//		break;
//	case 7:
//		printf("����7\n");
//		break;
//  default:
//      printf("�������");
//	}
//	return 0;
//}



/////////////////                   5      case���治һ������break
/////////////////                         �˴�����break,�����м�������ִ�в���printf�����������������break
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
//		printf("������\n");
//		break;
//	case 6:
//	case 7:
//		printf("��Ϣ��\n");
//		break;
//	default:
//		printf("�������\n");
//	}
//	return 0;
//}




////////////////                                6   while���
////////////////              continue:��ֹ����ѭ��continue����Ĵ��룬������ѭ������飬�ص���ͷ���жϲ���
////////////////              break:ֱ������ѭ��

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


////////////////              7     forѭ����for(���ʽ1; ���ʽ2;���ʽ3)
////////////////                            ����: ��ʼ��;  �ж�  ;  ����
////////ִ��˳�򣺱��ʽ1(��ʼ��)->���ʽ2(�ж�)->ִ��ѭ���������->���ʽ3(����)->2�ж�->ѭ���������ִ��->3����->.......
// ////////////                     for ѭ����Ҳ�ɳ��� break �� continue
//int main()
//{
//	int i;
//	for (i = 1; i<=10;i++)
//	{
//		printf("%d\n", i);
//	}
//	return 0;
//}


////////////////              8    �Ա��������δ���
//////         ������������ i++(����) ��λ�ò�ͬ��for���ĵ�����ѭ��������ⲿ(����),while���ĵ����ڴ�����ڲ�
//////         ���Զ�ȡcontinue����ѭ����俪�˴���for���ִ�е��� ��������� ����while ��䲻��������������� ������ѭ��
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



////////////                               9  getchar��������
//int main()
//{
//   int ch = 0;
//   //EOF-end of file �ļ�������־
//   while ((ch = getchar()) != EOF)
//   {
//	   putchar(ch);
//   }
//	return 0;
//}







//////////               10  scanf�����ʶ��һ���س�������getchar()�൱�ڱ���ʶ���ˡ�
//////////               getchar����������ȡ��һ�������ַ������ֻ��һ��getchar���Ͷ�ȡ���з���
//////////               ������Ҫ����getchar�����ó���������Ч
//int main()
//{
//	char num[20] = { 0 };
//	printf("�������ַ�����\n");
//	scanf("%s", num);//�����ַ��� ����&
//	printf("��ȷ�ϣ�1 or 0)\n");
////////	getchar();
//	int a = getchar();//getchar��������ַ���ʽ��'1'����������if�е�1ҲҪ����ַ���ʽ
//	if (a==49)
//	{
//		printf("ȷ�ϳɹ�\n");
//	}
//	else
//	{
//		printf("����ȷ��\n");
//	}
//	return 0;
//}





//////////////               11    for���Ľ��飺��������ѭ����������"ǰ�պ�"��д��
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	//10��ѭ��
//	//10�δ�ӡ  (�Ƿ���"ǰ�պ�"�����������
//	//10��Ԫ��
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d  ", arr[i]);
//	}
//	return 0;
//}



////////////               12     forѭ������ʼ�����жϣ�����������ʡ��
////////////                   �жϲ���ʡ�ԣ���ô�ж���������Ϊ��
////////////                   ����������������ʹ��
// 
//int main()
//{
//	for (;;)
//	{
//		printf("hhhh");
//	}
//	return 0;
//}




///////////     13  ��ʱԭ����ӡ100�Σ�����Ҫ��ȥ��for�����ڵĳ�ʼ������ֻ����10�Σ���Ϊi���е�2�ε�ʱ��j�Ѿ���10��δ�ٱ���ʼ��
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (/*i = 0*/; 1 < 10; i++)
//	{
//		for (/*j = 0*/; j < 10; j++)
//		{
//			printf("�Ǻ�\n");
//		}
//	}
//	return 0;
//}



//
////////////                        14    ѭ�������ж��ѭ������
//int main()
//{
//	int x;
//	int y;
//	for (x = 0, y = 0; x <= 4 && y < 5; x++, y++)
//	{
//		printf("������\n");
//	}
//	return 0;
//}




////////////////          15   ��ֵ=�����Ĵ�������for�ж��У���i=0��ʼ��δ����ӡ����i=��0��ʼ�մ�ӡ
////////////////           ��Ϊ  1.=�Ǹ�ֵ  2.�ж����ı��ʣ���Ϊ��(��0)������ѭ����������ѭ������Ϊ��(0)������ѭ��
//int main()
//{
//	int i=0;
//	/*for (; i = 10; i++)*/
//	for (; i =0; i++)
//		printf("hh");
//	return 0;
//}





//
////////////////              16   do while ���(��������ִ��һ�Σ�ʹ�ó������ޣ�����ʹ��)
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

////////////          17   do while ����У�break(����ѭ��) �� continue(����ѭ����ͷ) �÷���֮ǰһ��
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





//////////////                      18   n�Ľ׳�(n!)
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


//////////                          19   ���㣺1!+ 2!+ 3��+...+n!

///////       1. ������
	//int JC(n)//����n�Ľ׳˵ĺ���
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



//////////                                  2.Ƕ�׷�
//int main()
//{
//	int i;//�׳˴���
//  int n;//�׳˺͵Ĵ���
//	int ret = 1;//�׳˵�ֵ
//	int sum = 0;//�׳˵ĺ�
//	for (n = 1; n <= 10; n++)
//	{
//		for (i = 1, ret = 1; i <= n; i++)//n�Ľ׳�  
////////      ע�⣬����Ҫ��ʼ��n=1������ÿ�μӷ�ѭ�������У�n������ϴεĽ�����
//		{
//			ret = ret * i;
//		}
//		sum = sum + ret;
//	}
//	printf("%d", sum);
//	return 0;
//}


//
////////////////                              �׳˺͵ı�׼�𰸣�
//int main()
//{
//	int n;//���д���
//	int ret = 1;//ÿ�ν׳˵�ֵ
//	int sum = 0;//ÿ���׳˵ĺ�
//	for (n = 1; n <= 10; n++)
//	{
//		ret = ret * n;
//		sum = sum + ret;
//	}
//	return 0;
//}





////////////////                            20   ����������±�
////////////////                        1.��һѰ�ҷ�(���������������Ѱ��)
//int main()
//{   
//	int i;//forѭ��,����Ԫ���±�
//	int k;//Ҫ���ҵ�������Ԫ��
//	scanf("%d", &k);
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int num = sizeof(arr) / sizeof(arr[0]);//����Ԫ�ظ���
//	for (i = 0; i < num; i++)
//	{
//		if (k == arr[i])
//		{
//			printf("%d", i);
//			break;
//		}
//	}
//	if (i >= num)
//		printf("���ڷ�Χ��");
//	return 0;
//}




//////////////////                            21   ����������±�
/////////////////                      (�ѣ�  2.���ַ����±������ٶȿ飬��Ҫ��������
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	     //�±꣺ 0  1  2  3  4  5  6  7  8   9  
//	int k;//����Ҫ���ҵ�����
//	scanf("%d", &k);
//	int num = sizeof(arr) / sizeof(arr[0]);//����Ԫ�ظ���
//	int left = 0;//����������ֵ��±�
//	int right = num - 1;//�����ұ����ֵ��±�
//	while (left<=right)
//	{
//		int mid = (left + right) / 2;//�����±��ƽ������
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
//			printf("���Ϊ %d ", mid);
//			break;
//		}
//	}
//	if (left > right)
//		printf("������");
//	return 0;
//}





////////////////                  22   ʵ�ִ����˵��м��Ч��(?)
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
//		Sleep(1000);//������Ϣһ��,������"#include<windows.h>"
//		system("cls");//ִ��ϵͳ�����һ������-cls__���������Ļ,������"#include<stdlib.h>"
//	}
//	printf("%s\n", arr2);
//	return 0;
//}




//
//////////////                     23    ������������
//#include<string.h>
//int main()
//{
//	int i;
//	for (i = 0; i < 3; i++)
//	{
//		char m[20] = { 0 };
//		scanf("%s", m);
//		if (strcmp(m,"114514")==0)//  ==���������Ƚ������ַ����Ƿ���� Ӧ����һ���⺯��-strcmp����=�ң�����ֵ��0
//		{
//			printf("������ȷ");
//			break;
//		}
//		else if(i<2)
//			printf("��������\n");
//	}
//	if(3==i)
//	printf("�����������������");
//	return 0;
//}






//////////////////               24   �������ȴ�С
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






////////////////       25    �ж�1000~2000�������꣬���������(���꣺����1���ɱ�4���������ɱ�100���� ����2���ɱ�400����)
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
//////////////                 ����
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





//////////////               26    ��ӡ100~200�����������ܱ�����С������������������
//int main()
//{
//	int i;
//	int j;
//	int n = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		for (j = 2;j <i; j++)//����2~��i-1��������
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		////��������������1.ֱ�ӱ�break��������j  2.�������ѭ������������j����ʱi==j
//		if (i == j)
//		{
//			printf("%d  ", j);
//			n++;
//		}
//	}
//	printf("\n%d  ", n);
//	return 0;
//}





  ////////////          27   �����㷨�����Ż�(����ʱ��)
  ///////////           һ�����������϶�����������˵������������п϶���һ��С�����Ŀ�ƽ��
 ////////////              ���ֻ��Ҫ��jС�ڸ���i���ɽ�ʡ����ʱ��
//#include<math.h>
//int main()
//{
//	int i;
//	int j;
//	int n = 0;
//	for (i = 101; i <= 200; i+=2)
//	{
//		for (j = 2;j <sqrt(i); j++)//sqrt(i),�����ţ���ѧ�⺯������Ӧ#include<math.h>
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




//////////////                28     1~100�г��ֹ����ٸ�9��
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


//////////////                 ���򵥵Ľⷨ
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




////////////                  20    �󼸸��������ֵ
//int main()
//{
//	int arr[] = {333,545.53535,5,555,5555,1,323332,12112};
//	int  n = arr[0];//���˴�n=0����������ȫ�Ǹ����������ֵ����0����bug
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



////////////                          31    �˷��ڽ�
//int main()
//{
//	int x = 1;
//	int y = 1;
//	for (y = 1; y <10; y++)
//	{
//		for (x = 1; x <= y; x++)
//		{
//			int z = x * y;
//				printf("%d * %d=(%-2d)  ", y, x, z);//����%-2d��ʾ��ӡʱ�м��ӡ��λ��Ϊ�˹���(%2d���Ҷ��룬%-2d�������)
//		}
//		printf("\n");//ÿһ��Сѭ��yֵ��1��Ҫ��һ��ѭ������
//	}
//	return 0;
//}








//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
////////////                           32    goto  ֱ������ָ������
// 
////                                          ��ʽ����
//// 
//int main()
//{
//	printf("hhhh\n");
//	goto a;
//	printf("��������\n");
//	a:
//	printf("hhhh\n");
//	return 0;
//}





//////////////                     33      goto ��Ӧ��--�ػ�����
//int main() 
//{
//	char arr[20] = { 0 };
//	system("shutdown -s -t 60");              //shutdown -s  ���ùػ�       -t 60 �ػ�ʱ��      system():����ִ��ϵͳ����
//again:
//	printf("���롰����ɵ�ơ�����ȡ���ػ�\n�����룺");
//	scanf("%s", arr);
//	if (strcmp(arr, "����ɵ��") == 0)         //���ڱȽ��ַ����ĺ���
//		system("shutdown -a");                //shutdown -a  ȡ���ػ�
//	else
//		goto again;  //-------------- -����goto again,ֱ���������� again:
//	return 0;
//}






//////////��x����ת��Ϊy����
//int main() 
//{
//	int x, y, a, b, sum1 = 0, sum2 = 0;
//	printf("����x��������ֵ:");
//	scanf("%d", &a);
//	printf("x�Ľ�����:");
//	scanf("%d", &x);
//	int i;
//	for (i = 1; a != 0; i *= x)
//	{
//		int tem = (a % 10) * i;
//		sum1 = sum1 + tem;
//		a /= 10;
//	}
//	printf("ת����10����Ϊ%d\n",sum1);
//	int j;
//	printf("y�Ľ�����:");
//	scanf("%d", &y);
//	for (j = 1; sum1 != 0; j *= 10)
//	{
//		int tem = (sum1 % y) * j;
//		sum2 = sum2 + tem;
//		sum1 /= y;
//	}
//	printf("ת����y����Ϊ%d", sum2);
//	return 0;
//}