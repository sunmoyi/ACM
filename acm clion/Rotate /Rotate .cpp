//
// Created by 孙启龙 on 2017/8/5.
//

#include <cstdio>
#include <cmath>

#define pi acos(-1.0)

int main() {
    int t;
    int n;
    double x1, y1, x2, y2, r;
    double tx1, ty1, tx2, ty2;
    double rx0, ry0, a;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        x1 = y1 = 0;
        x2 = y2 = 1;
        r = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%lf%lf%lf", &rx0, &ry0, &a);
            r += a;
            if (r >= 2 * pi)
                r -= 2 * pi;
            tx1 = (x1 - rx0) * cos(a) - (y1 - ry0) * sin(a) + rx0;
            ty1 = (x1 - rx0) * sin(a) + (y1 - ry0) * cos(a) + ry0;
            tx2 = (x2 - rx0) * cos(a) - (y2 - ry0) * sin(a) + rx0;
            ty2 = (x2 - rx0) * sin(a) + (y2 - ry0) * cos(a) + ry0;
            x1 = tx1, y1 = ty1;
            x2 = tx2, y2 = ty2;
        }
        double t1 = (x1 * x1 + y1 * y1) * (2 * y2 - 2) - 2 * y1 * (x2 * x2 + y2 * y2) + 4 * y1;
        double t2 = 4 * y1 - 4 * y1 * x2 + 4 * x1 * y2 - 4 * x1;
        double x = t1 / t2;
        double t3 = (x1 * x1 + y1 * y1) - 2 * x * x1;
        double t4 = 2 * y1;
        double y = t3 / t4;
        printf("%lf %lf %lf\n", x, y, r);
    }
    return 0;
}