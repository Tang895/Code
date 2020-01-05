#include<iostream>
#include<cstdio>
//#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#define NN 1000000007
using namespace std;
long long pow(long long n,long long a){
	long long ans=1;
	for(int i=0;i<a;i++){
		ans=n*ans;
		ans=ans%NN;
	}
	return ans;
}
long long mipow(long long n,long long a){
	long long ans=1;
	while(a>0){
		if(a&1){
			ans=ans*n%NN;
		}
		n=n*n %NN;
		a>>=1;
	}
	return ans;
}
int main()
{
	long long n,a,b;
	long long ans=1;
	cin>>n>>a>>b;
	a=a %b;
	n=n %NN;
	/*
	while(1){
		ans=ans*pow(n,a/2);
		ans=ans%NN;
		a=a/2;
		if(a==1){
			break;
		}
	}
	//aÎªÆæÊý 
	if(a&1){
		ans=ans*n;
		ans%=NN;
	}
	*/
	
	ans=mipow(n,a);
	printf("%lld",ans-1);
	//cout<<a;
	return 0;
}
