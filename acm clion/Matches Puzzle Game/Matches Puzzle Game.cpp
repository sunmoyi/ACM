//
// Created by 孙启龙 on 2017/7/24.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define rep(i, n) for(int i=0;i<(int)n;i++)
using namespace std;

typedef long long ll;

const int N = 510;
const int cnt[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

ll d[N][2][8];
int M, n;
bool vis[N][2][8];

ll dp(int i, int j, int s) {
    if (vis[i][j][s])
        return d[i][j][s];
    vis[i][j][s] = 1;
    d[i][j][s] = 0;
    if (i == 0) {
        return d[i][j][s] = (j == 0 && s == 7);
    }
    rep(p, 10)
        rep(q, 10) {
            int nj = (p - j >= q ? 0 : 1);
            int a = p, b = q, c = nj * 10 + p - j - q;
            if ((s & 1) && c != 0)
                continue;
            if ((s & 2) && b != 0)
                continue;
            int nee = cnt[a] + ((s & 2) ? 0 : cnt[b]) + ((s & 1) ? 0 : cnt[c]);
            if (nee > i)
                continue;
            int vv[8] = {0};
            rep(t, 8) {
                int ts = 0;
                if ((t & 1) && (c > 0))
                    ts |= 1;
                if ((t & 2) && (b > 0))
                    ts |= 2;
                if ((t & 4) && (a > 0) && nj == 0 && i == nee)
                    ts |= 4;
                if (!vv[ts])
                    d[i][j][s] = (d[i][j][s] + dp(i - nee, nj, s | ts)) % M, vv[ts] = 1;
            }
        }
    return d[i][j][s];
}

int main() {
    int T, kase = 1;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &M);
        memset(vis, false, sizeof(vis));
        printf("Case #%d: %lld\n", kase++, dp(n - 3, 0, 0));
    }
    return 0;
}