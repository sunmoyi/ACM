//
// Created by 孙启龙 on 2017/3/15.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 20

using namespace std;

char grid[maxn][maxn];
int n;

int main (void)
{
    int T;
    scanf("%d", &T);
    for(int Case = 1; Case <= T; Case++)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%s", grid[i]);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '.')
                {
                    for(char ch = 'A'; ch <= 'Z'; ch++)
                    {
                        bool ok = true;
                        if(i > 0 && grid[i - 1][j] == ch)
                            ok = false;
                        if(i < n - 1 && grid[i + 1][j] == ch)
                            ok = false;
                        if(j > 0 && grid[i][j - 1] == ch)
                            ok = false;
                        if(j <= n - 1 && grid[i][j + 1] == ch)
                            ok = false;
                        if(ok)
                        {
                            grid[i][j] = ch;
                            break;
                        }
                    }
                }
            }
        }
        printf("Case %d:\n", Case);
        for(int i = 0; i < n; i++)
            printf("%s\n", grid[i]);
    }
    return 0;
}