//
// Created by 孙启龙 on 2016/11/6.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100

using namespace std;

int high[maxn][maxn];
int n, m;
int T;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main (void)
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &m);
        memset(high, 0, sizeof(high));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                scanf("%d", &high[i][j]);

        int sum = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                for(int k = 0; k < 4; k++)
                {
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    if(high[i][j] > high[x][y])
                        sum += (high[i][j] - high[x][y]);
                }
                if(high[i][j] != 0)
                    sum++;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}