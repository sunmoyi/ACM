//
// Created by 孙启龙 on 2017/4/1.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200020
#define mod 10007

using namespace std;

int dp[maxn];
char str[maxn];
int nextt[maxn];

void make_next(char *p)
{
    int j, k;
    j = 0;
    k = -1;
    nextt[0] = -1;
    int len = strlen(p);
    while (j<len)
    {
        if (k == -1 || p[j] == p[k])
        {
            j++;
            k++;
            nextt[j] = k;
        }
        else k = nextt[k];
    }
}

int main (void)
{
    int T;
    int n;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        scanf("%s", str);
        make_next(str);
        dp[0] = 0;
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            dp[i] = dp[nextt[i]] + 1;
            dp[i] %= mod;
            ans += dp[i];
            dp[i] %= mod;
        }
        printf("%d\n", ans);
    }
    return 0;
}