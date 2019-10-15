/*
date:2019.10.06
author:IanTang
*/
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int d[20000];
int c[10000][10000];
int a[10000],b[10000];
int x;

void init(int a[]);
void multiply(int a[],int b[]);
//void add(int a[],int b[]);
int main()
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	//memset(c2,0,sizeof(c2));
	init(a);
	init(b);
	multiply(a,b);
	
//	cin>>a[0];//pause
	return 0;
}

void init(int a[])
{
	string s;
	cin>>s;
	a[0]=s.length();
	for(int i=1;i<=a[0];i++){
		a[i]=s[a[0]-i]-'0';
	}
}
//错位相加函数，传入c1,c2;

void multiply(int a[],int b[])
{
	for(int j=1;j<=(a[0]+1)*(b[0]+1);j++){
		for(int i=1;i<=a[0];i++){
			c[j][i+j-1]=a[i]*b[j];
		}

		for(int k=1;k<=j+a[0]-1;k++){
			d[j]+=c[k][j];
		}
		if(d[j]>=10){
			d[j+1]+=d[j]/10;
			d[j]=d[j]%10;
		}
	}
	x=(a[0]+1)*(b[0]+1);
	while(d[x]==0){
		x--;
	}
	
	for(;x>0;x--){
		cout<<d[x];
	}
}