#pragma once
#include <stdio.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS

bool func01(int num)
/*输入一个整数，判断其是否是素数*/
{
	if (num > 1)
	{
		int sqr = sqrt(num), i;
		//第一步，取其开根号的值再下取整，赋给sqr
		for (i = 2; i <= sqr; i++)
			if (num % i == 0)
				return false;
		//第二步，循环除2到sqr，若能整除则不是素数
		return true;
	}
	return false;
}

void shuixian(int num)
{
	int i = 0, t, tmp = num;
	int w[5];	
	/*
	注意数组长度为5的话，当范围再大一点就会造成数组溢出，
	例如:范围大到200000
	*/

	while (tmp > 0)
	{
		w[i] = tmp % 10;
		i++;
		tmp /= 10;
	}

	int sum = 0;
	for ( t = 0; t < i; t++)
	{
		if (w[t])
			sum += (int)(pow(w[t], i));
	}
	if (sum == num)
		printf("%d\n", num);
}

void func02()
/*
打印1到20000的所有水仙花数
*/
{
	int i;
	for ( i = 2; i <= 20000; i++)
	{
		shuixian(i);
	}
}

void func03()
/*
求出2到20000的所有完数
*/
{
	int num, sum;
	for (int i = 2; i <= 20000; i++)
	{
		num = i;
		sum = 0;
		for (int j = 1; j < i; j++)
		{
			if (num % j == 0)
				sum += j;
		}
		if (sum == num)
			printf("%d\n", num);
	}
}

int gcd(int m, int n)
/*
求m，n的最大公因数
*/
{
	if (n == 0)
		return m;
	gcd(n, m % n);
}

int func04(int m,int n)
/*
求m和n的最小公倍数
*/
{
	return (m*n)/gcd(m,n);
}

double func05()
/*
小球从10m高的地方掉下，每一次弹回之前高度的一半，问求静止后，走过的距离
*/
{
	double sc = 0.0000001;
	double h = 10;
	double sum = 10;
	h /= 2;
	while (h > sc)
	{
		sum += 2 * h;
		//printf("%lf\n", h);
		h /= 2;
	}
	return sum;
}