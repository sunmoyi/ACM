#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 55
using namespace std;

int num[55][55];
int g[55][55];
int f[55][55];

void init()
{
	for (int i = 1; i < maxn; i++)
		num[i][0] = num[0][i] = 0;
	for (int i = 1; i < maxn; i++)
	{
		for (int j = 1; j < maxn; j++)
		{
			if (i < j)
				num[i][j] = 0;
			else if (i == j)
				num[i][j] = 1;
			else
				num[i][j] = num[i - 1][j - 1] + num[i - j][j];
		}
	}
	f[0][0] = 1, g[0][0] = 1;
	for (int i = 1; i <= 52; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			g[i][j] = f[i - j][j];
			f[i][j] = f[i - 1][j - 1] + g[i - j][j];
		}
	}
}

int dfs(int n, int m)
{
	if (n == 1 && m == 1)
		return 1;
	else if (m == 1)
		return 0;
	else if (n < m)
		return dfs(n, n);
	else if (n == m)
		return (1 + dfs(n, m - 1));
	else
		return (dfs(n, m - 1) + dfs(n - m, m - 1));
}


int main(void)
{
	int n, m;
	init();
	while (scanf("%d %d", &n, &m) != EOF)
	{
		printf("%d\n", num[n][m]);
		printf("%d\n", dfs(n, n));
		int sum = 0;
		for (int i = 1; i <= n; i++)
			sum += f[n][i];
		printf("%d\n", sum);
	}
	return 0;
}