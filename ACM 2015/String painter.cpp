#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110

using namespace std;

char str1[maxn], str2[maxn];
int dp[maxn][maxn], ans[maxn], len;

int main(void)
{
	while (scanf("%s %s", str1, str2) != EOF)
	{
		len = strlen(str1);
		memset(dp, 0, sizeof(dp));
		for (int j = 0; j < len; j++)
		{
			for (int i = j; i >= 0; i--)
			{
				dp[i][j] = dp[i + 1][j] + 1;
				for (int k = i + 1; k <= j; k++)
					if (str2[i] == str2[k])
						dp[i][j] = min(dp[i][j], dp[i + 1][k] + dp[k + 1][j]);
			}
		}
		for (int i = 0; i < len; i++)
			ans[i] = dp[0][i];
		for (int i = 0; i < len; i++)
		{
			if (str1[i] == str2[i])
				ans[i] = ans[i - 1];
			else
			{
				for (int j = 0; j < i; j++)
					ans[i] = min(ans[i], ans[j] + dp[j + 1][i]);
			}
		}
		printf("%d\n", ans[len - 1]);
	}
	return 0;
}