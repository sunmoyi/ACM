#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 100005;
int n,m,x,y,num1,num2;
int vis[N],flag = 1;
vector<int> G[N];
void dfs(int x,int k)
{
    if(vis[x])
    {
        if(vis[x] != k)
            flag = 0;
        return;
    }

    if(!flag)
        return;
    vis[x] = k;
    if(k == 1)
        num1++;
    else
        num2++;
    for(int i = 0;i < G[x].size() && flag;i++)
        dfs(G[x][i],-k);
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= m;i++)
    {
        scanf("%d%d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }

    for(int i = 1;i <= n;i++)
    {
        if(!vis[i])
            dfs(i,1);
    }

    if(!flag)
    {
        printf("-1\n");
        return 0;
    }

    printf("%d\n",num1);
    for(int i = 1,j = 1;i <= n;i++)
    {
        if(vis[i] == 1)
        {
            if(j == num1)
                printf("%d\n",i);
            else
                printf("%d ",i);
            j++;
        }
    }

    printf("%d\n",num2);
    for(int i = 1,j = 1;i <= n;i++)
    {
        if(vis[i] == -1)
        {
            if(j == num2)
                printf("%d\n",i);
            else
                printf("%d ",i);
            j++;
        }
    }
    return 0;
}
