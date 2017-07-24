//
// Created by 孙启龙 on 2017/2/13.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 15
#define INF 0x3f3f3f3f

using namespace std;

struct node{
    int x, y;
    node(int x, int y):x(x), y(y){}
};

int n, m, c;
int v[4][maxn << 1];
char a[maxn][maxn];
vector<node>vec;

bool judge()
{
    int size = vec.size();
    for(int i = 0; i < size; i++)
        if(!v[0][vec[i].x] && !v[1][vec[i].y] && !v[2][vec[i].y - vec[i].x + n] && !v[3][vec[i].x + vec[i].y])
            return false;
    return true;
}

bool dfs(int cur, int deep, int maxd)
{
    if(deep == maxd)
    {
        if(judge())
            return true;
        else
            return false;
    }
    else
    {
        if(cur == n)
            return false;
        if(dfs(cur + 1, deep, maxd))
            return true;
        for(int pos = 0; pos < m; ++pos)
        {
            int x = cur;
            int y = pos;
            int temp_a = v[0][x], temp_b = v[1][y], temp_c = v[2][y - x + n], temp_d = v[3][x + y];
            v[0][x] = v[1][y] = v[2][y - x + n] = v[3][x + y] = 1;
            if(dfs(cur + 1, deep + 1, maxd))
                return true;
            v[0][x] = temp_a;
            v[1][y] = temp_b;
            v[2][y - x + n] = temp_c;
            v[3][x + y] = temp_d;
        }
        return false;
    }
}

int main (void)
{
    while(scanf("%d", &n) != EOF && n)
    {
        vec.clear();
        scanf("%d", &m);
        for(int i = 0; i < n; ++i)
            scanf("%s", a[i]);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(a[i][j] == 'X')
                    vec.push_back(node(i, j));

        for(int maxd = 0; ; ++maxd)
        {
            memset(v, 0, sizeof(v));
            if(dfs(0, 0, maxd))
            {
                printf("Case %d: %d\n", ++c, maxd);
                break;
            }
        }
    }
    return 0;
}