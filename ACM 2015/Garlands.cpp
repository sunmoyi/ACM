#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 40010
#define INF 0x3f3f3f3f

using namespace std;

int w[maxn], sum[maxn];
int dp[maxn][2], n, m, d;

int check(int x)
{
	dp[0][0] = 0;
	dp[0][1] = INF;
	for (int i = 2; i <= n; i += 2)
	{
		dp[i][0] = INF;
		dp[i][1] = INF;
		for (int len = 1; len <= d && i - 2 * len >= 0; len++)
		{
			if (sum[i] - sum[i - len] > x)
				break;
			if (sum[i - len] - sum[i - 2 * len] <= x)
			{
				dp[i][0] = min(dp[i][0], dp[i - len * 2][1] + 1);
				dp[i][1] = min(dp[i][1], dp[i - len * 2][0] + 1);
			}
		}
	}
	if (dp[n][(m - 1) % 2] > m - 1)
		return 0;
	else
		return 1;
}

int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d %d", &n, &m, &d);
		sum[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &w[i]);
			sum[i] = sum[i - 1] + w[i];
		}
		if ((n & 1) || (n < 2 * (m - 1) || (n > 2 * d * (m - 1))))
			printf("BAD\n");
		else
		{
			int l = 1, r = sum[n];
			while (l < r)
			{
				int mid = (l + r) >> 1;
				if (check(mid))
					r = mid;
				else
					l = mid + 1;
			}
			printf("%d\n", l);
		}
	}
	return 0;
}