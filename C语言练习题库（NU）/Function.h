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
	for ( i = 1; i <= 20000; i++)
	{
		shuixian(i);
	}
}