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