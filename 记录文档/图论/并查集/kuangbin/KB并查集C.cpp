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
int f[10100]={0};
int n;//不要重复定义变量 
void init()
{
	for(int i=1;i<=n;i++) f[i]=i;
}
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
	int t;
	scanf("%d",&t);
	while(t--)
	{
		//int n,m;
		int m; 
		scanf("%d %d",&n,&m);
		init();
		for(int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			merge(x,y);
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i]==i) cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
