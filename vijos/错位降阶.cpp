#include<iostream>
using namespace std;
int a[100001];
int b[100001];
int ans=0;
int f(int n){
    ans+=a[n];
    for(int i=n;i>1;i--){
        b[i-1]=a[i]-a[i-1];
    }
    for(int i=n-1;i>=1;i--){
        a[i]=b[i];
    }
    if(n==1){
        return b[1];
    }
    return f(n-1);
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    f(n);
    cout<<ans<<endl;
    return 0;
}
