//
// Created by 孙启龙 on 2017/7/26.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

long long num[maxn];
long long lisan[maxn];
long long c[maxn];
long long c1[maxn], c2[maxn];
int n;

int lowbit(int x)
{
    return x & (-x);
}

void update(int x, int val)
{
    for(;x < maxn; x += lowbit(x))
        c[x] += val;
}

int query(int x)
{
    int ans = 0;
    for(; x >= 1; x -= lowbit(x))
        ans += c[x];
    return ans;
}

int main (void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &num[i]), lisan[i] = num[i];
    sort(lisan + 1, lisan + n + 1);
    int nn = unique(lisan + 1, lisan + n + 1) - lisan - 1;
    for(int i = 1; i <= n; i++)
        num[i] = lower_bound(lisan + 1, lisan + n + 1, num[i]) - lisan;

    memset(c, 0, sizeof(c));
    for(int i = 1; i <= n; i++)
    {
        c1[i] = query(nn - num[i]);
        update (nn - num[i] + 1, 1);
    }
    memset(c, 0, sizeof(c));
    for(int i = n; i >= 1; i--)
    {
        c2[i] = query(nn - num[i]);
        update(nn - num[i] + 1, 1);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++)
        if(max(c1[i], c2[i]) > 2 * min(c1[i], c2[i]))
            ans++;
    printf("%d\n", ans);
    return 0;
}