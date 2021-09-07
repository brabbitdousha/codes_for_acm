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
int f[100005]={0};
int n;
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
map<int,int> mp;
int num[100003];
int main()
{
   for(int i=0;i<=100003;i++) f[i]=i;
   int a,b;
   int flag=1;
   int cnt=0;
   while(~scanf("%d %d",&a,&b))
   {
       if(a==-1&&b==-1) break;
	   if(a==0&&b==0)
	   {  
	    int ans=0;
	    for(int i=1;i<=cnt;i++)
	    {
	    	if(f[num[i]]==num[i])
	    	{
	    		ans++;
	    	}
	    }
	    if(ans>1) flag=0;
	   if(flag) printf("Yes\n"); else printf("No\n");
	   flag=1;
	   cnt=0;
	   mp.clear();
	   for(int i=0;i<=100003;i++) f[i]=i;
	   continue; 
	   }
	   if(!mp[a]) {mp[a]=1;num[++cnt]=a;}
	   if(!mp[b]) {mp[b]=1;num[++cnt]=b;}
	   if(find1(a)==find1(b)){flag=0;}
	   else merge(a,b);
   }
   return 0;
}
	   


