/*
高精度计算
date:2019.10.05
author:IanTang

*/
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int lena;
int lenb;
int c[100];

void inita(int a[]);//传入数组函数a
void initb(int b[]);// 传入函数b

void add(int a[],int b[]);//相加函数
int main()
{

	
	
	int a[100];
	int b[100];
	memset(c,0,sizeof(c));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));

	inita(a);
	initb(b);

	add(a,b);

	cin>>lena;



	return 0;
}

//传入数组函数
void inita(int a[])
{
	string s;
	cin>>s;
	a[0]=s.length();
	lena = a[0];

	for(int i=1;i<=a[0];i++){
		a[i]=s[a[0]-i]-'0';//倒叙存储
	}

}

void initb(int b[])//传入函数b
{
	string s;
	cin>>s;
	b[0]=s.length();
	lenb = b[0];

	for(int i=1;i<=b[0];i++){
		b[i]=s[b[0]-i]-'0';//倒叙存储
	}

}


void add(int a[],int b[])
{
	int i=1;
	int x=0;
	while(i<=lenb || i<=lena){
		c[i]=b[i]+a[i];
		if(c[i]>=10){
			c[i]=c[i]%10;
			c[i+1]=c[i+1]+c[i+1]/10;
		}
		i++;
		
		
		}

		if(c[i+1])
			x=i;
		else
			x=i-1;

	//输出
	for(int i =x;i>0;i--){
			cout<<c[i];
		}
	

}
