#include "stdafx.h"
#include<cstdio>
#include<iostream>
using namespace std;
//判断大小函数

int a, b;
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
	printf("输入两个你要求的数\n");
	scanf_s("%d%d", &a, &b);
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

	cout << result;
	return 0;
}
