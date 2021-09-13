#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mp[700][700];
ll hang[700];
ll lie[700];
ll del_lie[700];
ll del_hang[700];
int shan_h[700];
int shan_l[700];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&mp[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		ll sum=0;
		for(int j=1;j<=n;j++)
		{
			sum+=mp[i][j];
		}
		hang[i]=sum;
	}
	for(int j=1;j<=n;j++)
	{  ll sum=0;
		for(int i=1;i<=n;i++)
		{
			 sum+=mp[i][j];
		}
		lie[j]=sum;
	}
	
	vector<int> ans;
	for(int k=1;k<=n;k++)
	{    ll nowsum=-1;int x,y;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				ll sum=hang[i]-del_hang[i]+lie[j]-del_lie[j]-mp[i][j];
				if(sum>nowsum)
				{
					nowsum=sum;
					x=i; y=j;
				}
			}
		}
		hang[x]=0; lie[y]=0;
		int qian_hang=0; int qian_lie=0;
		for(int i=1;i<=n;i++)
		{  if((shan_l[i]==1)&&i<y) qian_lie++;
			del_lie[i]+=mp[x][i];
		}
		for(int i=1;i<=n;i++)
		{   if((shan_h[i]==1)&&i<x) qian_hang++;
			del_hang[i]+=mp[i][y];
		}
		shan_h[x]=1; shan_l[y]=1;
		
		ans.push_back(x-qian_hang); ans.push_back(y-qian_lie);
	}
	
	for(int i=0;i<ans.size();i+=2)
	{
		cout<<ans[i]<<" "<<ans[i+1]<<"\n";
	}
	return 0;
}
		
				
				
