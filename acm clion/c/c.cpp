//
// Created by 孙启龙 on 2017/9/22.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 51

using namespace std;

int g[N][N], n, m, p, head[N * N], cnt;
int used[N * N], belong[N * N];
struct node {
    int v, pre;
};
node e[N * N * 2];

void add(int x, int y)
{
    e[++cnt].v = y;
    e[cnt].pre = head[x];
    head[x] = cnt;
}

bool find(int i)
{
    for (int j = head[i]; j != 0; j = e[j].pre)
    {
        if (!used[e[j].v])
        {
            used[e[j].v] = 1;
            if (!belong[e[j].v] || find(belong[e[j].v]))
            {
                belong[e[j].v] = i;
                return true;
            }
        }
    }
    return false;
}

int main() {
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= p; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x][y] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (((i + j) & 1) || g[i][j])
                continue;
            if (!g[i - 1][j] && i - 1 >= 1)
                add((i - 1) * m + j, (i - 2) * m + j);
            if (!g[i + 1][j] && i + 1 <= n)
                add((i - 1) * m + j, i * m + j);
            if (!g[i][j - 1] && j - 1 >= 1)
                add((i - 1) * m + j, (i - 1) * m + j - 1);
            if (!g[i][j + 1] && j + 1 <= m)
                add((i - 1) * m + j, (i - 1) * m + j + 1);
        }
    }
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (((i + j) & 1) || g[i][j])
                continue;
            memset(used, 0, sizeof(used));
            if (find((i - 1) * m + j))
                tot++;
        }
    }
    printf("%d", tot);
    return 0;
}