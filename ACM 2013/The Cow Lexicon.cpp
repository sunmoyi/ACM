#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int len, sum;
char str[605][30];
int lenn[605];
char g[305];
int dp[305];

int main(void)
{
	while (scanf("%d %d", &sum, &len) != EOF)
	{
		getchar();
		scanf("%s", g);
		for (int i = 1; i <= sum; i++)
		{
			scanf("%s", str[i]);
			lenn[i] = strlen(str[i]);
		}

		memset(dp, 0, sizeof(dp));
		dp[0] = 1;

		for (int i = 1; i <= len; i++)
		{
			dp[i] = dp[i - 1] + 1;
			for (int k = 1; k <= sum; k++)
			{
				int now = lenn[k] - 1, j = i;
				if (now > j)
					continue;
				while (now >= 0 && j >= 0 && j >= now)
				{
					if (str[k][now] == g[j])
						now--;
					j--;
				}
				if (now < 0)
					dp[i] = min(dp[i], dp[j] + i - j - lenn[k]);
			}
		}
		printf("%d\n", dp[len - 1]);
	}
	return 0;
}