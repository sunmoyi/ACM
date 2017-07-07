//
// Created by 孙启龙 on 2017/3/25.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010

using namespace std;

int n, v1[maxn], v2[maxn], res;

int main (void)
{
    while (scanf("%d", &n) == 1 && n)
    {
        res = 0;
        for (int i = 0; i < n; i++)
            scanf("%d", &v1[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &v2[i]);
        sort(v1, v1 + n);
        sort(v2, v2 + n);
        int a1 = 0, a2 = n - 1, b1 = 0, b2 = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (v1[a1] > v2[b1])
            {
                a1++;
                b1++;
                res += 200;
            }
            else if (v1[a2] > v2[b2])
            {
                a2--;
                b2--;
                res += 200;
            }
            else if (v1[a1] == v2[b2])
            {
                a1++;
                b2--;
            }
            else
            {
                a1++;
                b2--;
                res -= 200;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}