//
// Created by 孙启龙 on 2017/8/5.
//

#include <stdio.h>
#include <math.h>
#include <algorithm>

#define N 55
using namespace std;
double num095[N];
int a[N];

void gettable() {
    for (int i = 0; i <= 49; i++)
        num095[i] = pow(0.95, i);
}

bool cmp(int a, int b) {
    return a > b;
}

int main()
{
    int t;
    scanf("%d", &t);
    gettable();
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sort(a + 1, a + n + 1, cmp);
        double sum = 0;
        for (int i = 1; i <= n; i++)
            sum += a[i] * 1.0000 * num095[i - 1];
        printf("%lf\n", sum);
    }
    return 0;
}