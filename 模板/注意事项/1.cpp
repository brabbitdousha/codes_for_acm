vector<int> a;
 
void Input() {
	cin >> n >> s >> k; a.clear(); a.resize(k);
	for (auto &z: a) cin >> z;
}
进a里面去了
find(a.begin(), a.end(), s-i) == a.end()
神奇STL们
lower_bound(起始地址，结束地址，要查找的数值) 返回的是数值 第一个 出现的位置。

upper_bound(起始地址，结束地址，要查找的数值) 返回的是数值 最后一个 出现的位置。
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
	int hh=upper_bound(p+1,p+1+cnt,hehe)-p;//直接减p才是大于hehe的真实下标。 或者你就不要用数组从1开始
	cout<<p[hh];
	return 0;
}

map遍历方式
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
set遍历方式
int main(int argc, char* argv[])
{
    set<int> st;

    // 在容器中插入元素
    st.insert(4);
    // 任意位置插入一个元素
    set<int>::iterator it = st.begin();
    st.insert(it, 2);

    // 遍历显示
    for (it = st.begin(); it != st.end(); it++)
        cout << *it << " "; // 输出：2 4
    cout << endl;

    return 0;
}
向上取整，向下取整，四舍五入
在C++的头文件中有floor()和ceil()函数。在STL中还有round()函数。这三个函数的作用如下：

函数名称	函数说明   
floor()	不大于自变量的最大整数 向下取整
ceil()	不小于自变量的最大整数 向上取整
round()  	四舍五入到最邻近的整数 
                         

 

 


 

（1） floor()会取不大于自变量的最大整数的
（2） ceil()会取不小于自变量的最大整数
（3） round()函数，才是我们需要的四舍五入的函数，因为它会返回离自变量最近的整数，这个返回的整数可能大于也可能小于原来的数，但是一定是离它最近的那个整数。重载运算符和优先队列的问题

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
输出结果
6 80,  8 20,   10 100,   12 60,   14 40,
(14,40) (12,60) (10,100) (8,20) (6,80)字符数组读入问题
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

这样可以遍历map
map pair用法
 map< pair<string,string> ,int >a;
   if(a[make_pair(s1,s2)] == 0)字符串相关
 string的find函数
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
给一个范围，找一个数，每位数字都不同

大佬的stl水平高啊。。顺便学一下stingstream
头文件 
//
＃i nclude <iostream> 
＃i nclude <sstream> 
＃i nclude <string> 
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
在一个串里面找指定单词出现次数
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
putchar()学习
putchar(' ');
for(int j=0;j<k;j++)
putchar ("  ----- --"[c[i]-'0']);

strcpy（x，y） 将y数组的值赋给x数组（仅限char）
 strcat（x，y） x数组的值变为x数组后面紧跟y数组（仅限char）
 strcmp（x，y） 比较2个数组，如果ASCII码表值不一样，值小的那个数组小，
如果值都一样，长度不一样，短的小。如果x数组小于y，返回1，反之，返回-1，
相等，返回0.（仅限char）
