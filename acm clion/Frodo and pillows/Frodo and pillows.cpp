//
// Created by 孙启龙 on 2017/2/9.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m, k;
int ans = 1, cost = 1;

int main (void)
{
    scanf("%d %d %d", &n, &m, &k);

    m -= n;
    if(m == 0)
        return printf("1\n"), 0;
    while(m > 0)
    {
        if(k + ans <= n)
            ++cost;
        if(k - ans > 0)
            ++cost;
        m -= cost;
        ++ans;
    }
    printf("%d\n", ans);
    return 0;
}