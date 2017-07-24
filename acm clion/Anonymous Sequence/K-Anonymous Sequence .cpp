//
// Created by 孙启龙 on 2017/5/14.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 500010;

long long a[N], q[N], dp[N], sum[N];

long long dy(int j, int k) {
    return dp[j] - sum[j] + a[j+1]*j - (dp[k] - sum[k] + a[k+1]*k);
}

long long dx(int j, int k) {
    return a[j+1] - a[k+1];
}

int main()
{
    int T, n, k, i, j, x, y, z;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &k);
        sum[0] = 0;
        for(i = 1; i <= n; ++i)
        {
            scanf("%lld", a + i);
            sum[i] = sum[i-1] + a[i];
            dp[i] = 0x3f3f3f3f;
        }
        dp[0] = 0;
        int head = 0, tail = -1;
        q[++tail] = 0;
        for(i = 1; i <= n; ++i)
        {
            while(head < tail && dy(q[head], q[head+1]) >= i*dx(q[head], q[head+1]))
                head++;
            j = q[head];
            dp[i] = dp[j] + sum[i] - sum[j] - a[j+1]*(i - j);
            z = i - k + 1;
            if(z >= k)
            {
                while(head < tail)
                {
                    x = q[tail-1];
                    y = q[tail];
                    if(dy(x, y)*dx(y, z) >= dy(y, z)*dx(x, y))
                        tail--;
                    else
                        break;
                }
                q[++tail] = z;
            }
        }
        printf("%lld\n", dp[n]);
    }
    return 0;
}