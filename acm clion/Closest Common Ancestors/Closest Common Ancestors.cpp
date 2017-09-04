//
// Created by 孙启龙 on 2017/8/2.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 1010

using namespace std;

vector<int>c[maxn];
vector<int>q[maxn];
int father[maxn], ans[maxn], visit[maxn], root[maxn];
int n, x, y, m;
char s1[3], s2[3], s3[3];

int find(int x)
{
    return x == father[x]? x: father[x] = find(father[x]);
}

void tarjan(int x)
{
    father[x] = x;
    for(int i = 0; i < c[x].size(); i++)
    {
        tarjan(c[x][i]);
        father[c[x][i]] = x;
    }
    visit[x] = true;

    for(int i = 0; i < q[x].size(); i++)
        if(visit[q[x][i]])
            ans[find(q[x][i])]++;
}

int main (void)
{

    while(scanf("%d", &n) != EOF)
    {
        for(int i = 1; i <= n; i++)
        {
            visit[i] = ans[i] = root[i] = 0;
            c[i].clear(), q[i].clear();
        }
        for(int i = 1; i <= n; i++)
        {
            scanf("%d%1s%1s%d%1s", &x, s1, s2, &m, s3);
            for(int i = 1; i <= m; i++)
            {
                scanf("%d", &y);
                c[x].push_back(y);
                root[y] = 1;
            }
        }
        scanf("%d", &m);
        for(int i = 1; i <= m; i++)
        {
            scanf("%1s%d%d%1s", s1, &x, &y, s2);
            q[x].push_back(y);
            q[y].push_back(x);
        }
        for(int i = 1; i <= n; i++)
        {
            if (!root[i])
            {
                tarjan(i);
                break;
            }
        }
        for(int i = 1; i <= n; i++)
            if(ans[i])
                printf("%d:%d\n", i, ans[i]);
    }
    return 0;
}