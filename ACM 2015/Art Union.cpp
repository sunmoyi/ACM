#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

int num[maxn][15];
int dp[maxn][10];//dp[i][j] 前i幅画第j个人画完至少需要的时间
int n, m;

int main(void)
{
	while (scanf("%d %d", &n, &m) != EOF)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%d", &num[i][j]);


		memset(dp, 0, sizeof(dp));
		int temp = 0;
		for (int i = 1; i <= m; i++)
		{
			temp += num[1][i];
			dp[1][i] = temp;
		}
		temp = 0;
		for (int i = 1; i <= n; i++)
		{
			temp += num[i][1];
			dp[i][1] = temp;
		}


		for (int i = 2; i <= n; i++)
			for (int j = 2; j <= m; j++)
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + num[i][j];
		for (int i = 1; i < n; i++)
			printf("%d ", dp[i][m]);
		printf("%d\n", dp[n][m]);
	}
	return 0;
}