/*
蛇形填数，二维数组
描述：在n*n方阵里填入1，2，3，。。。。。，n*n,要求填成蛇形，例如当n=4时
10 11 12 1
9 16  13 2 
8 15  14 3 
7 6   5  4 


author:IanTang
date:2019.10.01 
*/
#include<cstdio>
#include<iostream>
#include<cstring>
//#include<iomanip>
//#define N 10
using namespace std;
//int num[N][N];
int main()
{
	int N;
	int i,j,k;
	i=0;
	k=1;
	int a=1;
	printf("输入n的值\n"); 
	scanf("%d",&N); 
	int num[N][N];
	memset(num,0,sizeof(num));//数组清零 
	
		j=N-1;
	while(k<=N*N){
		
		
		//下走 
		while(i<N-1 && !num[i+1][j]){
		
			num[i][j]=a;
			i++;
			a++;
		}
		//左走 
		while(j>=0 && !num[i][j-1]){
			num[i][j]=a;
			a++;
			j--;
			 
		}
		//上走
		while(i>=0 && !num[i-1][j]){
			num[i][j]=a;
			a++;
			i--;
		}
		//右走
		while(j<N-1 && !num[i][j+1]) {
			num[i][j]=a;
			a++;
			j++;
		}
		
		
		
		
		k++;
		
		
		
	}
	
	//输出 
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
				if(j==N-1)
				printf("%d\n",num[i][j]);
			else
			printf("%d   ",num[i][j]);
		}
	}
	

	
	

	return 0;
}
