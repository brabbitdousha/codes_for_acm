#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#define ll long long
using namespace std;
typedef struct node* tree;
typedef struct node
{
    int data;
    int height;
    tree left;
    tree right;
};
tree que[40];
int tail=0,head=0;
int max(int a,int b)
{
    return a>b? a:b;
}
int getHeight(tree t)
{
    if(t==NULL) { return -1;}
    else return t->height;
}
tree LL(tree K)
{
    tree tmp;
    tmp=K;
    K=K->left;
    tmp->left=K->right;
    K->right=tmp;
    tmp->height=max(getHeight(tmp->left),getHeight(tmp->right))+1;
    K->height=max(getHeight(K->left),getHeight(K->right))+1;
    return K;
}
tree RR(tree K)
{
    tree tmp;
    tmp=K;
    K=K->right;
    tmp->right=K->left;
    K->left=tmp;
    tmp->height=max(getHeight(tmp->left),getHeight(tmp->right))+1;
    K->height=max(getHeight(K->left),getHeight(K->right))+1;
    return K;
}
tree LR(tree K)
{
    K->left=RR(K->left);
    return LL(K);
}
tree RL(tree K)
{
    K->right=LL(K->right);
    return RR(K);
}
tree insert(tree AVL,int x)
{
    if(AVL==NULL)
    {
        AVL=(tree)malloc(sizeof(tree));
        AVL->data=x;
        AVL->height=0;
        AVL->left=NULL;
        AVL->right=NULL;
    }
    else if(x<AVL->data)
    {
        AVL->left=insert(AVL->left,x);
        if(getHeight(AVL->left)-getHeight(AVL->right)==2)
        {
            if(x>AVL->left->data)
            {
                AVL=LR(AVL);
            }
            else
            {
                AVL=LL(AVL);
            }
            
        }
    }
    else
    {
        AVL->right=insert(AVL->right,x);
        if(getHeight(AVL->right)-getHeight(AVL->left)==2)
        {
            if(x>AVL->right->data)
            {
                AVL=RR(AVL);
            }
            else
            {
                AVL=RL(AVL);
            }
            
        }
    }
    AVL->height=max(getHeight(AVL->left),getHeight(AVL->right))+1;
    return AVL;
}
int main()
{
    int n;
    tree AVL=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int temp;
        scanf("%d",&temp);
        AVL=insert(AVL,temp);
    }
    cout<<AVL->data;
    return 0;
}
