/*
求x!
用递归的方法
精度:x<=16
*/
#include<cstdio>
#include<iostream>
using namespace std;
int js(int x);

int main()
{
	int x,a;
	cin>>x;
	cout<<js(x)<<endl;
	cin>>a;
	return 0;
}

//递归函数开始
int js(int x)
{
	if(x==0)
		return 1;
	else
	{
		return x*js(x-1);
	}
}