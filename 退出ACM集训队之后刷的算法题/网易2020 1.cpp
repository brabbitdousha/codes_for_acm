#include<bits/stdc++.h>
#define ll long long
using namespace std;
int getnum(ll x)
{
	int ans=0;
	ll now=x;
	while(now)
	{
		if(now%2==1) ans++;
		now=now/2;
	}
	return ans;
}
map<int,int> check;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{   check.clear();
		int n;
		scanf("%d",&n);
		
		ll x;  int result=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&x);
			int nownum=getnum(x);
			if(!check[nownum]) {check[nownum]=1; result++;}
		}
		printf("%d\n",result);
	}
	return 0;
}
