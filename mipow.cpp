//
//  main.cpp
//  cppWrite
//
//  Created by IanTang on 2020/1/2.
//  Copyright © 2020 IanTang. All rights reserved.
//

#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
ll mipow(ll n,ll b, ll a){
    ll ans=1;
    while(n>0){
        //if n is jishu;
        if(n&1){
            ans=ans*a%b;
        }
        a=a*a%b;
        n>>=1;//means /2;
    }
    return ans;
}
int main()
{
    long long n,a,b;//a's pow n,then % b;
    cin>>n>>a>>b;
    ll ans;
    ans=mipow(n,a,b);
    cout<<ans;
    return 0;
}
