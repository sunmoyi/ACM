//
// Created by 孙启龙 on 2017/4/10.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 5050

using namespace std;

int num[maxn];
int sum, k, ans;

int main (void)
{
    scanf("%d", &k);
    sum = (1 << (k + 1)) - 1;
    //printf("%d\n", sum);
    for(int i = 2; i <= sum; i++)
        scanf("%d", &num[i]);

    sum /= 2;
    ans = 0;
    for(;sum >= 1; sum--)
    {
        int left = num[sum << 1 | 1];
        int right = num[sum << 1];
        int cha = max(left, right) - min(left, right);
        num[sum] += max(left, right);
        ans += cha;
        //printf("num[%d]: %d\n", sum, num[sum]);
    }
    printf("%d\n", ans);
    return 0;
}