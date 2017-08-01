//
// Created by 孙启龙 on 2017/7/24.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 20010

using namespace std;

int heigh[maxn];
int n, h;

int main (void)
{
    scanf("%d %d", &n, &h);
    for(int i = 0; i < n; i++)
        scanf("%d", &heigh[i]);

    sort(heigh, heigh + n);
    long long ans = 0;
    for(int i = 0; i < n - 1; i++)
    {
        int pos2 = upper_bound(heigh, heigh + n, h - heigh[i]) - heigh;
        if(pos2 <= i)
            continue;
        ans += (pos2 - i - 1);
    }
    printf("%lld\n", ans);
}