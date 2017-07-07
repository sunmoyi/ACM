//
// Created by 孙启龙 on 2017/2/10.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
const int N = 250;
const int tmp = 105;
const int dir[4][2] = { {1, 0}, {0, 1}, {0, -1}, {-1, 0} };
const char sign[5] = "ensw";

int n, ans;
int g[N][N], v[N], sum[tmp];

void init() {
    ans = 0;
    memset(g, 0, sizeof(g));

    int a, b, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &a, &b);
        if (abs(a) > tmp || abs(b) > tmp) continue;
        g[a+tmp][b+tmp] = -1;
    }
}

bool judge(int x, int y, int d, int k) {
    for (int i = 1; i <= k; i++) {
        x += dir[d][0]; y += dir[d][1];
        if (abs(x) > tmp || abs(y) > tmp) continue;
        if (g[x+tmp][y+tmp] == -1) return true;
    }
    if (abs(x) + abs(y) > sum[20] - sum[k]) return true;
    return false;
}

void dfs(int x, int y, int d, int f) {
    if (d > n) {
        if (x == 0 && y == 0) {
            for (int i = 1; i <= n; i++) printf("%c", sign[v[i]]);
            printf("\n");
            ans++;
        }
        return;
    }

    int& i = v[d];
    for (i = 0; i < 4; i++) {
        if (i == f || i + f == 3) continue;
        if (judge(x, y, i, d)) continue;
        int p = x + dir[i][0] * d, q = y + dir[i][1] * d;
        if (g[p+tmp][q+tmp]) continue;
        g[p+tmp][q+tmp] = 1;
        dfs(p, q, d + 1, i);
        g[p+tmp][q+tmp] = 0;
    }
}

int main() {
    sum[0] = 0;
    for (int i = 1; i <= 20; i++) sum[i] = sum[i-1] + i;
    int cas; scanf("%d", &cas);
    while (cas--) {
        init();
        dfs(0, 0, 1, -1);
        printf("Found %d golygon(s).\n\n", ans);

    }
    return 0;
}  