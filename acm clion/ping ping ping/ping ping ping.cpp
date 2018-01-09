//
// Created by 孙启龙 on 2017/9/24.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include <iostream>

#define maxn 10010

using namespace std;

struct node{
    int u, v, lca;
}qq[maxn * 5];

vector<int>vt[maxn];
int c[maxn << 1];
int in[maxn], out[maxn], deep[maxn], n;
int p[maxn][20];
int tot = 0;

void dfs(int u, int fa, int dep)
{
    in[u] = ++tot;
    deep[u] = dep;
    p[u][0] = fa;
    for(int i = 0; i < vt[u].size(); i++)
    {
        int to = vt[u][i];
        if(to == fa)
            continue;
        dfs(to, u, dep + 1);
    }
    out[u] = ++tot;
}

void init()
{
    for(int j = 1; (1 << j) <= n; j++)
    {
        for(int i = 1; i <= n; i++)
            if(p[i][j - 1] != -1)
                p[i][j] = p[p[i][j - 1]][j - 1];
    }
}

int lca(int a, int b)
{//最近公共祖先
    int i, j;
    if (deep[a] < deep[b])
        swap(a, b);
    for (i = 0; (1 << i) <= deep[a]; i++)
        ;
    i--;
    for (j = i; j >= 0; j--)
        if (deep[a] - (1 << j) >= deep[b])
            a = p[a][j];
    if (a == b)
        return a;
    for (j = i; j >= 0; j--)
    {
        if (p[a][j] != -1 && p[a][j] != p[b][j])
        {
            a = p[a][j];
            b = p[b][j];
        }
    }
    return p[a][0];
}

bool cmp(node a, node b)
{
    return deep[a.lca] > deep[b.lca];
}

int lowbit(int i)
{
    return i & (-i);
}

int sum(int i)
{
    int ans = 0;
    while (i)
    {
        ans += c[i];
        i -= lowbit(i);
    }
    return ans;

}

void change(int i, int k)
{
    while(i <= 2 * n)
    {
        c[i] += k;
        i += lowbit(i);
    }
}

int main (void)
{
    while(scanf("%d", &n) != EOF)
    {
        tot = 0;
        memset(p, 0, sizeof(p));
        memset(c, 0, sizeof(c));
        for(int i = 0; i < maxn; i++)
            vt[i].clear();
        for(int i = 0; i < n; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            u++;
            v++;
            vt[u].push_back(v);
            vt[v].push_back(u);
        }

        n++;
        dfs(1, 1, 1);
        init();
        int q;
        scanf("%d", &q);
        for(int i = 0; i < q; i++)
        {
            scanf("%d %d", &qq[i].u, &qq[i].v);
            qq[i].u++, qq[i].v++;
            qq[i].lca = lca(qq[i].u, qq[i].v);
        }
        sort(qq, qq + q, cmp);
        int ans = 0;
        for(int i = 0; i < q; i++)
        {
            int u = qq[i].u, v = qq[i].v, lc = qq[i].lca;
            if(sum(in[u])-sum(out[lc])+sum(in[v])-sum(out[lc]))
                continue;
            else
            {
                ans++;
                change(in[lc], 1);

                change(out[lc], -1);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}