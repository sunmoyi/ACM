//
// Created by 孙启龙 on 2017/7/28.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 410

using namespace std;

bool a[maxn][maxn];

int main (void)
{
    int n, x, y;
    while(scanf("%d", &n) != EOF)
    {
        memset(a, false, sizeof(a));
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &x, &y);
            x += 100, y += 100;
            a[x][y] = true;
        }
        int sum = 0;
        for(int i = 0; i < 202; i++)
        {
            for(int j = 0; j < 202; j++)
            {
                if(a[i][j])
                {
                    a[i][j] = 0;
                    for(int k = i; k < 202; k++)
                    {
                        for(int p = j + 1; p < 202; p++)
                        {
                            if(a[k][p])
                            {
                                int xx = k - i, yy = p - j;
                                if(a[i + yy][j - xx] && a[i + xx  + yy][j + yy - xx])
                                    sum++;
                            }
                        }
                    }
                    a[i][j] = 1;
                }
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}