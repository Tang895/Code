//
//  main.cpp
//  nasa
//P1334 NASA的食物计划
//  Created by IanTang on 2020/5/23.
//  Copyright © 2020 IanTang. All rights reserved.
//

#include <iostream>

#include<cstdio>
#include<algorithm>
#define MAXN 10002
using namespace std;
int dp[MAXN][MAXN];


int main(){
    int V,M,N;
    int value[MAXN];
    cin>>V>>M>>N;
    int v[MAXN];
    int m[MAXN];
    for(int i=1;i<=N;i++){
        cin>>v[i]>>m[i]>>value[i];
    }
    for(int i=1;i<=N;i++){
        for(int j=V;j>=v[i];j--){
            for(int k=M;k>=m[i];k--){
                dp[j][k]=max(dp[j][k],dp[j-v[i]][k-m[i]]+value[i]);
            }
        }
    }
    cout<<dp[V][M];
    
    return 0;
}
