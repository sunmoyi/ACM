//
// Created by 孙启龙 on 2017/7/28.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 210

using namespace std;

int a, b;
int sum_odd, sum_even;
int n;

int main (void)
{
    sum_even = sum_odd = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d %d", &a, &b);
        sum_even += a;
        sum_odd += b;
    }
    if(sum_even != sum_odd)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}