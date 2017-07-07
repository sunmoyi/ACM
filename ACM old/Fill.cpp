//
// Created by 孙启龙 on 16/10/21.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 210

using namespace std;

struct node{
    int v[3], dist;
    bool operator < (const node& rhs)const
    {
        return dist > rhs.dist;
    }
};

int mark[maxn][maxn], dist[maxn][maxn], cap[3], ans[maxn];

void update_ans(const node& a)
{
    for(int i = 0; i < 3; i++)
    {
        int d = a.v[i];
        if(ans[d] < 0 || a.dist < ans[d])
            ans[d] = a.dist;
    }
}

void solve(int a, int b, int c, int d)
{
    cap[0] = a, cap[1] = b, cap[2] = c;
    memset(ans, -1, sizeof(ans));
    memset(mark, 0, sizeof(mark));
    memset(dist, -1, sizeof(dist));
    priority_queue<node>Q;

    node start;
    start.dist = 0, start.v[0] = 0, start.v[1] = 0, start.v[2] = c;
    Q.push(start);
    dist[0][0] = 0;

    while(!Q.empty())
    {
        node u = Q.top();
        Q.pop();
        if(mark[u.v[0]][u.v[1]])
            continue;
        mark[u.v[0]][u.v[1]] = 1;
        update_ans(u);
        if(ans[d] >= 0)
            break;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(i != j)
                {
                    if(u.v[i] == 0 || u.v[j] == cap[j])
                        continue;
                    int amount = min(cap[j] - u.v[j], u.v[i]);
                    node u2 = u;
                    u2.dist = u.dist + amount;
                    u2.v[i] -= amount;
                    u2.v[j] += amount;
                    int &D = dist[u2.v[0]][u2.v[1]];
                    if(D < 0 || u2.dist < D)
                    {
                        D = u2.dist;
                        Q.push((u2));
                    }
                }
            }
        }
    }
    while(d >= 0)
    {
        if(ans[d] >= 0)
        {
            printf("%d %d\n", ans[d], d);
            return;
        }
        d--;
    }
}

int main (void)
{
    int T, a, b, c, d;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        solve(a, b, c, d);
    }
    return 0;
}
