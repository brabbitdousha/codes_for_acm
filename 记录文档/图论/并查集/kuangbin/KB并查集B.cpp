#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<bitset>
#include<string>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include<functional>

#define INF 0x3f3f3f3f //1061109567
#define llINF 9223372036854775807
#define pi 3.141592653589793
#define ll long long
using namespace std;
const ll maxn=1e3+7;
const double eps=1e-10;
const ll mod=1e9+7;
int f[30005];
int h[30005];
int find1(int x)
{
	int r=x;
	while(r!=f[r])
	{
		r=f[r];
	}
	int i=x,j;
	while(i!=r)
	{
		j=f[i];
		f[i]=r;
		i=j;
	}
	return r;
}
void merge(int x,int y)
{
	int t1=find1(x);
	int t2=find1(y);
	if(h[t1]==h[t2])
	{
		h[t1]++;
		f[t2]=t1;
	}
	else
    {
    	if(h[t1]>h[t2]) f[t2]=t1;
    	else f[t1]=t2;
    }
}
int main()
{
   int n,m;
   while(~scanf("%d %d",&n,&m)) 
   {    if(m==0&&n==0) break;
       for(int i=0;i<=n;i++) {f[i]=i;h[i]=0;}
	   	while(m--)
	   	{
	   		int k;
	   		scanf("%d",&k);
	   		int x;int last=0;
	   		for(int i=1;i<=k;i++)
	   		{
	   			scanf("%d",&x);
	   			if(i!=1) merge(last,x);
	   			last=x;
	   		}
	   	}
	   		for(int i=0;i<n;i++)
	   		{
	   			int hhh=find1(i);
	   			if(hhh!=f[i]) f[i]=hhh;
	   		}
	   		int now=f[0];int ans=0;
	   		for(int i=0;i<=n;i++) if(f[i]==now) ans++;
	   	printf("%d\n",ans);
	}
	return 0;
}
	   		
	   			
