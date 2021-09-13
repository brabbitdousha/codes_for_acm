01背包
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
 int f[1001][1001]={0}; int t[1001],v[1001];
 int n,m;
 scanf("%d%d",&n,&m);

 for(int i=1;i<=m;i++)
 {
   cin>>t[i];
   cin>>v[i];
 }
 for(int i=1;i<=m;i++)
 {
 	for(int j=n;j>=1;j--)
 	{
 		if(t[i]>j){f[i][j]=f[i-1][j];}
 		else
 		{
 			f[i][j]=max(f[i-1][j],f[i-1][j-t[i]]+v[i]) ;
 		}
 	}
 }
 	cout<<f[m][n];
 	return 0;
}kmp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
char a[1000010];
char b[1002];
int nextt[1002];
void KMP(char *x,int *nextt)
{
	nextt[0]=-1; nextt[1]=0;
	int len=strlen(x);
	int i=1,j=0;
	while(i<len&&j<len)
	{
		if(j==-1||x[i]==x[j]) nextt[++i]=++j;
		else j=nextt[j];
	}
}
int main()
{
	cin>>a>>b;
	KMP(b,nextt);
	int j=0;int i=0;
	int len1=strlen(a);
	int len2=strlen(b);
	while(i<len1&&j<len2)
	{
		if(j==-1||a[i]==b[j]) {i++;j++;}
		else
		j=nextt[j];
		if(j==len2) {cout<<i-j+1<<endl; j=nextt[j];}
	}
/*  len2为循环节长度,
           for(int i=1;i<=len;i++)
        {
        	int len2=i-nextt[i];
        	if(i!=len2&&i%len2==0)
            printf("%d %d\n",i,i/len2);
        }
*/
	for(int j=1;j<=len2;j++)
	cout<<nextt[j]<<" ";
	return 0;
}
	
    ;
	   
}多维dp
#include<iostream>
#include<cstdio>
using namespace std;
int f[55][55][55][55]={0},p[55][55];
int main()
{
	int n,m;int sum=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&p[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	for(int k=1;k<=n;k++)
	for(int l=1;l<=m;l++)
	{
		sum=max(max(f[i-1][j][k-1][l],f[i][j-1][k][l-1]),max(f[i-1][j][k][l-1],f[i][j-1][k-1][l]));
		if(i==k&&j==l)
		{
			f[i][j][k][l]+=sum+p[i][j];
		}
		else{
			f[i][j][k][l]+=sum+p[i][j]+p[k][l];
		}
	}
	cout<<f[n][m][n][m];
	return 0;
}完全背包
#include<iostream>
using namespace std;
int t,n;long long T[10005],V[10005],f[100005]={0};
int main()
{
cin>>t>>n;
for(int i=1;i<=n;i++)
cin>>T[i]>>V[i];
for(int i=1;i<=n;i++)
for(int j=T[i];j<=t;j++)
{
    f[j]=max(f[j],f[j-T[i]]+V[i]);
}
cout<<f[t];
return 0;
}