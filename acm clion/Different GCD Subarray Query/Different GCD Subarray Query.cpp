//
// Created by 孙启龙 on 2017/7/20.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 100010

using namespace std;

int a[maxn], ans[maxn];
vector<pair<int, int> >gc[maxn];
vector<pair<int, int> >query[maxn];
int vis[maxn * 10];
int n, q;

struct SegmentTree{
    int sum[maxn];

    void init()
    {
        memset(sum, 0, sizeof(sum));
    }

    int lowbit(int x)
    {
        return x & (-x);
    }

    void update(int x, int v)
    {
        for(int i = x; i <= n; i += lowbit(i))
            sum[i] += v;
    }

    int getsum(int x)
    {
        int ans =  0;
        for(int i = x; i > 0; i -= lowbit(i))
            ans += sum[i];
        return ans;
    }
}it;

void init()
{
    for(int i = 0; i <= n; i++)
        gc[i].clear(), query[i].clear();
    memset(vis, 0, sizeof(vis));
    it.init();
}

void input()
{
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++)
    {
        int x = a[i];
        int y = i;
        for(int j = 0; j < gc[i - 1].size(); j++)
        {
            int res = __gcd(gc[i - 1][j].first, x);
            if(x != res)
            {
                gc[i].push_back(make_pair(x, y));

                x = res;
                y = gc[i - 1][j].second;
            }
        }
        gc[i].push_back(make_pair(x, y));
    }

    for(int i = 1; i <= q; i++)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        query[r].push_back(make_pair(l, i));
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < gc[i].size(); j++)
        {
            int res = gc[i][j].first;
            int ind = gc[i][j].second;

            if(vis[res])
                it.update(vis[res], -1);
            vis[res] = ind;
            it.update(ind, 1);
        }
        for(int j = 0; j < query[i].size(); j++)
        {
            int l = query[i][j].first;
            int ind = query[i][j].second;

            ans[ind] = it.getsum(i) - it.getsum(l - 1);
        }
    }
    for(int i = 1; i <= q; i++)
        printf("%d\n", ans[i]);
}

int main (void)
{
    while(scanf("%d %d", &n, &q) != EOF)
    {
        init();
        input();
    }
    return 0;
}