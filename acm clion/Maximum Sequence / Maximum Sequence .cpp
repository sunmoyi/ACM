//
// Created by 孙启龙 on 2017/8/28.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include <queue>

#define maxn 250010
#define mod 1000000007

using namespace std;

int a[maxn << 1], b[maxn], ma[maxn];

int main  (void)
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        memset(ma, 0, sizeof(ma));
        memset(a, 0, sizeof(a));
        int x;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &x);
            a[i] = x - i;
        }
        for(int i = n; i >= 1; i--)
            ma[i] = max(a[i], ma[i + 1]);
        for(int i = 1; i <= n; i++)
            scanf("%d", &b[i]);
        priority_queue<int>Q;
        for(int i = 1; i <= n; i++)
            Q.push(ma[b[i]]);
        int ans = 0, temp = 0;
        for(int i = n + 1; i <= 2 * n; i++)
        {
            int s = Q.top();
            if(temp > s)
                a[i] = temp;
            else
            {
                a[i] = s;
                Q.pop();
            }
            ans = (ans + a[i]) % mod;
            temp = max(temp, a[i] - i);
        }
        printf("%d\n", ans % mod);
    }
    return 0;
}