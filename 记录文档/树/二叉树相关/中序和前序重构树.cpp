#include<bits/stdc++.h>
using namespace std;
int n;
int a[40],b[40]; 
//int ans[40];
vector<int> ans;
int cnt=0;
struct node
{
	int l,r;
}e[40];
int dfs(int x,int y,int l,int r)
{   if(x>y) return 0;
	int k;
	for(int i=x;i<=y;i++) 
	{
		if(a[i]==b[l]) k=i;
	}
	//ans[++cnt]=b[r];	
	//printf("%d ",b[r]);	
	e[b[l]].l=dfs(x,k-1,l+1,l+k-x);
	e[b[l]].r=dfs(k+1,y,l+k-x+1,r);
	return b[l];
}
void bfs(int rt)
{   queue<int> que;
que.push(rt);
    while(!que.empty())
    {
    	int now=que.front();
    	que.pop();
    	if(now==0) break;
    	ans.push_back(now);
    	//cout<<"1"<<endl;
    	if(e[now].l!=0) {que.push(e[now].l);}
    	if(e[now].r!=0) {que.push(e[now].r);}
    }
    for(int i=0;i<ans.size();i++)
    {
    	cout<<ans[i];if(i!=ans.size()-1) cout<<" ";
    }
}
int main()
{  // int nn;
cin>>n;

     for(int i=1;i<=n;i++) scanf("%d",&a[i]);
      for(int i=1;i<=n;i++) scanf("%d",&b[i]);

     //for(int i=1;i<=n;i++) scanf("%c",&a[i]);
     //for(int i=1;i<=n;i++) scanf("%c",&b[i]);
	//scanf("%s %s",a+1,b+1);
	//int n=strlen(a+1);	
	dfs(1,n,1,n); int rt=b[1];
	bfs(rt);

	
	//printf("Preorder: ");
	//for(int i=1;i<=cnt;i++) {cout<<ans[i];if(i!=cnt) cout<<" ";}
	return 0;
}
