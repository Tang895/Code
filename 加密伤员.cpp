/*
???ַ???
date:2019.10.02
author:IanTang

1：原文中所有的字符都在字母表中被循环左移了3个位置
2：逆序存储
3：大小写反转
*/


#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char a;
	char name[51];
	int i=0;
	memset(name,0,sizeof(name));
	gets(name);

	//大小写反转，右移3个位置
	for(;i<51;i++){
	
		if(name[i]==0)
		break;
		if(name[i]<92){
			name[i]+=35;
		}
		else{
			name[i]-=29;
		}
		
}
	//逆序输出
	for(;i>=0;i--){
		cout<<name[i];
	}

	return 0;
}
