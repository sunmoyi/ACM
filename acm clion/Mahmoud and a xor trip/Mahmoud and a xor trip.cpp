//
// Created by 孙启龙 on 2017/2/13.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

#define maxn 100007

using namespace std;

int n;
long long a[maxn], sum1, res, num[maxn][2];
vector<int>E[maxn];

void dfs(int x, int f, int bit)
{
    int t = (a[x] >> bit) & 1;
    num[x][t] = 1, num[x][t ^ 1] = 0;
    long long s = 0;
    for(int i = 0; i < E[x].size(); i++)
    {
        int v = E[x][i];
        if(v == f)
            continue;
        dfs(v, x, bit);
        s += num[x][0] * num[v][1] + num[x][1] * num[v][0];
        num[x][t ^ 0] += num[v][0];
        num[x][t ^ 1] += num[v][1];
    }
    res += s << bit;
}

int main (void)
{
    scanf("%d", &n);
    int maxx = -1;
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld\n", &a[i]);
        sum1 += a[i];
        long long temp = a[i];
        int len = 0;
        while(temp / 2)
        {
            temp /= 2;
            len++;
        }
        maxx = max(maxx, len);
    }
    for(int i = 1; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        E[x].push_back(y);
        E[y].push_back(x);
    }
    for(int i = 0; i < maxx + 1; i++)
        dfs(1, 0, i);
    printf("%lld\n", res + sum1);
}