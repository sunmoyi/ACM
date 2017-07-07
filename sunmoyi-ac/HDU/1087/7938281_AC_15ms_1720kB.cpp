//
// Created by 孙启龙 on 2017/1/18.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1100

using namespace std;

int ans, num[maxn];
int dp[maxn];

int main (void)
{
    while(scanf("%d", &ans) != EOF && ans)
    {
        for(int i = 1; i <= ans; i++)
            scanf("%d", &num[i]);

        for(int i = 1; i <= ans; i++)
        {
            int temp = 0;
            int maxx = -1;
            bool find = false;
            for(int j = 1; j <= i; j++)
            {
                if(num[j] < num[i] && dp[j] + num[i] > maxx)
                {
                    maxx = dp[j] + num[i];
                    find = true;
                }
            }
            if(find)
                dp[i] = maxx;
            else
                dp[i] = num[i];
        }
        int out = -1;
        for(int i = 1; i <= ans; i++)
            out = max(out, dp[i]);
        printf("%d\n", out);
    }
    return 0;
}