#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
ll a[N];
int n;
void quicksort(int l,int r)
{
	ll mid=a[(l+r)/2];
	int i=l,j=r;
	do
	{
		while(a[i]<mid) i++;
		while(a[j]>mid) j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}while(i<=j);
	if(l<j) quicksort(l,j);
	if(i<r) quicksort(i,r);
}
int main()
{
	  scanf("%d",&n);
	  for(int i=1;i<=n;i++)
	  {
	  	scanf("%lld",&a[i]);
	  }
	 // int k;
	  //scanf("%d",&k);
	  quicksort(1,n);
	  
	  for(int i=1;i<=n;i++) 
	  {   
	    printf("%lld",a[i]);
	    if(i!=n) printf(" ");
	    //else printf("\n");
	  } 
	  return 0;
} 
