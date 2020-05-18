#include<iostream>
#include<algorithm>
using namespace std;
void work(void){
    int m,n;
    cin>>m>>n;
    char color[101][101];
   // char c[101][101];
    char ans='B';
    char ans2='W';
    if(n%2!=0)
    for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(n*m%2==0&&(i==m-1)&&(j==n-1)){
                    color[i][j]='B';
                    break;
                }
                color[i][j]=ans;
                swap(ans,ans2);
            }
        }
    else if(m%2!=0){
        //swap(n,m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(n*m%2==0&&(i==n-1)&&(j==m-1)){
                    color[j][i]='B';
                    break;
                }
                color[j][i]=ans;
                swap(ans,ans2);
            }
        }
    }
    else{
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==m-1&&j==n-2){
                    color[i][j]=color[i][j+1]='B';
                    break;
                }
                color[i][j]=ans2;
                swap(ans,ans2);
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<color[i][j];
        }
        cout<<endl;
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
