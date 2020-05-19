#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
void work(void)
{
    int x,y,z;
    cin>>x>>y>>z;
    if(y==9&&z==30){
        cout<<"YES"<<endl;
        return;
    }
    if(y==11&&z==30){
        cout<<"YES"<<endl;
        return;
    }
    else if(y%2==z%2){
        cout<<"YES"<<endl;
        return;
    }
    else{
        cout<<"NO"<<endl;
        return;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        work();
    }
    return 0;
}
