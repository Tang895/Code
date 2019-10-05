/*\
递归求x的n次方
date:2019.10.05
author:IanTang
*/

#include<iostream>
using namespace std;
int xn(int n);
int n,x;

int main(){
		cin>>x>>n;
		int a;
	cout<<xn(n)<<endl;
	getchar();
	cin>>a;//暂停用的
	return 0;
}

//递归函数
int xn(int n){
	if(n==0)
		return 1;
	else
	{
		return x*xn(n-1);
	}
}