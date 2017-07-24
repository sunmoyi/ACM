//
// Created by 孙启龙 on 2017/7/18.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100007

using namespace std;

int n, m, a[maxn], degree[maxn];

int main (void)
{
    int T;
    scanf("%d", &T);

    while(T--)
    {
        memset(degree, 0, sizeof(degree));

        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);

        int u, v;
        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d", &u, &v);
            degree[u]++;
            degree[v]++;
        }

        int cnt = 0;
        for(int i = 1; i <= n; i++)
            if(degree[i] & 1)
                cnt++;

        if(cnt != 0 && cnt != 2)
        {
            printf("Impossible\n");
            continue;
        }

        int ans = 0;
        for(int i = 1; i <= n; i++)
            if(((degree[i] + 1) >> 1) & 1)
                ans ^= a[i];

        int maxx = ans;
        if(cnt == 0)
            for(int i = 1; i <= n; i++)
                maxx = max(maxx, maxx ^ a[i]);
        printf("%d\n", maxx);
    }
}