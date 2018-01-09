//
// Created by 孙启龙 on 2017/8/17.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 6000

using namespace std;

struct node{
    int u, v, next;
}edge[maxn * 2];
int len, head[maxn];
int vis[maxn], timee, bf[maxn];
int x[60][60], y[60][60];
char s[60][60];
int n, m;

void addedge(int u, int v)
{
    edge[++len].u = u;
    edge[len].v = v;
    edge[len].next = head[u];
    head[u] = len;
}

bool hungry(int u)
{
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        if(vis[edge[i].v] != timee)
        {
            int v = edge[i].v;
            vis[v] = timee;
            if(bf[v] == -1 || hungry(bf[v]))
            {
                bf[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main (void)
{
    int num1, num2, ans;
    scanf("%d %d", &n, &m);
    num1 = num2 = len = 0;
    memset(head, -1, sizeof(head));
    memset(bf, -1, sizeof(bf));
    for(int i = 1; i <= n; i++)
    {
        getchar();
        for(int j = 1; j <= m; j++)
            scanf("%c", &s[i][j]);
    }

    for(int i = 1; i <= n; i++)
    {
        num1++;
        for(int j = 1; j <= m; j++)
        {
            x[i][j] = num1;
            if(s[i][j] == '#')
                num1++;
        }
    }
    for(int i = 1; i <= m; i++)
    {
        num2++;
        for(int j = 1; j <= n; j++)
        {
            y[j][i] = num2;
            if(s[j][i] == '#')
                num2++;
        }
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(s[i][j] == '*')
                addedge(x[i][j], y[i][j]);

    timee = ans = 0;
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= num1; i++)
    {
        timee++;
        if(hungry(i))
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}