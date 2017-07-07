#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 45

using namespace std;

int plie[4][maxn], dp[maxn][maxn][maxn][maxn];
int n, top[4];
bool hashh[maxn];

int dfs(int count)
{
	if (dp[top[0]][top[1]][top[2]][top[3]] != -1)
		return dp[top[0]][top[1]][top[2]][top[3]];

	if (count == 5)
		return dp[top[0]][top[1]][top[2]][top[3]] = 0;

	int ans = 0;
	for (int i = 0; i < 4; i++)
	{
		if (top[i] == n)
			continue;
		int color = plie[i][top[i]];
		top[i] += 1;
		if (hashh[color])
		{
			hashh[color] = false;
			ans = max(ans, dfs(count - 1) + 1);
			hashh[color] = true;
		}
		else
		{
			hashh[color] = true;
			ans = max(ans, dfs(count + 1));
			hashh[color ] = false;
		}
		top[i] -= 1;
	}
	return dp[top[0]][top[1]][top[2]][top[3]] = ans;
}

int main (void)
{
	while (scanf("%d", &n) != EOF && n)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 4; j++)
				scanf("%d", &plie[j][i]);
		memset(dp, -1, sizeof(dp));
		memset(hashh, false, sizeof(hashh));
		top[0] = top[1] = top[2] = top[3] = 0;
		printf("%d\n", dfs(0));
	}
	return 0;
}