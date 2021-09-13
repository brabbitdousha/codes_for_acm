#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
	int x,y;
	int dis;
	int num;
}ee[2505];
map<int,int> is_vis; 
bool cmp(node a,node b)
{
	if(a.dis==b.dis)
	{
		return a.num<b.num;
	}
	else
	{
		return a.dis<b.dis;
	}
}
int nextx[4]={-1,1,0,0};
int nexty[4]={0,0,-1,1};
int dis[3000];
int head[3000];
int vis[3000];
struct nod
{
	int next;
	int to;
	int v;
}e[1000006];

int cnt=0;

void add(int x,int y,int v)
{
	e[cnt].next=head[x];
	e[cnt].to=y;
	e[cnt].v=v;
	head[x]=cnt++;
}
struct hh
{
	int dis[3000];
};
map<int,hh> mp;
void spfa(int s)
{   for(int i=0;i<=2998;i++) {dis[i]=0x3fffffff; vis[i]=0;}
	queue<int> que;
	que.push(s);
	vis[s]=1;
	dis[s]=0;
	while(!que.empty())
	{   
		int now=que.front();
	    que.pop();
	    for(int i=head[now];i!=-1;i=e[i].next)
	    {
	    	int to=e[i].to;
	    	if(dis[to]>dis[now]+e[i].v)
	    	{
	    		dis[to]=dis[now]+e[i].v;
	    		if(!vis[to])
	    		{
	    			vis[to]=1;
	    			que.push(to);
	    		}
	    	}
	    }
	    vis[now]=0;
	}
	for(int i=0;i<=2998;i++) mp[s].dis[i]=dis[i];
}
char A[100][100];	
int numx[2600];
int numy[2600];
int nowposx,nowposy;int n,m;
int thestep;
int topos=-1;
int ct=0; 
void dfs(int x,int y,int len,int step)
{   if(step==1)
{  nowposx=x; nowposy=y;thestep=step;
if((A[x][y]>='0'&&A[x][y]<='9')&&(is_vis[(x-1)*m+y]==0)){ ct++;is_vis[(x-1)*m+y]=1;}
   return;
}
	for(int i=0;i<4;i++)
	{
		int nx=nextx[i]+x;
		int ny=nexty[i]+y;
		if(nx>n||nx<=0||ny>m||ny<=0) continue;
		if(A[nx][ny]=='#') continue;
		if(mp[(nx-1)*m+ny].dis[topos]<len)
		{
		   dfs(nx,ny,mp[(nx-1)*m+ny].dis[topos],step+1);
	    }
	}
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {   is_vis.clear();
    	
    	scanf("%d %d",&n,&m);
    	for(int i=1;i<=n;i++)
    	scanf("%s",A[i]+1);
    	memset(numx,-1,sizeof numx);
    	memset(numy,-1,sizeof numy);
        memset(head,-1,sizeof head);
        cnt=0; int sx=1; int sy=1;
        int totk=0;
        for(int i=1;i<=n;i++)
        {
        	for(int j=1;j<=m;j++)
        	{    if(A[i][j]>='0'&&A[i][j]<='9') totk++;
        		int nowpos=(i-1)*m+j;
        		if(A[i][j]=='*') {sx=i; sy=j;}
        		numx[nowpos]=i;
        		numy[nowpos]=j;
        		for(int kk=0;kk<4;kk++)
        		{
        			int nx=i+nextx[kk];
        			int ny=j+nexty[kk];
        			
        			if(nx>n||nx<=0||ny>m||ny<=0) continue;
        			if(A[nx][ny]=='#') continue;
        			int topos=(nx-1)*m+ny;
        			add(nowpos,topos,1);
        			//cout<<i<<" "<<j<<"   "<<nx
        		}
        	}
        	
        }
        ct=0;
        for(int i=1;i<=n*m;i++) 
        	spfa(i);
        	
        	nowposx=sx; nowposy=sy;
        	int flag=1; int ans=0;
        	int shu=0;
      for(;;)
      { shu++; 
	    int nowdis=-1; topos=-1;
        for(int i=1;i<=n;i++)
        {
        	for(int j=1;j<=m;j++)
        	{
        		if(A[i][j]>='0'&&A[i][j]<='9')
        		{  if(is_vis[(i-1)*m+j]==1) continue;
        			int ctdis=abs(i-nowposx)+abs(j-nowposy);
        			if(nowdis==-1)
        			{
        				nowdis=ctdis;
        				topos=(i-1)*m+j;
        			}
        			else if(nowdis>ctdis)
        			{
        				nowdis=ctdis;
        				topos=(i-1)*m+j;
        			}
        			else if(nowdis==ctdis)
        			{   
        				int onum=A[numx[topos]][numy[topos]]-'0';
        				int nnum=A[i][j]-'0';
        				if(onum>nnum)
        				{
        					topos=(i-1)*m+j;
        				}
        			}
        		}
        	}
        }
        if(shu>=100000){flag=0; break;}
        if(ct==totk) break;
        thestep=0;
        if(mp[(nowposx-1)*m+nowposy].dis[topos]==0x3fffffff) {flag=0;break;}
        dfs(nowposx,nowposy,mp[(nowposx-1)*m+nowposy].dis[topos],thestep);
        
      //  cout<<nowposx<<" "<<nowposy<<endl;
        ans+=thestep;
       }
        if(flag==1) printf("%d\n",ans);
        else printf("-1\n");
        
        
        
    }

}
