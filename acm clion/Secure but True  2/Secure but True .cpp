//
// Created by 孙启龙 on 2017/8/18.
//

#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>

using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define maxn 1111
char c[] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'}, s[maxn];
int T, k, n, a[111];

void solve()
{
    ll temp = 0;
    int flag = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        temp = 11ll * temp + 10 - a[s[i]];
        if (temp >= k) {
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        k -= temp + 1;
        n++;
        for (int i = 0; i < n; i++)
            s[i] = 'A';
        solve();
    }
    else
    {
        int up = 0;
        for (int i = 0; i < n; i++)
        {
            up += a[s[i]] + k % 11;
            s[i] = c[up % 11];
            up /= 11, k /= 11;
        }
        for (int i = n - 1; i >= 0; i--)
            printf("%c", s[i]);
        printf("\n");
    }
}

int main()
{
    for (int i = 0; i < 11; i++)
        a[c[i]] = i;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %s", &k, s);
        n = strlen(s);
        for (int i = 0, j = n - 1; i < j; i++, j--)
            swap(s[i], s[j]);
        solve();
    }
    return 0;
}
