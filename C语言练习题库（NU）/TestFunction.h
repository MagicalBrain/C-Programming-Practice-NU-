#pragma once
#include <stdio.h>
#include "Function.h"
#include <math.h>

void Testfunc01()
{
	int num;
	char str[50];
	puts("������һ��������");
	//gets_s(str, 50);
	scanf("%d", &num);
	if (func01(num))
		puts("��������");
	else
		puts("����������");
}

void Testfunc02()
{
	func02();
}