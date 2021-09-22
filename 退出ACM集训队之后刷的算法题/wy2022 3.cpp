#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int head[N];
ll dis[N];
int vis[N];
struct node
{
	int to,next;
	ll v;
}e[4*N];
int cnt=0;
void add(int x,int y,ll w)
{
	e[cnt].to=y;
	e[cnt].v=w;
	e[cnt].next=head[x];
	head[x]=cnt++;
}
int n;
int pre[N];
void spfa(int s)
{   
     for(int i=0;i<=n+n+10;i++) {vis[i]=0; dis[i]=0x3fffffff;}
     
	queue<int> que;
	que.push(s);
	vis[s]=1;
	dis[s]=0;
	while(!que.empty())
	{
		int now=que.front(); que.pop();
		int is_li=0;
		
		for(int i=head[now];i!=-1;i=e[i].next)
		{    is_li=0;
             if(pre[now]>n&&e[i].to>n) is_li=1;
			if(dis[e[i].to]>(dis[now]+e[i].v+is_li))
			{   
				dis[e[i].to]=dis[now]+e[i].v+is_li;
				pre[e[i].to]=now;
				if(!vis[e[i].to])
				{
					vis[e[i].to]=1;
					que.push(e[i].to);
				}
			}
				
		}
		vis[now]=0;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{   memset(head,-1,sizeof head); cnt=0;
	    memset(pre,-1,sizeof pre);
		int m1,m2;
		scanf("%d %d %d",&n,&m1,&m2);
		for(int i=1;i<=m1;i++)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			add(u,v,1);
			add(v,u,1);
		}
		for(int i=1;i<=n;i++)
		{
			add(i,i+n,0);
		}
		for(int i=1;i<=m2;i++)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			add(u+n,v,0);
			add(v+n,u,0);
		}
		spfa(1);
		printf("%lld\n",dis[n]);
	}
	return 0;	
}


