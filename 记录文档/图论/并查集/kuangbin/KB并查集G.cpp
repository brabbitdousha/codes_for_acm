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
ll f[10005];
struct node
{
	ll p,d;
}e[10004];
ll find1(ll x)
{
	if(f[x]==x) return f[x];
	f[x]=find1(f[x]);
	return f[x];
}
int cmp(node a,node b)
{
	return a.p>b.p;
}
//priority_queue<ll> que;
int main()
{
   int n;
   while(~scanf("%d",&n))
   {   //while(!que.empty()) que.pop();
      ll maxn=0;
   	  for(int i=1;i<=n;i++)
   	  {
   	  	scanf("%lld %lld",&e[i].p,&e[i].d);
   	  	maxn=max(maxn,e[i].d);
   	  }
   	  sort(e+1,e+1+n,cmp);
   	  ll sum=0;
   	  for(int i=0;i<=maxn;i++) f[i]=i;
   	  for(int i=1;i<=n;i++)
   	  {
   	  	  int r=find1(e[i].d);
   	  	  if(r>0)
   	  	  {
   	  	  	sum+=e[i].p;
   	  	  	f[r]=r-1;
   	  	  }
   	  }
   	  printf("%lld\n",sum);
   }
   return 0;
}
   	  	
   	  	
   	  	
   	  	
   	  	
    
