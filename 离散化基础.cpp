/*
离散化基础
输出每个数排序后的编号
date:2019.10.05
author:IanTang

*/

#include<iostream>
#include<cstdio>
using namespace std;
struct data{
		int rank;//排名
		int daxiao;//数值
		int index;//小标
	};
	data a[1000];
int main()
{
	int n;
	int i;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i].daxiao;
		a[i].index=a[i].daxiao;
		a[i].rank=i+1;//排名先按照顺序排
	}

	//排序
	int temp;
	int j;
	for(j =i;j>=0;j--){
		for(int k=0;k<i-1;k++){
			if(a[k].daxiao>a[k+1].daxiao){
				temp = a[k].daxiao;
				a[k].daxiao=a[k+1].daxiao;
				a[k+1].daxiao=temp;
				//交换排名
				temp = a[k].rank;
				a[k].rank=a[k+1].rank;
				a[k+1].rank=temp;


			}
		}

		//a[n-1].rank=n;
		//n--;
	}

	//输出
	for(j=0;j<i;j++){
		cout<<a[j].rank;
	}
	cin>>n;

	return 0;
}