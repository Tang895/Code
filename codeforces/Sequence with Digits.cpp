//
//  main.cpp
//  2
//codeforce
//  Created by IanTang on 2020/5/17.
//  Copyright © 2020 IanTang. All rights reserved.
//Sequence with Digits

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int maxDig(string num){
    unsigned long len=num.length();
    int kk=0;
    for(int i=0;i<len;i++){
        if(num[i]!='0'){
            break;
        }
        if(num[i]=='0'){
            kk++;
        }
    }
    int max=num[kk];
    int min=num[kk];
    for(int i=kk;i<len;i++){
        if(num[i]>max){
            max=num[i];
        }
        if(num[i]<min){
            min=num[i];
        }
    }
    max=max-'0';
    min=min-'0';
    return max*min;
}

string add(string num){
    int dig=maxDig(num);
    int dig1=dig/10;//shiwei
    int dig2=dig%10;//gewei
    unsigned long len=num.length();
    string a="0";
    num=a+num;
    num[len]+=dig2;
    if(num[len]>'9'){
        num[len]-=10;
        dig1++;
    }
    num[len-1]+=dig1;
    
   
    for(int i=len-1;i>=0;i--){
        if(num[i]>'9'){
            num[i]-=10;
            num[i-1]+=1;
        }
        else{
            break;
        }
    }
    return num;
}
void printans(string aa){
    unsigned long len=aa.length();
           int kk=0;
           for(int i=0;i<len;i++){
               if(aa[i]!='0'){
                   kk=i;
                   break;
               }
           }
           for(int i=kk;i<len;i++){
               cout<<aa[i];
           }
           cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long  k;
        string aa;
        cin>>aa;
        cin>>k;
        
        for(int i=0;i<k-1;i++){
            if(maxDig(aa)==0){
                break;
            }
            aa=add(aa);
        }
        printans(aa);
       // add(aa);
    }
    return 0;
}
