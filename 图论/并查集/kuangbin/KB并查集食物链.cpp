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
/* ABC是一个环
*/ 
using namespace std;
const ll maxn=1e3+7;
const double eps=1e-10;
const ll mod=1e9+7;
int f[150005];
int find1(int x)
{
	if(f[x]==x) return f[x];
	f[x]=find1(f[x]);
	return f[x];
}
void merge(int x,int y)
{
	int t1=find1(x);
	int t2=find1(y);
	if(t1!=t2)
	{
		f[t2]=t1;
	}
}
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<=n*3;i++) f[i]=i;
	int ans=0;
	while(k--)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if((a==2&&b==c)||b>n||c>n){ans++;continue;}
		if(a==1)
		{
			if(find1(b+n)==find1(c)||find1(b+n+n)==find1(c)
			||find1(c+n)==find1(b)||find1(c+n+n)==find1(b))
			{ ans++;continue;}
			merge(b,c);
			merge(b+n,c+n);
			merge(b+n+n,c+n+n);
		}
		if(a==2)
		{
			if(find1(b)==find1(c)||find1(b+n+n)==find1(c)
			||find1(c+n)==find1(b))
			{ans++;continue;}
			merge(b,c+n+n);
			merge(b+n,c);
			merge(b+n+n,c+n); 
		}
	}
	cout<<ans;
	return 0;
}

