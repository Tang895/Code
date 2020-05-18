/*
 计算最小外接正方形
 odd情况
 C2. Not So Simple Polygon Embedding
 */

#include<cmath>
#include<iostream>
#include<cstdio>
#define PI 3.1415926
using namespace std;
double cul1(double angle,double len){
    angle/=2;
    len/=2;
    double ans;
    ans=len/sin(angle);
    return ans;
}
double cul2(double angle,double len){
    double ans;
    angle/=2;
    ans=len*sin(angle);
    ans*=2;
    return ans;
}

void work(void){
    int n;
    cin>>n;
    double ans;
    double angle;
    int a,b;
    a=n/2;
    b=a+1;
    double len1,len2;
    angle=PI/n;
    double angle1=a*angle;
    double angle2=b*angle;
    double len;
    len=cul1(angle,1);
    len1=cul2(angle1,len);
    len2=cul2(angle2,len);
    double ans1;
    double ans2;
    ans1=0.5*len1*len1;
    ans2=0.5*len2*len2;
    ans=sqrt(ans1)+sqrt(ans2);
    printf("%.9lf\n",ans);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        work();
    }
    return 0;
}
