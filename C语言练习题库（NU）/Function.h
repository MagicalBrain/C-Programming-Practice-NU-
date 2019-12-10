#pragma once
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Function33.h"

using namespace std;

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

int func06(int num)
/*
输出指定序号的斐波那契数
*/
{
	if (num <= 2)
		return 1;
	else
		return func06(num - 2) + func06(num - 1);
	//return 0;
}

int func07(char str[])
/*
统计字符串中单词的个数
*/
{
	char tmp[20];
	int top = 0;
	int i = 0,re = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			if (str[i - 1] == 'a' || str[i - 1] == 'A')
			{
				if (top > 1)
					re++;
			}
			else
				re++;
			top = 0;
		}
		else
			tmp[top++] = str[i];
		i++;
	}
	return re+1;
}

void func08()
{
	char a[] = {'a','b','c'};
	char b[] = { 'd','e','f' };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			switch (a[i])
			{
			case 'a':
				if (b[j] == 'd')
					continue;
				break;
			case 'c':
				if (b[j] == 'd' || b[j] == 'f')
					continue;
			default:
				break;
			}
			printf("%c with %c\n", a[i], b[j]);
		}
		
	}
}

char* CompareStr(char s1[], char s2[])
{
	int l1 = sizeof(s1) / sizeof(char);
	int l2 = sizeof(s2) / sizeof(char);

	int i = 0, l;
	char* re = NULL;
	while (i < l1 && i < l2)
	{
		if (s1[i] < s2[i])
		{
			re = s2;
			l = l2;
			break;
		}
		else if (s1[i] > s2[i])
		{
			re = s1;
			l = l1;
			break;
		}
		else
			i++;
	}
	if (NULL == re)
		if (l1 > l2)
		{
			re = s1;
			l = l1;
		}
		else
		{
			re = s2;
			l = l2;
		}
	
	return re;
}

char* func09(char s1[], char s2[],char s3[])
{
	char* t;
	t = CompareStr(s1, s2);
	t = CompareStr(t, s3);
	return t;
}

void func10(char* str)
{
	int i = 0;
	int U = 0, D = 0, N = 0, S = 0, E = 0;
	//U大写，D小写，N数字，S空格，E其他
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			i++;
			continue;
		}
		if (str[i] >= 'A' && str[i] <= 'Z')
			U++;
		else if (str[i] >= 'a' && str[i] <= 'z')
			D++;
		else if (str[i] >= '0' && str[i] <= '9')
			N++;
		else if (str[i] == ' ')
			S++;
		else
			E++;
		i++;
		
	}
	printf("大写字母：%d\n小写字母：%d\n数字：%d\n空格：%d\n其他字符：%d\n",U,D,N,S,E);
}

void func11(int **a,int r,int c)
{
	int* max = (int*)malloc(r * sizeof(int));
	int* min = (int*)malloc(c * sizeof(int));
	int* max_r = (int*)malloc(r * sizeof(int));
	//int* min_c = (int*)malloc(c * sizeof(int));
	
	for (int i = 0; i < r; i++)
	{
		max[i] = 0;
	}
	

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (a[i][j] > max[i])
			{
				max[i] = a[i][j];
				max_r[i] = j;
			}
		}
	}

	for (int i = 0; i < c; i++)
	{
		min[i] = a[0][i];
		for (int j = 0; j < r; j++)
		{
			if (a[j][i] < min[i])
			{
				min[i] = a[j][i];
			}
		}
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (a[i][max_r[i]] == min[j])
				printf("鞍点为：%d，（%d,%d）\n", max[i],i,j);
		}
	}
}

char* func12(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = 'Z' - ((str[i] - 'A') % 26);
		}
		else if(str[i] >= 'a' && str[i] <= 'z')
			str[i] = 'z' - ((str[i] - 'a') % 26);
		i++;
	}
	return str;
}

char* func13(char* str1, char* str2)
{
	int i = 0, flag = 0;
	while (str1[i] != '\0')
		i++;

	flag = i; i = 0;
	while (str2[i] != '\0')
	{
		str1[flag + i] = str2[i];
		i++;
	}
	return str1;
}

int func14(char* str1, char* str2)
{
	int i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] > str2[i])
		{
			return str1[i] - str2[i];
		}
		else if (str1[i] < str2[i])
			return str1[i] - str2[i];	
		i++;
	}
	if (str1[i] != '\0')
		return 1;
	else if (str2[i] != '\0')
		return -1;
	return 0;
}

void func15(char *s1, char *s2)
{
	int i = 0, j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
}

void func16(int in[],int l)
{
	//int l = sizeof(in) / sizeof(int);
	int* fu = (int*)malloc(l * sizeof(int));
	int* zh = (int*)malloc(l * sizeof(int));
	int f = 0, z = 0;
	for (int i = 0; i < l; i++)
	{
		if (in[i] < 0)
			fu[f++] = in[i];
		if (in[i] > 0)
			zh[z++] = in[i];
		else if(in[i]==0)
			fu[f++] = in[i];
	}
	z = 0;
	for (int i = 0; i < l; i++)
	{
		if (i < f)
			in[i] = fu[i];
		else
			in[i] = zh[z++];
	}
}

bool func17(int a[10],int b[10])
{
	int geq = 0, e = 0, leq = 0;
	for (int i = 0; i < 10; i++)
	{
		if (a[i] > b[i])
			geq++;
		if (a[i] < b[i])
			leq++;
		if (a[i] == b[i])
			e++;
	}
	printf("大于次数：%d\n等于次数：%d\n小于次数：%d\n", geq, e, leq);
	if (geq > 5)
		return true;
	else 
		return false;
}

void func18(char *str)
{
	int l = 0, mid;
	while (str[l] != '\0')
		l++;
	mid = l / 2;
	for (int i = 0; i < mid; i++)
	{
		char t = str[i];
		str[i] = str[l - i - 1];
		str[l - i - 1] = t;
	}
}

void func19()
{
	int a, n;
	puts("输入a：");
	scanf("%d", &a);
	puts("输入n：");
	scanf("%d", &n);
	
	double l = 1;
	double* num = (double*)malloc(sizeof(double));
	for (int i = 0; i < n; i++)
	{
		if (i > 0)
		{
			num[i] = num[i - 1] + (a * l);
		}
		else
			num[i] = a;
		l *= 10;
		//printf("%d, ", num[i]);
	}
	//printf("\n");
	double re = 0;
	for (int i = 0; i < n; i++)
	{
		re += num[i];
	}
	printf("%lf\n", re);
}

void process(int a,int b)
{
	static int times = 0;
	
	switch (times)
	{
	case 0:
		if (a > b)
			printf("%d\n", a);
		else
			printf("%d\n", b);
		break;
	case 1:
		if (a > b)
			printf("%d\n", b);
		else
			printf("%d\n", a);
		break;
	case 2:
		printf("%d\n", a + b);
		break;
	}
	times++;
}

void func21()
{
	int year, month, day;
	scanf("%d年%d月%d日", &year, &month, &day);

	int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

	if ((year % 4) == 0 && (year % 100) != 0)
		months[1] = 29;
	else if (year % 400 == 0)
		months[1] = 29;

	int sum = 0;
	for (int i = 0; i < month-1; i++)
	{
		sum += months[i];
		printf("%d, ", months[i]);
	}
	printf("\n");
	//puts("")
	printf("%d\n", sum + day);
}

int func22(char* s)
{
	int l = 0;
	while (s[l] != '\0')
		l++;
	return l;
}

void func23(int* num, int n, int m)
{
	int* move = (int*)malloc(m * sizeof(int));
	int i = 0;
	for (i = 0; i < m; i++)
	{
		move[i] = num[i];
	}
	for (i = 0; i < n - m; i++)
		num[i] = num[i + m];
	for (int j = 0; i < n; i++, j++)
		num[i] = move[j];
}

bool func24(char* str, int n, int m,char s0[])
{
	int i;
	
	for (i = m-1; i < n; i++)
	{
		s0[i - m + 1] = str[i];
	}
	str[i] = '\0';
	return true;
}

void replace(char* str1, char* str2, int i, int j)
{
	int k = 0, l = 0;
	k = j;
	char s0[100];
	while (str1[k] != '\0')
	{
		s0[l] = str1[k];
		k++, l++;
	}
	s0[l] = '\0';
	k = i - 1;
	l = 0;
	while (str2[l] != '\0')
	{
		str1[k] = str2[l];
		k++;
		l++;
	}
	l = 0;
	while (s0[l] != '\0')
	{
		str1[k] = s0[l];
		l++, k++;
	}
	str1[k] = '\0';
}

double func26()
{
	double n1 = 1.0, n2 = 2.0;
	double t, re = 0.0;
	for (int i = 0; i < 20; i++)
	{
		re += n2 / n1;
		printf("%lf / %lf\n", n1, n2);
		t = n1;
		n1 = n2;
		n2 = n1 + t;
	}
	return re;
}


void func27()
/*
打印10行杨辉三角
*/
{
	int n = 10;
	//行数
	int m = 2 * n + 1;
	//列数

	int** array = (int**)malloc(sizeof(int*));// [n] [m] = { 0 };
	for (int i = 0; i < n; i++)
	{
		array[i] = (int*)malloc(m * sizeof(int));
		for (int j = 0; j < m; j++)
		{
			array[i][j] = 0;
		}
	}

	//将每一行的两端元素值为1
	for (int i = 0; i < n; i++)
	{
		array[i][n + i + 1] = 1;
		array[i][n - i + 1] = 1;
	}

	//开始计算每一行的元素值
	for (int i = 2; i < n; i++)
	//第1、2行只有1，已经搞定了
	{
		for (int j = n-i+1; j < n +i+1; j+=2)
		{
			array[i][j] = array[i - 1][j - 1] + array[i - 1][j + 1];
		}	
	}

	//输出语句
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			if (array[i][j])
			{
				if (array[i][j] / 100 != 0)
					printf("%.3d", array[i][j]);
				else if (array[i][j] / 10 != 0)
					printf("%.3d", array[i][j]);
				else
					printf("%.3d", array[i][j]);
			}
			else
				printf("   ");
		printf("\n");
	}
	printf("\n");
	
}

void func2701()
{
	int i, j, a[11][11]; 									/*定义i，j，a[11][11]为基本整型*/
	for (i = 1; i < 11; i++)								/*for循环i的范围从1到10*/
	{
		a[i][i] = 1; 									/*对角线元素全为1*/
		a[i][1] = 1; 									/*每行第一列元素全为1*/
	}
	for (i = 3; i < 11; i++)								/*for循环范围从第3行开始到第10行*/
		for (j = 2; j <= i - 1; j++)							/*for循环范围从第2列开始到该行行数减一列为止*/
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];				/*第i行j列等于第i-1行j-1列的值加上第i-1行j列的值*/
	for (i = 1; i < 11; i++)
	{
		for (j = 1; j <= i; j++)
			printf("%4d", a[i][j]);						/*通过上面两次for循环将二维数组a中元素输出*/
		printf("\n"); 									/*每输出完一行进行一次换行*/
	}
}


void func2702()
{
	const int n = 10;
	const int m = 2 * n - 1;
	int arr[n + 1][m] = { 0 };
	for (int i = 0; i < n; i++)
	{
		arr[i][n - i - 1] = 1;
		arr[i][n + i - 1] = 1;

	}
	for (int i = 2; i < n; i++)
	{
		for (int j = n - i + 1; j < n - 2 + i; j = j + 2)
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j + 1];
	}
	int p;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
			cout << "    ";
		p = 1;
		for (int j = n - i - 1; p < i + 2; j = j + 2)
		{
			cout << setw(4) << arr[i][j] << "    ";
			p = p + 1;
		}
		cout << endl;
	}
}

double func28(int n, double x)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return x;
	return (2 * n - 1) * x * func28(n - 1, x) - (n - 1) * func28(n - 2, x);
}

float P(int n, float x)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return x;
	else
		return (2 * (n - 1) + 1) * x * P(n - 1, x) - (n - 1) * P((n - 1) - 1, x);
}

void func29(int n)
/*

*/
{
	int* h = (int*)malloc(n * sizeof(int));
	int i = 0, flag = 0, j = 1;
	for ( i = 0; i < n; i++)
	{
		h[i] = i+1;
	}
	i = 0; j = 0;
	while (flag != n)
	{
		if (h[i] == 0)
			flag++;
		if (h[i] != 0)
		{
			j++;
			flag = 0;
		}
		if (j % 3 == 0  && h[i] != 0)
		{
			printf("%d\n", h[i]);
			h[i] = 0;
			flag = 0;
			j = 0;
		}
		
		i++;
		i = i % n;
	}
	
}

void func2901(int n) 
{
	int* h = (int*)malloc(n * sizeof(int));
	memset(h, 0, sizeof(int));
	int count = 0;
	int num = 3;
	int remain = n;
	while (1)
	{
		for (int i = 0; i < n; i++)
		{
			if (h[i] != 1 && ++count == num)
			{
				count = 0;
				h[i] = 1;
				remain -= 1;
				printf("%d ", i + 1);
			}
		}
		if (0 >= remain)
			break;
	}
}

void func30()
{
	int n = 100;
	double re = 1.0;
	for (int i = 2; i <= n; i++)
	{
		if (i % 2 == 0)
			re -= (1.0 / i);
		else
			re += (1.0 / i);
	}
	printf("%lf\n", re);
}

void func3001()
{
	int fm = 1;
	double partion = 1.0 / fm;
	double sum = 0;

	int n = 100;
	int label = 1;
	
	for (int i = 1; i <= n; i++)
	{
		sum += partion;
		fm += 1;
		label *= -1;
		partion = 1.0 / fm * label;
	}
	printf("%lf", sum);
}

void func31(char str1[],char str2[])
{
	int i = 1, j = 0;
	while (str1[i]!='\0')
	{
		str2[j] = str1[i];
		i += 2;
		j++;
	}
	str2[j] = '\0';
}

void func32()
/*
由于没说不可以用库函数，所以可以用string.h的库函数
*/
{
	char name[5][40];
	char* tmp = (char*)malloc(40 * sizeof(char));
	
	ifstream fin;
	fin.open("func32.txt");
	if (!fin.is_open())
		printf("open fail!\n");

	for (int i = 0; i < 5; i++)
	{
		printf("请输入国家%d的英文名：", i + 1);
		fin >> name[i];
		puts(name[i]);
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5-i-1; j++)
		{
			if (strcmp(name[j], name[j+1]) == 1)
			{
				strcpy(tmp, name[j]);
				strcpy(name[j], name[j + 1]);
				strcpy(name[j + 1], tmp);
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		puts(name[i]);
	}
}

void func33(CourseScoreRecords &stu, int sum_score[])
/*
最后根据总分对8名学生进行排名，且输出前三名的信息
*/
{
	for (int i = 0; i < stuNum; i++)
	{
		sum_score[i] = stu[i].ChineseScore + stu[i].EnglishScore + stu[i].MathScore;
	}
	for (int i = 0; i < stuNum-1; i++)
	{
		for (int j = 0; j < stuNum-i-1; j++)
		{
			if (sum_score[j] > sum_score[j + 1])
			{
				int tmp;
				CourseScore t;
				
				tmp = sum_score[j];
				sum_score[j] = sum_score[j + 1];
				sum_score[j + 1] = tmp;

				t = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = t;
			}
		}
	}
	int k = 0;
	while (k < 3)
	{
		printf("%d,学生信息：\n", k + 1);
		printf("语文成绩：%d\n", stu[stuNum - k - 1].ChineseScore);
		printf("数学成绩：%d\n", stu[stuNum - k - 1].MathScore);
		printf("英语成绩：%d\n", stu[stuNum - k - 1].EnglishScore);
		printf("总成绩：%d\n", sum_score[stuNum - k - 1]);
		k++;
	}
}