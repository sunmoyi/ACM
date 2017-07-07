//
// Created by 孙启龙 on 2017/3/12.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200020

using namespace std;

int father[maxn], rankk[maxn];
int n, m, ans;

void init()
{
    ans = 0;
    for(int i = 0; i <= n; i++)
    {
        rankk[i] = 0;
        father[i] = i;
    }
}

int find(int x)
{
    if(father[x] == x)
        return x;
    int temp = find(father[x]);
    rankk[x] += rankk[father[x]];
    return father[x] = temp;
}

void unoin(int x, int y, int w)
{
    int fx = find(x);
    int fy = find(y);
    if(fx == fy)
    {
        if(rankk[y] - rankk[x] != w)
            ans++;
    }
    else
    {
        father[fy] = fx;
        rankk[fy] = w - rankk[y] + rankk[x];
    }
}

int main (void)
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        init();
        int u, v, w;
        while(m--)
        {
            scanf("%d %d %d", &u, &v, &w);
            u--;
            unoin(u, v, w);
        }
        printf("%d\n", ans);
    }
    return 0;
}