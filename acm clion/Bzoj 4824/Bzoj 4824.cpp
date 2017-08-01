//
// Created by 孙启龙 on 2017/7/30.
//

#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;
typedef long long ll;

inline char nc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}

inline void read(int &x) {
    char c = nc(), b = 1;
    for (; !(c >= '0' && c <= '9'); c = nc())
        if (c == '-')
            b = -1;
    for (x = 0; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = nc());
    x *= b;
}

inline void read(char *s) {
    char c = nc();
    int len = 0;
    for (; !(c == '<' || c == '>'); c = nc());
    for (; c == '<' || c == '>'; s[++len] = c, c = nc());
}

const int N = 105;
const int P = 1e9 + 7;

int n;
char s[N];

struct edge {
    int u, v, next;
} G[N];
int head[N], inum;

inline void add(int u, int v, int p) {
    G[p].u = u;
    G[p].v = v;
    G[p].next = head[u];
    head[u] = p;
}

#define V G[p].v

ll C[N][N], f[N][N];
ll g[N];
int size[N];

inline void dfs(int u) {
    size[u] = 1;
    for (int p = head[u]; p; p = G[p].next)
        dfs(V);
    f[u][1] = 1;
    for (int p = head[u]; p; p = G[p].next)
    {
        int n = size[u], m = size[V];
        for (int i = 1; i <= n + m; i++)
            g[i] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (s[V] == '>')
                    for (int x = j; x <= m; x++)
                        g[x + i] += f[u][i] * f[V][j] % P * C[i + x - 1][x] % P * C[n + m - i - x][m - x] % P;
                else
                    for (int x = 0; x < j; x++)
                        g[x + i] += f[u][i] * f[V][j] % P * C[i + x - 1][x] % P * C[n + m - i - x][m - x] % P;
        for (int i = 1; i <= n + m; i++)
            f[u][i] = g[i] % P;
        size[u] += size[V];
    }
}


int main() {
    read(n);
    read(s + 1);
    for (int i = 2; i <= n; i++)
        add(i / 2, i, ++inum);
    C[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
    }
    dfs(1);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans += f[1][i];
    printf("%d\n", ans % P);
    return 0;
}