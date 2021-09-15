#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
	int l;
	int r;
	int len;
}e[50005];
int main()
{    int cnt=0;
     int t;
	 scanf("%d",&t);
	 while(t--)
	 {   cnt=0;
	 	string a;
	 	cin>>a;
	 	int ans=0;
	 	for(int i=0;i<a.length();)
	 	{
	 		if(a[i]=='N')
	 		{  cnt++;
	 		    e[cnt].l=i;
	 		    
	 			int ct=0;
	 			while(a[i]=='N'&&i<a.length())
	 			{   
	 			    e[cnt].r=i;
	 			    
	 				ct++; i++;
	 				
	 			}
	 			e[cnt].len=ct;
	 			ans=max(ans,ct);
	 			if(e[cnt].r+1<a.length())
	 			{
	 				ans=max(ans,ct+1);
	 			}
	 			if(e[cnt].r+2<a.length())
	 			{
	 				ans=max(ans,ct+2);
	 			}
	 			if(e[cnt].l-1>=0)
	 			{
	 				ans=max(ans,ct+1);
	 			}
	 			if(e[cnt].l-2>=0)
	 			{
	 				ans=max(ans,ct+2);
	 			}
	 			if((e[cnt].l-1>=0)&&(e[cnt].r+1<a.length()))
	 			{
	 				ans=max(ans,ct+2);
	 			}
	 		}
	 		else
	 		{
	 			i++;
	 		}
	 	}
	 	
	 
	 	for(int i=1;i<=cnt;i++)
	 	{
	 		if(i+1>cnt) break;
	 		int des=e[i+1].l-e[i].r;
	 		if(des==2)
	 		{
	 		int now1=e[i].len+e[i+1].len;
	 		now1++; 
	 		ans=max(ans,now1);
	 		
	 		int left=e[i].l-1;
			 int right=e[i+1].r+1;
			 if((left>=0)&&(right<a.length()))
	    	{
	    		ans=max(ans,now1+1);
	    	}
	    	else if(left>=0)
	    	{
	    		ans=max(ans,now1+1);
	    	}
	    	else if(right<a.length())
	    	{
	    		ans=max(ans,now1+1);
	    	} 
	 		if(i-1>=1)
	 		{   int dess=e[i].l-e[i-1].r;
			   if(dess==2)
			   { 
			   int now2;
	 			now2=now1+e[i-1].len;
	 			now2++;
	 			ans=max(ans,now2);
	 		   }
	 		}
	 		if(i+2<=cnt)
	 		{    int dess=e[i+2].l-e[i+1].r;
	 		    if(dess==2)
	 		    {
			    int now2;
	 			now2=now1+e[i+2].len;
	 			now2++;
	 			ans=max(ans,now2);
	 		    }
	 		}
	 	    }
	 	    else if(des==3)
	 	    {
	 	    	int now1=e[i].len+e[i+1].len+2;
	 	    	ans=max(ans,now1);
	 	    }
	 	   // if(ans==14) {cout<<i<<" "<<e[i].len<<endl;}
	 	}
	 	if(cnt==0)
	 	{
	 		if(a.length()>=2) ans=max(ans,2);
	 		if(a.length()>=1) ans=max(ans,1);
	 	}
	 	printf("%d\n",ans); 
	 	
     }
     
     
     return 0;
}
