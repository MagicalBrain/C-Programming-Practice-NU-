#pragma once
#include <stdio.h>
#include <malloc.h>
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

int func06(int num)
/*
���ָ����ŵ�쳲�������
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
ͳ���ַ����е��ʵĸ���
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
	//U��д��DСд��N���֣�S�ո�E����
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
	printf("��д��ĸ��%d\nСд��ĸ��%d\n���֣�%d\n�ո�%d\n�����ַ���%d\n",U,D,N,S,E);
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
				printf("����Ϊ��%d����%d,%d��\n", max[i],i,j);
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
	printf("���ڴ�����%d\n���ڴ�����%d\nС�ڴ�����%d\n", geq, e, leq);
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
	puts("����a��");
	scanf("%d", &a);
	puts("����n��");
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
	printf("%ld\n", re);
}