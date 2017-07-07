//
// Created by 孙启龙 on 2017/2/10.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 5
#define maxm 100

using namespace std;

int n, c, ans, w[maxn], jump[maxm];

bool judge(int *s, int k)
{
    for(int i = 0; i < maxn; i++)
        if((s[i] >> k) & w[i])
            return false;
    return true;
}

void init()
{
    char str[maxm];

    c = 0;
    ans = n * 10;
    memset(w, 0, sizeof(w));
    for(int i = 0; i < maxn; i++)
    {
        scanf("%s", str);
        for(int j = 0; j < n; j++)
            if(str[j] == 'X')
                w[i] |= (1 << j);
    }

    for(int i = 0; i <= n; i++)
        if(judge(w, i))
            jump[c++] = i;
}

void dfs(int *s, int d, int sum)
{
    if(sum + jump[0] * (10 - d) > ans)
        return;
    if(d == 10)
    {
        ans = min(ans, sum);
        return;
    }

    for(int i = 0; i < c; i++)
    {
        if(judge(s, jump[i]))
        {
            int p[maxn];
            for(int j = 0; j < maxn; j++)
                p[j] = (s[j] >> jump[i]) ^ w[j];
            dfs(p, d + 1, sum + jump[i]);
        }
    }
}

int main (void)
{
    while(scanf("%d", &n) != EOF && n)
    {
        init();
        dfs(w, 1, n);
        printf("%d\n", ans);
    }
    return 0;
}