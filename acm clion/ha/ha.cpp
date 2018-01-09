//
// Created by 孙启龙 on 2017/8/2.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 10010

using namespace std;

vector<int>G[maxn];
int father[maxn];
bool vis[maxn];
int qx, qy, ans;

void init()
{
    for(int i = 0; i < maxn; i++)
        G[i].clear();
    memset(vis, false, sizeof(vis));
    for(int i = 0; i < maxn; i++)
        father[i] = i;
}

int find(int x)
{
    if(x != father[x])
        father[x] = find(father[x]);
    return father[x];
}

void LCA(int u)
{
    father[u] = u;vis[u] = true;
    for(int k = 0; k < G[u].size(); k++)
    {
        int v = G[u][k];
        LCA(v);
        father[v] = u;

    }


    if(qx == u && vis[qy])
        ans = find(qy);
    if(qy == u && vis[qx])
        ans = find(qx);
}

int main (void)
{
    printf("%d\n", 1 << 32);
    return 0;
}