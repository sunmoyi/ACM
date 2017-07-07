//
// Created by 孙启龙 on 2017/4/10.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 5050

using namespace std;

int sum, k, ans;
int num[maxn];

int main (void)
{
    scanf("%d %d", &sum, &k);
    for(int i = 1; i <= sum; i++)
        scanf("%d", &num[i]);

    ans = 0;
    for(int i = 2; i <= sum; i++)
    {
        int d = k - num[i - 1] - num[i];
        if(d > 0)
        {
            num[i] += d;
            ans += d;
        }
    }
    printf("%d\n", ans);
    for(int i = 1; i < sum; i++)
        printf("%d ", num[i]);
    printf("%d\n", num[sum]);
    return 0;
}