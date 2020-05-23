#include<iostream>
#include<vector>

using namespace std;
void dfs(char p[],int level,bool pd[1001],vector<char>res){
    //戒指条件
    if(level==strlen(p)){
        for(int i=0;i<strlen(p);i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=0;i<strlen(p);i++){
        if(!pd[i]){
            res.push_back(p[i]);
            pd[i]=1;
            dfs(p,level+1,pd,res);
            res.pop_back();
            pd[i]=0;
        }
    }
    
}
int main(){
    int n;
    cin>>n;
    char p[1001];
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    bool pd[1001]={0};
    vector<char> res;
    dfs(p,0,pd,res);
    return 0;
}
