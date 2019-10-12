#pragma once
#include <stdio.h>
#include "Function.h"
#include <math.h>
#include "Function33.h"
#include<iostream>
#include <fstream>

using namespace std;

void Testfunc01()
{
	int num;
	//char str[50];
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

void Testfunc20()
{
	int a, b;
	scanf("%d%d", &a, &b);
	process(a, b);
	process(a, b);
	process(a, b);
}

void Testfunc21()
{
	func21();
}

void Testfunc22()
{
	//char s[5] = {'a','b','c','d','e'};	这种情况怎么处理？
	char s[100] = "adsfag";
	printf("%d\n",func22(s));
}

void Testfunc23()
{
	int num[10] = {1,2,3,4,5,6,7,8,9,10};
	func23(num, 10, 9);
	for (int i = 0; i < 10; i++)
	{
		printf("%d, ", num[i]);
	}
	printf("\n");
}

void Testfunc24()
{
	char str[100] = "qweasdf";//7+1=8
	char s0[100];//4+1=5
	int num;
	puts("输入m：");
	scanf("%d", &num);
	puts(str);
	if (func24(str, 8, num, s0))
	{
		puts("处理成功！");
		
		puts(s0);
	}
	else
		puts("处理失败！");
}

void Testfunc25()
{
	char str[100] = "qweasdf";
	char s0[100] = "jkli";
	int i, j;

	puts(str);
	puts(s0);
	puts("输入i：");
	scanf("%d", &i);
	puts("输入j：");
	scanf("%d", &j);
	
	replace(str, s0, i, j);
	puts(str);
}

void Testfunc26()
{
	puts("我的答案：");
	printf("%lf\n", func26());

	puts("师兄的答案：");

	int num = 2;
	int den = 1;
	double sum = 0;
	int cnt = 1;

	for (; cnt <= 20; cnt++)
	{
		sum += num * 1.0 / den;

		num += den;
		den = num - den;
	}

	printf("%f\n", sum);
}

void Testfunc27()
{
	func27();
}

void Testfunc28()
{
	printf("%lf\n",func28(10,3));

	printf("%f\n", P(10, 3));
}

void Testfunc29()
{
	int n;
	puts("输入n：");
	scanf("%d", &n);
	func29(n);
	puts("");
	func2901(n);
}

void Testfunc30()
{
	func30();
	func3001();
}

void Testfunc31()
{
	char str1[100] = "asdfg";
	char str2[100];
	puts(str1);
	func31(str1, str2);
	puts(str2);
}

void Testfunc32()
{
	func32();
}

void Testfunc33()
{
	CourseScoreRecords stu = {0};
	int score[stuNum] = { 0 };
	ifstream fin;
	fstream fout;
	//puts("C:\\C++ 试作品\\VS2015 Project\\sjjg02\\东北大学C语言题库\\C语言练习题库（NU）\\func33.textfin.open("func33.text",ios::in);
	fin.open("func33.txt");
	if (!fin.is_open())
		//cout << "文件打开失败！" << endl;
		perror("Error:");
	//if (!fout.is_open())
	//	cout << "文件打开失败！" << endl;
	for (int i = 0; i < stuNum; i++)
	{
		//printf("学生%d的信息：\n", i + 1);
		//puts("输入学生姓名：");
		//scanf("%s", stu[i].StudentName);
		fin >> stu[i].StudentName;
		//puts("输入语文成绩：");
		//scanf("%d", &stu[i].ChineseScore);
		fin >> stu[i].ChineseScore;
		//puts("输入数学成绩：");
		fin >> stu[i].MathScore;
		//scanf("%d", &stu[i].MathScore);
		//puts("输入英语成绩：");
		//scanf("%d", &stu[i].EnglishScore);
		fin >> stu[i].EnglishScore;
	}
	fin.clear();
	fin.close();
	for (int i = 0; i < stuNum; i++)
	{
		cout << stu[i].StudentName << endl;
		cout << stu[i].ChineseScore << endl;
		cout << stu[i].MathScore << endl;
		cout << stu[i].EnglishScore << endl;
	}

	func33(stu,score);

	for (int i = 0; i < stuNum; i++)
	{
		printf("%d:%d\n", i + 1, score[i]);
	}
}

void Testfunc_string()
{
	char str1[100] = "asdfg";
	char str2[100] = "wefg";
	if (strcmp(str1, str2))
		puts(str1);
	else
		puts(str2);
}