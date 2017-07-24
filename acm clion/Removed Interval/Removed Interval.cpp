//
// Created by 孙启龙 on 2017/7/21.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100110

using namespace std;

int n, L;
int a[maxn], g[maxn];
int lis[maxn], flis[maxn];

int solve()
{
    memset(g, 0x3f, sizeof(g));
    for(int i = n - 1; i >= 0; i--)
    {
        int k = lower_bound(g + 1, g + n + 1, -a[i]) - g;
        flis[i] = k;
        g[k] = -a[i];
    }
    memset(g, 0x3f, sizeof(g));
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(i - L > 0)
            g[lower_bound(g + 1, g + n + 1, a[i - L - 1]) - g] = a[i - L - 1];
        lis[i] = lower_bound(g + 1, g + n + 1, a[i]) - g;
        if(i - L >= 0)
            ans = max(ans, lis[i] + flis[i] - 1);
    }
    if(n > L)
        ans = max(ans, (int)(lower_bound(g + 1, g + n + 1, a[n - L - 1]) - g));
    return ans;
}

int main (void)
{
    int T, Case = 0;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &L);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        printf("Case #%d: %d\n", ++Case, solve());
    }
    return 0;
}