/*
冒泡排序来一波 

*/ 

#include<cstdio>
#include<iostream>

using namespace std;
int main()
{
	
	int i,j,k,l;
	cout<<"输入数字个数"<<endl;
	cin>>i;
	int a[i];
	for(j=0;j<i;j++) 
	{
		cin>>a[j];
	}
	l=0;
	for(k=i-1;k>=0;k--){
		l++;
	
	for(j=0;j<i-1;j++)
	{
		if(a[j]>a[j+1])
		{
			a[j]=a[j]+a[j+1];
			a[j+1]=a[j]-a[j+1];
			a[j]=a[j]-a[j+1];
			
		}
		
	}
		printf("No.%d:  %d\n",l,a[k]);

	
}
	
	//printf("jjjjjj");
	getchar();
	return 0;
}
