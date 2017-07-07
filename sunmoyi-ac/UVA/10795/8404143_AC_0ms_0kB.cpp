//
// Created by 孙启龙 on 2017/3/11.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 210

using namespace std;

int n, start[maxn], finish[maxn];

long long f(int *p, int i, int final)
{
    if(i == 0)
        return 0;
    else if (p[i] == final)
        return f(p, i - 1, final);
    else
        return f(p, i - 1, 6 - p[i] - final) + ((long long)1LL << (i - 1));
}

int main (void)
{
    int Case = 0;
    while(scanf("%d", &n) != EOF && n)
    {
        for(int i = 1; i <= n; i++)
            scanf("%d", &start[i]);
        for(int i = 1; i <= n; i++)
            scanf("%d", &finish[i]);
        int k = n;
        while(k >= 1 && start[k] == finish[k])
            k--;

        long long ans = 0;
        if(k >= 1)
        {
            int other = 6 - finish[k] - start[k];
            ans = f(start, k - 1, other) + f(finish, k - 1, other) + 1;
        }
        printf("Case %d: %lld\n", ++Case, ans);
    }
    return 0;
}