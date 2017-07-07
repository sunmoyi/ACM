//
// Created by 孙启龙 on 2016/11/8.
//

#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

vector<int>G[1010];
struct Point{
    long long x, y, r, price;
}point[1010];
int sum;
int exist[20002], dfn[20002], low[20002], stack[20002], weight[20002], top, Count, Time;
int ind[20002];
long long minn[1010];

bool judge(int x, int y)
{
    long long dis = ((point[x].x - point[y].x) * (point[x].x - point[y].x) + (point[x].y - point[y].y) * (point[x].y - point[y].y));
    if(dis > (point[x].r * point[x].r))
        return false;
    return true;
}

void tarjan(int u)
{
    stack[top++] = u;
    dfn[u] = low[u] = ++Time;
    exist[u] = 1;
    int size = G[u].size();
    for (int i = 0; i < size; i++)
    {
        if (!dfn[G[u][i]])
        {
            tarjan(G[u][i]);
            low[u] = min(low[u], low[G[u][i]]);
        }
        else
        {
            if (exist[G[u][i]] == 1)
                low[u] = min(low[u], dfn[G[u][i]]);
        }
    }
    if (dfn[u] == low[u])
    {
        //weight[u] = Count;
        //minn[Count] = min(minn[Count], point[u].price);
        //while (u != stack[top])
        //{
            //weight[stack[top - 1]] = Count;
            //exist[stack[top - 1]] = 0;
            //minn[Count] = min(minn[Count], point[stack[top - 1]].price);
            //top--;
        //}
        int v;
        do {
            v = stack[--top];
            minn[Count] = min(minn[Count], point[v].price);
            exist[v] = false;
            weight[v] = Count;
        } while( v != u);
        Count++;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++)
    {
        scanf("%d", &sum);
        for (int i = 0; i <= sum; i++)
        {
            G[i].clear();
            ind[i] = exist[i] = weight[i] = low[i] = dfn[i] = 0;
            minn[i] = 0x3f3f3f3f;
        }
        Time = top = Count = 0;
        for(int i = 1; i <= sum; i++)
            scanf("%lld %lld %lld %lld", &point[i].x, &point[i].y, &point[i].r, &point[i].price);

        for (int i = 1; i <= sum; i++)
        {
            for(int j = 1; j <= sum; j++)
            {
                if(i != j && judge(i, j))
                {
                    G[i].push_back(j);
                }
            }
        }

        for (int i = 1; i <= sum; i++)
        {
            if (!dfn[i])
            {
                tarjan(i);
            }
        }

        for (int i = 1; i <= sum; i++)
        {
            int size = G[i].size();
            for (int j = 0; j < size; j++)
            {
                if (weight[i] != weight[G[i][j]])
                {
                    ind[weight[G[i][j]]]++;
                }
            }
        }

        long long ans = 0;
        for(int i = 0; i < Count; i++)
        {
            if(ind[i] == 0)
                ans += minn[i];
        }
        printf("Case #%d: ", Case);
        printf("%lld\n", ans);
    }
    return 0;
}