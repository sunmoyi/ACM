//
// Created by 孙启龙 on 2017/3/26.
//

#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define maxn 5010
#define esp 1e-6
struct Target{
    double y, x_l, x_r;
}t[maxn];

bool cmp(Target &a, Target &b) {
    return a.y < b.y;
}

double w;
int n;
int judge(double pos) {
    double L = atan2(t[0].y, t[0].x_r - pos);
    double R = atan2(t[0].y, t[0].x_l - pos);
    for(int i = 1; i < n; i++) {
        double l = atan2(t[i].y, t[i].x_r - pos);
        double r = atan2(t[i].y, t[i].x_l - pos);

        if(r - L < -esp)
            return -1;
        if(l - R > esp)
            return 1;
        L = max(L, l);
        R = min(R, r);
    }
    return 0;
}

bool solve() {
    sort(t,t + n, cmp);
    double l = 0, r = w;
    int mark;
    while(r - l > esp) {
        double mid = (r + l) / 2;
        mark = judge(mid);
        if(mark == 0)
            return true;
        else if(mark == -1)
            r = mid;
        else
            l = mid;
    }
    return false;
}

int main() {
    int test;
    scanf("%d", &test);
    while(test--) {
        scanf("%lf%d", &w, &n);
        for(int i = 0; i < n; i++)
            scanf("%lf%lf%lf", &t[i].y, &t[i].x_l, &t[i].x_r);
        printf("%s\n", solve()?"YES":"NO");
    }
    return 0;
}