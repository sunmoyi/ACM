#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int dp[1010];
char str[1010];
bool re[1010][1010];

int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		memset(re, false, sizeof(re));
		memset(dp, 0x42, sizeof(dp));
		scanf("%s", str + 1);
		int len = strlen(str + 1);
		for (int k = 1; k <= len; k++)
		{
			for (int i = 1; i + k - 1 <= len; i++)
			{
				int j = i + k - 1;
				if (k <= 2)
				{
					if (str[i] == str[j])
						re[i][j] = true;
				}
				else
				{
					if (re[i + 1][j - 1] && str[i] == str[j])
						re[i][j] = true;
				}
			}
		}

		dp[0] = 0;
		for (int i = 1; i <= len; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				if (re[j][i])
					dp[i] = min(dp[i], dp[j - 1] + 1);
			}
		}
		printf("%d\n", dp[len] - 1);
	}
}