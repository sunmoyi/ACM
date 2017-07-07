//
// Created by 孙启龙 on 2017/3/2.
//

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

const int maxn = 17005;

int n, num, pos, C;
int r[maxn];
bool flag;
double tmp;
double x[5], a[maxn][10];

int main()
{
    while (~scanf("%d", &n), n)
    {
        flag = true;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; ++i)
        {
            scanf("%lf%lf%lf", &x[0], &x[1], &x[2]);
            for (int j = 0; j < 8; ++j)
            {
                num = j;
                pos = 0;
                while (num)
                {
                    if (num & 1)
                        a[i][j] += x[pos];
                    num >>= 1;
                    ++pos;
                }
            }
            sort(a[i], a[i] + 8);
        }
        for (int i = 0; i < n; ++i)
            scanf("%d", &r[i]);
        tmp = a[r[0] - 1][7];
        for (int i = 1; i < n; ++i)
            if (r[i] > r[i - 1])
            {
                for (int j = 7; j >= 0; --j)
                    if (a[r[i] - 1][j] <= tmp + 1e-6)
                    {
                        tmp = a[r[i] - 1][j];
                        break;
                    }
            }
            else
            {
                flag = false;
                for (int j = 7; j >= 0; --j)
                    if (fabs(a[r[i] - 1][j] - tmp) < 1e-6)
                        continue;
                    else if (a[r[i] - 1][j] < tmp)
                    {
                        tmp = a[r[i] - 1][j];
                        flag = true;
                        break;
                    }
                if (!flag)
                    break;
            }
        printf("Case %d: ", ++C);
        if (flag)
            printf("%.2lf\n", tmp);
        else
            printf("No solution\n");
    }
    return 0;
}