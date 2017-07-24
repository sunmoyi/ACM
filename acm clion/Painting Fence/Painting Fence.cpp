//
// Created by 孙启龙 on 2017/4/3.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 5050

using namespace std;

int n;
int num[maxn];

int dp(int l, int r, int len)
{
    if(l > r)
        return 0;
    if(l == r)
    {
        if(num[l] <= len)
            return 0;
        else
            return 1;
    }
    int minn = 0x3f3f3f3f, pos = 0;
    for(int i = l; i <= r; i++)
        if(minn > num[i])
            minn = num[i], pos = i;
    return min(r - l + 1, dp(l, pos - 1, minn) + dp(pos + 1, r, minn) + minn - len);
}

int main (void)
{
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 1; i <= n; i++)
            scanf("%d", &num[i]);
        int ans = dp(1, n, 0);
        printf("%d\n", ans);
    }
    return 0;
}