//
// Created by 孙启龙 on 2017/2/8.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long quick1(long long a, long long b)
{
    long long ans = 1;
    while(b)
    {
        if(b & 1)
        {
            ans *= a;
            b--;
        }
        b >>= 1;
        a *= a;
    }
    return ans;
}

int main (void)
{
    int n;
    char c[100];
    scanf("%d", &n);
    scanf("%s", c);
    long long len = (long long)strlen(c);
    long long now = 0;
    long long ans = 0;
    long long f1;

    for(long long i = len - 1; i >= 0; i--)
    {
        long long now1 = c[i] - '0';
        long long g = 1;
        f1 = i;
        while(i - 1 >= 0 && now1 + (c[i -1] - '0') * quick1(10, g) < n && now1 + 1*quick1(10, g) < n)
        {
            now1 += (c[i - 1] - '0') * quick1(10, g);
            g++;
            i--;
            if(c[i] != '0')
                f1 = i;
        }
        i = f1;
        ans += now1 * quick1(n, now);
        now++;
    }
    printf("%I64d\n", ans);
}