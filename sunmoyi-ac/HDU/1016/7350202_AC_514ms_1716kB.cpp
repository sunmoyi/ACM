//
// Created by 孙启龙 on 2016/10/27.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

int n, k;
int a[100];
int b[100];
int c[100];

void dfs(int n, int cur)
{
    if (cur - 1 == n  && b[a[cur - 1] + a[1]] == 1)
    {
        for (int i = 1; i < n; i++)
            printf("%d ", a[i]);
        printf("%d\n", a[n]);
    }
    else
    {
        for(int i = 2; i <= n; i++)
        {
            if(c[i] == 0 && b[a[cur - 1] + i] == 1)
            {
                c[i] = 1;
                a[cur] = i;
                dfs(n, cur + 1);
                c[i] = 0;
            }
        }
    }
}

void prime()
{
    for(int i = 1; i < 40; i++)
    {
        b[i] = 1;
        for(int j = 2; j < i; j ++)
            if(i % j == 0)
                b[i] = 0;
    }
}

int main (void)
{
    prime();
    int Case = 0;
    while(scanf("%d", &n) != EOF)
    {
        Case++;
        printf("Case %d:\n", Case);
        memset(a, 0, sizeof(a));
        memset(c, 0, sizeof(c));
        a[1] = 1;
        dfs(n, 2);
        printf("\n");
    }
    return 0;
}