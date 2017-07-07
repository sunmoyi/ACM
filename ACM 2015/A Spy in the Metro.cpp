#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 440
#define INF 0x3f3f3f3f

using namespace std;

int n, T;
int t[maxn];
int m1, d1[maxn];
int m2, d2[maxn];
int dp[maxn][maxn];
int hasR[maxn][maxn], hasL[maxn][maxn];

void init()
{
	memset(hasR, 0, sizeof(hasR));
	memset(hasL, 0, sizeof(hasL));
	memset(dp, INF, sizeof(dp));
	memset(t, 0, sizeof(t));
	memset(d1, 0, sizeof(d1));
	memset(d2, 0, sizeof(d2));
}

void getH()
{
	for (int i = 0; i < m1; i++)
	{
		int time = d1[i];
		for(int j = 1; j <= n; j++)
		{
			time += t[j];
			hasR[time][j] = true;
		}
	}

	for (int i = 0; i<m2; i++)
	{
		int time = d2[i];
		for (int j = n; j >= 1; j--)
		{
			time += t[j + 1];
			hasL[time][j] = true;
		}
	}
}

int main(void)
{
	int icase = 1;
	while(scanf("%d", &n) != EOF && n)
	{
		init();

		scanf("%d", &T);
		for (int i = 2; i <= n; i++)
			scanf("%d", t + i);
		scanf("%d", &m1);
		for (int i = 0; i < m1; i++)
			scanf("%d", d1 + i);
		scanf("%d", &m2);
		for (int i = 0; i < m2; i++)
			scanf("%d", d2 + i);

		getH();

		dp[T][n] = 0;

		for (int i = T - 1; i >= 0; i--)
		{
			for (int j = 1; j <= n; j++)
			{
				dp[i][j] = dp[i + 1][j] + 1;

				if (j < n && i + t[j + 1] <= T && hasR[i][j])
					dp[i][j] = min(dp[i][j], dp[i + t[j + 1]][j + 1]);

				if (j > 1 && i + t[j] <= T && hasL[i][j])
					dp[i][j] = min(dp[i][j], dp[i + t[j]][j - 1]);
			}
		}
		printf("Case Number %d: ", icase++);
		if (dp[0][1] >= INF)
			printf("impossible\n");
		else
			printf("%d\n", dp[0][1]);
	}
	return 0;
}