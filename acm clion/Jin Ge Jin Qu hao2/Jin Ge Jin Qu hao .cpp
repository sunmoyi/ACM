//
// Created by 孙启龙 on 2017/3/3.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 180 * 50 + 5

using namespace std;

int n, maxx;
int t[55];

struct node{
    int num;
    int time;
    bool friend operator < (const node&a, const node&b)
    {
        return a.num < b.num || (a.num == b.num && a.time < b.time);
    }
}dp[maxn];

int main (void)
{
    int T;
    scanf("%d", &T);
    for(int iCase = 1; iCase <= T; iCase++)
    {
        scanf("%d %d", &n, &maxx);
        memset(dp, 0, sizeof(dp));

        int sum = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &t[i]);
            sum += t[i];
        }

        maxx = min(maxx - 1, sum);

        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = maxx; j >= t[i]; j--)
            {
                node temp;
                temp.num = dp[j - t[i]].num + 1;
                temp.time = dp[j - t[i]].time + t[i];
                if(dp[j] < temp)
                    dp[j] =  temp;
            }
        }
        printf("Case %d: ", iCase);
        printf("%d %d\n", dp[maxx].num + 1, dp[maxx].time + 678);
    }
    return 0;
}