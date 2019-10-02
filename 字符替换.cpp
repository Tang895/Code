/*
×Ö·ûÌæ»»
date:2019.10.02
author:IanTang 
*/


#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	char string[300];
	char A0;
	char A1;
	gets(string);
	cin>>A0;
	cin>>A1;
	int i=0;
	while(i<=300){
		if(A0==string[i]){
			string[i]=A1;
		}
		i++;
	}
	
	
	
	
	puts(string);
	cout<<string<<endl;
	
	
	return 0;
}
