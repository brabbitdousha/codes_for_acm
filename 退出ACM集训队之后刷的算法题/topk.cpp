#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
ll a[N];
int n;
ll ans;
void quicksort(int l,int r,int k)
{
	int now=a[l];
	int i=l,j=r;
	while(i<j)
	{
		while((i<j)&&a[j]>=now) j--;
		a[i]=a[j];
		while((i<j)&&a[i]<=now) i++;
		a[j]=a[i];
	}
	a[i]=now;
	if(l<r)
	{
		
	if(i-l+1==k) {ans=now; return;}
	else if(i-l+1>k) quicksort(l,i-1,k);
	else quicksort(i+1,r,k-(i-l+1));
    }
}
int main()
{
	  scanf("%d",&n);
	  for(int i=1;i<=n;i++)
	  {
	  	scanf("%lld",&a[i]);
	  }
	  int k;
	  scanf("%d",&k);
	  quicksort(1,n,k);
	  
	  cout<<ans;
	  return 0;
}
