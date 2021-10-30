#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	scanf("%d",&t); int num=0;
	while(t--)
	{   num++;
		int n,m;
		scanf("%d %d",&n,&m);
		int y=0x3fffffff;
		int x=0x3fffffff;
		for(int i=1;i<=n;i++)
	      {
	      	int kk; scanf("%d",&kk);
	      	 y=min(y,kk);
	      }
	    for(int i=1;i<=m;i++)
	    {
	    	int kk; scanf("%d",&kk);
	    	x=min(x,kk);
	    }
	    printf("Problem %d:\n",num+1000);
	    if(y!=0x3fffffff)
	    {
	    	printf("Shortest judge solution: %d bytes.\n",y);
	    }
	    else printf("Shortest judge solution: N/A bytes.\n");
	    
	    if(x!=0x3fffffff)
	    {
	    	printf("Shortest team solution: %d bytes.\n",x);
	    }
	    else
	    printf("Shortest team solution: N/A bytes.\n");
	}
}
