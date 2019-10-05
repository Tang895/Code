#include<iostream>
#include<cstdio>
using namespace std;
int yue(int a,int b);

int main()
{
	int a,b,temp;
	cin>>a>>b;
	if(b>a){
		temp = a;
		a=b;
		b=temp;
	}

	temp=yue(a,b);
	cout<<temp;
	cin>>temp;//暂停用的
	return 0;
}

int yue(int a,int b)
{
	a=a%b;
	if(a==0)
		return b;
	b=b%a;
	if(b==0)
		return a;
	yue(a,b);
}