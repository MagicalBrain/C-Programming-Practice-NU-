#pragma once
#include <stdio.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS

bool func01(int num)
/*����һ���������ж����Ƿ�������*/
{
	if (num > 1)
	{
		int sqr = sqrt(num), i;
		//��һ����ȡ�俪���ŵ�ֵ����ȡ��������sqr
		for (i = 2; i <= sqr; i++)
			if (num % i == 0)
				return false;
		//�ڶ�����ѭ����2��sqr������������������
		return true;
	}
	return false;
}

void shuixian(int num)
{
	int i = 0, t, tmp = num;
	int w[5];	
	/*
	ע�����鳤��Ϊ5�Ļ�������Χ�ٴ�һ��ͻ�������������
	����:��Χ��200000
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
��ӡ1��20000������ˮ�ɻ���
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
���2��20000����������
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
��m��n���������
*/
{
	if (n == 0)
		return m;
	gcd(n, m % n);
}

int func04(int m,int n)
/*
��m��n����С������
*/
{
	return (m*n)/gcd(m,n);
}

double func05()
/*
С���10m�ߵĵط����£�ÿһ�ε���֮ǰ�߶ȵ�һ�룬����ֹ���߹��ľ���
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