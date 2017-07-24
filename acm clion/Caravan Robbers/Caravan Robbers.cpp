//
// Created by 孙启龙 on 2017/3/8.
//

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 1e5 + 5;

struct node{
    int l, r;
    bool operator < (const node &p) const{
        return r < p.r;
    }
};
node a[maxn];
int n;

int main(){
    while(scanf("%d", &n) == 1)
    {
        for(int i = 0; i < n; ++i)
            scanf("%d %d", &a[i].l, &a[i].r);

        double r = 1000000, l = 0, ans = 0;

        sort(a, a+n);
        while(r - l > eps)
        {
            double m = ((l+r)/2.0);
            bool ok = true;
            double s = 0;
            for(int i = 0; i < n; ++i)
            {//贪心
                if(s < a[i].l)
                    s = a[i].l;
                if(s + m > a[i].r)
                {
                    ok = false;
                    break;
                }
                s += m;
            }
            if(ok)
            {
                ans = m;
                l = m;
            }
            else
                r = m;
        }

        int rp = 0, rq = 1;//小数化分数
        for(int p, q = 1; q <= n; ++q)
        {
            p = round(ans * q);
            if(fabs((double)p/q - ans) < fabs((double)rp/rq - ans))
            {
                rp = p;  rq = q;
            }
        }

        printf("%d/%d\n", rp, rq);
    }
    return 0;
}