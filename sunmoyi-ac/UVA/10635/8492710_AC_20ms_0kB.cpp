//
// Created by 孙启龙 on 2017/3/19.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 250 * 251
#define INF 0x3f3f3f3f

using namespace std;

int S[maxn], g[maxn], d[maxn];
int num[maxn];

int main (void)
{
    int T;
    scanf("%d", &T);
    for(int Case = 1; Case <= T; Case++)
    {
        int N, p, q, x;
        scanf("%d %d %d", &N ,&p, &q);
        memset(num, 0, sizeof(num));
        for(int i = 1; i <= p + 1; i++)
        {
            scanf("%d", &x);
            num[x] = i;
        }
        int n = 0;
        for(int i = 0; i < q + 1; i++)
        {
            scanf("%d", &x);
            if(num[x])
                S[n++] = num[x];
        }

        for(int i = 1; i <=n; i++)
            g[i] = INF;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int k = lower_bound(g + 1, g + n + 1, S[i]) - g;
            d[i] = k;
            g[k] = S[i];
            ans = max(ans, d[i]);
        }
        printf("Case %d: %d\n", Case, ans);
    }
    return 0;
}