 c++语言中，multiset是<set>库中一个非常有用的类型，它可以看成一个序列，插入一个数，删除一个数都能够在O(logn)的时间内完成，而且他能时刻保证序列中的数是有序的，而且序列中可以存在重复的数。
放入自定义类型的数据：
不只是int类型，multiset还可以存储其他的类型诸如 string类型，结构(struct或class)类型。而我们一般在编程当中遇到的问题经常用到自定义的类型，即struct或class。例如下面的例子：

struct rec{
    int x,y;
};
multiset<rec>h;
不过以上的代码是没有任何用处的，因为multiset并不知道如何去比较一个自定义的类型。怎么办呢？我们可以定义multiset里面rec类型变量之间的小于关系的含义（这里以x为第一关键字为例），具体过程如下：

定义一个比较类cmp，cmp内部的operator函数的作用是比较rec类型a和b的大小(以x为第一关键字，y为第二关键字)：

struct cmp{
    bool operator()(const rec&a,const rec&b){
        return a.x<b.x||a.x==b.x&&a.y<b.y;
    }
};
 然后将语句"multiset<rec>h ;”改成"multiset<rec,cmp>h;"这样以后，我们就告诉了序列h如何去比较里面的元素(重载运算符)

此时rec以及multiset的定义部分完整代码可参考如下：

struct rec{
    int x,y;
};
struct cmp{
    bool operator()(const rec&a,const rec&b){
        return a.x<b.x||a.x==b.x&&a.y<b.y;
    }
};
multiset<rec,cmp>h;树状数组求逆序对
#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) x&(-x)
using namespace std;
const int maxn=5e5+100;
ll a[maxn],tree[maxn],n;//注意如果数据过大 要离散化
ll b[maxn]; 
void add(ll x,ll d)
{
	while(x<=n)
	{
		tree[x]+=d;
		x+=lowbit(x);
	}
}
ll getsum(ll x)
{
	ll sum=0;
	while(x>0)
	{
		sum+=tree[x];
		x-=lowbit(x);
	}
	return sum;
}
bool cmp1(const int &x,const int &y)
{
	return b[x]<b[y];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
	 scanf("%lld",&b[i]);
	 a[i]=b[i];
    }
    sort(b+1,b+1+n);
    int tt=unique(b+1,b+1+n)-b-1;
	ll res=0;
	for(int i=1;i<=n;i++)
	{  a[i]=lower_bound(b+1,b+1+tt,a[i])-b;
	//cout<<a[i]<<" ";
    } //cout<<endl;
	for(ll i=1;i<=n;i++)
	{
		add(a[i],1);
		res+=(i-getsum(a[i]));
	}
	cout<<res;
	return 0;
}