//
// Created by 孙启龙 on 2017/4/12.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010
using namespace std;

int n, m, a[maxn];

int main(void)
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for(int i = 1; i <= m; i++)
    {
        int maxx = 0, w;
        for(int j = 1; j <= n; j++)
        {
            if(a[j] > maxx)
            {
                maxx = a[j];
                w = j;
            }
        }
        printf("%d\n", w);
        int p = a[w] / (n-1);
        int q = a[w] % (n-1);
        a[w] = 0;
        for(int j = 1; j <= n; j++)
        {
            if(j != w)
            {
                a[j] += p;
                if(q)
                {
                    a[j]++;
                    q--;
                }
            }
        }
    }
    return 0;
}