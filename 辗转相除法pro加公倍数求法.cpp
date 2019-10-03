#include "stdafx.h"
#include<cstdio>
#include<iostream>
using namespace std;
//判断大小函数

int a, b, c;
int jud;
int result;

void judge(void) {
	//交换值，a为最大值
	if (a < b) {
		a = a + b;
		b = a - b;
		a = a - b;
	}


}

int main() {
	printf("输入你想求最小公倍数还是最大公因数，1为最大公因数，2为最大公倍数\n");
	scanf_s("%d", &jud);
	printf("输入两个你要求的数\n");
	scanf_s("%d%d", &a, &b);
	c = a*b;
	judge();
	while (1 > 0) {
		a = a%b;
		if (a==0)
		{
			result = b;
			break;
		}
		b = b%a;
		if (b==0)
		{
			result = a;
			break;
		}
	}
	if (jud==1)
	cout << result;
	else {
		cout << c / result;
	}
	return 0;
}
