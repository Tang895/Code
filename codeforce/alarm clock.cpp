//
//  main.cpp
//  4
//
//  Created by IanTang on 2020/5/17.
//  Copyright © 2020 IanTang. All rights reserved.
//

#include <iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
void work(void){
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    long long ans=0;
    if(b>=a){
        cout<<b<<endl;
        return;
    }
    if(d>=c){
        cout<<"-1"<<endl;
        return;
    }
    a=a-b;
    ans+=b;
    long long child=c-d;
    long long fuck;
    fuck=a/child;
    if(a%child!=0){
        fuck++;
    }
    ans+=c*fuck;
    cout<<ans<<endl;
    return;
}
int main(){
    int t;
    cin>>t;
    //int aa=t;
    //long long ans[1001]={0};
    while(t--){
        work();
    }
    return 0;
}
