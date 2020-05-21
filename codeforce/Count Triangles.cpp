#include<iostream>
#include<cmath>
#include<algorithm>
#define MOD 1000000007
using namespace std;
int A,B,C,D;
typedef long long ll;
ll quick(ll a,ll n){
    ll ans=1;
    while(n>0){
        if(n&1){
            ans=ans*a%MOD;
        }
        a=a*a%MOD;
        n=n/2;
    }
    return ans;
}
long long f(long long T,int a,int b,int c){
    long long ans=0;
    int aa=a;
    int cnt=T-aa;
    while(cnt>C){
        aa++;
        cnt=T-aa;
    }
    ans=min(B-aa,cnt-B);
    return ans+1;
}
int work(void){
    int ans=0;
    for(int x=A;x<=B;x++){
        for(int y=B;y<=C;y++){
            for(int z=C;z<=D;z++){
                if(x+y>z){
                    ans++;
                }
            }
        }
    }
    return ans;
}
int main(){
    long long ans=0;
    cin>>A>>B>>C>>D;
    int k=1;
    for(int loop=max(A+B,C+1);loop<=B+C;loop++){
        long long t=f(loop,A,B,C);
        k=min(loop-C,D-C+1);
        ans+=t*k;
        //k++;
    }
    cout<<ans<<endl;
    //cout<<work();
    //cout<<f(5,1,2,3);
    return 0;
}
