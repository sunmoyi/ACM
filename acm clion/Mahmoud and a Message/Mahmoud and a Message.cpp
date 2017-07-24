//
// Created by 孙启龙 on 2017/2/12.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010
#define mod 1000000007

using namespace std;

int s[30];
char str[maxn];
int dp[maxn], dp2[maxn], n;

int main (void)
{
    while(scanf("%d", &n) != EOF)
    {
        scanf("%s", str + 1);
        for(int i = 0; i < 26; i++)
            scanf("%d", &s[i]);

        memset(dp, 0, sizeof(dp));
        memset(dp2, 0x3f3f3f3f, sizeof(dp2));
        dp[0] = 1;
        dp2[0] = 0;
        int maxx = 1;
        for(int i = 1; i <= n; i++)
        {
            int minn = 0x3f3f3f3f;
            for(int j = 1; j <= s[str[i] - 'a']; j++)
            {
                if(i >= j)
                {
                    minn = min(minn, s[str[i - j + 1] - 'a']);
                    if (minn >= j)
                    {
                        dp[i] = (dp[i] + dp[i - j]) % mod;
                        dp2[i] = min(dp2[i], dp2[i - j] + 1);
                        maxx = max(maxx, j);
                    } else
                        break;
                }
                else
                    break;
            }
        }
        printf("%d\n%d\n%d\n", dp[n], maxx, dp2[n]);
    }
    return 0;
}