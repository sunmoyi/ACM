#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int N[105], A[35], B[35], V[105];
int ans, n, m, k;
int dp[1005][35];

int main (void)
{
	while (scanf("%d", &ans) != EOF)
	{
		while (ans--)
		{
			scanf("%d %d %d", &n, &m, &k);
			for (int i = 1; i <= n; i++)
				scanf("%d", &V[i]);
			for (int i = 1; i <= n; i++)
				scanf("%d", &N[i]);

			memset(dp, 0, sizeof(dp));

			for (int i = 1; i <= n; i++)
			{
				for (int j = m; j >= N[i]; j--)
				{
					for (int kk = 1; kk <= k; kk++)
					{
						A[kk] = dp[j - N[i]][kk] + V[i];
						B[kk] = dp[j][kk];
					}

					A[k + 1] = B[k + 1] = -1;
					int a = 1, b = 1, c = 1;
					while (c <= k && (A[a] != -1 || B[b] != -1))
					{
						if (A[a] > B[b])
							dp[j][c] = A[a], a++;
						else
							dp[j][c] = B[b], b++;
						if (dp[j][c] != dp[j][c - 1])
							c++;
					}
				}
			}
			printf("%d\n", dp[m][k]);
		}
	}
	return 0;
}