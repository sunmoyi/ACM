//
// Created by 孙启龙 on 2017/2/8.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 9

using namespace std;

int n, a[maxn];

bool is_sorted()
{
    for(int i = 0; i < n - 1; i++)
        if(a[i] >= a[i + 1])
            return false;
    return true;
}

int h()
{
    int cnt = 0;
    for(int i = 0; i < n - 1; i++)
        if(a[i] + 1 != a[i + 1])
            cnt++;
    if(a[n - 1] != n)
        cnt++;
    return cnt;
}

bool dfs(int d, int maxd)
{
    if(d * 3 + h() > maxd * 3)
        return false;
    if(is_sorted())
        return true;

    int b[maxn], old_a[maxn];
    memcpy(old_a, a, sizeof(a));
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            int cnt = 0;
            for(int k = 0; k < n; k++)
            {
                if(k < i || k > j)
                    b[cnt++] = a[k];
            }
            for(int k = 0; k <= cnt; k++)
            {
                int cnt2 = 0;
                for(int p = 0; p < k; p++)
                    a[cnt2++] = b[p];
                for(int p = i; p <= j; p++)
                    a[cnt2++] = old_a[p];
                for(int p = k; p < cnt; p++)
                    a[cnt2++] = b[p];
                if(dfs(d + 1, maxd))
                    return true;
                memcpy(a, old_a, sizeof(a));
            }
        }
    }
    return false;
}

int solve()
{
    if(is_sorted())
        return 0;
    int max_ans = 5;
    for(int maxd = 1; maxd < max_ans; maxd++)
        if(dfs(0, maxd))
            return maxd;
    return max_ans;
}

int main (void)
{
    int kase = 0;
    while(scanf("%d", &n) == 1 && n)
    {
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        printf("Case %d: %d\n", ++kase, solve());
    }
    return 0;
}