//
// Created by 孙启龙 on 2017/7/18.
//

#include<cstdio>
#include<algorithm>
#include<bitset>

using namespace std;

bitset<90>dp[11];
int ans[60][60][60];
int a[100], n, m;
int q[5];

int check(int x, int y, int z)
{
    for(int i = 0; i <= n; i++)
        dp[i].reset();
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++)
        if(i != x && i != y && i != z && a[i] <= 87)
            for(int t = 10; t >= 1; t--)
                dp[t] |= dp[t - 1] << a[i];
    if(dp[10][87] == 1)
        return 1;
    return 0;
}

int main (void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for(int i = 1; i <= n; i++)
            for(int j = i; j <= n; j++)
                for(int k = j; k <= n; k++)
                    ans[i][j][k] = check(i, j, k);
        scanf("%d", &m);
        while(m--)
        {
            for(int i = 0; i < 3; i++)
                scanf("%d", &q[i]);
            sort(q, q + 3);
            if(ans[q[0]][q[1]][q[2]])
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}