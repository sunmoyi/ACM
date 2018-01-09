//
// Created by 孙启龙 on 2017/8/28.
//

#include<cstdio>
#include<cstring>
#include<algorithm>


using namespace std;
typedef long long LL;
const int MAXN = 105;

int n, m;
int color[MAXN][MAXN];

int cal(int x, int y) {
    LL res = 0;
    int c = color[x][y], L = 1, R = m;
    for (int i = x; i >= 1; i--) {
        if (i < x && color[i][y] == c)
            break;
        int l = y, r = y;
        for (int j = y - 1; j >= max(1, L); j--) {
            if (color[i][j] == c)
                break;
            l = j;
        }
        L = max(L, l);
        if (i == x) {
            res += (LL) (n - x + 1LL) * (y - L + 1LL) * (R - y + 1LL);
            continue;
        }
        for (int j = y + 1; j <= min(m, R); j++) {
            if (color[i][j] == c)
                break;
            r = j;
        }
        R = min(R, r);
        res += (LL) (n - x + 1LL) * (y - L + 1LL) * (R - y + 1LL);
    }
    return res;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++)
                scanf("%d", &color[i][j]);
        }
        LL gg = 0, ss = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                gg += cal(i, j);
                ss += i * j;
            }
        }
        printf("%.9f\n", gg * 1.0 / ss);
    }
    return 0;
}