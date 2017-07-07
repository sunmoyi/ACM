#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 19

using namespace std;

long long ma[maxn][maxn];
long long s[maxn + 10];
long long dp[1 << maxn][maxn + 10];

int main(void)
{
	int n, m, k, a, b, c;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%lld", &s[i]);
	for (int i = 0; i < k; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		a--, b--;
		ma[a][b] = c;
	}
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++)
		dp[1 << i][i] = s[i];
	long long maxx = 0;
	for (int i = 0; i < (1 << n); i++)
	{
		long long temp = i;
		long long num = 0;
		while (temp > 0)
		{
			if (temp & 1)
				num++;
			temp >>= 1;
		}
		if (num == m)
		{
			for (int j = 0; j < n; j++)
				maxx = max(maxx, dp[i][j]);
		}
		else
		{
			for (int j = 0; j < n; j++)
			{
				if (dp[i][j] == -1)
					continue;
				for (int k = 0; k < n; k++)
				{
					if (i & (1 << k))
						continue;
					else
						dp[i | (1 << k)][k] = max(dp[i | (1 << k)][k], dp[i][j] + s[k] + ma[j][k]);
				}
			}
		}
	}
	printf("%lld\n", maxx);
}