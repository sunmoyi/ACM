#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, map[105][105];
int dp[105][105];
int maxx;

int main(void)
{
	while (scanf_s("%d", &n) != EOF)
	{
		memset(map, 0, sizeof(map));
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				scanf_s("%d", &map[i][j]);
				map[i][j] += map[i][j - 1];
			}
		}

		maxx = -9999999;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= n; j++)
			{
				int sum = 0;
				for (int k = 1; k <= n; k++)
				{
					if (sum < 0)
						sum = 0;
					sum += map[k][j] - map[k][i - 1];
					maxx = max(maxx, sum);
				}
			}
		}
		printf("%d\n", maxx);
	}
	return 0;
}