/*
date:2019.10.01
author:IanTang
矩阵对角线，一条，反斜杠加值输出；值为十 
*/

#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int a,b;//a为行，b为列
	printf("输入行\n");
	cin>>a;
	printf("输入列\n");
	cin>>b;
	int num[a][b];
	int i,j;
	for(i = 0;i<a;i++){
		for(j = 0;j<b;j++){
			scanf("%d",&num[i][j]);
		}
	}
	num[0][b-1] = num[0][b]+10;
	num[a-1][0] = num[a][0]+10;
	i = 0;
	for(i = 0;i<a;i++){
		for(j = 0;j<b;j++){
			
			if(j==b-1)
				printf("%d\n",num[i][j]);
			else
			printf("%d ",num[i][j]);
		}
	}
	return 0;
}
