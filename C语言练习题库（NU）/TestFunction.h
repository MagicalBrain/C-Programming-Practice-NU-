#pragma once
#include <stdio.h>
#include "Function.h"

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