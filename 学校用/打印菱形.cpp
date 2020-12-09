#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
//死循环多次输入
	while(1>0){
	cout<<"打印n*n菱形"<<endl<<"输入n的值:"; 
	int n;
	cin>>n;
	int m=n;//n的值最后要改变，最后输出用m代替
	char a[200][200];
  //字符清空
	memset(a,' ',sizeof(a));
  //输入的第一个值横坐标通过计算为n/2+n%2
	int t=n/2+n%2;
  //循环次数通过计算为上面的t
	int judge=t;
  
  //t的值在改变，用t1代替
	int t1=t;
  //主代码开始
	for(int j=1;j<=judge;j++){
	
	for(int i=j;i<=judge+j-1;i++){
		a[i][t]='*';
		t++;
	}
	t=t1-1;
	t1=t;
	}	
  
	//输出
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
		printf(" %c",a[i][j]);
		}
		cout<<""<<endl;
	}
}	
	return 0;
}
