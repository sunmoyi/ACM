//
// Created by 孙启龙 on 2016/10/29.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define abs(x) ((x) > 0 ? (x) : (-x))
#define INF 0x3f3f3f3f
#define maxn 1010

using namespace std;

int T;
int father[maxn];
int minn[maxn];
struct node{
    int r, x, y;
    int cost;
}num[maxn];
int n;

int init()
{
    memset(minn, INF, sizeof(INF));
    for(int i = 0; i < maxn; i++)
        father[i] = i;
}

int find(int x)
{
    int far = x;
    while(far != father[far])
        far = father[far];

    while(father[x] != far)
    {
        int temp = father[x];
        father[x] = far;
        x = temp;
    }
    return far;
}

void unoin(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return ;
    else
        father[x] = y;
}

void build(int i, int j)
{
    double dit = num[i].r + num[j].r;
    double dis = sqrt((num[i].x - num[j].x) * (num[i].x - num[j].x) + (num[i].y - num[j].y) * (num[i].y - num[j].y));
    if(abs(dit - dis) < 1e-6)
        unoin(i, j);
    else if(dit > dis)
        unoin(i, j);
    return ;
}

int main (void)
{
    scanf("%d", &T);
    while(T--)
    {
        init();
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d %d %d %d", &num[i].r, &num[i].x, &num[i].y, &num[i].cost);
        for(int i = 1; i <= n; i++)
        {
            for(int j = i + 1; j <= n; j++)
            {
                build(i, j);
            }
        }
        for(int i = 1; i <= n; i++)
            minn[find(i)] = min(minn[find(i)], num[i].cost);

        int ans = 0;
        for(int i = 1; i <= n; i++)
            if(minn[i] != INF)
                ans += minn[i];
        printf("%d\n", ans);
    }
}