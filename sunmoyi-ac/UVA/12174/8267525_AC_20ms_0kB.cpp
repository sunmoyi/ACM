//
// Created by 孙启龙 on 2017/2/26.
//
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int N = 1e5+5;

int s, n, p[N], c[N];
bool flag[N];

void init ()
{
    scanf("%d%d", &s, &n);

    int tmp = 0;
    memset(flag, 0, sizeof(flag));
    memset(c, 0, sizeof(c));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
        if (i < s)
        {
            if (c[p[i]])
                tmp++;
            c[p[i]]++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (tmp == 0)
            flag[i] = true;

        if (c[p[i]] == 2)
            tmp--;
        c[p[i]]--;

        int k = i + s;
        if (k >= n)
            continue;
        if (c[p[k]])
            tmp++;
        c[p[k]]++;
    }
}

bool judge (int x)
{
    for (int i = x; i < n; i += s)
        if (!flag[i])
            return false;
    return true;
}

int solve ()
{
    memset(c, 0, sizeof(c));

    int ans = 0;
    for (int i = 0; i < s; i++)
    {
        if (judge(i))
            ans++;
        if (i >= n)
            continue;
        if (c[p[i]])
            break;
        c[p[i]]++;
    }
    return ans;
}

int main ()
{
    int cas;
    scanf("%d", &cas);
    while (cas--)
    {
        init();
        printf("%d\n", solve());
    }
    return 0;
}