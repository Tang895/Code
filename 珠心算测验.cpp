/*

描述
珠心算是一种通过在脑中模拟算盘变化来完成快速运算的一种计算技术。珠心算训练， 既能够开发智力，又能够为日常生活带来很多便利，因而在很多学校得到普及。

某学校的珠心算老师采用一种快速考察珠心算加法能力的测验方法。他随机生成一个正整数集合，集合中的数各不相同，然后要求学生回答：其中有多少个数，恰好等于集合中另外两个（不同的）数之和？

最近老师出了一些测验题，请你帮忙求出答案。

格式
输入格式
输入共两行，第一行包含一个整数 n，表示测试题中给出的正整数个数。

第二行有 n 个正整数，每两个正整数之间用一个空格隔开，表示测试题中给出的正整数。

输出格式
输出共一行，包含一个整数，表示测验题答案。

样例1
样例输入1
4
1 2 3 4

Copy
样例输出1
2
Copy
限制
对于 100%的数据，3 ≤ n ≤ 100，测验题给出的正整数大小不超过 10,000。

提示
由 1+2=3，1+3=4，故满足测试要求的答案为 2。注意，加数和被加数必须是集合中的两个不同的数。

来源
NOIP2014 普及组




*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int b[100002];
	int h=0;
	int i=0;
	int sum=0;
	int n;
	int j;
	cin>>n;
	int a[n];
	for(int k=0;k<n;k++)
	cin>>a[k];
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			b[h]=a[i]+a[j];
			h++;
		}
	}
	for(j=0;j<n;j++){
		for(i=0;i<h;i++){
			if(a[j]==b[i]){
				sum++;
				break;
			}
		}
	}
	cout<<sum;
	return 0;
}
