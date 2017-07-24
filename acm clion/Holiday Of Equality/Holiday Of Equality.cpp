//
// Created by 孙启龙 on 2017/2/2.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int num[100000], sum;
int maxx, n;

int main (void)
{
    while(scanf("%d", &n) != EOF)
    {
        maxx = -0x3f3f3f3f;sum = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &num[i]);
            maxx = max(maxx, num[i]);
        }
        for(int i = 1; i <= n; i++)
            sum += (maxx - num[i]);

        printf("%d\n", sum);
    }
    return 0;
}