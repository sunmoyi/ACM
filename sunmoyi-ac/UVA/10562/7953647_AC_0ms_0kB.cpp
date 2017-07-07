//
// Created by 孙启龙 on 2017/1/20.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cctype>
#define maxn 210

using namespace std;

int n;
char buf[maxn][maxn];

void dfs(int r, int c)
{
    printf("%c(", buf[r][c]);
    if(r + 1 < n && buf[r + 1][c] == '|')
    {
        int i = c;
        while(i - 1 >= 0 && buf[r + 2][i - 1] == '-')
            i--;
        while(buf[r + 2][i] == '-' && buf[r + 3][i] != '\0')
        {
            if(!isspace(buf[r + 3][i]))
                dfs(r + 3, i);
            i++;
        }
    }
    printf(")");
}

void solve()
{
    n = 0;
    while(fgets(buf[n], maxn, stdin) && buf[n][0] != '#')
        n++;
    printf("(");
    if(n)
    {
        for(int i = 0 ; i < strlen(buf[0]); i++)
        {
            if (buf[0][i] != ' ')
            {
                dfs(0, i);
                break;
            }
        }
    }
    printf(")\n");
}

int main (void)
{
    int T;
    fgets(buf[0], maxn, stdin);
    sscanf(buf[0], "%d", &T);
    while(T--)
    {
        solve();
    }
}

/*
 *    A
 *    |
 *--------
 *B  C   D
 *   |   |
 * ----- -
 * E   F G
 *#
 *
 * */