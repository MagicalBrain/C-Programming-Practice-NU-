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
	for ( i = 1; i <= 20000; i++)
	{
		shuixian(i);
	}
}