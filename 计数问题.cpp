/*

描述
试计算在区间 1 到 n 的所有整数中,数字 x(0 ≤ x ≤ 9)共出现了多少次?例如,在 1 到 11 中,即在 1、2、3、4、5、6、7、8、9、10、11 中,数字 1 出现了 4 次。

格式
输入格式
输入共 1 行,包含 2 个整数 n、x,之间用一个空格隔开。

输出格式
输出共 1 行,包含一个整数,表示 x 出现的次数。

样例1
样例输入1
11 1

Copy
样例输出1
4

Copy
限制
每个测试点1s。

提示
对于 100%的数据,1≤ n ≤ 1,000,000,0 ≤ x ≤ 9。

来源
NOIP 2013 普及组


*/





#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int main(){
	int n;
	int x;
	cin>>n>>x;
	int a[n];
	int num[10];
	memset(num,0,sizeof(num));
	//输入 
	for(int i=0;i<=n;i++){
		a[i]=i;
	}
	int i=1;
	while(i<=n){
	
	while(a[i]){
		int judge = a[i]%10;
		switch (judge){
		case 0:num[0]++;break;
		case 1:num[1]++;break;
		case 2:num[2]++;break;
		case 3:num[3]++;break;
		case 4:num[4]++;break;
		case 5:num[5]++;break;
		case 6:num[6]++;break;
		case 7:num[7]++;break;
		case 8:num[8]++;break;
		case 9:num[9]++;break;
		
		}
		a[i]/=10;
	}
	i++;
}
	cout<<num[x];
	
	
	return 0;
} 
