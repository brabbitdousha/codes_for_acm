线性筛素数
#include<bits/stdc++.h>
using namespace std;
int read()
{
int x=0;int f=1;char ch=getchar();
while(ch>'9'||ch<'0'){if(ch=='-'){f=-1;}ch=getchar();}
while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
return x*f;
}
bool prime[10001000];
int rec[10001000];
int cnt;
int n,m;

int init_p(int n)
{   cnt=0;
    memset(prime,true,sizeof prime);
    prime[0]=prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(prime[i])
        rec[cnt++]=i;
        for(int j=0;j<cnt&&rec[j]<=n/i;++j)
        {
            prime[rec[j]*i]=false;
            if(i%rec[j]==0) break;
        }
    }
}
int main()
{
    n=read();
    m=read();
    init_p(n);int x;
    for(int i=1;i<=m;i++)
    {
        x=read();
        if(prime[x]) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}线性组合数公式
ll inv[300009];
ll C(ll m,ll nn)
{ 
   inv[1]=1; 
   for(int i=2;i<=300005;i++) inv[i]=((ll)(mod-mod/i)*(ll)inv[mod%i])%mod;
   ll zhuhe=1;
   for(int i=1;i<=nn;i++) zhuhe=(zhuhe*(ll)(m-i+1)%mod*inv[i])%mod;
   return zhuhe;
}//C(m,nn)

ll C[2005][2005];
	for(int i=0;i<2000;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(j==0) {c[i][j]=1;continue;}
			if(i==j) {c[i][j]=1;continue;}
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
		}
	}
	
int gcd(int x,int y)
{
	if(y==0) return x;
	else return gcd(y,x%y);
}N内多少个质数
const int N=1000006;
vector<int> prime;
bool mark[N+5];//开int会MLE
void goprime()
{
	memset(mark,0,sizeof mark);
	prime.clear();
	for(int i=2;i<=N;i++)
	{
		int tt=N/i;
		for(int j=2;j<=tt;j++)
		   mark[i*j]=1;
	}
	for(int i=2;i<=N;i++)
	{
		if(!mark[i])
		prime.push_back(i);
	}
} 计算系数 组合数
#include<iostream>
#include<cstdio>
#define mod 10007
using namespace std;
int k,n,m; long long a,b;
int c[2000][2000];
long long power(long long x,long long y)
{
	long long ans=1;
	for( ;y;y>>=1) {if(y&1) ans=ans*x%mod; x=x*x%mod;}
   return ans;
}
int main()
{
	scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
	c[0][0]=1;
	for(int i=1;i<=k;i++) c[i][0]=c[i][i]=1;
	for(int i=1;i<=k;i++)
	for(int j=1;j<i;j++)
	c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	printf("%d",c[k][m]*power(a,n)*power(b,m)%mod);
	return 0;
}
进制转换
#include<stdio.h>
int main(void)
{
    int i=0,n,a[1000];int k;
    scanf("%d",&n);
    scanf("%d",&k);
    while (n>0)
    {
        a[i]=n%k;
        i=i+1;
        n=n/k;
    }  
    for(i--;i>=0;i--)
        printf("%d",a[i]);
    return 0;
}矩阵快速幂
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
const int mod=7;
struct node
{
	int mat[15][15];
}x,y;
int n;
node a;
node mul(node x,node y)
{
	node tmp;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{    tmp.mat[i][j]=0;
			for(int k=0;k<n;k++)
			{
				tmp.mat[i][j]+=(x.mat[i][k]*y.mat[k][j])%mod;
			}
			tmp.mat[i][j]=tmp.mat[i][j]%mod;
		}
	}
	return tmp;
}
node ksm(node x,int num)
{    node y;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    if(i==j) y.mat[i][j]=1;
    else y.mat[i][j]=0;
	while(num)
	{
		if(num&1)
		{
			y=mul(y,x);
		}
		x=mul(x,x);
		num=num>>1;
	}
	return y;
}
int main()
{    n=2;
	int a,b,c;
	while(cin>>a>>b>>c&&a&&b&&c)
	{
		if(c==1||c==2) {printf("1\n");continue;}
		node base; node now;
		memset(base.mat,0,sizeof base);
		base.mat[0][0]=a; base.mat[0][1]=b; base.mat[1][0]=1;
		memset(now.mat,0,sizeof now);
		now.mat[0][0]=1; now.mat[1][0]=1;
		node ans=ksm(base,c-2);
		ans=mul(ans,now);
		cout<<ans.mat[0][0]<<endl;
	}
	
	return 0;
}快速幂
long long power(long long x,long long y)
{
	long long ans=1;
	for( ;y;y>>=1) {if(y&1) ans=ans*x%mod; x=x*x%mod;}
   return ans;
}快速幂+gcd+log+质因数
long long power(long long x,long long y)
{
	long long ans=1;
	for( ;y;y>>=1) {if(y&1) ans=ans*x%mod; x=x*x%mod;}
   return ans;
}

int gcd(int x,int y)

{
    if(y==0) return x;
	
      else gcd(y,x%y);

}
ll int logi(ll int n,ll int b)
{
	ll int cnt=0;
	while(n>1)
	{
		cnt++;
		n=n/b;
	}
	return cnt;
}
cout<<logi(8,2)<<endl;//  值为3
质因数
vector<ll int> divi;
	for(int i=2;i*i<=x;i++)
	{
		int cnt=0;
		while(x%i==0)
		{
			x=x/i;
			cnt=1;
		}
		if(cnt==1) divi.push_back(i);
	}
	if(x>1) divi.push_back(x);欧拉函数
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100000
int primes[N], euler[N], cnt;
bool st[N];
/* 欧拉函数
可以在 O(n) 的时间复杂度内求出 1～n中所有数的欧拉函数 同时也能算质数
质数存在primes[]中(用cnt统计<=n的素数个数)，euler[i] 表示 i的欧拉函数*/
int get_eulers(int n) {
    euler[1] = 1;
    for (int i = 2; i <= n; i ++ ) {
        if (!st[i]) {
            primes[cnt ++ ] = i;
            euler[i] = i - 1;
        }
        for (int j = 0; j < cnt && i * primes[j] <= n; j ++ ) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) {
                euler[i * primes[j]] = euler[i] * primes[j];
                break;
            }
            euler[i * primes[j]] = euler[i] * (primes[j] - 1);
        }
    }
    return cnt;
}
 
int main(void) {
   
 
    get_eulers(101);
   
    for (int j = 1 ; j < 101; j++) {
        cout << j << " " << euler[j] << endl;
    }
    
    return 0;
}区间素数个数
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define LL long long
#define MAX_L 5000010 
bool is_prime[MAX_L];
bool is_prime_small[MAX_L];
void segment_sieve(LL a,LL b)//左闭右开
{
	for(LL i=0;(LL)i*i<b;i++) is_prime_small[i]=true;
	for(LL i=0;i<b-a;i++) is_prime[i]=true;
	for(LL i=2;(LL)i*i<b;i++)
	{
		if(is_prime_small[i])
		{
			for(LL j=2*i;(LL) j*j<b;j+=i)
			{
				is_prime_small[j]=false;
			}
			for(LL j=max(2LL,(a+i-1)/i)*i;j<b;j+=i)
			{
				is_prime[j-a]=false;
			}
		}
	}
}
int main()
{  int t;
   scanf("%d",&t);
   while(t--)
   {
	long long a,b;
	scanf("%lld %lld",&a,&b);
	
		segment_sieve(a,b);
		LL cnt=0;
		for(LL j=0;j<b-a;j++)
		{
			if(is_prime[j]) cnt++;
		}
		if(a==1) cnt--;
		printf("%lld\n",cnt);
	
   }
	return 0;
}拓展欧几里得
两个青蛙的位置分别为(x+mt)mod L、(y+nt) mod L，相遇即是(x+mt)%L=(y+nt)%L，即(m-n)*t+k*L=y-x。
已经符合ax+by=c的方程了，设a=m-n，b=L，c=y-x，
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
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	ll r,t;
	if(!b)
	{
		x=1;
		y=0;
		return a;
	}
	r=exgcd(b,a%b,x,y);
	t=x;
	x=y;
	y=t-a/b*y;
	return r;
}
int main()
{
	ll x,y,m,n,l;
	scanf("%lld %lld %lld %lld %lld",&x,&y,&m,&n,&l);
	ll a=n-m;
	ll c=x-y;
	ll b=l;
	if(a<0)
	{
		a=-a;
		c=-c;
	}
	ll p=exgcd(a,b,x,y);
	if(c%p!=0)
	  printf("Impossible\n");
	else
	{
		x=x*c/p;
		ll t=b/p;
		if(x>=0) x=x%t;
		else
		  x=x%t+t;
		printf("%lld\n",x);
	}
	return 0;
}

如果 res<0，说明结果向量垂直于屏幕向里，也就是指向Z轴的负方向，P点在直线的下侧。
如果res>0，说明结果向量垂直于屏幕向外，也就是指向Z轴的正方向，P点在直线的上侧。
如果res=0，P点在直线上。
然后就是把所有线段弄成同一个方向
int chacheng(Point a,Point b,Point c)
{
	return (c.first-a.first)*(b.second-a.second)-(c.second-a.second)*(b.first-a.first)<=0;
}