#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 12
#define INF 0x3f3f3f3f

using namespace std;

int stamp[maxn][maxn];
int dp[1110][maxn];

bool fun(int set, int c, int n)
{
	if (dp[c][n] != -1)
		return dp[c][n];
	if (!c)
		return dp[c][n] = true;
	if (!n)
		return dp[c][n] = false;
	for (int i = 1; i <= stamp[set][0]; i++)
		if (c >= stamp[set][i] && fun(set, c - stamp[set][i], n - 1))
			return dp[c][n] = true;
	return dp[c][n] = false;
}

int cmp(int a, int b)
{
	if (stamp[a][0] != stamp[b][0])
		return (stamp[a][0] < stamp[b][0]) ? a : b;
	for (int i = stamp[a][0]; i > 0; i--)
		if (stamp[a][i] != stamp[b][i])
			return (stamp[a][i] < stamp[b][i]) ? a : b;
	return a;
}

int main(void)
{
	int s;
	while (scanf("%d", &s) != EOF  && s)
	{
		int N;
		scanf("%d", &N);
		int ans = 0, key = 0;
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &stamp[i][0]);
			for (int j = 1; j <= stamp[i][0]; j++)
				scanf("%d", &stamp[i][j]);
		}
		for (int i = 1; i <= N; i++)
		{
			memset(dp, -1, sizeof(dp));
			int k = 0;
			for (int j = 1;; j++)
			{
				if (fun(i, j, s))
					k = j;
				else
					break;
			}
			if (k == ans)
				key = cmp(key, i);
			if (k > ans)
			{
				ans = k;
				key = i;
			}
		}
		printf("max coverage =%4d :", ans);
		for (int i = 1; i <= stamp[key][0]; i++)
			printf("%3d", stamp[key][i]);
		printf("\n");
	}
	return 0;
}