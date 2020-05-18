//
//  main.cpp
//  6
//
//  Created by IanTang on 2020/5/17.
//  Copyright © 2020 IanTang. All rights reserved.
//
/*
描述
一个旅行家想驾驶汽车以最少的费用从一个城市到另一个城市(假设出发时油箱是空的)。给定两个城市之间的距离d1、汽车油箱的容量c（以升为单位）、每升汽油能行驶的距离d2、出发点每升汽油价格p和沿途油站数n，油站i离出发点的距离d[i]、每升汽油价格p[i]。

计算结果四舍五入至小数点后两位。

如果无法到达目的地，则输出-1。

格式
输入格式
输入共n+1行，第一行为d1,c,d2,p,n，以下n行，每行两个数据，分别表示该油站距出发点的距离d[i]和该油站每升汽油的价格p[i]。两个数据之间用一个空格隔开。
*/

#include <iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    int n;
    double d1,c,d2;
    double d[1002];
    double p[1002];
    cin>>d1>>c>>d2>>p[0]>>n;
    for(int i=1;i<=n;i++){
        cin>>d[i]>>p[i];
    }
    for(int i=1;i<=n+1;i++){
        if(c*d2<d[i]-d[i-1]){
            cout<<"-1"<<endl;
            return 0;
        }
    }
    int min;
    d[n+1]=d1;
    d[0]=0;
    p[n+1]=-9999;
    double cc=0;
    double money=0;
    int pos=0;
    int pos2=0;
    while(pos!=n+1){
    for(int i=n+1;i>pos;i--){
        if(d[i]<=c*d2+d[pos]){
            min=pos+1;
            for(int j=pos+1;j<=i;j++){
                if(p[j]<=p[pos]){
                    pos2=j;
                    break;
                }
                if(p[j]<p[min]){
                    min=j;
                }
            }
            //full
            if(pos==pos2){
                pos2=min;
                money+=(c-cc)*p[pos];
                cc=c-(d[pos2]-d[pos])/d2;
            }
            else{
                //can reach
                if(cc*d2>=d[pos2]-d[pos]){
                    money+=0;
                    cc=cc-(d[pos2]-d[pos])/d2;
                }
                else{
                money+=((d[pos2]-d[pos])/d2-cc)*p[pos];
                cc=0;
                }
                
            }
            
            pos=pos2;
            break;
        }
    }
    }
    money*=100;
    money=round(money);
    money=money/100;
    printf("%.2lf\n",money);
    //cout<<cc;
    return 0;
}
