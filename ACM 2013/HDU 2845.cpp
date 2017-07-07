#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m, map[200010];
int a[10000], b[10000];
int dp[10000];

int main(void)
{
	while (scanf_s("%d %d", &n, &m) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &map[1]);
			a[1] = map[1];
			for (int j = 2; j <= m; j++)
			{
				scanf_s("%d", &map[j]);
				a[j] = max(a[j - 1], a[j - 2] + map[j]);
			}
			b[i] = a[m];
		}

		dp[1] = b[1];
		for (int i = 2; i <= n; i++)
		{
			dp[i] = max(dp[i - 1], dp[i - 2] + b[i]);
		}

		printf("%d\n", dp[n]);
	}
	return 0;
}