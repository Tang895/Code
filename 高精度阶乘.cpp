#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int num[1000];
int k=0;
int add(int a[],int n);
int main()
{
    int n;
    cin>>n;
    
    memset(num,0,sizeof(num));
    num[0]=1;
    
    for(int i=2;i<=n;i++){
        add(num,i);
    }
    for(int i=998;i>=0;i--){
        if(num[i]!=0){
            k=i;
            break;
        }
    }
    for(int i=k;i>=0;i--){
        cout<<num[i];
    }
    return 0;
}
int add(int num[],int n)
{
    
    for(int i=0;i<=999;i++){
        num[i]*=n;
    }
    
    for(int i=0;i<=999;i++){
        if(num[i]>=10){
            num[i+1]+=num[i]/10;
            num[i]=num[i]%10;
        }
    }
    
    return 0;
}
