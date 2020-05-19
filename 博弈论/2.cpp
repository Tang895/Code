#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans1=0,ans2=0;
    int a[50001][4];
    //memset(a,0,sizeof(a));
    for(int i=0;i<n-2;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }
    int judge=0;
    for(int i=1;i<n-2;i++){
        for(int j=0;j<3;j++){
            for(int l=0;l<3;l++){
                if(a[0][j]==a[i][l]){
                    judge++;
                    if(judge==2){
                        judge=0;
                        if(!ans1)
                        ans1=i;
                        else{
                            ans2=i;
                        }
                    }
                }
            }
           
        }
        judge=0;
    }
    if(ans1==0||ans2==0){
        cout<<"JMcat Win"<<endl;
    }
    else{
        if((n-2)%2==0){
            cout<<"JMcat Win"<<endl;
        }
        else{
            cout<<"PZ Win"<<endl;
        }
    }
    
    return 0;
}
