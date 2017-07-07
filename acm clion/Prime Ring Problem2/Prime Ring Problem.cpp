//
// Created by 孙启龙 on 2016/10/31.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

bool prime[50];
int num[50];
int vis[50];
int n;

void dfs(int cur)
{
    if(cur == n + 1 && prime[num[n] + num[1]] == true)
    {
        for(int i = 1; i < n; i++)
            printf("%d ", num[i]);
        printf("%d\n", num[n]);
    }
    for(int i = 2; i <= n; i++)
    {
        if (!vis[i] && prime[num[cur - 1] + i] == true)
        {
            vis[i] = 1;
            num[cur] = i;
            dfs(cur + 1);
            vis[i] = 0;
        }
    }
}

void isprime()
{
    memset(prime, true, sizeof(prime));
    prime[1] = 0;
    for(int i = 2; i < 50; i++)
        if(prime[i])
            for(int j = i + i; j < 50; j += i)
                prime[j] = false;
}

int main (void)
{
    isprime();
    int Case = 0;
    while(scanf("%d", &n) != EOF)
    {
        if(Case)
            printf("\n");
        printf("Case %d:\n", ++Case);
        memset(vis, 0, sizeof(vis));
        num[1] = 1;
        dfs(2);
    }
    return 0;
}