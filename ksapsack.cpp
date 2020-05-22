//
//  main.cpp
//  3
//
//  Created by IanTang on 2020/5/17.
//  Copyright © 2020 IanTang. All rights reserved.
//

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=100002;
int dp[MAXN]={0};//this storage the max value

//dp[i]/-->i means the max value
int main(){
    int w;
    int n;
    int value[MAXN];
    int weight[MAXN];
    cin>>w>>n;;
    for(int i=1;i<=n;i++){
        cin>>weight[i];
    }
    for(int i=1;i<=n;i++){
        cin>>value[i];
    }
    
    
    
    
    
    for(int i=1;i<=n;i++){
        for(int l=w;l>=weight[i];l--){
            if(dp[l-weight[i]]+value[i]>dp[l]){
                dp[l]=dp[l-weight[i]]+value[i];
            }
        }
    }
    cout<<dp[w];
    
    
    return 0;
}
