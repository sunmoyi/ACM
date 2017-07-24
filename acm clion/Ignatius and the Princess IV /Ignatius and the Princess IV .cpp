//
// Created by 孙启龙 on 2017/1/18.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, s, num[1000010], ans;

int main (void)
{
    while(scanf("%d", &n) != EOF)
    {
        memset(num, 0, sizeof(num));
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &s);
            num[s]++;
            if(num[s] > (n / 2))
                ans = s;
        }
        printf("%d\n", ans);
    }
    return 0;
}