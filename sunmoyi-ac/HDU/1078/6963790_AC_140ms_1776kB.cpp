#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110

using namespace std;

int dp[maxn][maxn], a[maxn][maxn];
int to[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int n, k;

bool check(int x, int y)
{
	if (x <= 0 || x > n || y <= 0 || y > n)
		return false;
	return true;
}

int dfs(int x, int y)
{
	if (dp[x][y])
		return dp[x][y];
	int maxx = 0;
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int xx = x + to[j][0] * i;
			int yy = y + to[j][1] * i;
			if (!check(xx, yy))
				continue;
			if (a[xx][yy] > a[x][y])
				maxx = max(maxx, dfs(xx, yy));
		}
	}
	return dp[x][y] = maxx + a[x][y];
}

int main(void)
{
	while(scanf("%d %d", &n, &k) != EOF && n > 0 && k > 0)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &a[i][j]);

		memset(dp, 0, sizeof(dp));

		printf("%d\n", dfs(1, 1));
	}
	return 0;
}