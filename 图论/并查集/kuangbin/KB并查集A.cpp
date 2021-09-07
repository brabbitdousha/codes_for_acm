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
//#include<bits/stdc++.h>
#define INF 0x3f3f3f3f //1061109567
#define llINF 9223372036854775807
#define pi 3.141592653589793
#define ll long long
using namespace std;
const ll maxn=1e3+7;
const double eps=1e-10;
const ll mod=1e9+7;
int f[10100]={0};
int n;
void init()
{
	for(int i=1;i<=n;i++) f[i]=i;
}
int find1(int x)
{
	if(f[x]==x) return x;
	f[x]=find1(f[x]);
	return f[x];
}
void merge(int x,int y)
{
	int t1=find1(x);
	int t2=find1(y);
	if(t1!=t2)
	f[t2]=t1;
}
struct node
{
	double x,y;
}e[2000];
vector<int> G[2000];
double dis(int a,int b)
{
	return sqrt((e[a].x-e[b].x)*(e[a].x-e[b].x)+(e[a].y-e[b].y)*(e[a].y-e[b].y));
}
int vis[2000];
int main()
{
	scanf("%d",&n);
	double d;
	scanf("%lf",&d);
	init();
	for(int i=1;i<=n;i++)
	{
		scanf("%lf %lf",&e[i].x,&e[i].y);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(dis(i,j)<=d)
			{
				G[i].push_back(j);
				G[j].push_back(i);
			}
		}
	}
	/*for(int i=1;i<=n;i++)
	{  cout<<i<<": ";
		for(int j=0;j<G[i].size();j++)
		{
			cout<<G[i][j]<<" ";
		}
		cout<<endl;
	}*/
	char c;
	while(cin>>c)
	{   //cout<<c<<endl;
		if(c=='O')
		{
			int p;
			scanf("%d",&p);
			vis[p]=1;
			//cout<<p<<endl;
			for(int j=0;j<G[p].size();j++)
			{   if(vis[G[p][j]])
				{merge(p,G[p][j]);
				//cout<<p<<" "<<G[p][j]<<endl;
			     }
			}
			/*for(int i=1;i<=n;i++)
			if(vis[i]) cout<<i<<" ";
			cout<<endl;*/
		}
		else
		{
			int p,q;
			scanf("%d %d",&p,&q);
			int t1=find1(p);
			int t2=find1(q);
			if(t1!=t2) printf("FAIL\n");
			else printf("SUCCESS\n");
		}
	}
	return 0;
}
	
