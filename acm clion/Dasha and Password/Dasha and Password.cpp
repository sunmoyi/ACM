//
// Created by 孙启龙 on 2017/2/15.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 55

using namespace std;

int ans, n, m;
char ch[maxn];
int a[maxn], b[maxn], c[maxn];

int main (void)
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%s", ch);
        a[i] = m;
        b[i] = m;
        c[i] = m;
        for(int j = 0; j < m; j++)
        {
            if(ch[j] >= '0' && ch[j] <= '9')
                a[i] = min(a[i], min(j, m - j));
            else if (ch[j] >= 'a' && ch[j] <= 'z')
                b[i] = min(b[i], min(j, m - j));
            else if (ch[j] == '&' || ch[j] == '*' || ch[j] == '#')
                c[i] = min(c[i], min(j, m - j));
        }
    }

    ans = 300;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == m)
            continue;
        for(int j = 1; j <= n; j++)
        {
            if(i == j || b[j] == m)
                continue;
            for(int k = 1; k <= n; k++)
            {
                if(k == i || k == j || c[k] == m)
                    continue;
                ans = min(ans, a[i] + b[j] + c[k]);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}