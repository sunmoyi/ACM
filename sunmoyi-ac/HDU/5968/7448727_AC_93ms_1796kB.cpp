//
// Created by 孙启龙 on 2016/11/7.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110
#define abs(x) (x > 0 ? (x): (-(x)))

using namespace std;

int T;
int num[maxn], sum;
int xxor[maxn][maxn];
int Q, que;
int vis[1024 << 3];

int main (void)
{
    scanf("%d", &T);
    while(T--)
    {
        memset(vis, -1, sizeof(vis));
        scanf("%d", &sum);
        for(int i = 1; i <= sum; i++)
            scanf("%d", &num[i]);
        for(int i = 1; i <= sum; i++)
        {
            xxor[i][i] = num[i];
            vis[xxor[i][i] + 2048] = 1;
            //printf("%d %d %d\n", i, i, xxor[i][i]);
        }

        for(int i = 1; i <= sum; i++)
        {
            for(int j = i + 1; j <= sum; j++)
            {
                xxor[i][j] = xxor[i][j - 1] ^ num[j];
                //printf("%d %d %d\n", i, j, xxor[i][j]);
                vis[xxor[i][j] + 2048] = max(vis[xxor[i][j] + 2048], j - i + 1);
            }
        }

        scanf("%d", &Q);
        while(Q--)
        {
            scanf("%d", &que);
            int ans = 0, kk = 0;
            for(ans = 0; ans < 1300; ans++)
            {
                if(vis[que + 2048 - ans] != -1 && vis[que + 2048 + ans] != -1)
                {
                    kk = max(vis[que + 2048 - ans], vis[que + 2048 + ans]);
                    break;
                }
                if(vis[que + 2048 - ans] != -1)
                {
                    kk = vis[que + 2048 - ans];
                    break;
                }
                if(vis[que + 2048 + ans] != -1)
                {
                    kk = vis[que + 2048 + ans];
                    break;
                }
            }
            printf("%d\n", kk);
        }
        printf("\n");
    }
    return 0;
}