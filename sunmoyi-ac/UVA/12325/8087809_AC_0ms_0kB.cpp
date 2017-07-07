//
// Created by 孙启龙 on 2017/2/8.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main (void)
{
    int T;
    scanf("%d", &T);
    for(int Case = 1; Case <= T; Case++)
    {
        int n, s1, v1, s2, v2;
        scanf("%d %d %d %d %d", &n, &s1, &v1, &s2, &v2);
        if(s1 > s2)
        {
            swap(s1, s2);
            swap(v1, v2);
        }
        long long ans = 0;
        if(n / s2 >= 65536)
        {
            for(long long i = 0; i <= s1; i++)
                ans = max(ans, v2 * i + (n - s2 * i) / s1 * v1);
            for(long long i = 0; i <= s2; i++)
                ans = max(ans, v1 * i + (n - s1 * i) / s2 * v2);
        }
        else
        {
            for(long long i = 0; s2 * i <= n; i++)
                ans = max(ans, v2 * i + (n - s2 * i) / s1 * v1);
        }
        printf ("Case #%d: %lld\n", Case, ans);
    }
    return 0;
}