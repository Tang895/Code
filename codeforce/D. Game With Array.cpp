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
int main(){
    int n,s;
    cin>>n>>s;
    if(s>=2*n){
        cout<<"YES"<<endl;
        for(int i=1;i<n;i++){
            cout<<2<<" ";
        }
        cout<<s-2*(n-1)<<endl;
        cout<<1;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
