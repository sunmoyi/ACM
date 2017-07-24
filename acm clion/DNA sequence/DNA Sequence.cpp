//
// Created by 孙启龙 on 2017/4/5.
//

#include<queue>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define N 101
#define mod 100000
using namespace std;
typedef long long ll;
struct trie
{
    int fail,next[4];
    bool is;
}tr[N];
struct matrix
{
    ll a[N][N];
}In,T,ans;
queue<int>q;
char str[20];
int tot;
int in(char ch)
{
    switch(ch)
    {
        case'A':return 0;
        case'G':return 1;
        case'C':return 2;
        case'T':return 3;
    };
}
matrix mul(matrix x,matrix y)
{
    matrix ret;
    int i,j,k;
    for(i=1;i<=tot;i++)
        for(j=1;j<=tot;j++)
            for(k=1,ret.a[i][j]=0;k<=tot;k++)
                ret.a[i][j]=(ret.a[i][j]+x.a[i][k]*y.a[k][j])%mod;
    return ret;
}
matrix pow(matrix x,ll y)
{
    matrix ret=In;
    while(y)
    {
        if(y&1)
            ret=mul(ret,x);
        x=mul(x,x);
        y>>=1;
    }
    return ret;
}
void insert(int root,char *s)
{
    int index,p=root;
    while(*s!='\0')
    {
        index=in(*s);
        if(tr[p].next[index]==0)
            tr[p].next[index]=++tot;
        p=tr[p].next[index];
        s++;
    }
    tr[p].is=1;
}
void build(int root)
{
    q.push(root);
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            if(tr[p].next[i])
            {
                if(p==root) tr[tr[p].next[i]].fail=root;
                else
                {
                    int temp=tr[p].fail;
                    while(temp)
                    {
                        if(tr[temp].next[i])
                        {
                            tr[tr[p].next[i]].fail=tr[temp].next[i];
                            tr[tr[p].next[i]].is|=tr[tr[temp].next[i]].is;
                            break;
                        }
                        temp=tr[temp].fail;
                    }
                    if(temp==0) tr[tr[p].next[i]].fail=root;
                }
                q.push(tr[p].next[i]);
            }
            else
            {
                if(p==root)
                    tr[p].next[i]=root;
                else
                    tr[p].next[i]=tr[tr[p].fail].next[i];
            }
        }
    }
}
void initmat(int root)
{
    int i,j,k;
    for(i=1;i<=tot;i++)
    {
        if(tr[i].is)
            continue;
        for(k=0;k<4;k++)
        {
            if(tr[j=tr[i].next[k]].is)
                continue;
            T.a[i][j]++;
        }
    }
    for(i=1;i<=tot;i++)
        In.a[i][i]=1;
}
int main()
{
    int n,i,j,k;
    ll m,sum;
    scanf("%d%lld",&n,&m);
    for(i=1,tot=1;i<=n;i++)
    {
        scanf("%s",str);
        insert(1,str);
    }
    build(1);
    initmat(1);
    ans=pow(T,m);
    for(i=1,sum=0;i<=tot;i++)
        sum=(sum+ans.a[1][i])%mod;
    printf("%lld",sum);
    return 0;
}