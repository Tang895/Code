#include<iostream>
using namespace std;
void work(void){
    string a,b;
    cin>>a>>b;
    int a1,b1;
    a1=a[a.length()-1];
    b1=b[b.length()-1];
    a1-='0';
    b1-='0';
    int c=a1%5;
    if(c==0||c==1||c==4){
        cout<<"Matrix67"<<endl;
    }
    else {
        c=b1%5;
        if(c==0||c==1||c==4){
        cout<<"Matrix67"<<endl;
    }
        else{
            cout<<"Shadow"<<endl;
        }
    }
    
   
}
int main(){
    int n=10;
    while(n--){
        work();
    }
    return 0;
}
