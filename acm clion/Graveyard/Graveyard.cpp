//
// Created by 孙启龙 on 2016/11/21.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

int main (void)
{
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        double ans = 0;
        for(int i = 1; i <= n; i++)
        {
            double pos = i * 1.0 / n * (n + m);
            ans += fabs(pos - floor(pos + 0.5)) / (n + m);
        }
        printf("%.4lf\n", ans * 10000);
    }
    return 0;
}