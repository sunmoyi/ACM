//
// Created by 孙启龙 on 2017/4/22.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

pair<long long, long long>a[110], b[110];
long long T, n, m, x, y;

int main (void)
{
    while(scanf("%lld", &T) != EOF)
    {
        while(T--)
        {
            scanf("%lld %lld %lld %lld", &n, &m, &x, &y);
            for(int i = 0; i < x; i++)
                scanf("%lld %lld", &a[i].first, &a[i].second);
            for(int i = 0; i < y; i++)
                scanf("%lld %lld", &b[i].first, &b[i].second);

            sort(a, a + x);
            sort(b, b + y);

            long long posa = 0, posb = 0, ans = 0;
            for(long long i = max(a[posa].first, b[posb].first); i <= n;)
            {
                long long timee = min(a[posa].second, b[posb].second) - i + 1;
                //printf("%d %d\n", i, timee);
                if(timee >= m)
                    ans += timee - m + 1;
                if(a[posa].second < b[posb].second)
                {
                    posa++;
                    i = max(a[posa].first, b[posb].first);
                    if(posa >= x)
                        break;
                }
                else if (a[posa].second > b[posb].second)
                {
                    posb++;
                    i = max(a[posa].first, b[posb].first);
                    if(posb >= y)
                        break;
                }
                else if (a[posa].second == b[posb].second)
                {
                    posa++;
                    posb++;
                    i = max(a[posa].first, b[posb].first);
                    if(posa >= x)
                        break;
                    if(posb >= y)
                        break;
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}