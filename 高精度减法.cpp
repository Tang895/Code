#include<iostream>
#include<cstring>
using namespace std;
int c[100];
int a[100],b[100];
void init(int a[]);
void but(int a[],int b[]);
int main()
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	init(a);
	init(b);
	but(a,b);

	cin>>a[0];//pause
	return 0;
}
void init(int a[])
{
	string s;
	cin>>s;
	a[0]=s.length();
	for(int i=1;i<=a[0];i++){
		a[i]=s[a[0]-i]-'0';
	}
}

void but(int a[],int b[])
{
	int i=1;
	int x=0;
	while(i<=a[0]||i<=b[0]){
		if(b[i]>a[i]){
			a[i]+=10;
			a[i+1]--;
		}
		c[i]=a[i]-b[i];
		if(c[i]==0){
			x=i-1;
		}
		else
			x=i;
		i++;
	}
	for(i=x;i>0;i--){
		cout<<c[i];
	}
}