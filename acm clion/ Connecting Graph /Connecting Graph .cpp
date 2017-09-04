//
// Created by 孙启龙 on 2017/8/2.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 100010

using namespace std;

int father[maxn], size[maxn], numl[maxn], numr[maxn], op[maxn], ans[maxn];
vector<pair<int , int> >query[maxn];
vector<int>G[maxn];
int n, m;

void init()
{
    memset(ans, 0xff, sizeof(ans));
    for(int i = 1; i <= n; i++)
        G[i].clear(), query[i].clear(), father[i] = i, size[i] = 1, G[i].push_back(i);
}

int find(int x)
{
    return x == father[x]? x: father[x] = find(father[x]);
}

void unoin(int x, int y, int t)
{
    x = find(x);
    y = find(y);
    if(x != y)
    {
        if(size[x] > size[y])
            swap(x, y);
        for(int i = 0; i < G[x].size(); i++)
        {
            int now = G[x][i];
            pair<int, int>next;
            for(int j = 0; j < query[now].size(); j++)
            {
                next = query[now][j];
                if(find(next.first) == y && ans[next.second] == -1 && t < next.second)
                    ans[next.second] = t;
            }
            G[y].push_back(G[x][i]);
        }
        size[y] += size[x];
        father[x] = y;
    }
}

int main (void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &m);
        init();
        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d %d", &op[i], &numl[i], &numr[i]);
            if(op[i] == 2 && numl[i] == numr[i])
                ans[i] = 0;
            else if(op[i] == 2)
                query[numl[i]].push_back(make_pair(numr[i], i)),
                query[numr[i]].push_back(make_pair(numl[i], i));
        }
        for(int i = 1; i <= m; i++)
            if (op[i] == 1)
                unoin(numl[i], numr[i], i);
        for(int i = 1; i <= m; i++)
            if(op[i] == 2)
                printf("%d\n", ans[i]);
    }
}