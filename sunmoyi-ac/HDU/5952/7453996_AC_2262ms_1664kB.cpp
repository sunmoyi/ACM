/*
n dian m bian qiu n ge dian zhong wanquan zitu de shuliang


*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 105;
vector<int> G[N];
int e[N][N];
int n,m,s,ans;

void dfs(int u,int *temp,int size)
{
    if(size == s)
    {
        ans++;
        return;
    }
    for(int i = 0;i < G[u].size();i++)
    {
        int v = G[u][i];
        bool flag = true;
        for(int j = 1;j <= size;j++)
        {
            if(!e[v][temp[j]])
            {
                flag = false;
                break;
            }
        }
        if(flag)//可以加入最大团
        {
            size++;
            temp[size] = v;
            dfs(v,temp,size);
            size--;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&s);

        for(int i = 1;i <= n;i++)
            G[i].clear();
        memset(e,0,sizeof(e));

        int u,v;
        for(int i = 1;i <= m;i++)
        {
            scanf("%d%d",&u,&v);
            if(u > v)
                swap(u,v);
            G[u].push_back(v);
            e[u][v] = e[v][u] = 1;
        }
        ans = 0;
        for(int i = 1;i <= n;i++)
        {
            int temp[N];
            temp[1] = i;
            dfs(i,temp,1);
        }
        printf("%d\n",ans);
    }
}
