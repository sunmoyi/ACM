//
// Created by 孙启龙 on 2017/5/15.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
struct bian {
    int v1, v2;
    int w;
};
int n, m, r;
int f[50010];

bool cmp(const struct bian a, const struct bian b)
{
    return a.w > b.w;
}

void init()
{
    for (int i = 0; i <= 50010; ++i)
        f[i] = i;
}

int getf(int a)
{
    return a == f[a]? a: f[a] = getf(f[a]);
}

int merge(int a, int b)
{
    a = getf(a);
    b = getf(b);
    if (a == b)
        return 0;
    f[a] = b;
    return 1;
}

int main()
{
    int t;
    int ans;
    vector<struct bian> g;
    scanf("%d", &t);
    while (t--) {
        ans = 0;
        g.clear();
        init();
        scanf("%d%d%d", &n, &m, &r);
        for (int i = 0; i < r; ++i)
        {
            struct bian temp;
            scanf("%d%d%d", &temp.v1, &temp.v2, &temp.w);
            temp.v2 += n;
            g.push_back(temp);
            int tmp = temp.v1;
            temp.v1 = temp.v2;
            temp.v2 = tmp;
            g.push_back(temp);
        }
        sort(g.begin(), g.end(), cmp);

        for (int i = 0; i < (int) g.size(); ++i)
        {
            if (merge(g[i].v1, g[i].v2))
            {
                ans += g[i].w;
            }
        }
        printf("%d\n", ((n + m) * 10000 - ans));
    }
    return 0;
}