#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int n;
	int num[10001];
	int num_copy[10001];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num[i];
		num_copy[i]=num[i];
	}
	int min=num[0];
	int k=0;
	int judge =0;
	while(1){
		judge=0;
		k=0;
		min=num[0];
		for(int i=0;i<n-1;i++){
			if(num[i]==num[i+1]){
				judge++;
			}
			else{
				break;
			}
		}
		if(judge==n-1){
			cout<<num[0];
			break;
		}
		else{
			
			for(int i=1;i<n;i++){
				if(num[i]<min){
					min=num[i];
					k=i;
				}
			}
			num[k]+=num_copy[k];
		}
	}
	return 0;
}
