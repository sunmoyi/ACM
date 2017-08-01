//
// Created by 孙启龙 on 2017/7/24.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110

using namespace std;

int rec[maxn][maxn];
int n, k, d, s;
int timee[maxn];
int emp[maxn];

int dfs(int pos, int num)
{
    if(num <= 0)
        return 0;
    if(pos == k + 1)
        return 0x3f3f3f3f;
    if(rec[pos][num] != 0x3f3f3f3f)
        return rec[pos][num];
    return rec[pos][num] = min(dfs(pos + 1, num),
                               dfs(pos + 1, num - emp[pos]) + d)
                           + (timee[pos] - timee[pos - 1]) * num;
}

int main (void)
{
    scanf("%d %d %d %d", &n, &k, &d, &s);
    for(int i = 1; i <= k; i++)
        scanf("%d %d", &timee[i], &emp[i]);

    memset(rec, 0x3f, sizeof(rec));

    int ans = dfs(1, n);
    if(ans >= 0x3f3f3f3f)
        printf("impossible\n");
    else
        printf("%d\n", ans);
    return 0;
}