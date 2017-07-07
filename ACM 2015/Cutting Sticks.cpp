#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10000
#define INF 0x3f3f3f3f

using namespace std;

int dp[maxn][maxn];
int num[maxn];

int main(void)
{
	int n, m, i, j, L, p, k, temp;
	int min;
	int MIN;
	while (scanf("%d", &L) != EOF && L)
	{
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
			scanf("%d", &num[i]);
		num[0] = 0;
		num[n + 1] = L;
		memset(dp, 0, sizeof(dp));
		for (p = 1; p <= n + 1; p++)
		{
			for (i = 0; i <= n + 1; i++)
			{
				j = i + p;
				MIN = INF;
				if (j > n + 1)
					break;
				for (k = i + 1; k < j; k++)
				{
					temp = dp[i][k] + dp[k][j] + num[j] - num[i];
					if (MIN > temp)
						MIN = temp;
				}
				if (MIN != INF)
					dp[i][j] = MIN;
			}
		}
		printf("The minimum cutting is %d.\n", dp[0][n + 1]);
	}
	return 0;
}