vector<int> a;
 
void Input() {
	cin >> n >> s >> k; a.clear(); a.resize(k);
	for (auto &z: a) cin >> z;
}
��a����ȥ��
find(a.begin(), a.end(), s-i) == a.end()
����STL��
lower_bound(��ʼ��ַ��������ַ��Ҫ���ҵ���ֵ) ���ص�����ֵ ��һ�� ���ֵ�λ�á�

upper_bound(��ʼ��ַ��������ַ��Ҫ���ҵ���ֵ) ���ص�����ֵ ���һ�� ���ֵ�λ�á�
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int p[300];
	int cnt=0;
	p[++cnt]=2;
	p[++cnt]=6;
	p[++cnt]=7;
	p[++cnt]=20;
	int hehe=8;
	int hh=upper_bound(p+1,p+1+cnt,hehe)-p;//ֱ�Ӽ�p���Ǵ���hehe����ʵ�±ꡣ ������Ͳ�Ҫ�������1��ʼ
	cout<<p[hh];
	return 0;
}

map������ʽ
int main()
{
	map<char,int> ma;
	ma['A']=0;ma['B']=0;ma['C']=0;	ma['D']=0;
		ma['E']=0;	ma['F']=0;	ma['G']=0;	ma['H']=0;
			ma['I']=0;	ma['J']=0;	ma['K']=0;	ma['L']=0;
				ma['M']=0;	ma['N']=0;	ma['O']=0;ma['P']=0;
		ma['Q']=0;	ma['R']=0;	ma['S']=0;	ma['T']=0;	ma['U']=0;
			ma['V']=0;ma['W']=0;ma['X']=0;	ma['Y']=0;	ma['Z']=0;
	string a;
	getline(cin,a);
	for(int i=0;i<a.length();i++)
	{    ma[a[i]]++;}
	map<char, int>::const_iterator it; 
	for (it = ma.begin(); it != ma.end(); ++it)
        cout << it->first << "=" << it->second << endl; 
	 return 0;
}
set������ʽ
int main(int argc, char* argv[])
{
    set<int> st;

    // �������в���Ԫ��
    st.insert(4);
    // ����λ�ò���һ��Ԫ��
    set<int>::iterator it = st.begin();
    st.insert(it, 2);

    // ������ʾ
    for (it = st.begin(); it != st.end(); it++)
        cout << *it << " "; // �����2 4
    cout << endl;

    return 0;
}
����ȡ��������ȡ������������
��C++��ͷ�ļ�����floor()��ceil()��������STL�л���round()�������������������������£�

��������	����˵��   
floor()	�������Ա������������ ����ȡ��
ceil()	��С���Ա������������ ����ȡ��
round()  	�������뵽���ڽ������� 
                         

 

 


 

��1�� floor()��ȡ�������Ա��������������
��2�� ceil()��ȡ��С���Ա������������
��3�� round()����������������Ҫ����������ĺ�������Ϊ���᷵�����Ա��������������������ص��������ܴ���Ҳ����С��ԭ������������һ��������������Ǹ���������������������ȶ��е�����

using namespace std;
struct node
{
    int x,y;
    bool operator < (const node & a) const
    {
        return x<a.x;
    }
}k[100];
priority_queue <node> q;
int main()
{
    k[1].x=10,k[1].y=100; q.push(k[1]);
    k[2].x=12,k[2].y=60; q.push(k[2]);
    k[3].x=14,k[3].y=40; q.push(k[3]);
    k[4].x=6,k[4].y=80; q.push(k[4]);
    k[5].x=8,k[5].y=20; q.push(k[5]);
    sort(k+1,k+1+5); 
    for(int i=1;i<=5;i++) cout<<k[i].x<<" "<<k[i].y<<",";
    cout<<endl; 
    while(!q.empty())
    {
        node m=q.top(); q.pop();
        printf("(%d,%d) ",m.x,m.y);
    }
}
������
6 80,  8 20,   10 100,   12 60,   14 40,
(14,40) (12,60) (10,100) (8,20) (6,80)�ַ������������
#include<bits/stdc++.h>
using namespace std;
int main()
{   freopen("a.txt","r",stdin);
    freopen("b.txt","w",stdout);
	char a[200][200];
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%s",a[i]+1);
	for(int i=1;i<=n;i++)
	{for(int j=1;j<=n;j++)
	{printf("%c",a[i][j]);}
	cout<<"\n";
    }
    return 0;
}map
unordered_map<int, long long>::iterator iter = ex[i].begin();
	for (iter; iter != ex[i].end(); iter++) {
		qq[iter->first] += iter->second * visit[i];
                                                              }

�������Ա���map
map pair�÷�
 map< pair<string,string> ,int >a;
   if(a[make_pair(s1,s2)] == 0)�ַ������
 string��find����
int loc1=str.find("[");
            num=0;
            if(loc1!=-1)
            {
                int loc2=str.find("]");
                for(int i=loc1+1;i<loc2;i++)
                {
                    num=num*10+s[i]-'0';
                }
            }
            if(num)tmp*=num;
            ans+=tmp;
       }
       ans=ceil((double)ans/1024);
��һ����Χ����һ������ÿλ���ֶ���ͬ

���е�stlˮƽ�߰�����˳��ѧһ��stingstream
ͷ�ļ� 
//
��i nclude <iostream> 
��i nclude <sstream> 
��i nclude <string> 
//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(),cout.tie()
int main()
{
	fast;
	int l,r,sz;
	string str;
	stringstream ss;
	set<char> ch;
	cin>>l>>r;
	for(int i=l;i<=r;i++)
	{
		ss.clear();
		ch.clear();
		ss<<i;
		ss>>str;
		sz=str.size();
		for(int j=0;j<sz;j++)
		   ch.insert(str[j]);
		   if(ch.size()==sz)
		   {
		   	cout<<i<<"\n";
		   	return 0;
		   }
	}
	cout<<-1<<"\n";
	return 0;
}
��һ����������ָ�����ʳ��ִ���
int main()
{
    string a;string b;
   getline(cin,a);
    getline(cin,b);
    for(int i=0;i<a.length();i++){a[i]=tolower(a[i]);}
    for(int i=0;i<b.length();i++){b[i]=tolower(b[i]);}
    int ans=0;
    a=' '+a+' ';b=' '+b+' ';
    if(b.find(a)==string::npos)
    {cout<<"-1";}
    else {  
    	   int f=b.find(a);int next=b.find(a);
    	   while(next!=string::npos)
    	   {  ++ans;
    	   	  next=b.find(a,next+1);
    	   	  
    	   }
         cout<<ans<<" "<<f;
		 }
		 return 0;
}
putchar()ѧϰ
putchar(' ');
for(int j=0;j<k;j++)
putchar ("  ----- --"[c[i]-'0']);

strcpy��x��y�� ��y�����ֵ����x���飨����char��
 strcat��x��y�� x�����ֵ��Ϊx����������y���飨����char��
 strcmp��x��y�� �Ƚ�2�����飬���ASCII���ֵ��һ����ֵС���Ǹ�����С��
���ֵ��һ�������Ȳ�һ�����̵�С�����x����С��y������1����֮������-1��
��ȣ�����0.������char��
