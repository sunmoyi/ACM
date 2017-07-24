//
// Created by 孙启龙 on 2017/4/17.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10010

using namespace std;

int price[maxn], need[maxn];
int best, N, S;
long long ans;

int main (void)
{
    while(scanf("%d %d", &N, &S) != EOF)
    {
        for(int i = 1; i <= N; i++)
            scanf("%d %d", &price[i], &need[i]);

        ans = 0;
        best = price[1];
        for(int i = 1; i <= N; i++)
        {
            ans += (best * need[i]);
            best = min(best + S, price[i + 1]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}