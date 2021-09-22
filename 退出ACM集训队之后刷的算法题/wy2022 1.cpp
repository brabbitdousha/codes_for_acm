#include<bits/stdc++.h>
#define ll long long
using namespace std;
string get2(int val)
{
	int now=val;
	string result="";
	while(now)
	{
		if(now%2==1) result+='1';
		else result+='0';
		now=now/2;
	}
	reverse(result.begin(),result.end());
	return result;
}
int res[1000];
int cnt=0;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x;  cnt=0;
		scanf("%d",&x);
		string now="";
		int hehe=x;
		
		while(hehe)
		{
			int num=hehe%10;
			cnt++;
			res[cnt]=num;
			hehe=hehe/10;
		}
		for(int i=cnt;i>=1;i--)
		{
			if(res[i]==0) now+='0';
			else now+=get2(res[i]);
		}
		//cout<<endl;
		string tmp2="";
		int pos=0;
	//	cout<<"after 拆数字"<<now<<endl;
		reverse(now.begin(),now.end());
	//	cout<<"after 反转"<<now<<endl;
		while((now[pos]=='0')&&pos<now.length())
		{
			pos++;
		}
		for(int i=pos;i<now.length();i++) tmp2+=now[i];
		//cout<<"after 去0  "<<tmp2<<endl; 
		string aa="";
		for(int i=0;i<tmp2.length();)
		{
			if(tmp2[i]=='1')
			{
				aa+='1';
				while(tmp2[i]=='1'&&i<tmp2.length())
				{
					i++;
				}
			}
			else if(tmp2[i]=='0')
			{
				aa+='0';
				while(tmp2[i]=='0'&&i<tmp2.length())
				{
					i++;
				}
			}
		}
		cout<<aa<<"\n";
	}
     return 0;
}
