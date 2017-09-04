//
// Created by 孙启龙 on 2017/8/9.
//

/*
#include<cstdio>
#include<cstring>
#include<algorithm>
#include <cmath>
#include <queue>
#define inf 20000000
#define maxn 40000
#define maxm 210
#define esp 1e-8

using namespace std;

int to[maxn], sz[maxn], nextt[maxn], head[maxn], vis[maxn], list[maxn], fa[maxn];
int tot, S, T, n;
double cost, l, r, mid, ct[maxn], dis[maxn];
int a[maxm][maxm], b[maxm][maxm];
queue<int>Q;

void ADD(int x, int y, int u, double z)
{
    to[tot] = y;
    sz[tot] = u;
    nextt[tot] = head[x];
    ct[tot] = z;
    head[x] = tot++;
}

void add(int x, int y, double z)
{
    ADD(x, y, 1, z);
    ADD(y, x, 0, -z);
}

bool spfa()
{
    for(int i = S; i <= T; i++)
        dis[i] = inf, vis[i] = false;
    vis[S] = 1, dis[S] = 0;
    Q.push(S);
    while(!Q.empty())
    {
        int now = Q.front(); Q.pop();
        vis[now] = false;
        for(int i = head[now]; i != -1; i = nextt[i])
        {
            int next = to[i];
            if(sz[i] && (dis[next] - (dis[now] + ct[i]) >= esp))
            {
                dis[next] = dis[now] + ct[i];
                fa[next] = i;
                if(!vis[next])
                {
                    Q.push(next);
                    vis[next] = true;
                }
            }
        }
    }
    if(dis[T] == inf)
        return false;
    int f = 0x3f3f3f3f;
    for(int i = fa[T]; i ; i = fa[to[i ^ 1]])
        f = min(f, sz[i]);
    for(int i = fa[T]; i ; i = fa[to[i ^ 1]])
        sz[i] -= f, sz[i ^ 1] += f;
    cost += dis[T] * f;
    return true;
}

bool judge(double x)
{
    tot = 0;
    memset(head, -1, sizeof(head));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            add(i, j + n, -(a[i][j] - 1.0 * x * b[i][j]));
    for(int i = 1; i <= n; i++)
        add(S, i, 0), add(i + n, T, 0);
    cost = 0;
    while(spfa());
    //printf("%lf %lf\n", x, cost);
    return -cost >= esp;
}

int main (void)
{
    scanf("%d", &n);
    S = 0; T = n << 1 | 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &b[i][j]);
    l = 0.0, r = 10000.0;
    while(abs(r - l) > esp)
    {
        mid = (l + r) / 2;
        if(judge(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%.6lf\n", l);
    return 0;
}
*/

#include<cmath>
#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

#define N 233
#define M 53333
#define inf 1e12
#define eps 1e-10
using namespace std;
int a[N][N], b[N][N], inq[M], q[M], pv[M], pe[M], mak, n, qh, qt, s, t;
double d[N];
double x[N], e[N][N], y[N], lak[N];
int vis[N], link[N];

bool find(int u, int mak) {
    vis[u] = mak;
    for (int i = 1; i <= n; i++)
        if (vis[i + n] != mak) {
            double tmp = x[u] + y[i] - e[u][i];
            if (fabs(tmp) < eps) {
                vis[i + n] = mak;
                if (link[i] == -1 || find(link[i], mak)) {
                    link[i] = u;
                    return true;
                }
            } else
                lak[i] = min(lak[i], tmp);
        }
    return false;
}

double KM() {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        x[i] = -inf;
        for (int j = 1; j <= n; j++)
            x[i] = max(x[i], e[i][j]);
    }
    memset(y, 0, sizeof(y));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            lak[j] = inf;
        while (true) {
            ++mak;
            if (find(i, mak))
                break;
            double tmp = inf;
            for (int k = 1; k <= n; k++)
                if (vis[k + n] != mak)
                    tmp = min(tmp, lak[k]);
            for (int k = 1; k <= n; k++)
                if (vis[k] == mak)
                    x[k] -= tmp;
            for (int k = 1; k <= n; k++)
                if (vis[k + n] == mak)
                    y[k] += tmp;
                else
                    lak[k] -= tmp;
        }
    }
    for (int i = 1; i <= n; i++)
        if (link[i] != -1)
            sum += e[link[i]][i];
    return sum;
}

double chk(double lim) {
    memset(vis, 0, sizeof(vis));
    mak = 0;
    memset(link, -1, sizeof(link));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            e[i][j] = (double) a[i][j] - lim * (double) b[i][j];
    return KM();
}

int main() {
    int i, j;
    double sum = 0.0;
    scanf("%d", &n);
    s = 0;
    t = n + n + 1;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]), sum += a[i][j];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &b[i][j]);
    double ans = 0.0;
    for (double l = 0.0, r = sum, o; fabs(r - l) > eps; chk(o = (l + r) / 2) > -eps ? l = o, ans = max(ans, o) : r = o);
    printf("%.6lf", ans);
}
