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
ll f[200005];
ll sum[200005];
ll n,m;
ll ans;
ll find1(ll x)
{
	if(f[x]==x) return f[x];
	
	ll gen=find1(f[x]);
	sum[x]+=sum[f[x]];
	f[x]=gen;
	return f[x];
}
void merge(ll x,ll y)
{
   f[y]=x;
}
int main()
{
     while(~scanf("%lld %lld",&n,&m))
     {
     	for(int i=0;i<=n+1;i++)
	{
		f[i]=i;
		sum[i]=0;
	}
     	ans=0;
	   for(int i=1;i<=m;i++)
	   {
	   	  ll a,b;
	   	  ll c;
	   	  scanf("%lld %lld %lld",&a,&b,&c);
	   	  b++;
	   	  ll t1=find1(a);
	   	  ll t2=find1(b);
	   	  if(t1!=t2)
	   	  { merge(t1,t2);
	   	  	sum[t2]=sum[a]+c-sum[b];
	   	  }
	   	  else
	   	  {
	   	  	if(sum[b]-sum[a]!=c)
	   	  	ans++;
	   	  }
	   }
	   printf("%lld\n",ans);
     }
     return 0;
 }
	   	  
	
	
