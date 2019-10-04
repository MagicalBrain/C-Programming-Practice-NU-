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