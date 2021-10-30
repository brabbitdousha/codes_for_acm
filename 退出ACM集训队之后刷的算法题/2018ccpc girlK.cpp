#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int rank;
		string num;
		int prob;
		string status;
		int x;
		
		scanf("%d",&rank);
		cin>>num;
		scanf("%d",&prob);
		cin>>status;
		if(status=="Running") scanf("%d",&x);
		printf("%3d|",rank);
		cout<<num;
		for(int i=1;i<=16-num.size();i++) printf(" ");
		printf("|%d|",prob);
		if(status=="Running")
		{
			printf("[");
			for(int i=1;i<=10;i++) 
			{
			  if(i<=x)
			 printf("X");
			 else printf(" ");
		    }
		    printf("]");
			
		}
		else if(status=="FB")
		{
			printf("[");
				for(int i=1;i<=10;i++) 
			{
			  if(i==5)
			 {printf("AC*");i=7;}
			 else {printf(" ");}
		    }
		    printf("]");
		    
		}
		else
		{
			printf("[");
			int sz=status.size();
			for(int i=1;i<=4;i++) printf(" ");
			cout<<status;
			for(int i=1;i<=6-sz;i++) printf(" ");
			printf("]");
		}
		 printf("\n");
	}
	return 0;
}
