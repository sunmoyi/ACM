//
// Created by 孙启龙 on 2017/2/10.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int cct, fcount, num, _max, save[21], a[21];
bool vis[21][21], v[21], vv[21];

void dfs_1(int cur)
{
    vv[cur] = true;
    a[_max++] = cur;
    for(int i = 1; i < 21; i++)
        if(!vv[i] && vis[cur][i])
            dfs_1(i);
}

void dfs_2(int cur, int node)
{
    if(node == num)
    {
        ++fcount;
        printf("1");
        for(int i = 0; i < cur; i++)
            printf(" %d", save[i]);
        printf("\n");
    }
    else
    {
        for(int i = 0; i < _max; i++)
        {
            if(!v[a[i]] && vis[node][a[i]])
            {
                save[cur] = a[i];
                v[a[i]] = true;
                dfs_2(cur + 1, a[i]);
                v[a[i]] = false;
            }
        }
    }
}

int main (void)
{
    int x, y, fct = 0;
    memset(v, false, sizeof(v));
    while(scanf("%d", &num) != EOF)
    {
        _max = fcount = cct = 0;
        memset(vv, false, sizeof(vv));
        memset(vis, false, sizeof(vis));
        while(1)
        {
            scanf("%d %d", &x, &y);
            if(!x || !y)
                break;
            vis[x][y] = vis[y][x] = true;
        }
        dfs_1(num);
        sort(a, a + _max);
        v[1] = true;
        printf("CASE %d:\n", ++fct);
        dfs_2(0, 1);
        printf("There are %d routes from the firestation to streetcorner %d.\n", fcount, num);
    }
    return 0;
}
