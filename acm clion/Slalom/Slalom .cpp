//
// Created by 孙启龙 on 2017/3/24.
//

#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 1000005;
struct P {
    double x, y;
}p[N];
int w, v, S, n, s[N];

bool judge(int x) {
    double l = p[0].x, r = p[0].x + w;
    for (int i = 0; i < n - 1; i++) {
        double dis = p[i + 1].y - p[i].y;
        double t = dis / x;
        l -= t * v;
        r += t * v;
        if (l > (p[i + 1].x + w) || r < p[i + 1].x)
            return false;
        if (l < p[i + 1].x)
            l = p[i + 1].x;
        if (r > p[i + 1].x + w)
            r = p[i + 1].x + w;
    }
    return true;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &w, &v, &n);
        for (int i = 0; i < n; i++)
            scanf("%lf%lf", &p[i].x, &p[i].y);
        scanf("%d", &S);
        for (int i = 0; i < S; i++)
            scanf("%d", &s[i]);
        sort(s, s + S);
        if (!judge(s[0])) {
            printf("IMPOSSIBLE\n");
            continue;
        }
        int l = 0, r = S, res;
        while (l < r) {
            int mid = (l + r) / 2;
            if (judge(s[mid])) {
                res = s[mid];
                l = mid + 1;
            }
            else
                r = mid;
        }
        printf("%d\n", res);
    }
    return 0;
}