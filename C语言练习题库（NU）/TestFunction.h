#pragma once
#include <stdio.h>
#include "Function.h"
#include <math.h>

void Testfunc01()
{
	int num;
	char str[50];
	puts("请输入一个整数：");
	//gets_s(str, 50);
	scanf("%d", &num);
	if (func01(num))
		puts("是素数！");
	else
		puts("不是素数！");
}

void Testfunc02()
{
	func02();
}

void Testfunc03()
{
	func03();
}

void Testfunc04()
{
	int m, n;
	scanf("%d%d", &m, &n);
	printf("%d,%d\n%d\n", m, n, func04(m, n));
}

void Testfunc05()
{
	printf("%lf\n",func05());

	double dis = 0;
	double h = 10.0;

	double Bh = h / 2;

	while (Bh > 0)
	{
		dis += 2 * Bh;
		Bh /= 2;
	}

	dis += h;
	printf("白皮书结果：%f:", dis);
}

void Testfunc06()
{
	int num;
	scanf("%d", &num);

	for (int i = 1; i <= num; i++)
	{
		printf("%d,", func06(i));
	}
	printf("\n");
}

void Testfunc07()
{
	char str[100] = "A pen drop from a big tree";
	int re = func07(str);
	printf("%d\n", re);
}

void Testfunc08()
{
	func08();
}

void Testfunc09()
{
	char* re="";
	char s1[40] = "bsdf";
	char s2[40] = "bcdf";
	char s3[40] = "bsdfgh";
	re = func09(s1,s2,s3);

	puts(re);
}

void Testfunc10()
{
	char s[100] = "asd2.\n0sadf\n89 0a\n";
	func10(s);
}

void Testfunc11()
{
	int a[2][3] = {1,2,8,4,5,6};
	int** b = (int**)malloc(sizeof(int*));
	

	for (int i = 0; i < 2; i++)
	{
		b[i] = (int*)malloc(3 * sizeof(int));
		for (int j = 0; j < 3; j++)
		{
			b[i][j] = a[i][j];
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d,", b[i][j]);
		}
		printf("\n");
	}
	func11(b, 2, 3);
}

void Testfunc12()
{
	char str[100] = "as89DF1GW";
	int i = 0;
	
	puts(str);

	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			printf("%d ", str[i]-'A');
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
			printf("%d ", str[i]-'a');
		i++;
	}
	printf("\n"); i = 0;

	char* re = func12(str);
	puts(re);
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			printf("%d ", str[i] - 'A');
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
			printf("%d ", str[i] - 'a');
		i++;
	}
	printf("\n");
}

void Testfunc13()
{
	char str1[100] = "asdfg";
	char str2[100] = "mpiinifsdg";

	puts(str1);
	puts(str2);

	char* re = func13(str1, str2);
	puts(re);
}

void Testfunc14()
{
	char str1[100] = "asdf";
	char str2[100] = "asdf";

	printf("%d\n", func14(str1, str2));
}

void Testfunc15()
{
	char str1[100] = "asdf";
	char str2[100] = "dfgh";
	
	puts(str1);
	puts(str2);
	func15(str1, str2);
	puts(str1);
}

void Testfunc16()
{
	int in[] = {0,1,2,3,-1,-2,4,-3,6,-4};
	int l = sizeof(in) / sizeof(int);
	for (int i = 0; i < l; i++)
	{
		printf("%d, ", in[i]);
	}
	printf("\n");
	func16(in,l);
	for (int i = 0; i < l; i++)
	{
		printf("%d, ", in[i]);
	}
	printf("\n");
}

void Testfunc17()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int b[10] = { 2,3,4,10,9,8,7,5,6,1 };

	for (int i = 0; i < 10; i++)
	{
		printf("%d, ", a[i]);
	}
	printf("\n");

	for (int i = 0; i < 10; i++)
	{
		printf("%d, ", b[i]);
	}
	printf("\n");

	if (func17(a, b))
		printf("a大于b!\n");
}

void Testfunc18()
{
	char str[100] = "sdfjouyoa";

	puts(str);
	func18(str);
	puts(str);
}

void Testfunc19()
{
	func19();
}