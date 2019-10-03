// Win32Project1.cpp : 定义控制台应用程序的入口点。
//从m个数字中取出n个数的所有情况数
//date:2019.10.03
//#include "stdafx.h"
#include<iostream>
#include<cstdio>
using namespace std;


//阶乘函数
int js(int a)
{
	int i;
	int sum = 1;
	for (i = 1; i <= a; i++) {
		sum = sum*i;
	}
	return sum;

}

int main()
{

	int m, n;
	int fuck;
	printf("输入m和n\n");
	scanf_s("%d%d", &m,&n);
	fuck = js(m) / ((js(m - n))*(js(n)));
	cout << fuck;
	//printf("%ld", fuck);
    return 0;
}



