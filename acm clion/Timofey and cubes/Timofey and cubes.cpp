//
// Created by 孙启龙 on 2017/2/14.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 300010

using namespace std;

long long num[maxn];
int n;

int main (void)
{
    scanf("%I64d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%I64d", &num[i]);

    int mid = n / 2;

    for(int i = 1; i <= mid; i++)
        if(i % 2 == 1)
            swap(num[i], num[n - i + 1]);

    for(int i = 1; i <= n; i++)
        printf("%I64d ", num[i]);
    printf("\n");
    return 0;
}