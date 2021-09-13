1 x y z 区间加
2 x y z 区间乘
3 x y z 区间改
4 x y z 区间每个数的z的次方相加
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#define ll long long
using namespace std;
const int maxn=100010;
const int mod=10007;
int n,m;
struct node
{
	int l,r;
	ll sum[3];
	ll lz[3];
}tree[maxn*4];
void build(int i,int l,int r)
{   
	tree[i].l=l;
	tree[i].r=r;
	tree[i].sum[0]=tree[i].sum[1]=tree[i].sum[2]=0;
	tree[i].lz[0]=tree[i].lz[2]=0;
	tree[i].lz[1]=1;
	if(l!=r)
	{int mid=(l+r)>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
    }
}
void push_down(int i,int len)
{
	int left=i<<1; int right=i<<1|1;
	if(tree[i].lz[2])
	{
		tree[left].lz[2]=tree[right].lz[2]=tree[i].lz[2];
		tree[left].lz[1]=tree[right].lz[1]=1;
		tree[left].lz[0]=tree[right].lz[0]=0;
		ll now=(tree[i].lz[2]*tree[i].lz[2]%mod)*tree[i].lz[2]%mod;
		tree[left].sum[2]=now*(len-(len>>1))%mod;
		tree[right].sum[2]=now*(len>>1)%mod;
		
		tree[left].sum[1]=(((tree[i].lz[2]*tree[i].lz[2])%mod)*(len-(len>>1))%mod)%mod;
		tree[right].sum[1] =((tree[i].lz[2]*tree[i].lz[2]%mod)*(len>>1)%mod)%mod;
 
		tree[left].sum[0]=tree[i].lz[2]*(len-(len>>1))%mod;
		tree[right].sum[0]=tree[i].lz[2]*(len>>1)%mod;	
		tree[i].lz[2]=0;
	}
	if(tree[i].lz[1]!=1)
	{
		tree[left].lz[1]=tree[left].lz[1]*tree[i].lz[1]%mod;
		tree[right].lz[1]=tree[right].lz[1]*tree[i].lz[1]%mod;
		if(tree[left].lz[0]) tree[left].lz[0]=tree[left].lz[0]*tree[i].lz[1]%mod;
		if(tree[right].lz[0]) tree[right].lz[0]=tree[right].lz[0]*tree[i].lz[1]%mod;
		ll now=(tree[i].lz[1]*tree[i].lz[1]%mod)*tree[i].lz[1]%mod;
		
		tree[left].sum[2]=tree[left].sum[2]*now%mod;
		tree[right].sum[2]=tree[right].sum[2]*now%mod;
		
		 now=(tree[i].lz[1]*tree[i].lz[1]%mod);
		tree[left].sum[1]=tree[left].sum[1]*now%mod;
		tree[right].sum[1]=tree[right].sum[1]*now%mod;
		
		now=(tree[i].lz[1])%mod;
		
		tree[left].sum[0]=tree[left].sum[0]*now%mod;
		tree[right].sum[0]=tree[right].sum[0]*now%mod;
		
		tree[i].lz[1]=1;
	}
	if(tree[i].lz[0])
	{
		tree[left].lz[0]+=tree[i].lz[0];
		tree[right].lz[0]+=tree[i].lz[0];
		
		ll now=(tree[i].lz[0]*tree[i].lz[0]%mod)*tree[i].lz[0]%mod;
		
		tree[left].sum[2]=(tree[left].sum[2]+(tree[i].lz[0]*(tree[left].sum[1]+tree[i].lz[0]*tree[left].sum[0]%mod)%mod*3)%mod+(len-(len>>1))*now%mod)%mod;
		tree[right].sum[2]=(tree[right].sum[2]+(tree[i].lz[0]*(tree[right].sum[1]+tree[i].lz[0]*tree[right].sum[0]%mod)%mod*3)%mod+(len>>1)*now%mod)%mod;
		
		now=(tree[i].lz[0]*tree[i].lz[0]%mod);
		
		tree[left].sum[1]=(tree[left].sum[1]+2*(tree[i].lz[0]*tree[left].sum[0]%mod)%mod+(len-(len>>1))*now)%mod;
		tree[right].sum[1]=(tree[right].sum[1]+2*(tree[i].lz[0]*tree[right].sum[0]%mod)%mod+(len>>1)*now)%mod;
		 now=tree[i].lz[0];
		tree[left].sum[0]=(tree[left].sum[0]+(len-(len>>1))*now%mod)%mod;
		tree[right].sum[0]=(tree[right].sum[0]+(len>>1)*now%mod)%mod;
		
		tree[i].lz[0]=0;
	}
}
void push_up(int i)
{
	int l=i<<1,r=i<<1|1;
	tree[i].sum[0]=(tree[l].sum[0]+tree[r].sum[0])%mod;
	tree[i].sum[1]=(tree[l].sum[1]+tree[r].sum[1])%mod;
	tree[i].sum[2]=(tree[l].sum[2]+tree[r].sum[2])%mod;
}

void updata(int i,int x,int l,int r,int c)
{   //cout<<1<<endl;
	int len=r-l+1;
		if(tree[i].r<=r&&tree[i].l>=l)
		{
			if(x==2)
			{   
				tree[i].lz[2]=c;
				tree[i].lz[1]=1;
				tree[i].lz[0]=0;
				tree[i].sum[0]=(c*(r-l+1))%mod;
				tree[i].sum[1]=((c*c%mod)*(r-l+1))%mod;
				tree[i].sum[2]=(((c*c%mod)*c)%mod*(r-l+1))%mod;
			}
			else if(x==1)
			{
				tree[i].lz[1]=tree[i].lz[1]*c%mod;
				if(tree[i].lz[0]) tree[i].lz[0]=tree[i].lz[0]*c%mod;
				tree[i].sum[0]=tree[i].sum[0]*c%mod;
				tree[i].sum[1]=((c*c%mod)*tree[i].sum[1])%mod;
				tree[i].sum[2]=(((c*c%mod)*c)%mod*tree[i].sum[2])%mod;
			}
			else if(x==0)
			{
				    tree[i].lz[0]=(tree[i].lz[0]+c)%mod;
				tree[i].sum[2]=(tree[i].sum[2]+(tree[i].sum[1]+c*tree[i].sum[0]%mod)*3*c%mod+((((len*c)%mod)*c%mod)*c%mod))%mod;
				tree[i].sum[1]=(tree[i].sum[1]+(tree[i].sum[0]*c%mod)*2%mod+(len*c%mod)*c%mod)%mod;
				tree[i].sum[0]=(tree[i].sum[0]+c*len%mod)%mod;
			
			
			}
		return;
	   }
	   if(tree[i].l==tree[i].r) return;
	   push_down(i,tree[i].r-tree[i].l+1);
	  int mid=(tree[i].l+tree[i].r)>>1;
	
	   if(r<=mid) updata(i<<1,x,l,r,c);
	   else if(l>mid) updata(i<<1|1,x,l,r,c);
	   else
	  {
		updata(i<<1,x,l,mid,c);
		updata(i<<1|1,x,mid+1,r,c);
	  }
		push_up(i);
}
ll search(int i,int l,int r,int p)
{    //cout<<i<<" "<<l<<" "<<r<<" "<<p<<endl;
	if(tree[i].l==l&&tree[i].r==r)
	{   	//cout<<1<<endl;
		return tree[i].sum[p]%mod;
	}

	push_down(i,tree[i].r-tree[i].l+1);
	int mid=(tree[i].l+tree[i].r)>>1;
	ll s=0;
	if(r<=mid) s+=search(i<<1,l,r,p)%mod;
	else if(l>mid) s+=search(i<<1|1,l,r,p)%mod;
	else
	{
		s+=search(i<<1,l,mid,p)%mod;
		s+=search(i<<1|1,mid+1,r,p)%mod;
	}
	
	return s%mod;
}
int main()
{
	while(~scanf("%d %d",&n,&m))
	{
		if(n==0&&m==0) break;
		build(1,1,n); 
			int cao,x,y,z;
			while(m--)
			{
				scanf("%d %d %d %d",&cao,&x,&y,&z);
				//cout<<cao<<endl;
				if(cao==4)
				{
					ll ans=search(1,x,y,z-1)%mod;
					printf("%lld\n",ans);
				}
				else
				{
					updata(1,cao-1,x,y,z);
				}
			}
	}
	return 0;
}
并查集
#include<iostream>
#include<cstdio>
using namespace std;
int read()
{
	int x=0;int f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-'){f=-1;}ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int f[10100]={0};
int n,m;
int init()
{ 
for (int i=1;i<=n;i++)
 f[i]=i;
}
int find1(int x)
{ 
   if(f[x]==x) return x;
   f[x]=find1(f[x]);return f[x];
}
void merge(int x,int y)
{   int t1=find1(x);
    int t2=find1(y);
	if(t1!=t2)
	{
		f[t2]=t1;
	}
}
int main()
{
	n=read();m=read();int a,b,c;
	init();
	for(int i=1;i<=m;i++)
	{
		a=read();b=read();c=read();
		if(a==1)
		{
			merge(b,c);
		}
		if(a==2)
		{
			if(find1(b)==find1(c))
			cout<<"Y\n";
			else cout<<"N\n";
		}
	}
	return 0;
}
优化并查集
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int f[1005];
int h[1005];
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
   { if(h[t1]>h[t2]) f[t2]=t1;
     else f[t1]=t2;
    }
}    
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<=1005;i++) {f[i]=i;h[i]=0;}
        int x,y;
        for(int i=1;i<=m;i++)
        {
            scanf("%d %d",&x,&y);
            merge(x,y);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {  
        if(f[i]==i) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}单调队列
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<cmath>
#include<ctime>
#define ll long long
#define INF 0x3fffffff 
using namespace std;
const ll maxn=300010;
ll sum[maxn];
ll index1[maxn];
int main()
{
   ll n,m;
   while(~scanf("%lld %lld",&n,&m))
   {
       sum[0]=0;
       for(int i=1;i<=n;i++)
       {
       	 scanf("%lld",&sum[i]);
       	 sum[i]+=sum[i-1];
       }
       int left=1,right=1;
       index1[1]=1;
       ll ans=sum[1];
       for(int i=2;i<=n;i++)
       {
       	 while(index1[left]<i-m) left++;
       	 ans=max(ans,sum[i]-sum[index1[left]]);
       	 while(right>=left&&sum[i]<sum[index1[right]])
       	 right--;
       	 right++;
       	 index1[right]=i;
       }
       printf("%lld\n",ans);
   }
   return 0;
}普通线段树
改单点
inline void add(int i,int dis,int k)
{
    if(tree[i].l==tree[i].r)
    {
        tree[i].sum+=k;
        return;
    }
    if(dis<=tree[i*2].r) add(i*2,dis,k);
    else add(i*2+1,dis,k);
    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
    return;
}

找单点
ll ans=0;
void search(int i,int dis)
{
    ans+=tree[i].sum;
    if(tree[i].l==tree[i].r) return;
    if(dis<=tree[i*2].r) search(i*2,dis);
    if(dis>=tree[i*2+1].l) search(i*2+1,dis);
}

区间改，区间求和
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#define ll long long
using namespace std;
const int p=571373;
ll n,m;
struct node
{
    ll l,r;
    ll lz;
    ll mlz;
    ll sum;
}tree[2000003];
ll a[600000];
inline void build(ll i,ll l,ll r)
{   tree[i].lz=0;
    tree[i].mlz=0;
    tree[i].l=l;tree[i].r=r;
    if(l==r) {
        tree[i].sum=a[l];
        return;
    }
    ll mid=(l+r)>>1;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    tree[i].sum=(tree[i*2].sum+tree[i*2+1].sum);
}
void push_down(ll i)
{
    if(tree[i].lz!=0)
    {
        tree[i*2].lz+=tree[i].lz;
        tree[i*2+1].lz+=tree[i].lz;
        ll mid=(tree[i].l+tree[i].r)/2;
        tree[i*2].sum+=tree[i].lz*(mid-tree[i*2].l+1);
        tree[i*2+1].sum+=tree[i].lz*(tree[i*2+1].r-mid);
        tree[i].lz=0;
    }
    return;
}
void add(ll i,ll l,ll r,ll k)
{   ll mid=(tree[i].l+tree[i].r)>>1;
     if(tree[i].r<l || tree[i].l>r)  return ;
    if(tree[i].r==r&&tree[i].l==l)
    {
        tree[i].sum+=k*(tree[i].r-tree[i].l+1);
        tree[i].lz+=k;
        return;
    }
     push_down(i);
    if(r<=mid)
	{
		add(i<<1,l,r,k);
	}
	else if(l>mid)
	{
		add(i<<1|1,l,r,k);
	}
	else
	{
		add(i<<1,l,mid,k);
		add(i<<1|1,mid+1,r,k);
	}
    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
    return;
}

inline ll search(int i,int l,int r)
{
    if(tree[i].l>=l&&tree[i].r<=r) return tree[i].sum;
    if(tree[i].r<l||tree[i].l>r) return 0;
    push_down(i);
    ll s=0;
    if(tree[i*2].r>=l) s+=search(i*2,l,r);
    if(tree[i*2+1].l<=r) s+=search(i*2+1,l,r);
    return s;
}

int main()
{
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    build(1,1,n);
    while(m--)
    {
        ll k,x,y;
        scanf("%lld %lld %lld",&k,&x,&y);
        if(k==1) {ll num;scanf("%lld",&num);add(1,x,y,num);}
        if(k==2)
        { ll ans=search(1,x,y);
        printf("%lld\n",ans);
        }
    }
    return 0;
}树状数组
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<cmath>
#include<ctime>
#define ll unsigned long long
#define INF 0x3fffffff 
using namespace std;
const int MaxN=50005;
int n,m;
int a[MaxN];
int c[MaxN];
int lowbit(int x)
{
	return x&(-x);
}
void updata(int i,int k)
{
	while(i<=n)
	{
		c[i]+=k;
		i+=lowbit(i);
	}
}
int getsum(int i)
{
	int res=0;
	while(i>0)
	{
		res+=c[i];
		i-=lowbit(i);
	}
	return res;
}
int main()
{
	int t;
	scanf("%d",&t);int kk=0;
	while(t--)
	{   
		kk++;
		printf("Case %d:\n",kk); 
		memset(a,0,sizeof a);
		memset(c,0,sizeof c);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			updata(i,a[i]);
		}
		string s;
	   int x,y;
	   while(cin>>s&&s[0]!='E')
	   {
	   	scanf("%d %d",&x,&y);
	   	if(s[0]=='Q')
	   	{
	   		int sum=getsum(y)-getsum(x-1);
	   		printf("%d\n",sum);
	   	}
	   	else if(s[0]=='A')
	   	{
	   		updata(x,y);
	   	}
	   	else if(s[0]=='S')
	   	{
	   		updata(x,-y);
	   	}
	   }
    }
    return 0;
}
	
线段树 单点修改 查区间
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#define ll long long
using namespace std;
int n,m;
struct node
{
    int l,r;
    ll sum;
}tree[2000003];
ll a[600000];
inline void build(int i,int l,int r)
{
    tree[i].l=l;tree[i].r=r;
    if(l==r) {
        tree[i].sum=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
}
inline int search(int i,int l,int r)
{
    if(tree[i].l>=l&&tree[i].r<=r) return tree[i].sum;
    if(tree[i].r<l||tree[i].l>r) return 0;
    int s=0;
    if(tree[i*2].r>=l) s+=search(i*2,l,r);
    if(tree[i*2+1].l<=r) s+=search(i*2+1,l,r);
    return s;
}
inline void add(int i,int dis,int k)
{
    if(tree[i].l==tree[i].r)
    {
        tree[i].sum+=k;
        return;
    }
    if(dis<=tree[i*2].r) add(i*2,dis,k);
    else add(i*2+1,dis,k);
    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
    return;
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    build(1,1,n);
    while(m--)
    {
        int k,x,y;
        scanf("%d %d %d",&k,&x,&y);
        if(k==1) {add(1,x,y);}
        if(k==2)
        { ll ans=search(1,x,y);
        printf("%lld\n",ans);
        }
    }
    return 0;
}