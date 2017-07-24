//
// Created by 孙启龙 on 2017/3/24.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 10010

using namespace std;

double n, l, w;
struct node{
    double l, r;
}p[maxn];

int cmp(node a, node b)
{
    return a.l < b.l;
}

node cul(double cen, double ra)
{
    node temp;
    temp.l = cen - sqrt(ra * ra - (w / 2) * (w / 2));
    temp.r = cen + sqrt(ra * ra - (w / 2) * (w / 2));
    return temp;
}

int main (void)
{
    while(scanf("%lf %lf %lf", &n, &l, &w))
    {
        int num = 0;
        double cen, ra;
        for(int i = 0; i < n; i++)
        {
            scanf("%lf %lf", &cen, &ra);
            if(ra < w / 2)
                continue;
            else
                p[num++] = cul(cen, ra);
        }
        sort(p, p + num, cmp);

        double mi = 0;
        int t = 0;
        if(p[0].l > 0)
        {
            printf("-1\n");
            continue;
        }
        while(mi < l)
        {
            double temp = mi;
            for(int i = 0; i < num ;i++)
                if(p[i].l <= mi && p[i].r > temp)
                    temp = p[i].r;
            if(temp == mi)
            {
                t = -1;
                break;
            }
            mi = temp;
            t++;
        }
        printf("%d\n", t);
    }
    return 0;
}