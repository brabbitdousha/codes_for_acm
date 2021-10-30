#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
#define ll long long
using namespace std;
const int N=1e5+5;
vector<int> G[N];
//这种复杂度比较危险的,就不要用临时变量倒来倒去了，很危险 
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{    for(int i=0;i<=100000;i++) G[i].clear();
		int n,m;
		scanf("%d %d",&n,&m);
		for(int k=1;k<=n;k++)
		{
			int temp; scanf("%d",&temp);
			int x=temp;
			for(int i=2;i*i<=x;i++)
			{
				if(x%i==0)
				{
					while(x%i==0)
					{   
						G[i].push_back(k);
						x=x/i;
					}
				}
			}
			if(x>1) G[x].push_back(k);
		}
		while(m--)
		{
			int l,r,d;
			scanf("%d %d %d",&l,&r,&d);
			int x=d; int flag=1;
				for(int i=2;i*i<=x;i++)
			{   
				if(x%i==0)
				{   int cnt=0;
					while(x%i==0)
					{   
					   cnt++;
					   x=x/i;
					}
					//vector<int> temp=G[i];
					int left=lower_bound(G[i].begin(),G[i].end(),l)-G[i].begin();
					int right=upper_bound(G[i].begin(),G[i].end(),r)-G[i].begin();
					right--;
					int des=right-left+1;
					if(des<cnt) {flag=0;break;}
				}
				if(flag==0) break;
			}
			if(x>1)
			{
				vector<int> temp=G[x];
					int left=lower_bound(temp.begin(),temp.end(),l)-temp.begin();
					int right=upper_bound(temp.begin(),temp.end(),r)-temp.begin();
					right--;
					int des=right-left+1;
					if(des<1) {flag=0;}
			}
			
			if(flag==1) puts("Yes");
			else puts("No");
		
		}
	}
	return 0;
}
