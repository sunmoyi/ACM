//
// Created by 孙启龙 on 2016/11/8.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 35

using namespace std;

int map[maxn][maxn];
int n, m;
int T;

int main (void)
{
    scanf("%d", &T);
    for(int Case = 1; Case <= T; Case++)
    {
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                scanf("%d", &map[i][j]);

        bool flag = false;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j < m; j++)
                if(map[i][j] == map[i][j + 1])
                    flag = true;
        for(int i = 1; i < n; i++)
            for(int j = 1; j <= m; j++)
                if(map[i][j] == map[i + 1][j])
                    flag = true;
        for(int i = 1; i <= n; i++)
        {
            for(int j = i + 1; j <= n; j++)
            {
                if(map[i][1] == map[j][1])
                    flag = true;
                if(map[i][m] == map[j][m])
                    flag = true;
            }
        }
        for(int i = 1; i <= m; i++)
        {
            for(int j = i + 1; j <= m; j++)
            {
                if(map[1][i] == map[1][j])
                    flag = true;
                if(map[n][i] == map[n][j])
                    flag = true;
            }
        }
        printf("Case #%d: ", Case);
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
}