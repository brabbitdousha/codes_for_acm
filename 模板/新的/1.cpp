 c++�����У�multiset��<set>����һ���ǳ����õ����ͣ������Կ���һ�����У�����һ������ɾ��һ�������ܹ���O(logn)��ʱ������ɣ���������ʱ�̱�֤�����е���������ģ����������п��Դ����ظ�������
�����Զ������͵����ݣ�
��ֻ��int���ͣ�multiset�����Դ洢�������������� string���ͣ��ṹ(struct��class)���͡�������һ���ڱ�̵������������⾭���õ��Զ�������ͣ���struct��class��������������ӣ�

struct rec{
    int x,y;
};
multiset<rec>h;
�������ϵĴ�����û���κ��ô��ģ���Ϊmultiset����֪�����ȥ�Ƚ�һ���Զ�������͡���ô���أ����ǿ��Զ���multiset����rec���ͱ���֮���С�ڹ�ϵ�ĺ��壨������xΪ��һ�ؼ���Ϊ����������������£�

����һ���Ƚ���cmp��cmp�ڲ���operator�����������ǱȽ�rec����a��b�Ĵ�С(��xΪ��һ�ؼ��֣�yΪ�ڶ��ؼ���)��

struct cmp{
    bool operator()(const rec&a,const rec&b){
        return a.x<b.x||a.x==b.x&&a.y<b.y;
    }
};
 Ȼ�����"multiset<rec>h ;���ĳ�"multiset<rec,cmp>h;"�����Ժ����Ǿ͸���������h���ȥ�Ƚ������Ԫ��(���������)

��ʱrec�Լ�multiset�Ķ��岿����������ɲο����£�

struct rec{
    int x,y;
};
struct cmp{
    bool operator()(const rec&a,const rec&b){
        return a.x<b.x||a.x==b.x&&a.y<b.y;
    }
};
multiset<rec,cmp>h;��״�����������
#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) x&(-x)
using namespace std;
const int maxn=5e5+100;
ll a[maxn],tree[maxn],n;//ע��������ݹ��� Ҫ��ɢ��
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