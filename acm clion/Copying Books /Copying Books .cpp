//
// Created by 孙启龙 on 2017/2/26.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 510

using namespace std;

int a[maxn], usd[maxn];
long long low_bound, high_bound;
int n, m;

void init()
{
    low_bound = -1;
    high_bound = 0;
    memset(usd, 0, sizeof(usd));
}

int solve(long long mid)
{
    int sum = 0, group = 1;
    for(int i = n - 1; i >= 0; i--)
    {
        if(sum + a[i] > mid)
        {
            sum = a[i];
            group++;
            if(group > m)
                return false;
        }
        else
            sum += a[i];
    }
    return true;
}

void print(long long high_bound)
{
    int group = 1, sum = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        if(sum + a[i] > high_bound)
        {
            usd[i] = 1;
            sum = a[i];
            group++;
        }
        else
            sum += a[i];
        if(m - group == i + 1)
        {
            for(int j = 0; j <= i; j++)
                usd[j] = 1;
            break;
        }
    }
    for(int i = 0; i < n - 1; i++)
    {
        printf("%d ", a[i]);
        if(usd[i])
            printf("/ ");
    }
    printf("%d\n", a[n - 1]);
}

int main (void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        init();
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            if(low_bound < a[i])
                low_bound = a[i];
            high_bound += a[i];
        }
        long long x = low_bound, y = high_bound;
        while(x <= y)
        {
            long long mid = (x + y) >> 1;
            //printf("%lld\n", mid);
            if(solve(mid))
                y = mid - 1;
            else
                x = mid + 1;
        }
        print(x);
    }
    return 0;
}