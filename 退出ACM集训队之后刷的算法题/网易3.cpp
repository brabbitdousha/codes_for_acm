#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<string,int> mp[2500];
string a[2500];
string b[10][25];
map<string,int> check;
int main()
{
	b[1][1]="1W"; b[1][2]="4W"; b[1][3]="7W"; b[1][4]="2B"; b[1][5]="5B"; b[1][6]="8B"; b[1][7]="3T"; b[1][8]="6T"; b[1][9]="9T";
	b[2][1]="1W"; b[2][2]="4W"; b[2][3]="7W"; b[2][4]="2T"; b[2][5]="5T"; b[2][6]="8T"; b[2][7]="3B"; b[2][8]="6B"; b[2][9]="9B";
	b[3][1]="1T"; b[3][2]="4T"; b[3][3]="7T"; b[3][4]="2W"; b[3][5]="5W"; b[3][6]="8W"; b[3][7]="3B"; b[3][8]="6B"; b[3][9]="9B";
	b[4][1]="1T"; b[4][2]="4T"; b[4][3]="7T"; b[4][4]="2B"; b[4][5]="5B"; b[4][6]="8B"; b[4][7]="3W"; b[4][8]="6W"; b[4][9]="9W";
	b[5][1]="1B"; b[5][2]="4B"; b[5][3]="7B"; b[5][4]="2T"; b[5][5]="5T"; b[5][6]="8T"; b[5][7]="3W"; b[5][8]="6W"; b[5][9]="9W";
	b[6][1]="1B"; b[6][2]="4B"; b[6][3]="7B"; b[6][4]="2W"; b[6][5]="5W"; b[6][6]="8W"; b[6][7]="3T"; b[6][8]="6T"; b[6][9]="9T";
	int cnt=0;
	for(int i=1;i<=6;i++)
	{
		for(int j=1;j<=3;j++)
		{
			for(int num1=1;num1<=9;num1++)
			{  
				for(int num2=1;num2<=9;num2++)
				{ if(num1==num2) continue;
				cnt++; 
				for(int kk=1;kk<=9;kk++)
				{ 
					if(kk==num1) continue;
					if(kk==num2) continue;
					string temp=b[i][kk];
					
					//if(i==4) cout<<temp<<" ";
					mp[cnt][temp]=1;
				}
			    }
				//cout<<endl;
			}
		}
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{   check.clear(); int flag=1;
		for(int i=1;i<=7;i++)
		{cin>>a[i];check[a[i]]++;if(check[a[i]]!=1) flag=0;}
		if(flag==0) {printf("NO\n");continue;} 
		int ct=0;
		flag=0;
		for(int kk=1;kk<=cnt;kk++)
		{
			ct=0;
		for(int i=1;i<=7;i++)
		{
			if(mp[kk][a[i]]==1)
			{
				ct++;
			}
		}
		
		if(ct==7) {flag=1;break;}
	    }
	    if(flag==0) printf("NO\n");
	    else printf("YES\n");
	}
	return 0;
}
