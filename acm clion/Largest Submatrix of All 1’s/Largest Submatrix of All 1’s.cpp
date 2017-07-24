//
// Created by 孙启龙 on 2017/4/27.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include <iostream>

#define maxn 2010
#define INF 0x3f3f3f3f

using namespace std;

int n, m;
int M[maxn][maxn];
int u[maxn][maxn];
int l[maxn][maxn], r[maxn][maxn];
stack<pair<int, int> >S;

void pre()
{
    memset(u, 0, sizeof(u));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(M[i][j] == 0)
                u[i][j] = 0;
            else
                u[i][j] = u[i-1][j]+1;
        }
    }
}

int main (void)
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                scanf("%d", &M[i][j]);

        pre();
        for(int i = 1; i <= n; i++)
        {
            while(!S.empty())
                S.pop();
            for(int j = 1; j <= m; j++)
            {
                while(!S.empty() && u[i][j] <= S.top().first)
                    S.pop();
                if(S.size() == 0)
                    l[i][j] = 1;
                else
                    l[i][j] = S.top().second + 1;
                S.push(make_pair(u[i][j], j));
            }
        }
        for(int i = 1;i <= n;i++)
        {
            while(!S.empty())
                S.pop();
            for(int j = m;j >= 1;j--)
            {
                while(!S.empty() && u[i][j] <= S.top().first)
                    S.pop();
                if(S.size() == 0)
                    r[i][j] = m;
                else
                    r[i][j] = S.top().second-1;
                S.push(make_pair(u[i][j],j));
            }
        }

        int ans = 0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                ans = max(ans,u[i][j]*(r[i][j]-l[i][j]+1));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}