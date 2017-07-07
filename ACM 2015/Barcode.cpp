#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1100
#define INF 0x3f3f3f3f
#define min(a, b) (a < b? a:b)
using namespace std;

int n, m, x, y, a[maxn];
char map[maxn][maxn];
int dp[maxn][maxn];

int main(void)
{
	scanf("%d %d %d %d", &n, &m, &x, &y);
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= n; i++)
	{
		getchar();
		for (int j = 1; j <= m; j++)
			scanf("%c", &map[i][j]);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (map[i][j] == '#')
				a[j]++;
	for (int i = 1; i <= m; i++)
		a[i] += a[i - 1];
	memset(dp, 0x42, sizeof(dp));
	dp[0][0] = 0, dp[1][0] = 0;
	for (int i = 0; i <= m; i++)
	{
		for (int j = x; j <= y && i + j <= m; j++)
		{
			dp[0][i + j] = min(dp[1][i] + a[i + j] - a[i], dp[0][i + j]);
			dp[1][i + j] = min(dp[0][i] + n * j - a[i + j] + a[i], dp[1][i + j]);
		}
	}
	printf("%d\n", min(dp[0][m], dp[1][m]));
	return 0;
}