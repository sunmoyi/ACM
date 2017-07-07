#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int maxx, num, v[25];
int dp[100001];
int g[25][10001];

int main(void)
{
	while (scanf_s("%d %d", &maxx, &num) != EOF)
	{
		for (int i = 1; i <= num; i++)
			scanf_s("%d", &v[i]);

		memset(dp, 0, sizeof(dp));
		memset(g, 0, sizeof(g));

		for (int i = 1; i <= num; i++)
		{
			for (int j = maxx; j >= v[i]; j--)
			{
				if (dp[j] <= dp[j - v[i]] + v[i])
				{
					dp[j] = dp[j - v[i]] + v[i];
					g[i][j] = 1;
				}
			}
		}

		for (int i = num, j = maxx; i > 0; i--)
		{
			if (g[i][j] == 1)
			{
				printf("%d ", v[i]);
				j -= v[i];
			}
		}
		printf("sum:%d\n", dp[maxx]);
	}
	return 0;
}