#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 5010
#define mod 1000000007

using namespace std;

int n, a, b, k;
int dp[maxn][maxn];

void add(int x, int l, int r, int d)
{
	
	dp[x][l] += d;
	dp[x][l] %= mod;
	dp[x][r] -= d;
	dp[x][r] = (dp[x][r] + mod) % mod;
}

int main(void)
{
	scanf("%d %d %d %d", &n, &a, &b, &k);
	dp[0][a] = 1;
	for (int i = 0; i < k; i++)
	{
		//printf("%d\n", i);
		for (int j = 1; j <= n; j++)
		{
			
			if (j == b)
				continue;
			int temp = abs(j - b) - 1;
			add(i + 1, max(j - temp, 1), j, dp[i][j]);
			add(i + 1, j + 1, min(j + temp + 1, n + 1), dp[i][j]);
		}
		int cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			cnt += dp[i + 1][j];
			cnt %= mod;
			dp[i + 1][j] = cnt;
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		res += dp[k][i];
		res %= mod;
	}
	printf("%d\n", res);
	return 0;
}