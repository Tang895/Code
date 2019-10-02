/*
谁拿了最多奖学金，noip提高组2005第一题
author:IanTang
date:2019.10.02
*/
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int N;//People
	int i=0;
	
	
	char name[101][21];
	cin>>N;
	int scores1[N];//期末成绩,班级评议成绩
	int scores2[N];
	char a[N];//是否学生干部
	char b[N];//是否西部学生
	int num[N];//奖学金数量，排序！！！
	memset(num,0,sizeof(num));//奖学金为零
	int tot[N];//论文数量
	while(i<N){
		scanf("%s",name[i]);
		cin>>scores1[i];
		cin>>scores2[i];
		cin>>a[i];
		cin>>b[i];
		cin>>tot[i];
		//院士奖学金
		if(scores1[i]>80 && tot[i]!=0){
			num[i]=num[i]+8000;
		}
		//五四奖学金
		if(scores1[i]>85 && scores2[i]>80){
			num[i]+=4000;
		}
		//成绩优秀奖
		if(scores1[i]>90){
			num[i]+=2000;
		}
		//西部奖学金
		if(scores1[i]>85 && b[i]=='Y'){
			num[i]+=1000;
		}
		//班级贡献奖
		if (scores2[i]>80 && a[i]=='Y')
		{
			/* code */
			num[i]+=850;
		}
		i++;

	}
	/*
	//排序
	for(i=N-1;i>=0;i--){
		for(int j=0;j<N;j++){
			if(num[j]>num[j+1]){
				num[j]+=num[j]+num[j+1];
				num[j+1]=num[j]-num[j+1];
				num[j]=num[j]-num[j+1];
			}
		}
	}
	*/

	int max=0;//最大奖学金存放
	int total=0;//总的奖学金
	int j=0;//存储i
	for ( i = 0; i < N; ++i)
	{
		/* code */
		if(num[i]>max){
			max = num[i];
			j=i;

		}
		total = total+num[i];
	}


	cout<<name[j]<<endl;
	cout<<num[j]<<endl;
	cout<<total;
	return 0;
}
