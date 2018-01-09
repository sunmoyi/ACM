//
// Created by 孙启龙 on 2017/9/4.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

int n, m, sum1[maxn], sum2[maxn], sum3[maxn],
rsum1[maxn], rsum2[maxn], rsum3[maxn], a[maxn];

int main(void)
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        scanf("%d", &a[1]);
        sum1[1] = sum2[1] = sum3[1] = a[1];
        for(int i = 2; i <= n; i++)
        {
            scanf("%d", &a[i]);
            sum1[i]  = sum1[i - 1] & a[i];
            sum2[i]  = sum2[i - 1] | a[i];
            sum3[i]  = sum3[i - 1] ^ a[i];
        }
        rsum1[n] = rsum2[n] = rsum3[n] = a[n];
        for(int i = n - 1; i >= 1; i--)
        {
            rsum1[i] = rsum1[i + 1] & a[i];
            rsum2[i] = rsum2[i + 1] | a[i];
            rsum3[i] = rsum3[i + 1] ^ a[i];
        }
        int q;
        while(m--)
        {
            scanf("%d", &q);
            if(q == 1)
                printf("%d %d %d\n", rsum1[q + 1], rsum2[q + 1], rsum3[q + 1]);
            else if(q == n)
                printf("%d %d %d\n", sum1[n-1], sum2[n-1], sum3[n-1]);
            else
                printf("%d %d %d\n", sum1[q-1] & rsum1[q+1], sum2[q-1]|rsum2[q+1], sum3[q-1]^rsum3[q+1]);
        }
    }
}