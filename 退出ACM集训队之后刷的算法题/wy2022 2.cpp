#include<bits/stdc++.h>
#define ll long long
using namespace std;
int h[10000];
int n,m;
int getmax(int ss,int ee)
{
	int maxn=-1;
	for(int i=ss;i<=ee;i++) maxn=max(maxn,h[i]);
	return maxn;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%d",&h[i]);
		vector<int> pos1;
		vector<int> pos2;
		h[0]=0x3fffffff; h[n+1]=0x3fffffff;
		
		for(int i=m+1;i<=n;)
		{   int left=h[i-1];
		    int nowpos=i;
		    int now=h[i];
			while(h[i]==now&&i<=n)
			{
				i++;
			}
			int right=h[i];
			if(now<left&&now<right) pos1.push_back(nowpos);
		}
		
	
		int ans=1;  int nowmax=h[m];
		int last=m;
		for(int i=0;i<pos1.size();i++)
		{
			int num=pos1[i];
			if((num-1)<(last+1)) continue;
			int maxn=getmax(last+1,num-1);
			int hehe=max(h[num],h[last]);
			if(hehe<maxn) {ans++;}
		}
		
		for(int i=0;i<pos2.size();i++)
		{
			int num=pos2[i];
			if((last-1)<(num+1)) continue;
			int maxn=getmax(num+1,last-1);
			int hehe=max(h[num],h[last]);
			if(hehe<maxn) {ans++;}
		}
		//ans=min(ans,60);
		ans--;
		
		printf("%d\n",ans);
	}
}
