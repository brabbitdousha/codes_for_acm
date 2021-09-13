最短路计数
#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;
int n,m,d[200001],dis[200001];
vector <int> map[200001];
int bo[200001];
int count [200001];
int main()
{
	memset(dis,127,sizeof(dis));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		map[x].push_back(y);
		map[y].push_back(x);
	}
	int h=1;int t=1;
	d[1]=1;
	bo[1]=1;
	dis[1]=0;
	count[1]=1;
	while(h<=t)
	{
		int now=d[h];
		for(int i=0;i<map[now].size();i++)
		{
			int nn=map[now][i];
			if(dis[now]+1<dis[nn])
			{
				dis[nn]=dis[now]+1;
				count[nn]=count[now]%100003;
				if(!bo[nn])
				{
					bo[nn]=1;
					d[++t]=nn;
				}
			}
			else
			if(dis[now]+1==dis[nn])
			count[nn]=(count[nn]+count[now])%100003;
		}
	h++;bo[now]=0;
}
for(int i=1;i<=n;i++)
if(count[i]!=count[0])
{
	printf("%d\n",count[i]);
}
else
{
	printf("%d\n",0);
}
return 0;
}最小生成树 k
#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0;int f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-'){f=-1;}ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct hh
{
	int a,b,c;
}e[200100];
int n,m;
int f[200000];
long long int sum=0;
int cmp(hh x,hh y)
{
	return x.c<y.c;
}
int find1(int x)
{
	if(f[x]==x) return x;
	f[x]=find1(f[x]);return f[x];
}
int merge(int x,int y)
{
	int t1=find1(x);
	int t2=find1(y);
	if(t1!=t2)
	{
		f[t1]=t2;return 1;
	}
	return 0;
}
int main()
{
	n=read();
	m=read();
	for(int i=0;i<=n;i++)
	f[i]=i;
	for(int i=1;i<=m;i++)
	{
		e[i].a=read();
		e[i].b=read();
		e[i].c=read(); 
    }int ct=0;
    sort(e+1,e+1+m,cmp);
    for(int i=1;i<=m;i++)
    {
    	if(find1(e[i].a)!=find1(e[i].b))
    	{
    		if(merge(e[i].a,e[i].b))
    		{
    			sum+=e[i].c;
    			ct++;
    		}
    	}
    	if(ct==n-1) break;
    }
    int x=find1(1);
    for(int i=2;i<=n;i++)
    {
    	if(x!=find1(i)) {cout<<"orz"; return 0;}
    }
    cout<<sum;
    return 0;
}最小生成树prim
#include<bits/stdc++.h>
using namespace std;
const int MAXN=5000+10;
inline int read()
{
	    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}
struct node{ int x,y;}point[MAXN];
double ans,dis[MAXN];
bool vis[MAXN];
int n;
double calc(int a,int b)
{
	return sqrt((double)(point[a].x-point[b].x)*(point[a].x-point[b].x)+(double)(point[a].y-point[b].y)*(point[a].y-point[b].y));
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		point[i].x=read();
		point[i].y=read();
		dis[i]=1e8;
	}
	int pos;dis[1]=0;
	for(int i=1;i<=n;i++)
	{
		double minn=1e8;
		for(int j=1;j<=n;++j)
		if(!vis[j]&&dis[j]<minn)
		{ minn=dis[j];pos=j;
	    }
	    ans+=minn; vis[pos]=true;
	    for(int j=1;j<=n;++j)
	    {
	    	double d=calc(pos,j);
	    	if(dis[j]>d)
	    	dis[j]=d;
	    }
	}
	printf("%.2f\n",ans);
	return 0;
}noip2015 tarjan
2015信息传递 tarjan
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,ans=1000000;
int sta[200001],top=0;
int dfn[200001],low[200001],tot=0;
int head[200001],nxt[200001],to[200001],cnt=0;
int f[200001];
void addedge(int x,int y)//邻接链表存图
{
    cnt++;
    nxt[cnt]=head[x];
    head[x]=cnt;
    to[cnt]=y;
}
void tarjan(int u)//tarjan求强联通分量
{
    f[u]=1;
    dfn[u]=low[u]=++tot;
    sta[++top]=u;//入栈
    for(int i=head[u];i!=0;i=nxt[i])
    {
        int v=to[i];
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(f[v]) low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u])
    {
        int res=0;
        do
        {
            f[sta[top]]=0;
            res++;
        }while(sta[top--]!=u);//出站并统计个数
        if(res!=1) ans=min(ans,res);//注意，一个点不算一个环，排除掉就能过啦
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        addedge(i,a);//加边，是有向边，别加两次
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i]) tarjan(i);
    cout<<ans;
    return 0;
}clj的反向拓扑
#include<bits/stdc++.h>
using namespace std;
int T,n,m;
void topsoft();
int en=0;
int head[30007];
int ans[30007];
int in[30007];
struct node
{
	int to,next;
}e[100007];
void add(int x,int y)
{
	en++;
	e[en].to=y;
	e[en].next=head[x];
	head[x]=en;
}
int main()
{   
	scanf("%d",&T);
	while(T--)
	{
		en=0;
		memset(head,0,sizeof head);
		memset(ans,0,sizeof ans);
		memset(in,0,sizeof in);
		scanf("%d %d",&n,&m);
		int a,b;
		while(m--)
		{
			scanf("%d %d",&a,&b);
			add(b,a);
			in[a]++;
		}
		topsoft();
		printf("\n");
	}
	return 0;
}
void topsoft()
{   int ct=0;
	priority_queue<int> que;
	for(int i=1;i<=n;i++)
	if(!in[i]) que.push(i);
	while(!que.empty())
	{
		int now=que.top();
		ans[++ct]=now;
		que.pop();
		int i=head[now];
		while(i)
		{
			in[e[i].to]--;
			if(in[e[i].to]==0)
			que.push(e[i].to);
			i=e[i].next;
		}
	}
	for(int i=n;i>=1;i--)
	if(i!=1){printf("%d ",ans[i]);}
	else {printf("%d",ans[i]);}
}dfs模板题lake counting
Sample Input
10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.
Sample Output
3
Hint
OUTPUT DETAILS: 

There are three ponds: one in the upper left, one in the lower left,and one along the right side.


从任意W开始，不停把邻接的部分用’.’代替，DFS次数就是ans


#include<iostream>
#include<cstdio>
using namespace std;
int next[2][8]={{-1,-1,0,1,1,1,0,-1},{0,1,1,1,0,-1,-1,-1}};
int n,m;
char mp[101][101];
void dfs(int x,int y)
{
	mp[x][y]='.';
	for(int i=0;i<8;i++)
	{
		int nx=x+next[0][i];
		int ny=y+next[1][i];
		if(nx>n||nx<1||ny>m||ny<1) continue;
		else if(mp[nx][ny]=='W')dfs(nx,ny);
	}
}
int main()
{   
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%s",mp[i]+1);
	long long int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]=='W')
			{
				dfs(i,j);
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}dijkstra的路径还原
0
dousha written 4周 ago

用prev[j]来记录最短路上顶点j的前趋

更新最短路的时候修改

int prev[MAX_V];
void dijkstra(int s)
{
fiil(d,d+v,INF);
fill(used,used+V,false);
fill(prev,prev+V,-1);
d[s]=0;
while(true)
{
int v=-1;
for(int u=0;u<V;u++)
{
  if(!used[u]&&(v==-1||d[u]<d[v])) v=u;
}
if(v==-1) break;
used[v]=true;
for(int u=0;u<V;u++)
{
	if(d[u]>d[V]+cost[v][u])
	{
		if(d[u]>d[v]+cost[v][u])
		{
			d[u]=d[v]+cost[v][u];
			prev[u]=v;
		}
	}
}
}
vector<int> get_path(int t)
{
	vector<int> path;
	for(;t!=-1;t=prev[t]) path.push_back(t);
	reverse(path.begin(),path.end());
	return path;
}

dijkstra模板堆优化
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;
const int MaxN=100010,MaxM=500010;
struct edge
{
	int to,v,next;
};
edge e[MaxM];
int head[MaxN];
int cnt;
ll dis[MaxN];
bool vis[MaxN];
int n,m,s;
inline void add(int x,int y,int z)
{
	e[cnt].v=z;
	e[cnt].to=y;
	e[cnt].next=head[x];
	head[x]=cnt++;
}
struct node
{
	ll dis;
	int pos;
	bool operator <(const node &x)const
	{
		return x.dis<dis;
	}
};
inline void dij()
{   for(int i=0;i<=n+2;i++) {dis[i]=0x3fffffff;vis[i]=0;}
	priority_queue<node> que;
	dis[s]=0;
	que.push((node){0,s});
	while(!que.empty())
	{
		node tmp=que.top();
		que.pop();
		int x=tmp.pos;
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i!=-1;i=e[i].next)
		{
			int to=e[i].to;
			if(dis[to]>dis[x]+e[i].v)
			{
				dis[to]=dis[x]+e[i].v;
				if(!vis[to])
				{
					que.push((node){dis[to],to});
				}
			}
		}
	}
}
int main()
{
	int t;  int kk=0;
	scanf("%d",&t);
	while(t--)
	{   kk++;
		scanf("%d %d",&n,&m);
		cnt=0;
		for(int i=0;i<=n+2;i++) {head[i]=-1;}
	    for(int i=1;i<=m;i++)
	    {
	    	int u,v;
	    	ll w;
	    	scanf("%d %d %lld",&u,&v,&w);
	    	add(u,v,w);
	    	add(v,u,w);
	    }
	    s=1;
	    dij();
	    printf("Case %d: ",kk);
	    if(dis[n]==0x3fffffff) printf("Impossible\n");
	    else printf("%lld\n",dis[n]);
	}
	return 0;
}floyd
#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0;int f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-'){f=-1;}ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m;int k;
int d[300][300];
int t[300];
int main()
{
	n=read();
	m=read();
	for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++)
	 d[i][j]=1e9;

	for(int i=0;i<n;i++)
	t[i]=read();int a,b,c;
	for(int i=1;i<=m;i++)
	{
		a=read();b=read();c=read();
		d[a][b]=c;
		d[b][a]=c;
	}
	int p;
	p=read();int ti;
	for(int i=1;i<=p;i++)
	{    
		a=read();b=read(); ti=read();
		if(t[a]>ti||t[b]>ti) {printf("-1\n");continue;}
		for(;t[k]<=ti&&k<n;k++)
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{  
			if(d[i][j]>d[i][k]+d[k][j])
			{
				d[i][j]=d[i][k]+d[k][j];
			}
		}
		if(d[a][b]==1e9) printf("-1\n");
		else printf("%d\n",d[a][b]);
	}
	return 0;
}
floyd判断是否联通
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
int flag,n,t;int s;
int mmp[100][100];
struct node
{
	string str,son;
}e[111];
map<string,int> num;
void floyd()
{
	for(int k=1;k<=s;k++)
	for(int i=1;i<=s;i++)
	for(int j=1;j<=s;j++)
	if(mmp[i][k]&&mmp[k][j])
	mmp[i][j]=1;
}
int main()
{
	while(cin>>n)
	{
		memset(mmp,0,sizeof mmp);
		s=flag=0;
		num.clear();
		for(int i=1;i<=n;i++)
		{
			getchar();
			cin>>e[i].str>>e[i].son;
			if(num[e[i].str]==0) num[e[i].str]=++s;
			if(num[e[i].son]==0) num[e[i].son]=++s;
		}
		for(int i=1;i<=n;i++)
		{
			floyd();
			if(mmp[num[e[i].son]][num[e[i].str]]==1)
			{
				
				cout<<e[i].str<<" "<<e[i].son<<"\n";
				flag=1;
				break;
			}
			mmp[num[e[i].str]][num[e[i].son]]=1;
		}
		if(flag==0) printf("0\n");
	}
	return 0;
}hopcroftCarp#include<iostream>#include<cstdio>#include<cstring>#include<algorithm>#include<map>#include<vector>#include<set>#include<queue>#define ll long long#define INF 0x3fffffff using namespace std;const int MAXN=40005;const int N=500000;int n;vector<int> G[MAXN];int Mx[MAXN],My[MAXN];int dx[MAXN],dy[MAXN];int dis;bool used[MAXN];void init(){	for(int i=0;i<=n;i++)	{		G[i].clear();			}}bool searchp(){	queue<int> q;	dis=INF;	memset(dx,-1,sizeof dx);	memset(dy,-1,sizeof dy);	for(int i=0;i<n;i++)	{		if(Mx[i]==-1)		{			q.push(i);			dx[i]=0;		}	}	while(!q.empty())	{		int u=q.front();		q.pop();		if(dx[u]>dis)		break;		int l=G[u].size();		for(int i=0;i<l;i++)		{			int to=G[u][i];			if(dy[to]==-1)			{				dy[to]=dx[u]+1;				if(My[to]==-1)				 dis=dy[to];				 else				 {				 	dx[My[to]]=dy[to]+1;				 	q.push(My[to]);				 }			}		}	}	return dis!=INF;}bool dfs(int u){	int len=G[u].size();	for(int i=0;i<len;i++)	{		int to=G[u][i];		if(!used[to]&&dy[to]==dx[u]+1)		{			used[to]=true;			if(My[to]!=-1&&dy[to]==dis)			continue;			if(My[to]==-1||dfs(My[to]))			{				My[to]=u;				Mx[u]=to;				return true;			}		}	}	return false;}int getMax(){	int ans=0;	memset(Mx,-1,sizeof Mx);	memset(My,-1,sizeof My);	while(searchp())	{		memset(used,false,sizeof used);		for(int i=0;i<n;i++)		{			if(Mx[i]==-1&&dfs(i))			  ans++;		}	}	return ans;}int main(){		int T; int kk=0;	scanf("%d",&T);	while(T--)	{  	    init();	    int ans=getMax();	}	return 0;}                                                                                                                    LCA tarjan
#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct edge
{
	int to,next;
}e[1000001];
struct questions
{
	int to,next,same,num;
	bool flag;
	questions(){flag=false;}
}q[1000001];
bool b[500001];
int head[500001],que[500001],father[500001];
int n,m,s,nume=0,numq=0,ans[500001];
void add_que(int x,int y,int k)
{
	q[++numq].to=y;
	q[numq].same=numq+1;
	q[numq].next=que[x];
	q[numq].num=k;
	que[x]=numq;
	q[++numq].to=x;
	q[numq].same=numq-1;
	q[numq].next=que[y];
	q[numq].num=k;
	que[y]=numq;
}
void add_edge(int x,int y)
{
    e[++nume].to=y;
    e[nume].next=head[x];
    head[x]=nume;
    e[++nume].to=x;
    e[nume].next=head[y];
    head[y]=nume;
}
int find(int x)
{
	if(father[x]!=x)
	father[x]=find(father[x]);
	return father[x];
}
void merge(int x,int y)
{
	father[find(y)]=find(x);
}
void LCA(int point,int f)
{
	for(int i=head[point];i;i=e[i].next)
	if(e[i].to!=f&&!b[e[i].to])
	{
		LCA(e[i].to,point);
		merge(point,e[i].to);
		b[e[i].to]=1;
	}
	for(int i=que[point];i;i=q[i].next)
	if(!q[i].flag&&b[q[i].to])
	{
		ans[q[i].num]=find(q[i].to);
		q[i].flag=1;
		q[q[i].same].flag=1;
	}
}
int main()
{
	n=read();m=read();s=read();
	for(int i=1,x,y;i<=n-1;i++)
	{
		father[i]=i;
		x=read();y=read();
		add_edge(x,y);
	}
	father[n]=n;
	for(int i=1,x,y;i<=m;i++)
	{
		x=read();y=read();
		add_que(x,y,i);
	}
	LCA(s,0);
	for(int i=1;i<=m;i++)
	printf("%d\n",ans[i]);
	return 0;
}LCA tree
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
struct node{int y,next;}e[201000];
int n,m,len,z,a[201000],dep[201000],f[201000],top[201000],son[201000],size[201000];
inline int read()
{
    int x=0,f=1;  char ch=getchar();
    while(!isdigit(ch))  {if(ch=='-')  f=-1;  ch=getchar();}
    while(isdigit(ch))  {x=x*10+ch-'0';  ch=getchar();}
    return x*f;
}
void insert(int xx,int yy)
{
    e[++len].next=a[xx];
    a[xx]=len;
    e[len].y=yy;
}
void dfs1(int x)
{
    dep[x]=dep[f[x]]+1;  size[x]=1;
    for(int i=a[x];i;i=e[i].next)
    {
        if(e[i].y!=f[x]&&!f[e[i].y])
        {
            f[e[i].y]=x;
            dfs1(e[i].y);
            size[x]+=size[e[i].y];
            if(size[son[x]]<size[e[i].y])  son[x]=e[i].y;
        }
    }
}
void dfs2(int x)
{
    if(x==son[f[x]])  top[x]=top[f[x]];
    else top[x]=x;
    for(int i=a[x];i;i=e[i].next)  
        if(f[e[i].y]==x)  dfs2(e[i].y);
}
int ask(int xx,int yy)
{
    while(top[xx]!=top[yy])
    {
        if(dep[top[xx]]>dep[top[yy]])  xx=f[top[xx]];
        else yy=f[top[yy]];
    }
    if(dep[xx]<dep[yy])  return xx;
    else return yy;
}
int main()
{
    n=read();  m=read();
    for(int i=1;i<n;i++)
    {
        int xx=read(),yy=read();
        insert(xx,yy);
        insert(yy,xx);
    }
    dfs1(1);
    dfs2(1);
    for(int i=1;i<=m;i++)
    {
        int xx=read(),yy=read();
        printf("%d\n",ask(xx,yy));
    }
    return 0;
}spfa

#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0;int f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-'){f=-1;}ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct node
{
	int v,next,to;
}e[500010];
int head[11000];int vis[11000],dis[11000];
int en=0;int T,C,TS,TE;
void add(int x,int y,int z)
{
	en++;
	e[en].to=y;
	e[en].v=z;
	e[en].next =head[x];
	head[x]=en;
}
int main()
{
	T=read();
	C=read();
	TS=read();
	TE=read();
	memset(vis,0,sizeof vis);memset(dis,127,sizeof dis);
	int a,b,c;
	for(int i=1;i<=C;i++)
	{ 
	   a=read();b=read();c=read();
	   add(a,b,c); add(b,a,c);
    }
    int start=TS;
    queue<int> que;
    que.push(start);
    vis[start]=1; dis[start]=0;
    while(!que.empty())
    {
    	int now=que.front();
    	que.pop();
    	int i=head[now];
    	vis[now]=0;
    	while(i)
    	{
    		if(dis[e[i].to]>dis[now]+e[i].v)
    		{
    			dis[e[i].to]=dis[now]+e[i].v;
    			if(!vis[e[i].to])
    			{
    				vis[e[i].to]=1;
    				que.push(e[i].to);
    			}
    		}
    		i=e[i].next;
    	}
    }
    printf("%d",dis[TE]);
    return 0;
}
   spfa找负环 一个点更新大于n次
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring> 
using namespace std;
int head[20007];
int vis[20007],dis[20007];
int cnt[20007];int n,m;
int en=0;
struct node
{
	int to,next,v;
}e[60007];
void add(int x,int y,int z)
{
	e[en].to=y;
	e[en].v=z;
	e[en].next=head[x];
	head[x]=en++;
}
int spfa()
{
		queue<int> que;
		int start=1;
		que.push(start);
		vis[start]=1;
		dis[start]=0;
		while(!que.empty())
		{
			int now=que.front();
			que.pop();
			vis[now]=0;
			int i=head[now];
			while(i!=-1)
			{
				if(dis[e[i].to]>dis[now]+e[i].v)
				{
					dis[e[i].to]=dis[now]+e[i].v;
					cnt[e[i].to]++;
					if(cnt[e[i].to]>n) return 1;
					if(!vis[e[i].to])
					{  vis[e[i].to]=1;
						que.push(e[i].to);
					}
				}
				i=e[i].next;
			}
		}
		return 0;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{   memset(head,-1,sizeof head);
	    memset(dis,127,sizeof dis);
	    memset(cnt,0,sizeof cnt);
	    memset(vis,0,sizeof vis);
	
		scanf("%d %d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			add(a,b,c);
			if(c>=0)
			{
				add(b,a,c);
			}
		}
		if(spfa()) printf("YE5\n");
		else printf("N0\n");
	}
	return 0;
}tarjan模板
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5;
const int M=1e5+5;
int n,m;
vector<int> G[N];
int dfn[N],low[N],tot;
int ans;
bool vis[N];
stack<int> sta;
void tarjan(int x)
{
	dfn[x]=low[x]=++tot;
	sta.push(x);
	vis[x]=1;
	for(int i=0;i<G[x].size();i++)
	{
		int to=G[x][i];
		if(!dfn[to])
		{
			tarjan(to);
			low[x]=min(low[x],low[to]);
		}
		else if(vis[to])
		{
			low[x]=min(low[x],dfn[to]);
		}
	}
	if(low[x]==dfn[x])
	{
		ans++;
		while(1)
		{
			int now=sta.top();
			sta.pop();
			vis[now]=0;
			if(now==x) break;
		}
	}
}
void init()
{
	tot=0;
	ans=0;
	memset(vis,0,sizeof vis);
	memset(dfn,0,sizeof dfn);
	memset(low,0,sizeof low);
	while(!sta.empty())
	{
		sta.pop();
	}
	for(int i=0;i<=n;i++) G[i].clear();
}
int main()
{
	while(scanf("%d %d",&n,&m))
	{
		if(n==0&&m==0) break;
		init();
		int u,v;
		for(int i=1;i<=m;i++)
		{
			scanf("%d %d",&u,&v);
			G[u].push_back(v);
		}
		for(int i=1;i<=n;i++)
		{
			if(!dfn[i])
			tarjan(i);
		}
		if(ans==1) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}拓扑排序
#include<bits/stdc++.h>
using namespace std;
#define N 1001
struct edge
{
	int v,next,to;
}mem[N*N];
int n,m,size,MAX;
int a[N],head[N],in[N],q[N],ans[N];
bool map1[N][N],v[N];
void add(int from,int to)
{
	size++;
	mem[size].to=to;
	mem[size].next=head[from];
	head[from]=size;
}
void topsort()
{
	int tot=0;
	int tmp=1;
	for(int i=1;i<=n;i++)
	{
		if(in[i]==0)
		{
			tot++;
			q[tot]=i;
		}
	}
	while(tot<n)
	{
		int ka=0;
		for(int i=tmp;i<=tot;i++)
		{
			int now=q[i];
			for(int e=head[now];e;e=mem[e].next)
			{
				in[mem[e].to]--;
				if(in[mem[e].to]==0)
				{
					ka++;
					q[tot+ka]=mem[e].to;
					ans[mem[e].to]=ans[now]+1;
				}
			}
		}
		tmp=tot+1; tot+=ka;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int si;
		memset(v,0,sizeof(v));
		scanf("%d",&si);
		for(int j=1;j<=si;j++)
		{
			scanf("%d",&a[j]);
			v[a[j]]=1;
		}
		for(int j=a[1];j<=a[si];j++)
		{
			if(v[j]) continue;
			for(int k=1;k<=si;k++)
			{
				if(map1[a[k]][j]==0) add(a[k],j),map1[a[k]][j]=1,in[j]++;
			}
		}
		
	}
		topsort();
		for(int i=1;i<=n;i++)
		MAX=max(MAX,ans[i]);
		printf("%d",MAX+1);
	
}我们把路口看作顶点，把道路看作边的无向图。到某个顶点v的次短路要么是到其他某个顶点u的最短路再加上u到v的边，
要么是到u的次短路再加上u到v的边，因此所需要求的就是到所有顶点的最短路和次短路。
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int maxn=100010,maxm=500010;
const int inf=0x3fffffff;
int dis[maxn],dis2[maxn];
int n,m;
struct node
{
	int pos;
	int d;
	bool operator < (const node &t) const
	{
		return t.d<d;
	}
};
struct edge
{
	int to,cost;
};
vector<edge> e[maxm];
inline void add(int x,int y,int z)
{
	e[x].push_back((edge) {y,z});
}
inline void dijkstra(int s)
{
	for(int i=0;i<=n;i++) dis[i]=dis2[i]=inf;
	dis[s]=0;dis2[s]=inf;
	priority_queue<node> que;
	que.push((node) {s,0});
	while(!que.empty())
	{
		node tmp=que.top();
		que.pop();
		int x=tmp.pos;int di=tmp.d;
		if(di>dis2[x]) continue;
		for(int i=0;i<e[x].size();i++)
		{
			int to=e[x][i].to;int cost=e[x][i].cost;
			int w=cost+di;
			if(w<dis[to])
			{
				swap(w,dis[to]);
				que.push((node){to,dis[to]});
			}
			if(w<dis2[to]&&w>dis[to])
			{
				dis2[to]=w;
				que.push((node){to,dis2[to]});
			}
		}
	}
}
int main()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		int u,v,w;
		for(int i=1;i<=m;i++)
		{
			scanf("%d %d %d",&u,&v,&w);
			add(u,v,w);
			add(v,u,w);
		}
		dijkstra(1);
		printf("%d\n",dis2[n]);
	}
	return 0;
}二分图匹配
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAX=100;
const int MAXL=10000;
struct line
{
	int v,next;
}e[MAXL];
int h[MAX],cnt=0,tot;
int home[MAX];int T,n; 
int school[MAX],a,sum;
inline void Add(int u,int v)
{
	e[cnt]=(line){v,h[u]};
	h[u]=cnt++;
}
int match[MAX];
bool vis[MAX];
bool DFS(int x)
{
	for(int i=h[x];i!=-1;i=e[i].next)
	{
		int v=e[i].v;
		if(!vis[v])
		{
			vis[v]=true;
			if(!match[v]||DFS(match[v]))
			{
				match[v]=x;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	cin>>T;
	while(T--)
	{
		cnt=tot=0;
		memset(h,-1,sizeof(h));
		cin>>n;
		for(int i=1;i<=n;i++)
		cin>>school[i];
		for(int i=1;i<=n;i++)
		{
			cin>>home[i];
			if(home[i]==0&&school[i])
			Add(i,i);
		}
		for(int i=1;i<=n;i++)
		if(!school[i]||(school[i]&&!home[i]))
		++tot;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>a;
				if(a&&school[j])
				  Add(i,j);
			}
		}
		memset(match,0,sizeof match);
		sum=0;
		for(int i=1;i<=n;i++)
		{
			if((school[i]&&home[i]==0)||!school[i])
			{
				memset(vis,0,sizeof vis);
				if(DFS(i)) ++sum;
			}
		}
		if(sum==tot) cout<<"^_^"<<endl;
             else
                cout<<"T_T"<<endl;
       }
       return 0;
}二分图染色hdu5285
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100005;
struct node
{
int to,next;
}e[maxn<<1];
int n,m,cnt,zero,one,head[maxn];
int color[maxn];
bool flag;
void add(int x,int y)
{
	e[cnt].to=y;
	e[cnt].next=head[x];
	head[x]=cnt++;
}
void dfs(int u)
{
	for(int i=head[u];i!=-1;i=e[i].next)
	{
		int to=e[i].to;
		if(color[u]==color[to]) flag=false;
		if(color[to]!=-1) continue;
		color[to]=color[u]^1;
		if(color[to]==0) zero++;
		else one++;
		dfs(to);
	}
}
int main()
{ freopen("a.txt","r",stdin);
    freopen("b.txt","w",stdout);
	int t,u,v;
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		memset(head,-1,sizeof head);
		memset(color,-1,sizeof color);
		flag=true;
		scanf("%d%d",&n,&m);
		if(n<=1)
		{
			printf("Poor wyh\n");
			continue;
		}
		if(m==0)
		{
			printf("%d 1\n",n-1);
			continue;
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		int a=0,b=0;
		for(int i=1;i<=n;i++)
		{
			if(color[i]==-1&&head[i]!=-1)
			{
				color[i]=0;
				zero=1,one=0;
				dfs(i);
				a+=max(zero,one);
				b+=min(zero,one);
			}
			else if(color[i]==-1&&head[i]==-1)
			a++;
		}
		if(flag==false)
		{
			printf("Poor wyh\n");
			continue;
		}
		printf("%d %d\n",a,b);
	}
	return 0;
}拓扑 关键路径
#include<bits/stdc++.h>
using namespace std;
int T,n,m;
void topsoft();
int en=0;
int head[30007];
int ans[30007];
int in[30007];
int dis[30007];
int d[30007];
int G[30007];
stack<int> sta;
int anss=0;
struct node
{
	int to,next;
	int v;
}e[100007];
void add(int x,int y,int z)
{
	en++;
	e[en].to=y;
	e[en].v=z;
	e[en].next=head[x];
	head[x]=en;
}
void important_path()
{   //cout<<"hh"<<endl;
	for(int i=0;i<=n;i++) d[i]=anss;
	while(!sta.empty())
	{
		int u=sta.top(); sta.pop();
		for(int i=head[u];i!=-1;i=e[i].next)
		{
			int v=e[i].to;
			int c=e[i].v;
			if(d[u]>d[v]-c) d[u]=d[v]-c;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int ei=head[i];ei!=-1;ei=e[ei].next)
		{
			int v=e[ei].to;
			if(dis[i]==d[v]-e[ei].v)
			  printf("%d->%d\n",i,v);
		}
	}
}
int main()
{   
	
		en=0;
		memset(head,-1,sizeof head);
		memset(ans,0,sizeof ans);
		memset(in,0,sizeof in);
		scanf("%d %d",&n,&m);
		int a,b;
		for(int i=1;i<=m;i++)
		{  int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		 in[v]++;
		 add(u,v,w);
		   
		}
		topsoft();int flag=1;
		for(int i=1;i<=n;i++)
		{
			if(in[i]) flag=0;
		}
		if(flag) {printf("%d\n",anss);important_path(); }else printf("0");
	
	return 0;
}
void topsoft()
{   int ct=0;
	priority_queue<int> que;
	for(int i=1;i<=n;i++)
	if(!in[i]) que.push(i);
	while(!que.empty())
	{
		int now=que.top();
		sta.push(now);
		//printf("%d->",now);
		ans[++ct]=now;
		que.pop();
		int i=head[now];
		while(i!=-1)
		{   dis[e[i].to]=max(dis[e[i].to],dis[now]+e[i].v);
			in[e[i].to]--;
			if(in[e[i].to]==0)
			{que.push(e[i].to);
			  //printf("%d\n",e[i].to);
		    }
			i=e[i].next;
		}
	}
	//for(int i=1;i<=ct;i++) cout<<ans[i]<<" ";
	//cout<<endl;
	
	for(int i=1;i<=n;i++) {anss=max(anss,dis[i]);}
	
}spfa判负环
#include<bits/stdc++.h>
using namespace std;
int read()
{
    int x=0;int f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-'){f=-1;}ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
#define N 10005
struct node
{
    int to,next,v;
}e[N<<1];
int inE[N],inS[N];
int sta[N];
int head[N];int dis[N];int top;
int cnt=0;
void add(int x,int y,int z)
{
    e[cnt].to=y;
    e[cnt].next=head[x];
    e[cnt].v=z;
    head[x]=cnt++;
}
int spfa()
{
    memset(dis,99,sizeof(dis));
    dis[0]=0;
    sta[++top]=0;
    while(top)
    {
        int u=sta[top--];
        inS[u]=0;
        for(int i=head[u];i;i=e[i].next)
        {      int v=e[i].to;
            if(dis[v]>dis[u]+e[i].v)
            {
                if(inS[v]) return 0;
                dis[v]=dis[u]+e[i].v;
                sta[++top]=v;
                inS[v]=1;
            }
        }
    }
    return 1;
}
int main()
{
    int n,m; memset(head,-1,sizeof(head));
    n=read();m=read();
    while(m--)
    {
        int p,a,b;
        p=read(); a=read(); b=read();
        if(p==3) {add(a,b,0); add(b,a,0);inE[a]=inE[b]=1;continue;}
        int c; c=read();
        if(p==2)
        {
            add(a,b,c);
            inE[b]=1;
        }
        else
        { 
            add(b,a,-c);
            inE[a]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!inE[i]) add(0,i,0);
    }
    if(spfa()) printf("Yes\n");
    else printf("No\n");
    return 0;
}tarjan缩点
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector> 
#define ll long long
using namespace std;
const int N=200;
int n,t,num,top;
int dfn[N],low[N],in[N],out[N],id[N];
int sta[N],insta[N];
vector<int> G[N];
void tarjan(int u)
{
    dfn[u]=low[u]=++t;
	sta[++top]=u;
	insta[u]=1;
	for(int i=0;i<G[u].size();i++)
	{
		int to=G[u][i];
		if(!dfn[to])
		{
			tarjan(to);
			low[u]=min(low[u],low[to]);
		}
		else if(insta[to])
		{
			low[u]=min(low[u],dfn[to]);
		}
	}
	if(dfn[u]==low[u])
	{
		num++;
		int now;
		do
		{
			now=sta[top--];
			insta[now]=0;
			id[now]=num;
		}while(now!=u);
	}
}
int main()
{
	t=0;num=0; top=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
	  int x;
	  while(~scanf("%d",&x))
	  {
	    if(x==0) break;
		G[i].push_back(x);
	  }
    }
    for(int i=1;i<=n;i++)
    {
    	if(!dfn[i])
    	{
    		tarjan(i);
    	}
    }
    for(int i=1;i<=n;i++)
    {
    	for(int j=0;j<G[i].size();j++)
    	{
    		int to=G[i][j];
    		if(id[to]!=id[i])
    		{
    			out[id[i]]++;
    			in[id[to]]++;
    		}
    	}
    }
    if(num==1) {printf("1\n0");return 0;}
    int ct1=0;int ct2=0;
    for(int i=1;i<=num;i++)
    {
    	if(in[i]==0) ct1++;
    	if(out[i]==0) ct2++;
    }
    printf("%d\n",ct1);
    ct1=max(ct1,ct2);
    
    printf("%d\n",ct1);
    return 0;
    
}tarjan割点
#include<bits/stdc++.h>
using namespace std;
const int N=100010;
vector<int> G[N];
int dfn[N],low[N];
bool isge[N];
int n,m;
int tt;
void tarjan(int u,int fa)
{
	dfn[u]=low[u]=++tt;
	int child=0;
	for(int i=0;i<G[u].size();i++)
	{
		int to=G[u][i];
		if(!dfn[to])
		{
			tarjan(to,fa);
			low[u]=min(low[u],low[to]);
			if(low[to]>=dfn[u]&&u!=fa)
			  isge[u]=1;
			if(u==fa) child++;
		}
		low[u]=min(low[u],dfn[to]);
	}
	if(child>=2&&u==fa) isge[u]=1;
}
int main()
{
	memset(dfn,0,sizeof dfn);
    tt=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		if(dfn[i]==0) tarjan(i,i);
	}  int ans=0;
	for(int i=1;i<=n;i++) if(isge[i]) ans++;
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
	{
		if(isge[i]) printf("%d ",i);
	}
	return 0;
}
