/*
已知一个一维数组，a[1....n],又已知一整数m，如果能使数组a中的任意几个元素之和等于m，则输出yes,反之则输出no
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

bool flag;
int a[100];

void sum(int n,int m);

int main()
{
	int n,m;
	cout<<"输入n"<<endl；
	cin>>n;
	cout<<"输入m"<<endl;
	cin>>m;
	cout<<"输入n个数"<<endl;
	for(int i=0;i<n;i++)
		cin>>a[i];
	flag=false;
	sum(n,m);
	cout<<flag;
	cin>>a[0];//pause

}

void sum(int n,int m)
{
	if(a[n]==m){
		flag=true;
		return;
	}
	else
	{
		sum(n-1,m);
		sum(n-1,m-a[n]);
	}
}

