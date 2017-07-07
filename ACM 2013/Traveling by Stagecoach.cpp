#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10
#define maxm 40
#define INF 0x3f3f3f3f

using namespace std;

int n, m, a, b;
int t[maxn];
int d[maxm][maxm];
double dp[1 << maxn][maxm];

void solve()
{
	for (int i = 0; i < (1 << n); i++)
		fill(dp[i], dp[i] + m, INF);

	dp[(1 << n) - 1][a - 1] = 0;
	double res = INF;
	for(int s = (1 << n) - 1; s >= 0; s--)
	{
		res = min(res, dp[s][b - 1]);
		for (int v = 0; v < m; v++)
		{
			for (int i = 0; i < n; i++)
			{
				if ((s >> i) & 1)
				{
					for (int u = 0; u < m; u++)
					{
						if(d[v][u] >= 0)
							dp[s & ~(1 << i)][u] = min(dp[s & ~(1 << i)][u], dp[s][v] + d[v][u] * 1.0 / t[i]);
					}
				}
			}
		}
	}
	if (res == INF)
		printf("Impossible\n");
	else
		printf("%.3f\n", res);
}

int main(void)
{
	int s, from, to, len;
	while (scanf("%d %d %d %d %d", &n, &m, &s, &a, &b) != EOF && (n + m + s + a + b))
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &t[i]);

		memset(d, -1, sizeof(d));
		for (int i = 1; i <= s; i++)
		{
			scanf("%d %d %d", &from, &to, &len);
			d[from - 1][to - 1] = len;
			d[to - 1][from - 1] = len;
		}
		solve();
	}
}