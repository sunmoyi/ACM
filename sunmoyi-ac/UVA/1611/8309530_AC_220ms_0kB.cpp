//
// Created by 孙启龙 on 2017/3/2.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10010

using namespace std;

int v[maxn], p[maxn];
int s[2 * maxn + 5][2], len;

int main (void)
{
    int T, n;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &v[i]);
            p[v[i]] = i;
        }
        len = 0;
        for(int i = 1; i <= n; i++)
        {
            while(p[i] != i)
            {
                int t = min(n - p[i] + 1, p[i] - i);
                int m = p[i], l = p[i] - t, r = p[i] + t - 1;
                s[len][0] = l, s[len++][1] = r;
                for(int j = 0; j <= t - 1; j++)
                    swap(v[l + j], v[m + j]), swap(p[v[l + j]], p[v[m + j]]);
            }
        }
        printf("%d\n", len);
        for(int i = 0; i <= len - 1; i++)
            printf("%d %d\n", s[i][0], s[i][1]);
    }
    return 0;
}