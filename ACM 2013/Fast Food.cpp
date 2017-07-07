#include<stdio.h>
#include<string.h>

const int maxn = 220;
const int INF = 99999999;

int dis[maxn], dp[maxn][maxn], cost[maxn][maxn];

int abs(int x){
	return x<0 ? -x : x;
}

int min(int a, int b){
	return a<b ? a : b;
}

int main(){

	int n, k;
	int cases = 0;
	while (scanf_s("%d%d", &n, &k) != EOF && (n + k))
	{
		int i, j, m;

		for (i = 1; i <= n; i++)
			scanf_s("%d", &dis[i]);

		for (i = 1; i <= n; i++)
		{
			for (j = i; j <= n; j++)
			{
				cost[i][j] = 0;
				for (m = i; m <= j; m++)
					cost[i][j] += abs(dis[m] - dis[(i + j) / 2]);
			}
		}

		for (i = 1; i <= n; i++)
			dp[1][i] = cost[1][i];
		for (i = 2; i <= k; i++)
		{
			for (j = i; j <= n; j++)
			{
				dp[i][j] = INF;
				for (m = i - 1; m <= j - 1; m++)
				{
					dp[i][j] = min(dp[i][j], dp[i - 1][m] + cost[m + 1][j]);
				}
			}
		}
		printf("Chain %d\nTotal distance sum = %d\n\n", ++cases, dp[k][n]);
	}
	return 0;
}