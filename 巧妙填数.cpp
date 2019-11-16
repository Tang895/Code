/*


描述
将1,2,\cdots,91,2,?,9共99个数分成三组，分别组成三个三位数，且使这三个三位数构成1:2:31:2:3的比例。

试求出所有满足条件的三个三位数。
例如：三个三位数192,384,576192,384,576满足以上条件。

格式
输入格式
无输入。

输出格式
需要输出全部结果。每行输出3个数 用空格隔开。按照字典序的顺序输出。

来源
NOIP 1998 普及组 第一题


*/



#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int num[9];
	int b;
	int c;
	for(int i=100;i<=333;i++){
		b=2*i;c=3*i;
		int judge=1;
		num[1]=i%10;
		num[2]=i/10%10;
		num[3]=i/100;
		num[4]=b%10;
		num[6]=b/10%10;
		num[7]=c%10;
		num[8]=c/10%10;
		num[0]=c/100;
		num[5]=b/100;
		int sum=0;
		for(int j=0;j<9;j++){
			
			sum+=num[j];
		}
		if(sum!=45){
			sum=0;
			continue;
			
		}
		
			
			for(int k=0;k<8;k++){
			for(int j=k+1;j<9;j++){
				if(num[j]==num[k]){
					judge=0;
				}
			}
		}
		
		
		if(judge!=0)
		{
		cout<<i<<" "<<b<<" "<<c<<endl;
	}
	judge = 1;
	}
	return 0;
}
