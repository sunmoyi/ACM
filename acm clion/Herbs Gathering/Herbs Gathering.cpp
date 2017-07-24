//
// Created by 孙启龙 on 2017/7/18.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110

using namespace std;

struct data{
    long long w, val;
    bool operator < (const data&tp)const{
        return val * tp.w > tp.val * w;
    }
}pk[maxn];

int n;
long long sum[maxn], sw[maxn], lim;
long long ans;

void dfs(int d, long long w, long long val)
{
    if(val > ans)
        ans = val;
    if(d >= n)
        return;
    if(val + (double)pk[d].val / (double)pk[d].w * (lim - w) + 0.4 <= ans)
        return;
    if(w + pk[d].w <= lim)
        dfs(d + 1, w + pk[d].w, val + pk[d].val);

    dfs(d + 1, w, val);
}

int main (void)
{
    while(scanf("%d %lld", &n, &lim) != EOF)
    {
        for(int i = 0; i < n; i++)
            scanf("%lld %lld", &pk[i].w, &pk[i].val);
        sort(pk, pk + n);
        ans = 0;
        sum[n] = 0;
        sw[n] = 0;
        dfs(0, 0, 0);
        printf("%lld\n", ans);
    }
    return 0;
}