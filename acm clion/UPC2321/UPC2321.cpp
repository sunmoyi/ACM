//
// Created by 孙启龙 on 2017/8/8.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110

using namespace std;

struct node{
    int sum;
    int god[10], num[10], price;
    bool useful = true;
}method[maxn];
struct thing{
    int god, num, price;
}things[10];
int dp[10][10][10][10][10];
int n, m;

bool cmp1(node &a)
{
    if(a.useful)
        return true;
    else
        return false;
}

bool cmp2(thing a, thing b)
{
    return a.god < b.god;
}

void GetUseful()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= method[i].sum; j++)
        {
            bool find = false;
            for(int k = 1; k <= m; k++)
                if(things[k].god == method[i].god[j])
                    find = true;
            if(!find)
                method[i].useful = false;
        }
    }
}

int DP(int a, int b, int c, int d, int e, bool flag)
{
    if(!flag && dp[a][b][c][d][e] != -1)
        return dp[a][b][c][d][e];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j < method[i].sum; j++) {
            if (method[i].god)
        }
    }
}

int main (void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &method[i].sum);
        for(int j = 1; j <= method[i].sum; j++)
            scanf("%d %d", &method[i].god[j], &method[i].num[j]);
        scanf("%d", &method[i].price);
    }
    scanf("%d", &m);
    int ans = 0;
    for(int i = 1; i <= m; i++)
        scanf("%d %d %d", &things[i].god, &things[i].num, &things[i].price), ans += things[i].num * things[i].price;
    sort(things + 1, things + m + 1, cmp2);
    GetUseful();
    sort(method + 1, method + 1 + n, cmp1);
    memset(dp, -1, sizeof(dp));
    dp[things[1].num][things[2].num][things[3].num][things[4].num][things[5].num] = ans;
    dp[0][0][0][0][0] = 0;
    DP(things[1].num, things[2].num, things[3].num, things[4].num, things[5].num, true);
    printf("%d\n", dp[things[1].num][things[2].num][things[3].num][things[4].num][things[5].num]);
    return 0;
}