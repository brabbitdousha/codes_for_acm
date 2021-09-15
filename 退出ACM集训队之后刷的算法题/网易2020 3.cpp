#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int maxm;
		int n;
		int m1,t1;
		int m2,t2;
		scanf("%d %d %d %d %d %d",&maxm,&n,&m1,&t1,&m2,&t2);
		int s1=1;
		int s2=1;
		int now=0;
		for(int i=1;i<=n;i++)
		{
			
			int des=0;
			if(s1==1) des+=m1;
			if(s2==1) des-=m2;
			if((now+des)>=0&&(now+des)<=maxm)
			{
				now+=des;
			}
			else if((now+des)<0) {now=0;}
			else if((now+des)>maxm) {now=maxm;}
			if(i%t1==0) {if(s1==1) s1=0; else s1=1;}
			if(i%t2==0) {if(s2==1) s2=0; else s2=1;}
		}
		printf("%d\n",now); 
	}
	return 0;
}
