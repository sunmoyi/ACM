//
// Created by 孙启龙 on 2017/3/13.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

double PI = acos(-1.0);
double A[10010];
int n, f;

bool ok(double area)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += floor(A[i] / area);
    return sum >= f + 1;
}

int main (void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &f);
        double maxa = -1;
        for(int i = 0; i < n; i++)
        {
            int r;
            scanf("%d", &r);
            A[i] = PI * r * r;
            maxa = max(maxa, A[i]);
        }
        double L = 0, R = maxa;
        while(R - L > 1e-5)
        {
            double M = (R + L) / 2;
            if(ok(M))
                L = M;
            else
                R = M;
        }
        printf("%.5lf\n", L);
    }
    return 0;
}