//
// Created by 孙启龙 on 2017/7/20.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#define maxn 100010

using namespace std;

int dp[maxn][50], a[maxn], n, q;

void st()
{
    for(int j = 1; (1 << j) <= n; j++)
        for(int i = 1; (i + (1 << j) - 1) <= n; i++)
            dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
}

int query(int l, int r)
{
    int len = r - l + 1;
    int k = 0;
    while((1 << (k + 1)) <= len)
        k++;
    return min(dp[l][k], dp[r - (1 << k) + 1][k]);
}

int brinary_search(int l, int r, int res)
{
    int s = r + 1;
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        if(query(l, mid) <= res)
            r = mid - 1, s = mid;
        else
            l = mid + 1;
    }
    return s;
}

int main (void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]), dp[i][0] = a[i];
        st();
        scanf("%d", &q);
        for(int i = 1; i <= q; i++)
        {
            int x, y, L, R;
            scanf("%d %d", &x, &y);
            int res = a[x];
            L = x + 1, R = y;
            while(L <= R && res)
            {
                L = brinary_search(L, R, res);
                if(L <= R)
                {
                    res %= a[L];
                    L++;
                }
            }
            printf("%d\n", res);
        }
    }
    return 0;
}