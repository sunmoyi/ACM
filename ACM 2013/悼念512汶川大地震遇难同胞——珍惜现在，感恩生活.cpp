#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int ans, maxx, sum, M[105], V[105], W[105];
int dp[500][500];

int main(void)
{
	while (scanf_s("%d", &ans) != EOF)
	{
		while (ans--)
		{
			scanf_s("%d %d", &maxx, &sum);
			for (int i = 1; i <= sum; i++)
			{
				scanf_s("%d %d %d", &M[i], &V[i], &W[i]);
			}

			memset(dp, 0, sizeof(dp));

			for (int i = 1; i <= sum; i++)
			{
				for (int j = 0; j <= maxx; j++)
				{
					int MAX = 0;
					for (int k = 0; k <= W[i] && k * M[i] <= j; k++)
					{
						int temp = dp[i - 1][j - k * M[i]] + k * V[i];
						if (temp > MAX)
							MAX = temp;
					}
					dp[i][j] = MAX;
				}
			}
			printf("%d\n", dp[sum][maxx]);
		}
	}
	return 0;
}