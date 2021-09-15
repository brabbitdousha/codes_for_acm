#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;

int is_alive[N];
struct node
{
	int num;
	ll val;
	int ans;
}e[N];
node a[N];
bool cmp1(node a,node b)
{
	return a.val<b.val;
}
bool cmp2(node a,node b)
{
	return a.num<b.num;
}
int main()
{
	int now_num=1;
	int n;
	scanf("%d",&n);
	for(int i=0;i<=n;i++) is_alive[i]=1;
	
	for(int i=1;i<=n;i++) {scanf("%lld",&a[i].val);a[i].num=i;}
	sort(a+1,a+1+n,cmp1);
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++) {scanf("%lld",&e[i].val); e[i].num=i; e[i].ans=0;}
	sort(e+1,e+1+q,cmp1);
	int nowpos=1;
	for(int i=1;i<=q;i++)
	{
		ll nowmax=e[i].val;
		//printf("%lld\n",nowmax);
		while(a[nowpos].val<=nowmax&&nowpos<=n)
	    {
	    	int num=a[nowpos].num;
	    	is_alive[num]=0;
	    	int left=num-1; int right=num+1;
	    	if((left>=1)&&(right<=n))
	    	{
	    		if((is_alive[left]==1)&&(is_alive[right]==1)) {now_num++;}
	    		else if((is_alive[left]==0)&&(is_alive[right]==0))
	    		 {
	    		 	now_num--;
	    		 }
	    	}
	    	else if(left>=1)
	    	{
	    		if(is_alive[left]==0) now_num--;
	    	}
	    	else if(right<=n)
	    	{
	    		if(is_alive[right]==0) now_num--;
	    	}
	    	nowpos++;
	    }
	    e[i].ans=now_num;
	}
//	printf("\n");
	sort(e+1,e+1+q,cmp2);
	for(int i=1;i<=q;i++)
	{
		printf("%d\n",e[i].ans);
	}
	
	return 0;
}
