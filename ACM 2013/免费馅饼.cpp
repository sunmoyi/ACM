#include<iostream>  
#include<algorithm>  
using namespace std;
int dp[11][100001];
int max(int a, int b, int c = -1)
{
	if (a<b) a = b;
	if (a<c) a = c;
	return a;
}
int main()
{
	int n, i, j;
	int t, x;
	while (scanf("%d", &n) != EOF &&n)
	{
		memset(dp, 0, sizeof(dp));
		int maxtime = 0;
		for (i = 0; i<n; i++)
		{
			scanf("%d%d", &x, &t);
			++dp[x][t];
			maxtime = t>maxtime ? t : maxtime;
		}
		for (j = maxtime - 1; j >= 0; --j)
		{
			dp[0][j] += max(dp[0][j + 1], dp[1][j + 1]);
			dp[10][j] += max(dp[10][j + 1], dp[9][j + 1]);
			for (i = 1; i<10; i++)
			{
				dp[i][j] += max(dp[i][j + 1],
						dp[i + 1][j + 1], dp[i - 1][j + 1]);
			}
		}
		printf("%d\n", dp[5][0]);
	}
	return 0;
}
