#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010
#define maxm 110010

using namespace std;

int maxx, n, ans;
int val[maxn], num, VAL;
int dp[maxm];

int main(void)
{
	while (scanf("%d %d", &maxx, &n) != EOF)
	{
		ans = 1;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d %d", &num, &VAL);
			int kk = 1;
			while (num >= kk)
			{
				val[ans++] = kk * VAL;
				num -= kk;
				kk *= 2;
			}
			val[ans++] = num * VAL;
		}

		memset(dp, 0, sizeof(dp));

		for (int i = 1; i < ans; i++)
		{
			for (int j = maxx; j >= val[i]; j--)
			{
				dp[j] = max(dp[j], dp[j - val[i]] + val[i]);
			}
		}
		printf("%d\n", dp[maxx]);
	}
}