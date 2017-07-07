//
// Created by 孙启龙 on 2016/10/29.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#define maxn 1000007

using namespace std;

long long hashh[maxn];

struct node{
    int map[4][8], step;
    bool operator == (const node &p)
    {
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 8; j++)
                if(map[i][j] != p.map[i][j])
                    return false;
        return true;
    }
    long long hashvalue()
    {
        long long val = 0;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                val += (val << (long long)1) + map[i][j];
            }
        }
        return val;
    }
};

node start, endd;

void init()
{
    memset(hashh, -1, sizeof(hashh));
    for(int i = 0; i < 4; i++)
    {
        start.map[i][0] = 0;
        for(int j = 1; j < 8; j++)
            scanf("%d", &start.map[i][j]);
    }
    start.step = 0;
}

void getend()
{
    for(int i = 0; i < 4; i++)
    {
        endd.map[i][7] = 0;
        for(int j = 0; j < 7; j++)
            endd.map[i][j] = (i + 1) * 10 + (j + 1);
    }
}

bool hashinsert(long long val)
{
    int v = val % maxn;
    while (hashh[v] != -1 && hashh[v] != val)
    {
        v += 10;
        v %= maxn;
    }
    if(hashh[v] == -1)
    {
        hashh[v] =val;
        return true;
    }
    return false;
}

void bfs()
{
    queue<node>Q;
    node p, q;
    Q.push(start);
    hashinsert(start.hashvalue());
    while(!Q.empty())
    {
        p = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                if(!p.map[i][j])
                {
                    q = p;
                    q.step++;
                    int value = p.map[i][j - 1] + 1;
                    if(value == 1 || value % 10 == 8)
                        continue;
                    int x, y, flag = 1;
                    for(int k = 0; k < 4 && flag; k++)
                    {
                        for(int l = 1; l < 8 && flag; l++)
                        {
                            if(p.map[k][l] == value)
                            {
                                x = k, y = l;
                                flag = false;
                            }
                        }
                    }
                    if(!flag)
                    {
                        swap(q.map[i][j], q.map[x][y]);
                        long long value = q.hashvalue();
                        if(hashinsert((value)))
                        {
                            if(q == endd)
                            {
                                printf("%d\n", q.step);
                                return;
                            }
                            Q.push(q);
                        }
                    }
                }
            }
        }
    }
    printf("-1\n");
    return ;
}

void solve()
{
    int k = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(start.map[i][j] == (k + 1) * 10 + 1)
            {
                swap(start.map[i][j], start.map[k][0]);
                k++, j = 0, i = 0;
            }
        }
    }
    if(start == endd)
    {
        printf("0\n");
        return;
    }
    bfs();
}

int main (void)
{
    int Case;
    scanf("%d", &Case);
    getend();
    while(Case--)
    {
        init();
        solve();
    }
    return 0;
}