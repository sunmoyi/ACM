//
// Created by 孙启龙 on 2017/4/12.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000010

using namespace std;

long long num[maxn];
long long temp;
long long ans;
bool vis[maxn];
long long pos[maxn];
long long T, n;

int main (void)
{
    while(scanf("%lld", &T) != EOF)
    {
        while(T--)
        {
            memset(vis, false, sizeof(vis));
            ans = 0, temp = 0;

            scanf("%lld", &n);
            for(long long i = 1; i <= n; i++)
                scanf("%lld", &num[i]);
            temp = num[1];
            vis[num[1]] = true;
            pos[num[1]] = 1;
            ans = temp;

            for(long long i = 2; i <= n; i++)
            {
                if(!vis[num[i]])
                {
                    temp += num[i] * i;
                    ans += temp;
                    vis[num[i]] = 1;
                    pos[num[i]] = i;
                }
                else
                {
                    long long kk = i - pos[num[i]];
                    temp += num[i] * kk;
                    ans += temp;
                    pos[num[i]] = i;
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}