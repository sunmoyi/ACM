//
// Created by 孙启龙 on 2017/2/9.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define INF 0x3f3f3f3f
#define maxn 100010

using namespace std;

int a[maxn], dp[maxn], n;

int main (void)
{
    while(cin >> n) {
        int pre = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        memset(dp, INF, sizeof(dp));
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1] + 20;
            int pos = upper_bound(a + 1, a + 1 + i, a[i] - 90) - a;
            dp[i] = min(dp[i], dp[pos - 1] + 50);
            pos = upper_bound(a + 1, a + 1 + i, a[i] - 1440) - a;
            dp[i] = min(dp[i], dp[pos - 1] + 120);
            cout << dp[i] - dp[i - 1] << endl;
        }
    }
    return 0;
}