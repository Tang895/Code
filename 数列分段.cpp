/*
CSP数列分段
author:Ian Tang
Date:2019/9/12 
Demo 
*/
#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int Num;//数字个数 
	int i;
	int Temp;
	int Result = 1;
	cout<<"输入数字个数\n";
	cin>>Num;
	int a[Num];
	
	
	
	
	cin>>a[0];
	for(i = 1;i<Num;i++)
	{
		 cin>>a[i];
		  if(a[i]!=a[i-1]){
		  	Result++;
		  }
	} 
	cout<<Result<<endl;
	
	//getchar();
	cout<<"运行完成"<<endl;
	cin>>Temp;
	return 0;
}
