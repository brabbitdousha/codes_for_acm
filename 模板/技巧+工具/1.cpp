vectorÌ×set
#define fast ios::sync_with_stdio(0);cin.tie(),cout.tie()
using namespace std;
int main()
{   
	string s;
	cin>>s;
	vector<set<int> > pos(26);
	for(int i=0;i<s.length();i++)
	{
		pos[s[i]-'a'].insert(i);
	}
	int q;
	cin>>q;
	int a;
	while(q--)
	{
		cin>>a;
		if(a==1)
		{
			int p;char c;
			cin>>p>>c;
			--p;
			pos[s[p]-'a'].erase(p);
			s[p]=c;
			pos[c-'a'].insert(p);
		}
		else if(a==2)
		{
			int l,r;
			cin>>l>>r;
			l--;
			r--;
			int cnt=0;
			for(int i=0;i<26;i++)
			{
				 set<int>::iterator it=pos[i].lower_bound(l);
				if(it!=pos[i].end()&&*it<=r)cnt++;
			}
			cout<<cnt<<"\n";
		}
	}
	return 0;
}¶þ·ÖµÄ¾«¶ÈÎÊÌâ
double l=0,r=INF;
	for(int i=0;i<100;i++)
	{
		double mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	printf("%.2f\n",floor(r*100)/100);
    }
	return 0;
	
}
lower_boundº¯ÊýÓÃ·¨
	int res=n;
		for(int s=0;sum[s]+S<=sum[n];s++)
		{
			int t=lower_bound(sum+s,sum+n,sum[s]+S)-sum;
			res=min(res,t-s);
		}
		printf("%d\n",res);
	}
	return 0;
}
È»ºó¾ÍÊÇÎÒrÐ´ÁËmaxx+1£¬²ÅÄÜÈÃmaxx½øÈ¥µ±mid£¬£¬‡å¡£¡£¸ß¾«¶ÈÄ£°å
#include <iostream>
#include <cstdio>
#include <cstring>
#define res register int
using namespace std;
const int N=10010;
string sa,sb;
//ÓÃ×Ö·û´®ÐÎÊ½´æ´¢Êý¾Ý 
string add(string sa,string sb)//¸ß¾«¶È¼Ó·¨ 
{
	string ans="";
	int a[N],b[N],c[N];
	int la=sa.length();//µÃµ½saÓÐ¶àÉÙÎ» 
	int lb=sb.length();//µÃµ½sbÓÐ¶àÉÙÎ» 
	memset(a,0,sizeof(a));//³õÊ¼»¯Ò»ÏÂ 
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	for(res i=0;i<la;i++) a[la-i-1]=sa[i]-'0';//°Ñ×Ö·û×ª»¯ÎªÊý×Ö  Í¬Ê±°ÑÊý×Ö·­×ª¹ýÀ´ 
											  //ÕâÑùa[i]¾Í±íÊ¾µÚiÎ» 
	for(res i=0;i<lb;i++) b[lb-i-1]=sb[i]-'0';
	int lc=max(la,lb);//×îºóµÄ½á¹û¾ÍÊÇÁ½¸öµÄ×î´óÖµ 
	for(res i=0;i<lc;i++)
	{
		c[i]+=a[i]+b[i];//¼Ó·¨ 
		if(c[i]>=10) c[i+1]=1,c[i]-=10;//´¦ÀíÒ»ÏÂ½øÎ»µÄÎÊÌâ 
	}
	if(c[lc]>0) lc++;
	for(res i=lc-1;i>=0;i--)
	{
		char tmp=c[i]+'0';
		ans=ans+tmp;//½á¹û 
	}
	return ans;
}

int _compare(string sa,string sb)//±È½ÏÁ½¸öÕýÊýµÄ´óÐ¡ 
{//1´úsa>sb 0´ú±íÏàµÈ -1´ú±ísa<sb 
	int la=sa.length(),lb=sb.length();
	if(la<lb) return -1;//Èç¹û³¤¶È²»Í¬ ÄÇÃ´´óÐ¡¾Í¿ÉÒÔÈ·¶¨ 
	if(la>lb) return 1;
	for(res i=0;i<la;i++)
	{
		char tmpa=sa[i];
		char tmpb=sb[i];
		if(tmpa>tmpb) return 1;
		if(tmpa<tmpb) return -1;
	}
	return 0;
}



string _minus(string sa,string sb,int x)//¸ß¾«¶È¼õ·¨ x´ú±íÊÇ·ñÈ¡¸ººÅ 
{
	string ans="";
	int a[N],b[N],c[N];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	int la=sa.length();
	int lb=sb.length();
	for(res i=0;i<la;i++) a[la-i-1]=sa[i]-'0';
	for(res i=0;i<lb;i++) b[lb-i-1]=sb[i]-'0';//Ç°ÃæÓÐ½âÊÍ 
	int lc=max(la,lb);
	for(res i=0;i<lc;i++)
    {
        if(c[i]+a[i]-b[i]<0)
        {
            c[i+1]--;
            c[i]+=10;
        }//½èÎ»´¦Àí
        c[i]+=a[i]-b[i];
    }
	while(c[lc-1]==0&&lc>0) lc--;//É¾³ýÔÚ×î¿ªÊ¼µÄ0 
	for(res i=lc-1;i>=0;i--)
	{
		char tmp=c[i]+'0';
		ans=ans+tmp;
	} 
	if(x==-1) ans="-"+ans;
	return ans;
}

string _mul(string sa,string sb)
{
	if(sa[0]=='0'||sb[0]=='0') return "0";
	string ans="";
	int a[N],b[N],c[N];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	int la=sa.length();
	int lb=sb.length();
	for(res i=0;i<la;i++) a[la-i-1]=sa[i]-'0';
	for(res i=0;i<lb;i++) b[lb-i-1]=sb[i]-'0';
	for(res i=0;i<la;i++)
		for(res j=0;j<lb;j++)
		{
			int f,w,jw;//iºÍjÎ»Ïà³Ë´æ´¢ÔÚ´ð°¸µÄi+jÎ»µ±ÖÐ 
			f=a[i]*b[j]; jw=f/10; f=f%10;w=i+j;//jw±íÊ¾½øÎ» f±íÊ¾½øÎ»ºóÊ£ÏÂµÄÊý 
			c[w]=c[w]+f;jw+=c[w]/10;c[w]=c[w]%10;
			c[w+1]=c[w+1]+jw;
		}
	int lc=la+lb;
	while(c[lc-1]==0&&lc>0) lc--;//Ç°ÃæÓÐ½âÊÍ 
	for(res i=lc-1;i>=0;i--)
	{
		char tmp=c[i]+'0';
		ans=ans+tmp;
	}
	return ans;
}

int main()
{
//	freopen("test.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin>>sa>>sb;
//ÔÚ×ö¼õ·¨Ö®Ç° ÒªÏÈ±È½ÏÄÄÒ»¸öÊý¸ü´ó 
   if(_compare(sa,sb)==1) cout<<_minus(sa,sb,1);
	else if(_compare(sa,sb)==-1) cout<<_minus(sb,sa,-1);
	else cout<<"0";

	//cout<<_mul(sa,sb);
	return 0;
} ¼ÆÊ±º¯Êý
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
clock_t start,end;
 
int main(){
	start=clock();		//³ÌÐò¿ªÊ¼¼ÆÊ±
	int ans=0;
	for(int i=1;i<=1e8;i++)
		ans++;
	end=clock();		//³ÌÐò½áÊøÓÃÊ±
	double endtime=(double)(end-start)/CLOCKS_PER_SEC;
	cout<<"Total time:"<<endtime<<endl;		//sÎªµ¥Î»
	cout<<"Total time:"<<endtime*1000<<"ms"<<endl;	//msÎªµ¥Î»
	system("pause");
	return 0;
}
249ms

Å·À­³£Êý
const double r=0.57721566490153286060651209;//Å·À­³£Êý
¹é²¢ÅÅÐò
#include<iostream>
#include<cstdio>
using namespace std;
int n;
int a[40002];
int c[40002];
long long  int p=0;
int read()
{
	int x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
void mergesort(int l,int r)
{
	if(l==r) return;
	int m=(l+r)/2;
	mergesort(l,m);
	mergesort(m+1,r);
	int i=l,j=m+1,k=l;
	while(i<=m&&j<=r)
	{
	 if(a[i]>a[j])
	 {p+=m-i+1;
	 	c[k++]=a[j++];
	 	
	 }
	 else{
	 	c[k++]=a[i++];
	 }
	}
	while(i<=m){c[k]=a[i];i++;k++;}
	while(j<=r){c[k]=a[j];j++;k++;}
	for(int w=l;w<=r;w++) a[w]=c[w];
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	mergesort(1,n);
	printf("%d",p);
	return 0;
}
Ç°×ººÍ
Ò»Î¬
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+9;
int a[maxn],b[maxn];
int main(){
	int i,j,k,n,m,p;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) {b[i]=a[i]-a[i-1];}
	for(i=1;i<=m;i++){
		int L,R,t;
		cin>>t>>L>>R>>p;
		if(t==1){
			b[L]+=p;b[R+1]-=p; //×ÐÏ¸ÏëÏëÎªÊ²Ã´b[R+1]Òª¼õÈ¥p 
		}
		else{
			b[L]-=p;b[R+1]+=p;
		}
	}
	int add=0;
	for(i=1;i<=n;i++){
		add+=b[i];
		cout<<add<<" ";
		a[i]=a[i-1]+add;
	}
	cout<<endl;
	int x,y;
	cin>>x>>y;
	cout<<a[y]-a[x-1]<<endl;
}
»òÕß
#include<cstdio>
	int n,m,q;
	int a[100000],d[100000],f[100000],sum[100000];
int main()
{
	int x,y,z;
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		d[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		d[x]+=z;
		d[y+1]-=z;
	}		
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1]+d[i];
		sum[i]=sum[i-1]+f[i];
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d %d",&x,&y);
		printf("%d\n",sum[y]-sum[x-1]);
	}
}
2Î¬
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e3+9;
ll a[maxn][maxn];
ll b[maxn][maxn];
int main(){
	int i,j;
	ll n,m,k,q;
	scanf("%lld %lld %lld %lld",&n,&m,&k,&q);
	//swap(n,m);
	  for(int i=0;i<k;i++)
	  {
    	ll x1,y1,x2,y2,p;
    	p=1;
    	scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
    	//swap(x1,y1);swap(x2,y2);
    	b[x1][y1]+=p;b[x2+1][y2+1]+=p;
    	b[x2+1][y1]-=p;b[x1][y2+1]-=p;
      }
      for(int i=1;i<=n;i++)
      {
      	for(int j=1;j<=m;j++)
      	{
      		b[i][j]+=b[i][j-1]+b[i-1][j]-b[i-1][j-1];
      		a[i][j]=a[i][j-1]+a[i-1][j]-a[i-1][j-1]+b[i][j];
      	}
      }
      		
	for(i=1;i<=q;i++){
		ll x1,y1,x2,y2;
			scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
		//swap(x1,y1);swap(x2,y2);
		ll ans=a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1];
		printf("%lld\n",ans);
	}
	  
}Êä³öµÚ¼¸Ð¡
#include<bits/stdc++.h>
using namespace std;
struct int2{
    int x;
    bool operator <(const int2& a)const{return x>a.x;}
};
priority_queue<int> pq1;
priority_queue<int2> pq2;
int a[1000000],b[1000000];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++)
        scanf("%d",a+i);
    for (int i=0;i<m;i++){
        int x;
        scanf("%d",&x);
        b[x-1]++;
    }
    for (int i=0;i<n;i++){
        if (pq1.empty()||(pq1.top()<a[i])) pq2.push((int2){a[i]});
        else{
            int x=pq1.top();
            pq1.pop();
            pq1.push(a[i]);
            pq2.push((int2){x});
        }
        while(b[i]){
            int x=pq2.top().x;pq2.pop();
            printf("%d\n",x);
            pq1.push(x);
            b[i]--;
        }
    }
    return 0;
}01è¡¨
#include<bits/stdc++.h>
using namespace std;
int mp[400000][16];
int main()
{   int m; 
    cin>>m;int cnt=0;int cnt2=0;
    
	for ( int i = ( 1 << m ) - 1 ; i >= 0; i -- )
	{   cnt++;cnt2=0;
		for ( int j = 1; j <= (1 << m) - 1 ; j <<= 1 ) 	
		{
			if ( i & j ) mp[cnt][++cnt2]=1;//printf("1");
			else mp[cnt][++cnt2]=0;//printf("0");
		}
		//printf("\n");
	}
	for(int i=1;i<=pow(2,m);i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<mp[i][j];
		}
		printf("\n");
	}
	return 0;
}äºŒè¿›åˆ¶åŠ æ³•
#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<bitset>
#include<string>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include<functional>
#define INF 0x3f3f3f3f //1061109567
#define llINF 9223372036854775807
#define pi 3.141592653589793
#define ll long long
using namespace std;
string doit(string a,string b)
{
	string ans="";
	if(a.length()<b.length()) swap(a,b);
	int res=0;
	for(int i=0;i<b.length();i++)
	{
		ans+=(char)((a[i]-'0'+b[i]-'0'+res)%2+'0');
		if(a[i]-'0'+b[i]-'0'+res>=2) res=1;
		else res=0;
	}
	for(int i=b.length();i<a.length();i++)
	{
		ans+=(char)((a[i]-'0'+res)%2+'0');
		if((a[i]-'0'+res)>=2) res=1;
		else res=0;
	}
	int n=a.length();
	if(res) {ans+=(char)(res+'0');}
	return ans;	
}		
int main()
{
	string diyi="1";
	string jia="111";
	string ans=doit(diyi,jia);
	int cnt=0;
	int maxn=40;
	for(int i=2;i<=maxn;i++)
	{
	 diyi=ans;
	reverse(ans.begin(),ans.end());
	cout<<ans<<endl;
	if(ans.length()<=65) cnt++;
	else break;
    }
    cout<<cnt;
	return 0;
}Êý¾ÝÉú³ÉÆ÷
#include<bits/stdc++.h>
using namespace std;
int main()
{
	FILE *fp1;
	 srand( (unsigned)time( NULL ) );
    fp1=fopen("data5.txt","w");
    fprintf(fp1,"1000\n");
    for(int i=1000;i>=1;i--)
	{ int num1 = rand() % 100 + 1;
	  int num2= rand() % 100 + 1;
	  if(num1%2==0) num1=-num1;
	  if(rand()%2==0) num2=-num2;
	 fprintf(fp1,"%d %d\n",num1,num2);
    }
    fclose(fp1);
    return 0;
}