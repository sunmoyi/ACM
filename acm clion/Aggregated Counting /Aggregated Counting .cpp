//
// Created by 孙启龙 on 2017/7/30.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100100

using namespace std;

pair<int, int>p[maxn];

int main (void)
{
    int n, t;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d %d", &p[i].second, &p[i].first);
    sort(p + 1, p + n + 1);

    int tou = 1, wei = n;
    int ans = 0;
    while(wei > tou)
    {
        ans = max(ans, p[tou].first + p[wei].first);
        t = min(p[tou].second, p[wei].second);
        p[tou].second -= t;
        if(p[tou].second == 0)
            tou++;
        p[wei].second -= t;
        if(p[wei].second == 0)
            wei--;
    }
    if(wei == tou)
        ans = max(ans, p[tou].first + p[wei].first);
    printf("%d\n", ans);
    return 0;
}