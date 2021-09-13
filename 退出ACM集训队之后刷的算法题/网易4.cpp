#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=200005;
vector<int> G[N];
map<string,int> num;
map<int,ll> back;
ll ans[N];
ll maxn=0;
ll start[N];
ll endtime[N];
int pre[N];
void dfs(int num)
{
     ll t=endtime[num]-start[num];
     //cout<<t<<endl;
	 for(int i=0;i<G[num].size();i++)
	 {
	    int to=G[num][i];
		dfs(to);
		t-=(endtime[to]-start[to]);
	}
	
	ans[num]=t;
}
struct node
{
	ll a,b;
	int num;
	ll hehe;
}record[N];
struct gett
{
	ll val;
	ll num;
}theans[N];
bool cmp(gett a,gett b)
{
	if(a.val==b.val)
	{
	return a.num<b.num;
    }
    else return a.val>b.val;
}
int to_dfs[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{   
	     num.clear();
		int n;
		scanf("%d",&n);  int cnt=0; maxn=0;
		for(int i=1;i<=n;i++)
		{  G[i].clear(); pre[i]=-1;
			ll tt,s;
			string e;
			scanf("%lld",&tt);
			cin>>e;
			ll hhh=0;
			for(int i=0;i<e.length();i++)
			{
				hhh=hhh*(ll)10+(ll)(e[i]-'0');
			}
			scanf("%lld",&s);
			if(num[e]==0)
			{
				cnt++;
				num[e]=cnt;
				back[cnt]=hhh;
			}
			int numi=num[e];
			if(s==0) start[numi]=tt;
			else if(s==1) endtime[numi]=tt;
			record[i].a=tt; record[i].num=numi; record[i].b=s; 
			
		}
		int up=-1;
		for(int i=1;i<=n;i++)
		{
			int numi=record[i].num;
			ll thetime=record[i].a;
			ll is_end=record[i].b;
			if(is_end==0)
			{
			 pre[numi]=up;
			 up=numi;
		    }
		    else if(is_end==1)
		    {
		    	up=pre[numi];
		    }
		}
		int ss=0;
		for(int i=1;i<=cnt;i++)
		{
			if(pre[i]!=-1) G[pre[i]].push_back(i);
			else to_dfs[++ss]=i;
		}
		for(int i=1;i<=ss;i++)
		{
			dfs(to_dfs[i]);
		}
	
		 
		for(int i=1;i<=cnt;i++)
		{   //cout<<back[i]<<" "<<ans[i]<<endl; 
			theans[i].val=ans[i];
			theans[i].num=back[i];
		}
		sort(theans+1,theans+1+cnt,cmp);
		printf("%lld\n",theans[1].num);
		
	}
	return 0;
}
		    
		
