//
// Created by 孙启龙 on 2017/10/3.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

#define maxn 2000010

using namespace std;

struct node{
    double x, y, ang;
    int v;

    void input() {
        scanf("%lf %lf %d", &x, &y, &v);
        ang = atan(y / x);
    }

    bool operator < (const node &p) const {
        return ang < p.ang;
    }
}p[maxn];
int n, T;
long long sumL, sumR, ans;

int main (void)
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            p[i].input();
        sort(p + 1, p + n + 1);
        sumL = sumR = ans = 0;
        for(int i = 1; i <= n; i++)
            p[i].x > 0? sumL += p[i].v: sumR += p[i].v;
        ans = sumL * sumR;
        for(int i = 1; i <= n; i++)
            (p[i].x > 0? (sumL -= p[i].v, sumR += p[i].v): (sumR -= p[i].v, sumL += p[i].v)), ans = max(ans, sumL * sumR);

        printf("%lld\n", ans);
    }
    return 0;
}