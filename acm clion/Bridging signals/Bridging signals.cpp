//
// Created by 孙启龙 on 2017/4/22.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
#define maxn 40010

using namespace std;

int dp[maxn], a[maxn];
int n;

int main (void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int ans = 0;
        for(int i = 1; i <= n; i++)
            dp[i] = INF;
        for(int i = 0; i < n; i++)
        {
            int k = (int)(lower_bound(dp + 1, dp + n + 1, a[i]) - dp);
            dp[k] = a[i];
            if(k > ans)
                ans = k;
        }
        printf("%d\n", ans);
    }
    return 0;
}