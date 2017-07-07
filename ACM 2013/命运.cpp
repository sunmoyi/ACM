#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int ans;
int wide, len;
int num[25][1010];
int dp[25][1010];

int main(void)
{
	while (scanf_s("%d", &ans) != EOF)
	{
		while (ans--)
		{
			scanf_s("%d %d", &wide, &len);
			for (int i = 1; i <= wide; i++)
			{
				for (int j = 1; j <= len; j++)
				{
					scanf_s("%d", &num[i][j]);
				}
			}

			for (int j = 0; j <= wide; j++)
				dp[j][0] = -1000;
			for (int i = 0; i <= len; i++)
				dp[0][i] = -1000;
			dp[1][0] = dp[0][1] = 0;
			for (int i = 1; i <= wide; i++)
			{
				for (int j = 1; j <= len; j++)
				{
					int temp = max(dp[i - 1][j], dp[i][j - 1]);
					for (int s = 2; s <= j; s++)
					{
						if (j % s == 0)
						{
							temp = max(temp, dp[i][j / s]);
						}
					}
					dp[i][j] = temp + num[i][j];
				}
			}
			printf("%d\n", dp[wide][len]);
		}
	}
	return 0;
}