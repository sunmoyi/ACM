//
// Created by 孙启龙 on 2017/5/15.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 1e5 + 10;
int a[maxN];
int n, m;

int test(int x)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += lower_bound(a + i, a + n, a[i] + x) - (a + i) - 1;
    if (sum <= m)
        return 1;
    return 0;
}

int main()
{
    while (scanf("%d", &n) == 1)
    {
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        sort(a, a + n);

        int l, r, mid, ans;
        m = n * (n - 1) / 2;
        if (m % 2 == 1)
            m /= 2;
        else
            m = m / 2 - 1;

        l = 0, r = a[n - 1] - a[0] + 1;
        while (l < r)
        {
            mid = (l + r) / 2;
            if (test(mid))
            {
                l = mid + 1;
                ans = mid;
            }
            else
                r = mid;
        }
        printf("%d\n", ans);
    }
    return 0;
}