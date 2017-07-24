//
// Created by 孙启龙 on 2017/4/12.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110

using namespace std;

int map[maxn][maxn];
int n, m, a, b;

void floyed()
{
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(map[i][k] && map[k][j] && i != j)
                    map[i][j] = 1;
}

int main (void)
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        memset(map, 0, sizeof(map));
        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d", &a, &b);
            map[a][b] = 1;
        }

        floyed();

        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            int temp = 0;
            for(int j = 1; j <= n; j++)
            {
                if(map[j][i] || map[i][j])
                    temp++;
            }
            if(temp == n - 1)
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}