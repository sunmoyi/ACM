//
// Created by 孙启龙 on 2017/10/3.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 20000010
using namespace std;

int T, n, m, a[maxn], b[maxn];

int main (void)
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &m);
        memset(b, 0, sizeof(b));
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for(int i = 1; i <= n; i++)
        {
            int k = m + i - 2, l = i - 1;
            if((k & l) == l)
                for(int j = i; j <= n; j++)
                    b[j] ^= a[j - i + 1];
        }
        for(int i = 1; i < n; i++)
            printf("%d ", b[i]);
        printf("%d\n", b[n]);
    }
    return 0;
}